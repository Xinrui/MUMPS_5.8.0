add_executable(ecl32_test ecl32.c)

target_link_libraries(ecl32_test PRIVATE 
  MUMPS::MUMPS
)