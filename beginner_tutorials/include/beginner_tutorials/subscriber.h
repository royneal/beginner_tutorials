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

class subscriber {
    subscriber();
public:
void subscribe();
private: 
ros::NodeHandle h_; 
ros::subscriber sub_;

}