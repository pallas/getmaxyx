cmake_minimum_required(VERSION 3.1)

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
		STRING "Choose the type of build." FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
		"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

project(GetMax)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
find_library(TINFO tinfo)

add_executable(getmaxx getmaxyx.cc)
target_compile_definitions(getmaxx PRIVATE MAX_X)
target_link_libraries(getmaxx ${CURSES_LIBRARIES} ${TINFO})

add_executable(getmaxy getmaxyx.cc)
target_compile_definitions(getmaxy PRIVATE MAX_Y)
target_link_libraries(getmaxy ${CURSES_LIBRARIES} ${TINFO})

install(TARGETS getmaxx getmaxy
	RUNTIME DESTINATION bin
	)
