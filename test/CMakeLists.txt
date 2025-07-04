add_executable(ecl32_test ecl32.c)

target_link_libraries(ecl32_test PRIVATE 
  MUMPS::MUMPS
)

add_executable(apd3d_test apd3d.cpp)

target_link_libraries(apd3d_test PRIVATE 
  HDF5::HDF5
  HighFive::HighFive
  MUMPS::MUMPS
)