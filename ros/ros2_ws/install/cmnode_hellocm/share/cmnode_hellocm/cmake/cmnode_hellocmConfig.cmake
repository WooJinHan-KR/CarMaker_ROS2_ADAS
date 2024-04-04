# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_cmnode_hellocm_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED cmnode_hellocm_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(cmnode_hellocm_FOUND FALSE)
  elseif(NOT cmnode_hellocm_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(cmnode_hellocm_FOUND FALSE)
  endif()
  return()
endif()
set(_cmnode_hellocm_CONFIG_INCLUDED TRUE)

# output package information
if(NOT cmnode_hellocm_FIND_QUIETLY)
  message(STATUS "Found cmnode_hellocm: 1.0.0 (${cmnode_hellocm_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'cmnode_hellocm' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${cmnode_hellocm_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(cmnode_hellocm_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_libraries-extras.cmake;ament_cmake_export_dependencies-extras.cmake")
foreach(_extra ${_extras})
  include("${cmnode_hellocm_DIR}/${_extra}")
endforeach()
