cmake_minimum_required(VERSION 3.12)
project(numeric)

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


set(SOURCE_FILES
    src/quadrature.cpp
    src/polynomials.cpp
    src/linSystems.cpp
    src/functional.cpp
    src/solveDU.cpp
    src/derivative.cpp
)

set(HEADER_FILES
    include/numeric/quadrature.hpp
    include/numeric/polynomials.hpp
    include/numeric/linSystems.hpp
    include/numeric/functional.hpp
    include/numeric/solveDU.hpp
    include/numeric/derivative.hpp
)

add_library(numeric ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(numeric PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# add_executable(example1 examples/main.cpp)
# target_link_libraries(example1 PRIVATE numeric)


# Tests
enable_testing()
add_executable(tests 
    tests/test_main.cpp
    tests/test_polynomials.cpp
    tests/test_linSystems.cpp
    tests/test_functional.cpp
    tests/test_solveDU.cpp
    tests/test_derivative.cpp
)
target_link_libraries(tests PRIVATE numeric gtest gtest_main)


include(GoogleTest)
gtest_discover_tests(tests)

