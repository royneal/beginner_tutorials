/**
 * @file    publisher.h
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * Class for demonstrating publishing a topic in ROS.
 *
 */

#pragma once

#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"

class Publiser {
    Publisher();
public:
void Publish();
private: 
ros::NodeHandle h_; 
ros::publisher pub_;

}