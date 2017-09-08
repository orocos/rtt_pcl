cmake_minimum_required(VERSION 2.8.3)
project(rtt_pcl)

## Find PCL
find_package(PCL REQUIRED)

## Find Orocos RTT
find_package(OROCOS-RTT REQUIRED)
include(${OROCOS-RTT_USE_FILE_PATH}/UseOROCOS-RTT.cmake)

## Set default build type to MinSizeRel
if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CMAKE_BUILD_TYPE MinSizeRel)
endif()

###################################
## catkin specific configuration ##
###################################
if(catkin_FOUND)
  catkin_package(
    DEPENDS PCL
  )
endif()

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
  include/orocos
  ${PCL_INCLUDE_DIRS}
)

## Orocos typekit plugin
orocos_typekit(rtt_pcl-typekit
  src/typekit.cpp
  src/point_xyz.cpp
  src/point_xyzrgb.cpp
  src/point_xyzrgbnormal.cpp
)
target_link_libraries(rtt_pcl-typekit ${PCL_LIBRARIES})

#############
## Install ##
#############

# Note: The typekit library is already installed by the orocos_typekit() macro.

## Install headers
orocos_install_headers(
  DIRECTORY include/orocos/${PROJECT_NAME}/
)

## Generate Orocos package
orocos_generate_package(
  DEPENDS pcl_common-${PCL_VERSION_MAJOR}.${PCL_VERSION_MINOR}
)
