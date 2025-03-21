cmake_minimum_required(VERSION 3.14)
project(FooBar1) # Replace “MyCalc” with your repo name
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL
        https://github.com/google/googletest/archive/03597a01ee50ed
        33e9dfd640b249b4be3799d395.zip
)
#FetchContent_MakeAvailable(googletest)
enable_testing()


set(SOURCE_FILES
        src/calc.cpp # this is where the code we want to test
        src/main.cpp
        src/BloomFilter.cpp
        src/BloomFilter.h
        src/URLArray.h
        src/Hash1.cpp
        src/Hash1.h
        src/Hash2.cpp
        src/Hash2.h
        src/URLVector.cpp
        src/URLVector.h
        src/HashFunctions.cpp
        src/HashFunctions.h
        src/AddUrl.h
        src/AddUrl.cpp
        src/SearchUrl.h
        src/SearchUrl.cpp
        src/Menu.cpp
        src/Menu.h
        src/ServerBloom.h
        src/ServerBloom.cpp
        src/ServerBloom.h
        src/Menus.h
        src/ServerMenu.cpp
        src/ServerMenu.h
)

set(TEST_FILES
        tests/test_main.cpp # this is the main for tests
        tests/calc_test.cpp # this file contain the tests
)

set (SOURCE_FILES_TEST
        src/calc.cpp # this is where the code we want to test
        src/URLArray.h
        src/Hash1.cpp
        src/Hash1.h
        src/Hash2.cpp
        src/Hash2.h
        src/URLVector.cpp
        src/URLVector.h
        src/calc.h
        src/HashFunctions.cpp
        src/HashFunctions.h
        src/AddUrl.h
        src/AddUrl.cpp
        src/SearchUrl.h
        src/SearchUrl.cpp
        src/BloomFilter.cpp
        src/BloomFilter.h
        tests/BloomFilter_test.cpp
)


add_executable(main ${SOURCE_FILES})
add_executable(CalcTests ${TEST_FILES} ${SOURCE_FILES_TEST})

# Link Google Test to the test executable
target_link_libraries(CalcTests PRIVATE gtest gtest_main)
# Include the source directory for tests
target_include_directories(CalcTests PRIVATE src)
include(GoogleTest)
gtest_discover_tests(CalcTests)
#add_test(NAME CalcTests COMMAND CalcTests)

