add_executable(ecl32 ecl32.cpp)

target_link_libraries(ecl32 PRIVATE 
  MUMPS::MUMPS
)

add_executable(apd3d apd3d.cpp)

target_link_libraries(apd3d PRIVATE 
  MUMPS::MUMPS
)