#include <mumps.hpp>

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>

#include <vector>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " <matrix_file> <rhs_file>" << std::endl;
		return 1;
	}

	int n = 59901;
	int nnz = 1300196;

	// argv[1] : apd3d.mtx
	std::ifstream fin{argv[1]};
	if (!fin)
	{
		std::cerr << "Error opening file: " << argv[1] << std::endl;
		return 1;
	}

	std::vector<int> irn, jcn;
	std::vector<double> value;

	irn.reserve(nnz);
	jcn.reserve(nnz);
	value.reserve(nnz);

	for (std::string line; std::getline(fin, line);)
	{
		std::stringstream ss{line};
		int i, j;
		double a;
		ss >> i >> j >> a;
		irn.push_back(i);
		jcn.push_back(j);
		value.push_back(a);
	}
	fin.close();

	// argv[2] : apd3d.rhs
	fin.open(argv[2]);
	if (!fin)
	{
		std::cerr << "Error opening file: " << argv[2] << std::endl;
		return 1;
	}

	std::vector<double> rhs;
	rhs.reserve(n);

	for (std::string line; std::getline(fin, line);)
	{
		std::stringstream ss{line};
		double b;
		ss >> b;
		rhs.push_back(b);
	}
	fin.close();

	MUMPS_STRUC_C<double> mumps_par;
	mumps_par.comm() = USE_COMM_WORLD;
	mumps_par.par() = 1;
	mumps_par.sym() = 0;
	mumps_par.job() = JOB_INIT;
	mumps_c(mumps_par);

	mumps_par.n() = n;
	mumps_par.nnz() = nnz;
	mumps_par.irn() = irn.data();
	mumps_par.jcn() = jcn.data();
	mumps_par.a() = value.data();
	mumps_par.rhs() = rhs.data();

	mumps_par.job() = 6;

	using namespace std::chrono;
	auto t1 = system_clock::now();
	mumps_c(mumps_par);
	auto t2 = system_clock::now();

	auto elapsed = duration_cast<nanoseconds>(t2 - t1);

	// powershell中，按照以下方法设置环境变量：
	// $env:OMP_NUM_THREADS = "12"
	std::printf("执行时间: %f 秒\n", elapsed.count() / 1.e9);

	mumps_par.job() = JOB_END;
	mumps_c(mumps_par);

	return 0;
}