cmake_minimum_required(VERSION 3.0)

project("json_conversion" CXX)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

################################################################################

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE src)

################################################################################

add_executable(test-${PROJECT_NAME} EXCLUDE_FROM_ALL
	test/stream.cc
	test/visitor.cc
	test/input.cc
)

target_link_libraries(test-${PROJECT_NAME}
	PRIVATE Catch2::Catch2WithMain
	PRIVATE ${PROJECT_NAME}
)

target_compile_options(test-${PROJECT_NAME}
	PRIVATE -Wall
	PRIVATE -Wextra
	PRIVATE -Wpedantic
	PRIVATE -std=c++17
)
