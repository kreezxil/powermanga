####################################################################
#
# PowerManga
#
####################################################################

cmake_minimum_required(VERSION 3.21)

project(PowerManga C)

set(CMAKE_C_STANDARD	17)
SET(CMAKE_BUILD_TYPE Release)

option(UNDER_DEVELOPMENT "Build development version" 	off)

if(NOT EMSCRIPTEN)
	find_package(SDL2 REQUIRED)
	find_package(SDL2_mixer REQUIRED)
endif()

# assets path
if(EMSCRIPTEN)
SET(PATH_FILE_ASSETS "assets")
endif()

# ---------------------------------------------------------------------------------------
# emscripten
if(EMSCRIPTEN)

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
#SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --preload-file ${PATH_FILE_ASSETS} -s ALLOW_MEMORY_GROWTH=1")
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --preload-file ${PATH_FILE_ASSETS} -s TOTAL_MEMORY=40000000")
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --closure 0")
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --memory-init-file 1")

else()

# ---------------------------------------------------------------------------------------
# windows mingw gcc options
if(WIN32 AND MINGW)

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=gnu99")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pipe -Wall -Wextra")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Ofast -ffast-math")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DNDEBUG -D_WIN32")
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -pipe -g -DDEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

endif()

# ---------------------------------------------------------------------------------------
# windows visual studio options
if(WIN32 AND MSVC)

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /W3 /WX-")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /D \"_CRT_SECURE_NO_WARNINGS\" /D \"WIN32\" /D \"NDEBUG\" /D \"_WIN32\"")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2 /Ob1 /Oi /Ot /Oy /MT /GS- /EHsc /fp:fast /GL")
SET(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /OPT:REF /LTCG")

endif()

# ---------------------------------------------------------------------------------------
# unix gcc options
if(UNIX AND NOT APPLE)

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -pipe -Wall -Wextra -Wpedantic -Wshadow -Werror=return-type -Wstrict-aliasing=2")
SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s -g0 -Ofast -ffast-math")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -pipe O0 -ggdb3 -DDEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

endif()

# end EMSCRIPTEN
endif()

if(NOT EMSCRIPTEN)
	include_directories(${INCLUDE_DIRECTORIES})
	include_directories(${SDL2_INCLUDE_DIRS})
	include_directories(${SDL2_MIXER_INCLUDE_DIRS})
endif()

# files
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS src/*.c src/*.h)
add_executable(powermanga ${GAME_SOURCES})

if(NOT EMSCRIPTEN)
	target_link_libraries(powermanga SDL2::SDL2)
	target_link_libraries(powermanga SDL2_mixer::SDL2_mixer)
	if(UNIX)
		target_link_libraries(powermanga -lm)
	endif()
endif()

if(EMSCRIPTEN)
	SET(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

SET(RELEASE_NAME "powermanga")
set_target_properties(powermanga PROPERTIES
	OUTPUT_NAME "${RELEASE_NAME}"
	XCODE_GENERATE_SCHEME TRUE
	XCODE_SCHEME_WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
