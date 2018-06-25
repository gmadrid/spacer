project(spacer)
cmake_minimum_required(VERSION 3.11)

include(cmake/DownloadProject.cmake)

#
# Library
#
add_library(spacer_lib
  src/lib/mnemonica.cc
  src/lib/spacer.cc
)
target_compile_features(spacer_lib
  PUBLIC
    cxx_auto_type
    cxx_constexpr
    cxx_defaulted_functions
    cxx_deleted_functions
    cxx_nullptr
    cxx_override
    cxx_range_for
    cxx_rvalue_references
)

#
# Executable
#
add_executable(spacer src/main/main.cc)
target_link_libraries(spacer
  PRIVATE
    spacer_lib)
