cmake_minimum_required(VERSION 3.10)

project(MUMPS VERSION 5.8.0
  DESCRIPTION "MUMPS: MUltifrontal Massively Parallel Sparse directSolver"
  HOMEPAGE_URL "https://mumps-solver.org/"
  LANGUAGES C CXX Fortran)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include(cmake/INTEL.SEQ.cmake)

set(MKL_LINK static)
set(MKL_INTERFACE lp64)
find_package(MKL REQUIRED)

find_package(OpenMP REQUIRED)

add_subdirectory(PORD)
add_subdirectory(libseq)

add_subdirectory(src)
add_subdirectory(examples)

find_package(HDF5 REQUIRED)
add_subdirectory(external/highfive)
add_subdirectory(test)