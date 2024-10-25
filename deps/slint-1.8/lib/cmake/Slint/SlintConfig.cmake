# Copyright © SixtyFPS GmbH <info@slint.dev>
# SPDX-License-Identifier: GPL-3.0-only OR LicenseRef-Slint-Royalty-free-2.0 OR LicenseRef-Slint-Software-3.0


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was SlintConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

add_library(slint_cpp-shared SHARED IMPORTED)
set_target_properties(slint_cpp-shared PROPERTIES IMPORTED_LOCATION;${_IMPORT_PREFIX}/lib/libslint_cpp.so;IMPORTED_NO_SONAME;TRUE)

function(_slint_download_compiler_and_cache)
    set(SLINT_GITHUB_RELEASE 1.8.0 CACHE STRING "GitHub Release to use for Slint Binary Artifact Downloads")

    if (CMAKE_HOST_WIN32)
        set(compiler_exe_suffix ".exe")
        set(platform_suffix "windows")
    else()
        set(platform_suffix "${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_PROCESSOR}")
    endif()

    set(prebuilt_archive_filename "slint-compiler-${platform_suffix}.tar.gz")
    set(download_url "https://github.com/slint-ui/slint/releases/download/${SLINT_GITHUB_RELEASE}/${prebuilt_archive_filename}")
    set(download_directory "${CMAKE_BINARY_DIR}/slint-prebuilt")
    message(STATUS "Downloading pre-built Slint compiler binary from ${download_url}")
    file(DOWNLOAD "${download_url}" "${download_directory}/${prebuilt_archive_filename}" STATUS download_status)
    list(GET download_status 0 download_code)
    if (NOT download_code EQUAL 0)
        list(GET download_status 1 download_message)
        message(FATAL_ERROR "Download of Slint compiler binary package failed: ${download_message}")
    else()
        file(ARCHIVE_EXTRACT INPUT "${download_directory}/${prebuilt_archive_filename}" DESTINATION "${download_directory}")
        file(REMOVE "${download_directory}/${prebuilt_archive_filename}")

        set(SLINT_COMPILER "${download_directory}/slint-compiler${compiler_exe_suffix}")
        set(SLINT_COMPILER "${SLINT_COMPILER}" CACHE STRING "Path to the slint-compiler executable" FORCE)
        set(SLINT_COMPILER "${SLINT_COMPILER}" PARENT_SCOPE)
    endif()
endfunction()

set(SLINT_COMPILER  CACHE STRING "Path to the slint-compiler executable")
if (SLINT_COMPILER)
    if (SLINT_COMPILER STREQUAL "download")
        _slint_download_compiler_and_cache(_)
    endif()

    add_executable(Slint::slint-compiler IMPORTED GLOBAL)
    set_target_properties(Slint::slint-compiler PROPERTIES IMPORTED_LOCATION ${SLINT_COMPILER})
    include("${CMAKE_CURRENT_LIST_DIR}/SlintMacro.cmake")
elseif (ON)
    add_executable(Slint::slint-compiler IMPORTED GLOBAL)
    set_target_properties(Slint::slint-compiler PROPERTIES IMPORTED_LOCATION "${_IMPORT_PREFIX}/bin/slint-compiler")
    include("${CMAKE_CURRENT_LIST_DIR}/SlintMacro.cmake")
endif()

set(_IMPORT_PREFIX)

include("${CMAKE_CURRENT_LIST_DIR}/SlintTargets.cmake")

set(SLINT_STYLE qt CACHE STRING "The Slint widget style")
set_property(GLOBAL PROPERTY SLINT_STYLE ${SLINT_STYLE})
