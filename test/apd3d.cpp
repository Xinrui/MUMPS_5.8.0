#include <highfive/highfive.hpp>
#include <mumps.hpp>

#include <ctime>
#include <omp.h>

using namespace HighFive;

int main()
{
	// 1. 读取数据

	File file{"E:/workspace/MUMPS_5.8.0/data/linear_system_dump.h5", File::ReadOnly};

	auto dataset = file.getDataSet("New_SingleScan1/0.001_04/jacobian_column_indices");
	auto column_indices = dataset.read<std::vector<int>>();

	dataset = file.getDataSet("New_SingleScan1/0.001_04/jacobian_row_pointers");
	auto row_pointers = dataset.read<std::vector<int>>();

	dataset = file.getDataSet("New_SingleScan1/0.001_04/jacobian_data");
	auto data = dataset.read<std::vector<double>>();

	int nnz = data.size();
	int nrows = row_pointers.size() - 1;

	std::vector<int> row_coo(nnz);
	std::vector<int> col_coo(nnz);
	std::vector<double> val_coo(nnz);

	for (int i = 0; i < nrows; ++i)
	{
		for (int j = row_pointers[i]; j < row_pointers[i + 1]; ++j)
		{
			row_coo[j] = i;					// 行号
			col_coo[j] = column_indices[j]; // 列号
			val_coo[j] = data[j];			// 值
		}
	}

	std::vector<double> rhs(59900);
	dataset = file.getDataSet("New_SingleScan1/0.001_04/rhs");
	dataset.read_raw(rhs.data());

	assert(nrows == rhs.size());

	// 2. 求解方程
	MUMPS_STRUC_C<double> mumps_par;
	mumps_par.comm() = 	USE_COMM_WORLD;
	mumps_par.par() = 1; 
	mumps_par.sym() = 0; 
	mumps_par.job() = JOB_INIT;
	mumps_c(mumps_par);

	mumps_par.n() = nrows;
	mumps_par.nnz() = nnz;
	mumps_par.irn() = row_coo.data();
	mumps_par.jcn() = col_coo.data();
	mumps_par.a() = val_coo.data();
	mumps_par.rhs() = rhs.data();

	mumps_par.ICNTL(1) = 1; 
	mumps_par.ICNTL(2) = -1; 
	mumps_par.ICNTL(3) = -1; 
	mumps_par.ICNTL(4) = -1; 

	mumps_par.job() = 6;

	std::clock_t t1 = clock();
	mumps_c(mumps_par);
	std::clock_t t2 = clock();

	double elapsed = static_cast<double>(t2 - t1) / CLOCKS_PER_SEC;

	mumps_par.job() = JOB_END;
	mumps_c(mumps_par);

	// powershell中，按照以下方法设置环境变量：
	// $env:OMP_NUM_THREADS = "12"
	printf("线程数：%d\n", omp_get_max_threads());
	printf("执行时间: %f 秒\n", elapsed);

	return 0;
}