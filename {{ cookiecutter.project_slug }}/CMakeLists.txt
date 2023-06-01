cmake_minimum_required(VERSION 3.6)
project({{cookiecutter.project_slug}} VERSION {{cookiecutter.version}} LANGUAGES CXX)

# Set CMake policies for this project

# We allow <Package>_ROOT (env) variables for locating dependencies
cmake_policy(SET CMP0074 NEW)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    )


catkin_package(CATKIN_DEPENDS
    std_msgs
    roscpp
    )

add_library(${PROJECT_NAME} STATIC
    src/{{cookiecutter.project_slug}}.cpp
    )

target_include_directories(${PROJECT_NAME}
  PRIVATE
    src
    ${catkin_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    include
    ${catkin_INCLUDE_DIRS}
)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
    PUBLIC_HEADER DESTINATION include
    )


add_executable(${PROJECT_NAME}_node
    src/{{cookiecutter.project_slug}}_node.cpp
    )

target_link_libraries(${PROJECT_NAME}_node
    ${PROJECT_NAME}
    ${catkin_LIBRARIES}
    )

install(TARGETS ${PROJECT_NAME}_node
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
    PUBLIC_HEADER DESTINATION include
    )

if(CATKIN_ENABLE_TESTING)
  add_subdirectory(test)
endif()
