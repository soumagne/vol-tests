set(UBSAN_FLAG "-fsanitize=undefined")
set(UBSAN_C_FLAGS "-O1 -g ${UBSAN_FLAG} -fno-omit-frame-pointer")
set(UBSAN_CXX_FLAGS ${UBSAN_C_FLAGS})

get_property(UBSAN_LANGUAGES GLOBAL PROPERTY ENABLED_LANGUAGES)
foreach(lang ${UBSAN_LANGUAGES})
  set(UBSAN_${lang}_LANG_ENABLED 1)
endforeach()

if(UBSAN_C_LANG_ENABLED)
  include(CheckCCompilerFlag)
  set(CMAKE_REQUIRED_LINK_OPTIONS ${UBSAN_FLAG})
  check_c_compiler_flag(${UBSAN_FLAG} UBSAN_C_FLAG_SUPPORTED)
  if(NOT UBSAN_C_FLAG_SUPPORTED)
    message(STATUS "Ubsan flags are not supported by the C compiler.")
  else()
    if(NOT CMAKE_C_FLAGS_UBSAN)
      set(CMAKE_C_FLAGS_UBSAN ${UBSAN_C_FLAGS} CACHE STRING "Flags used by the C compiler during UBSAN builds." FORCE)
    endif()
  endif()
  unset(CMAKE_REQUIRED_LINK_OPTIONS)
endif()

if(UBSAN_CXX_LANG_ENABLED)
  include(CheckCXXCompilerFlag)
  set(CMAKE_REQUIRED_LINK_OPTIONS ${UBSAN_FLAG})
  check_cxx_compiler_flag(${UBSAN_FLAG} UBSAN_CXX_FLAG_SUPPORTED)
  if(NOT UBSAN_CXX_FLAG_SUPPORTED)
    message(STATUS "Ubsan flags are not supported by the CXX compiler.")  
  else()
    if(NOT CMAKE_CXX_FLAGS_UBSAN)
      set(CMAKE_CXX_FLAGS_UBSAN ${UBSAN_CXX_FLAGS} CACHE STRING "Flags used by the CXX compiler during UBSAN builds." FORCE)
    endif()
  endif()
  unset(CMAKE_REQUIRED_LINK_OPTIONS)
endif()
