# WIP
#[=======================================================================[.rst:
FindHighs
--------

This module determines the HiGHS library of the system.

IMPORTED Targets
^^^^^^^^^^^^^^^^

This module defines :prop_tgt:`IMPORTED` target ``highs::highs``, if
HiGHS has been found. 

Result Variables
^^^^^^^^^^^^^^^^

This module defines the following variables:

::

HiGHS_FOUND          - True if HiGHS found.

#]=======================================================================]
include(FindPackageHandleStandardArgs)

  # do a find package call to specifically look for the CMake version
  find_package(HiGHS QUIET NO_MODULE)

  # if we found the Clp cmake package then we are done, and
  # can print what we found and return.
  if(HiGHS_FOUND)
    find_package_handle_standard_args(HiGHS CONFIG_MODE)
    return()
  endif()

find_package(PkgConfig QUIET)
if(PKG_CONFIG_FOUND)
  pkg_check_modules(highs QUIET highs IMPORTED_TARGET GLOBAL)
  if(HiGHS_FOUND)
    add_library(highs::highs ALIAS PkgConfig::highs)
  endif()
endif()
