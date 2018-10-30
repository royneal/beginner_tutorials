/**
 * @file    subscriber.h
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * Class for demonstrating subscribing to a topic in ROS.
 *
 */

#pragma once

#include "ros/ros.h"
#include "std_msgs/String.h"

class Subscriber {
    
public:
    Subscriber();
    void Chattercallback(const std_msgs::String::ConstPtr& msg);
private: 
    ros::NodeHandle h_; 
    ros::Subscriber sub_;

};