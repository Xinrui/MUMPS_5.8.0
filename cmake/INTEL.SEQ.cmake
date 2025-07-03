set(LIBSEQNEEDED ON)
set(ARITH d)
configure_file(${MUMPS_SOURCE_DIR}/src/mumps_int_def32_h.in 
  ${MUMPS_SOURCE_DIR}/include/mumps_int_def.h @ONLY)