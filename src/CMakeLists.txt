set(SRCS_COMMON_MOD 
  ana_blk_m.F
  ana_omp_m.F
  ana_orderings_wrappers_m.F
  double_linked_list.F
  fac_asm_build_sort_index_ELT_m.F
  fac_asm_build_sort_index_m.F
  fac_descband_data_m.F
  fac_future_niv2_mod.F
  fac_maprow_data_m.F
  front_data_mgt_m.F
  lr_common.F
  lr_stats.F
  mumps_comm_buffer_common.F
  mumps_intr_types_common.F
  mumps_l0_omp_m.F
  mumps_load.F
  mumps_memory_mod.F
  mumps_mpitoomp_m.F
  mumps_ooc_common.F
  mumps_pivnul_mod.F 
  mumps_static_mapping.F
  omp_tps_common_m.F
  sol_ds_common_m.F
  sol_omp_common_m.F
  tools_common_m.F
)

# Object files for arithmetic-independent FORTRAN files.
set(SRCS_COMMON_OTHER
  ana_blk.F
  ana_orderings.F
  ana_set_ordering.F
  ana_AMDMF.F
  bcast_errors.F
  estim_flops.F
  mumps_type2_blocking.F
  mumps_version.F
  mumps_print_defined.F
  sol_common.F
  tools_common.F
)

# Object files for arithmetic-independent C files.
set(SRCS_C_COMMON
  mumps_addr.c
  mumps_common.c
  mumps_config_file_C.c
  mumps_io.c
  mumps_io_basic.c
  mumps_io_err.c
  mumps_numa.c
  mumps_io_thread.c
  mumps_pord.c
  mumps_metis.c
  mumps_metis64.c
  mumps_metis_int.c
  mumps_scotch.c
  mumps_scotch64.c
  mumps_scotch_int.c
  mumps_register_thread.c
  mumps_thread.c
  mumps_thread_affinity.c
  mumps_flytes.c
  mumps_save_restore_C.c
)

set(SRCS_MOD_ARITHDEP
  ${ARITH}ana_aux.F
  ${ARITH}ana_aux_par.F
  ${ARITH}ana_lr.F
  ${ARITH}fac_asm_master_ELT_m.F
  ${ARITH}fac_asm_master_m.F
  ${ARITH}fac_compact_factors_m.F
  ${ARITH}fac_front_aux.F
  ${ARITH}fac_front_LU_type1.F
  ${ARITH}fac_front_LU_type2.F
  ${ARITH}fac_front_LDLT_type1.F
  ${ARITH}fac_front_LDLT_type2.F
  ${ARITH}fac_front_type2_aux.F
  ${ARITH}fac_sispointers_m.F
  ${ARITH}fac_lr.F
  ${ARITH}fac_mem_dynamic.F
  ${ARITH}fac_omp_m.F
  ${ARITH}fac_par_m.F
  ${ARITH}fac_sol_l0omp_m.F
  ${ARITH}lr_core.F
  ${ARITH}lr_type.F
  ${ARITH}mumps_comm_buffer.F
  ${ARITH}mumps_config_file.F
  ${ARITH}mumps_intr_types.F
  ${ARITH}mumps_lr_data_m.F
  ${ARITH}mumps_mpi3_mod.F
  ${ARITH}mumps_ooc_buffer.F
  ${ARITH}mumps_ooc.F
  ${ARITH}mumps_sol_es.F
  ${ARITH}mumps_save_restore_files.F
  ${ARITH}mumps_save_restore.F
  ${ARITH}mumps_struc_def.F
  ${ARITH}omp_tps_m.F
  ${ARITH}sol_lr.F
  ${ARITH}sol_omp_m.F
  ${ARITH}static_ptr_m.F
)

# Mixture of C and Fortran source files
set(SRCS_OTHER
  ${ARITH}ana_aux_ELT.F
  ${ARITH}ana_dist_m.F
  ${ARITH}ana_driver.F
  ${ARITH}ana_LDLT_preprocess.F
  ${ARITH}ana_reordertree.F
  ${ARITH}arrowheads.F
  ${ARITH}bcast_int.F
  ${ARITH}end_driver.F
  ${ARITH}fac_asm_ELT.F
  ${ARITH}fac_asm.F
  ${ARITH}fac_b.F
  ${ARITH}fac_diag.F
  ${ARITH}fac_distrib_distentry.F
  ${ARITH}fac_dist_arrowheads_omp.F
  ${ARITH}fac_distrib_ELT.F
  ${ARITH}fac_driver.F
  ${ARITH}fac_lastrtnelind.F
  ${ARITH}fac_mem_alloc_cb.F
  ${ARITH}fac_mem_compress_cb.F
  ${ARITH}fac_mem_free_block_cb.F
  ${ARITH}fac_mem_stack_aux.F
  ${ARITH}fac_mem_stack.F
  ${ARITH}fac_process_band.F
  ${ARITH}fac_process_blfac_slave.F
  ${ARITH}fac_process_blocfacto_LDLT.F
  ${ARITH}fac_process_blocfacto.F
  ${ARITH}fac_process_bf.F
  ${ARITH}fac_process_end_facto_slave.F
  ${ARITH}fac_process_contrib_type1.F
  ${ARITH}fac_process_contrib_type2.F
  ${ARITH}fac_process_contrib_type3.F
  ${ARITH}fac_process_maprow.F
  ${ARITH}fac_process_master2.F
  ${ARITH}fac_process_message.F
  ${ARITH}fac_process_root2slave.F
  ${ARITH}fac_process_root2son.F
  ${ARITH}fac_process_rtnelind.F
  ${ARITH}fac_root_parallel.F
  ${ARITH}fac_scalings.F
  ${ARITH}fac_determinant.F
  ${ARITH}fac_scalings_simScaleAbs.F
  ${ARITH}fac_scalings_simScale_util.F
  ${ARITH}fac_sol_pool.F
  ${ARITH}fac_type3_symmetrize.F
  ${ARITH}ini_defaults.F
  ${ARITH}ini_driver.F
  mumps_c.c
  ${ARITH}mumps_driver.F
  ${ARITH}mumps_f77.F
  ${ARITH}mumps_gpu.c
  ${ARITH}mumps_iXamax.F
  ${ARITH}ana_mtrans.F
  ${ARITH}ooc_panel_piv.F
  ${ARITH}rank_revealing.F
  ${ARITH}sol_aux.F
  ${ARITH}sol_bwd_aux.F
  ${ARITH}sol_bwd.F
  ${ARITH}sol_c.F
  ${ARITH}sol_distrhs.F
  ${ARITH}sol_distsol.F
  ${ARITH}sol_driver.F
  ${ARITH}sol_fwd_aux.F
  ${ARITH}sol_fwd.F
  ${ARITH}sol_matvec.F
  ${ARITH}sol_root_parallel.F
  ${ARITH}tools.F
  ${ARITH}type3_root.F
)

add_library(mumps_common
  ${SRCS_COMMON_MOD}
  ${SRCS_COMMON_OTHER}
  ${SRCS_C_COMMON}
)

target_include_directories(mumps_common PUBLIC
  $<BUILD_INTERFACE:${MUMPS_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_definitions(mumps_common PUBLIC
  $<$<COMPILE_LANGUAGE:C>:Add_>
  $<$<COMPILE_LANGUAGE:Fortran>:GEMMT_AVAILABLE>
)

target_link_libraries(mumps_common PUBLIC
  lib::pord
  lib::mpiseq
  metis::metis
  OpenMP::OpenMP_C
  OpenMP::OpenMP_Fortran
  Threads::Threads
)

set_target_properties(mumps_common
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

add_library(lib::mumps_common ALIAS mumps_common)

add_library(${ARITH}mumps
  ${SRCS_MOD_ARITHDEP}
  ${SRCS_OTHER}
)

target_include_directories(${ARITH}mumps PUBLIC
  $<BUILD_INTERFACE:${MUMPS_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(${ARITH}mumps PUBLIC
  lib::pord
  lib::mpiseq
  metis::metis
  OpenMP::OpenMP_C
  OpenMP::OpenMP_Fortran
  MKL::MKL
  Threads::Threads PRIVATE
  lib::mumps_common
)

target_compile_definitions(${ARITH}mumps PUBLIC
  $<$<COMPILE_LANGUAGE:C>:Add_>
  $<$<COMPILE_LANGUAGE:Fortran>:GEMMT_AVAILABLE>
)

set_target_properties(${ARITH}mumps
  PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

set_property(SOURCE mumps_c.c APPEND PROPERTY
  COMPILE_DEFINITIONS "MUMPS_ARITH=MUMPS_ARITH_${ARITH}"
)

add_library(MUMPS INTERFACE)

target_link_libraries(MUMPS INTERFACE 
  mumps_common
  ${ARITH}mumps
)

add_library(MUMPS::MUMPS ALIAS MUMPS)