cmake_minimum_required(VERSION 2.8.3)
project(rrtstar)
## Find dependencies
find_package(catkin REQUIRED COMPONENTS roscpp xtf)
find_package(OPENRAVE REQUIRED)
if(NOT OPENRAVE_FOUND)
  message(FATAL_ERROR "Could not find openrave")
else()
  message(STATUS "OPENRAVE_INCLUDE_DIRS : " ${OpenRAVE_INCLUDE_DIRS})
  message(STATUS "OPENRAVE_LIBRARIES : " ${OpenRAVE_LIBRARIES})
endif()
## Catkin setup
catkin_package(INCLUDE_DIRS include LIBRARIES ${PROJECT_NAME} CATKIN_DEPENDS roscpp xtf DEPENDS system_lib)
## Set special library output path since we're making an openrave plugin
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/plugins)
## Include both default Catkin headers and LibXML++ headers
include_directories(include ${catkin_INCLUDE_DIRS} ${OpenRAVE_INCLUDE_DIRS})
link_directories(${OpenRAVE_LIBRARY_DIRS})
## Declare a cpp library
add_library(${PROJECT_NAME} SHARED src/rrtstarmain.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${OpenRAVE_CXX_FLAGS}" LINK_FLAGS "${OpenRAVE_LINK_FLAGS}")
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${OpenRAVE_LIBRARIES})
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
## Mark library for installation
#install(TARGETS ${PROJECT_NAME}
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)
## Mark cpp header files for installation
#install(DIRECTORY include/${PROJECT_NAME}/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#  PATTERN ".svn" EXCLUDE
#)
