cmake_minimum_required(VERSION 3.10)

project(MT6MSGDB)

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

include_directories(
	${PROJECT_SOURCE_DIR}/thirdparty/rapidcsv/src/
)

if (MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /W4)
	add_definitions(-DWIN32_LEAN_AND_MEAN)
else()
	target_compile_options(${PROJECT_NAME} PRIVATE -march=native -Wall -Wextra -Wpedantic)
endif()
