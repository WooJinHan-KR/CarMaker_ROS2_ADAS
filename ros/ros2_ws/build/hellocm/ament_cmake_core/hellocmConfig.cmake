# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_hellocm_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED hellocm_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(hellocm_FOUND FALSE)
  elseif(NOT hellocm_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(hellocm_FOUND FALSE)
  endif()
  return()
endif()
set(_hellocm_CONFIG_INCLUDED TRUE)

# output package information
if(NOT hellocm_FIND_QUIETLY)
  message(STATUS "Found hellocm: 0.1.0 (${hellocm_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'hellocm' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${hellocm_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(hellocm_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${hellocm_DIR}/${_extra}")
endforeach()
