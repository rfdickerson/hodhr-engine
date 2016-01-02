cmake_minimum_required (VERSION 2.8 FATAL_ERROR)
project (HodhrGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${HodhrGame_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")

find_package(SDL2 REQUIRED)

find_package(OpenGL)
find_package(GLEW REQUIRED)
find_package(Assimp REQUIRED)
if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
endif()



include_directories(hodhrengine)

set(LIBS ${LIBS} ${OPENGL_LIBRARY} ${SDL2_LIBRARY} 
	${GLEW_LIBRARIES} ${assimp_LIBRARIES}) 

set(INCLUDE_DIRS ${OpenGL_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} 
	${Assimp_INCLUDE_DIRS})

include_directories(${INCLUDE_DIRS})

add_subdirectory(hodhrengine)
add_subdirectory(game)




