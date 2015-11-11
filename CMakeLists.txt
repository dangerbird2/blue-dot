cmake_minimum_required(VERSION 2.8)
PROJECT(EARTH)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1y -Wno-deprecated")

SET(MY_SOURCE_PATH ${CMAKE_SOURCE_DIR})
CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/source/common/SourcePath.cpp.in ${CMAKE_SOURCE_DIR}/source/common/SourcePath.cpp)

find_package(OpenGL)
find_package(GLUT)
find_package(PNG)
find_package(JPEG)

find_library(ASSIMP_LIBRARY assimp)
set(ASSIMP_INCLUDE_DIR CACHE PATH "path containing assimp include folder")

find_library(SOIL_LIBRARY soil)
set(SOIL_INCLUDE_DIR CACHE PATH "path containing soil include folder")


INCLUDE_DIRECTORIES(./source
  ./source/common
  ./shaders
  ${OPENGL_INCLUDE_DIR}
  ${GLUT_INCLUDE_DIR}
  ${PNG_INCLUDE_DIR}
  ${JPEG_INCLUDE_DIR}
  ${ASSIMP_INCLUDE_DIR}
  ${SOIL_INCLUDE_DIR}
  ./extern/glm)


INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/FreeImage3151/Source/LibTIFF")


set(EARTH_SOURCES
  source/common/Angel.h
  source/common/CheckError.h
  source/common/mat.h
  source/common/vec.h
  source/common/ObjMesh.cpp
  source/common/ObjMesh.h

  source/common/InitShader.cpp
  source/common/SourcePath.cpp
  source/common/SourcePath.h
  source/common/Trackball.cpp
  source/common/Trackball.h
  shaders/vshading_example.glsl
  shaders/fshading_example.glsl
  source/Earth.cpp

  source/common/Material.cc
  source/common/Material.h source/EarthSystem.cc source/EarthSystem.h source/sMesh.cc source/sMesh.h)


ADD_EXECUTABLE(earth
  ${EARTH_SOURCES})

TARGET_LINK_LIBRARIES(earth
  ${OPENGL_LIBRARY} ${GLUT_LIBRARY}
  ${JPEG_LIBRARY}
  ${PNG_LIBRARY}
  ${ASSIMP_LIBRARY}
  ${SOIL_LIBRARY})

