# mpiseq_C
add_library(mpiseq_C OBJECT
  elapse.c
  mpic.c
)

target_compile_options(mpiseq_C
  PRIVATE 
  ${OpenMP_C_FLAGS}
)

set_target_properties(mpiseq_C
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

# libmpiseq_Fortran
add_library(mpiseq_Fortran OBJECT
  mpi.f
)

target_compile_definitions(mpiseq_Fortran
  PRIVATE 
  GEMMT_AVAILABLE
)

target_compile_options(mpiseq_Fortran
  PRIVATE 
  ${OpenMP_Fortran_FLAGS}
)

set_target_properties(mpiseq_Fortran
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

add_library(mpiseq
  $<TARGET_OBJECTS:mpiseq_C>
  $<TARGET_OBJECTS:mpiseq_Fortran>
)

target_include_directories(mpiseq
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

add_library(lib::mpiseq ALIAS mpiseq)