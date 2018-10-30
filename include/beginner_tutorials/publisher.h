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

/**
 * @brief      A class for publishing to a ros topic
 */
class Publisher {
    public:
        Publisher();
        void Publish(const std::string& msg);
    private:
        ros::NodeHandle h_;  // ros handle
        ros::Publisher pub_;  // ros publisher object
};
