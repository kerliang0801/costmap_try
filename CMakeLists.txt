cmake_minimum_required(VERSION 3.5)
project(costmap_try)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()


find_package(catkin REQUIRED
    COMPONENTS
        actionlib
        base_local_planner
        clear_costmap_recovery
        cmake_modules
        costmap_2d
        dynamic_reconfigure
        geometry_msgs
        message_generation
        move_base_msgs
        nav_core
        nav_msgs
        navfn
        pluginlib
        roscpp
        rospy
        rotate_recovery
        std_srvs
        tf2_geometry_msgs
        tf2_ros
)
find_package(Eigen3 REQUIRED)
add_definitions(${EIGEN3_DEFINITIONS})

catkin_package(
    CATKIN_DEPENDS
        dynamic_reconfigure
        geometry_msgs
        move_base_msgs
        nav_msgs
        roscpp
)

###########
## Build ##
###########

include_directories(
	include
  ${catkin_INCLUDE_DIRS}
)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(costmap_try ${SRC_FILES})
target_link_libraries(costmap_try  ${catkin_LIBRARIES})

install(TARGETS
	costmap_try
	DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)