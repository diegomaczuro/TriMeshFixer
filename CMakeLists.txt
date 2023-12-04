cmake_minimum_required(VERSION 3.8.0)
if(MSVC)
  add_definitions(-D_WIN32_WINNT=0x600)
endif()

project(tri_graph VERSION 0.1.0 LANGUAGES C CXX DESCRIPTION "Graph comands")

set(CMAKE_CXX_STANDARD 17)



#-----------------------------------Include Dirs-------------------------------------------------

include_directories(${CMAKE_CURRENT_LIST_DIR}/include/)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src/)



#set(SOURCES  ${CMAKE_CURRENT_LIST_DIR}/src/GraphMesh.cpp)
#set(HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/GraphMesh.h)

#add_executable(TriGraph ${SOURCES} ${HEADERS})

set(SOURCES  ${CMAKE_CURRENT_LIST_DIR}/src/linkedList.cpp)
set(HEADERS ${CMAKE_CURRENT_LIST_DIR}/include/linkedList.h)

add_executable(LinkedList ${SOURCES} ${HEADERS})