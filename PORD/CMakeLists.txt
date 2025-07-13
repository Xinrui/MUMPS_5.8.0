add_library(pord)

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

target_link_libraries(pord
  PRIVATE
  OpenMP::OpenMP_C
)

target_compile_definitions(pord INTERFACE pord)

set_target_properties(pord
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

add_library(lib::pord ALIAS pord)
