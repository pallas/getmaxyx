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

add_executable(getmaxx getmaxyx.cc)
set_target_properties(getmaxx PROPERTIES COMPILE_FLAGS -DMAX_X)
target_link_libraries(getmaxx ${CURSES_LIBRARIES})

add_executable(getmaxy getmaxyx.cc)
set_target_properties(getmaxy PROPERTIES COMPILE_FLAGS -DMAX_Y)
target_link_libraries(getmaxy ${CURSES_LIBRARIES})

install(TARGETS getmaxx getmaxy
	RUNTIME DESTINATION bin
	)
