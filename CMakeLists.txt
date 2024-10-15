cmake_minimum_required(VERSION 3.14)
project(bms-monitor)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP true
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB SENDER_SOURCES "sender.cpp")
add_executable(
    sender
  ${SENDER_SOURCES}
)

file(GLOB PROCESSOR_SOURCES "processor.cpp")
add_executable(
    processor
  ${PROCESSOR_SOURCES}
)

file(GLOB TEST "test_SensorStub.cpp")
add_executable(
    test-sender
  ${TEST}
)

target_link_libraries(
    test-sender
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test-sender)
