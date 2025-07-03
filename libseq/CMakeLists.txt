add_library(libmpiseq_C OBJECT
  elapse.c
  mpic.c
)

target_link_libraries(libmpiseq_C
  PRIVATE
  OpenMP::OpenMP_C
)

add_library(libmpiseq_Fortran OBJECT
  mpi.f
)

target_link_libraries(libmpiseq_Fortran
  PRIVATE
  OpenMP::OpenMP_Fortran
)

target_compile_definitions(libmpiseq_Fortran
  PRIVATE 
  GEMMT_AVAILABLE
)

add_library(libmpiseq
  $<TARGET_OBJECTS:libmpiseq_C>
  $<TARGET_OBJECTS:libmpiseq_Fortran>
)

target_include_directories(libmpiseq
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(libmpiseq
  PRIVATE
  OpenMP::OpenMP_C
  OpenMP::OpenMP_Fortran
)

set_target_properties(libmpiseq
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON

)

add_library(lib::mpiseq ALIAS libmpiseq)