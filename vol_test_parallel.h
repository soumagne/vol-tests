/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://support.hdfgroup.org/ftp/HDF5/releases.  *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef VOL_TEST_PARALLEL_H
#define VOL_TEST_PARALLEL_H

#include <mpi.h>

#include "vol_test.h"
#include "testpar.h"

#define PARALLEL_TEST_FILE_NAME "vol_test_parallel.h5"
extern char vol_test_parallel_filename[];

#undef TESTING
#undef TESTING_2
#undef PASSED
#undef H5_FAILED
#undef H5_WARNING
#undef SKIPPED
#undef PUTS_ERROR
#undef TEST_ERROR
#undef STACK_ERROR
#undef FAIL_STACK_ERROR
#undef FAIL_PUTS_ERROR

#define TESTING(WHAT)  {if (MAINPROCESS) { printf("Testing %-62s",WHAT); fflush(stdout); }}
#define TESTING_2(WHAT)  {if (MAINPROCESS) { printf("  Testing %-60s",WHAT); fflush(stdout); }}
#define PASSED()  {if (MAINPROCESS) { puts(" PASSED");fflush(stdout); }}
#define H5_FAILED()  {if (MAINPROCESS) { puts("*FAILED*");fflush(stdout); }}
#define H5_WARNING()  {if (MAINPROCESS) { puts("*WARNING*");fflush(stdout); }}
#define SKIPPED()  {if (MAINPROCESS) { puts(" -SKIP-");fflush(stdout); }}
#define PUTS_ERROR(s)   {if (MAINPROCESS) { puts(s); AT(); } goto error;}
#define TEST_ERROR      {if (MAINPROCESS) { H5_FAILED(); AT(); } goto error;}
#define STACK_ERROR     {if (MAINPROCESS) { H5Eprint2(H5E_DEFAULT, stdout); } goto error;}
#define FAIL_STACK_ERROR {if (MAINPROCESS) { H5_FAILED(); AT(); H5Eprint2(H5E_DEFAULT, stdout); } goto error;}
#define FAIL_PUTS_ERROR(s) {if (MAINPROCESS) { H5_FAILED(); AT(); puts(s); } goto error;}

hid_t
create_mpio_fapl(MPI_Comm comm, MPI_Info info);

extern int mpi_size, mpi_rank;

#endif
