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
#include "beginner_tutorials/publisher.h"

/**
 * @brief      default class constructor, advertises the chatter topic
 */
Publisher::Publisher() {
    pub_ = h_.advertise<std_msgs::String>("chatter", 1000);
}

/**
 * @brief      method to publis messages on chatter topic 
 * @param      msg string to be published on topic 
 */
void Publisher::Publish(const std::string& msg) {
    ros::Rate loop_rate(10);  // rate at which messages get published
    std_msgs::String ros_msg;  // standard ros message type string

    while (ros::ok()) {
        ros_msg.data = msg;  // pass message to be sent to ros message object
        pub_.publish(ros_msg);  // publish message to topic
        ros::spinOnce();
        loop_rate.sleep();
    }
}
