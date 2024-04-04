#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cmrosutils::cmrosif" for configuration ""
set_property(TARGET cmrosutils::cmrosif APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(cmrosutils::cmrosif PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcmrosif.so"
  IMPORTED_SONAME_NOCONFIG "libcmrosif.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS cmrosutils::cmrosif )
list(APPEND _IMPORT_CHECK_FILES_FOR_cmrosutils::cmrosif "${_IMPORT_PREFIX}/lib/libcmrosif.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
