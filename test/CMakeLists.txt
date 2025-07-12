add_executable(ecl32 ecl32.cpp)

target_link_libraries(ecl32 PRIVATE 
  MUMPS::MUMPS
  OpenMP::OpenMP_CXX
)

# add_executable(apd3d_test apd3d.cpp)
# 
# target_link_libraries(apd3d_test PRIVATE 
#   HDF5::HDF5
#   HighFive::HighFive
#   MUMPS::MUMPS
# )