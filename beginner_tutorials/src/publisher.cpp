/**
 * @file    publisher.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * Class implementation for demonstrating publishing a topic in ROS.
 *
 */
#include <string>
#include "publisher.h"


Publisher::Publisher() {
    pub_=h_.advertise<std_msgs::string>("chatter", 1000);
}

Publisher::Publish(const std::string& msg) {
    ros::Rate loop_rate(10);
    std_msgs::string ros_msg;

    while (ros::ok()) {
        ros_msg.data = msg;
        pub_.publish(msg);
        ros::spinonce();
        loop_rate.sleep();
    }
}