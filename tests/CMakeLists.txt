cmake_minimum_required(VERSION 3.14)

if(POLICY CMP0135)
	cmake_policy(SET CMP0135 NEW)
endif()

project(unit_tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE headers
	${CMAKE_CURRENT_SOURCE_DIR}/unit_tests/*.hpp)

set(testcases testcases.hpp)

file(TOUCH ${testcases})
file(WRITE ${testcases} "")

foreach(file IN LISTS headers)
	file(APPEND ${testcases} "#include \"${file}\"\n")
endforeach()

add_executable(
  unit_tests
  unit_tests.cpp
)
target_link_libraries(
  unit_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)