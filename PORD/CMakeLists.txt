add_library(libpord STATIC)

target_sources(libpord
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

target_include_directories(libpord
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(libpord PRIVATE OpenMP::OpenMP_C)

target_compile_definitions(libpord INTERFACE PORD)

set_target_properties(libpord
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON

)

add_library(lib::pord ALIAS libpord)