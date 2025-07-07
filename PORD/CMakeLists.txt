add_library(pord STATIC)

target_sources(pord
  PRIVATE
  lib/graph.c 
  lib/gbipart.c 
  lib/gbisect.c 
  lib/ddcreate.c 
  lib/ddbisect.c 
  lib/nestdiss.c 
  lib/multisector.c 
  lib/gelim.c 
  lib/bucket.c 
  lib/tree.c 
  lib/symbfac.c 
  lib/interface.c 
  lib/sort.c 
  lib/minpriority.c
)

target_include_directories(pord
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_options(pord
  PRIVATE
  ${OpenMP_C_FLAGS}
)

target_compile_definitions(pord INTERFACE PORD)

set_target_properties(pord
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

add_library(lib::pord ALIAS pord)