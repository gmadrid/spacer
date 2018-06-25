project(spacer)
cmake_minimum_required(VERSION 3.11)

include(cmake/DownloadProject.cmake)

###
### gtest
###
download_project(PROJ                googletest
		 GIT_REPOSITORY      https://github.com/google/googletest.git
		 GIT_TAG             master
		 UPDATE_DISCONNECTED 1)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})		

###
### Library
###
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

###
### Executable
###
add_executable(spacer src/main/main.cc)
target_link_libraries(spacer
  PRIVATE
    spacer_lib)

###
### unittests
###
enable_testing()
add_executable(unit_tests
  src/test/mnemonica_test.cc)

target_link_libraries(unit_tests
  PRIVATE
    spacer_lib
    gtest
    gtest_main)
add_test(NAME    spacer_test
	 COMMAND unit_tests)
