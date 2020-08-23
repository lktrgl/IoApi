cmake_minimum_required(VERSION 3.5)

project ( IoApi )

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

if(NOT IS_SUBPROJECT)
	set ( CMAKE_C_STANDARD 99 )
	set ( CMAKE_CXX_STANDARD 17 )
	set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
	set ( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
else()
	set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNDEBUG" )
	set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG" )
endif()

include_directories (
     include
     )

set (ioapi_libsources
     src/ioapi/io.c
     include/ioapi/io.h
     src/ioapi/device.c
     include/ioapi/device.h
     include/ioapi/impl/io_cfg.h
     )

add_library ( ioapi
    ${ioapi_libsources}
     )

