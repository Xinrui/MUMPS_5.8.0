add_library(mpiseq
  elapse.c
  mpic.c
  mpi.f
)

target_link_libraries(mpiseq
  PRIVATE
  OpenMP::OpenMP_C
  OpenMP::OpenMP_Fortran
)

target_include_directories(mpiseq
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)


target_compile_definitions(mpiseq PRIVATE
  $<$<COMPILE_LANGUAGE:C>:Add_>
  $<$<COMPILE_LANGUAGE:Fortran>:GEMMT_AVAILABLE>
)

set_target_properties(mpiseq
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

add_library(lib::mpiseq ALIAS mpiseq)