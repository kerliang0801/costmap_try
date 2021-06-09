#include <vector>
#include <string>

#include <ros/ros.h>

#include <costmap_2d/costmap_2d_ros.h>
#include <costmap_2d/costmap_2d.h>

#include <tf2_ros/transform_listener.h>


int main(int argc, char** argv){
    ros::init(argc, argv, "costmap_node");
    tf2_ros::Buffer buffer(ros::Duration(10));
    tf2_ros::TransformListener tf(buffer);
    costmap_2d::Costmap2DROS controller_costmap_ros_("local_costmap", buffer);
    std::cout<<controller_costmap_ros_.getGlobalFrameID()<<std::endl;
    controller_costmap_ros_.start();
    ros::spin();
    return(0);
}