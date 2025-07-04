/*
 *
 *  This file is part of MUMPS 5.8.0, released
 *  on Tue May  6 08:27:40 UTC 2025
 *
 */
/* Example program using the C interface to the
 * double real arithmetic version of MUMPS, dmumps_c.
 * We solve the system A x = RHS with
 *   A = diag(1 2) and RHS = [1 4]^T
 * Solution is [1 2]^T */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"
#include "dmumps_c.h"
#include <omp.h>
#define JOB_INIT -1
#define JOB_END -2
#define USE_COMM_WORLD -987654

#if defined(MAIN_COMP)
/*
 * Some Fortran compilers (COMPAQ fort) define "main" in
 * their runtime library while a Fortran program translates
 * to MAIN_ or MAIN__ which is then called from "main".
 * We defined argc/argv arbitrarily in that case.
 */
int MAIN__();
int MAIN_()
{
	return MAIN__();
}

int MAIN__()
{
	int argc = 1;
	char *name = "c_example";
	char **argv;
#else
int main(int argc, char **argv)
{
#endif
	DMUMPS_STRUC_C id;
	MUMPS_INT n = 51993;
	MUMPS_INT nnz = 380415;
	MUMPS_INT *irn = NULL;
	MUMPS_INT *jcn = NULL;
	double *a = NULL;
	double *rhs = NULL;
	irn = (MUMPS_INT *)malloc(nnz * sizeof(MUMPS_INT));
	jcn = (MUMPS_INT *)malloc(nnz * sizeof(MUMPS_INT));
	a = (double *)malloc(nnz * sizeof(double));
	rhs = (double *)malloc(n * sizeof(double));
	// MUMPS_INT n = 2;
	// MUMPS_INT8 nnz = 2;
	// MUMPS_INT irn[] = {1,2};
	// MUMPS_INT jcn[] = {1,2};
	// double a[2];
	// double rhs[2];

	/* When compiling with -DINTSIZE64, MUMPS_INT is 64-bit but MPI
	   ilp64 versions normally still require standard int for C */
	/* MUMPS_INT myid, ierr; */
	int myid, ierr;

	int error = 0;
#if defined(MAIN_COMP)
	argv = &name;
#endif
	ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &myid);

	FILE *file = fopen("E:\\workspace\\MUMPS_4.10.0\\ecl32.mtx", "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error opening matrix file\n");
		return 1;
	}

	int row, col;
	double val;
	int count = 0;

	// Skip comments (if any)
	char line[256];
	// Read matrix entries
	while (count < nnz && fscanf(file, "%d %d %lf", &row, &col, &val) == 3)
	{
		irn[count] = row;
		jcn[count] = col;
		a[count] = val;
		count++;
	}

	fclose(file);

	for (int i = 0; i < n; i++)
	{
		rhs[i] = 1.0;
	}
	/* Define A and rhs */
	// irn[0] = 1; irn[1] = 2;
	// jcn[0] = 1; jcn[1] = 2;
	// rhs[0]=1.0;rhs[1]=1.0;
	// a[0]=1.0;a[1]=2.0;

	/* Initialize a MUMPS instance. Use MPI_COMM_WORLD */
	id.comm_fortran = USE_COMM_WORLD;
	id.par = 1;
	id.sym = 0;
	id.job = JOB_INIT;
	dmumps_c(&id);

	/* Define the problem on the host */
	if (myid == 0)
	{
		id.n = n;
		id.nz = nnz;
		id.irn = irn;
		id.jcn = jcn;
		id.a = a;
		id.rhs = rhs;
	}
#define ICNTL(I) icntl[(I) - 1] /* macro s.t. indices match documentation */
	/* No outputs */
	id.ICNTL(1) = 1;
	id.ICNTL(2) = -1;
	id.ICNTL(3) = -1;
	id.ICNTL(4) = -1;

	/* Call the MUMPS package (analyse, factorization and solve). */
	id.job = 6;

	clock_t t1 = clock();

	dmumps_c(&id);
	if (id.infog[0] < 0)
	{
		printf(" (PROC %d) ERROR RETURN: \tINFOG(1)= %d\n\t\t\t\tINFOG(2)= %d\n",
			   myid, id.infog[0], id.infog[1]);
		error = 1;
	}

	/* Terminate instance. */
	id.job = JOB_END;
	dmumps_c(&id);
	if (myid == 0)
	{
		if (!error)
		{
			printf("Solution is : (%8.2f  %8.2f)\n", rhs[0], rhs[1]);
		}
		else
		{
			printf("An error has occured, please check error code returned by MUMPS.\n");
		}
	}

	clock_t t2 = clock();

	double elapsed = (double)(t2 - t1) / CLOCKS_PER_SEC;

	// powershell中，按照以下方法设置环境变量：
	// $env:OMP_NUM_THREADS = "12"
	printf("线程数：%d\n", omp_get_max_threads());
	printf("执行时间: %f 秒\n", elapsed);

	ierr = MPI_Finalize();
	free(a);
	free(rhs);
	free(irn);
	free(jcn);
	return 0;
}