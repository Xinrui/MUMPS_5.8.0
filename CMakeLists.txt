cmake_minimum_required(VERSION 3.10)

project(MUMPS VERSION 5.8.0
	DESCRIPTION "MUMPS: MUltifrontal Massively Parallel Sparse direct Solver"
	HOMEPAGE_URL "https://mumps-solver.org/"
	LANGUAGES C Fortran)

include(cmake/INTEL.SEQ.cmake)

set(MKL_LINK static)
set(MKL_INTERFACE lp64)
find_package(MKL REQUIRED)

find_package(OpenMP REQUIRED)

add_subdirectory(PORD)
add_subdirectory(libseq)

add_subdirectory(src)