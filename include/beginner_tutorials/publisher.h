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
#include "beginner_tutorials/message_rate.h"


/**
 * @brief      A class for publishing to a ros topic
 */
class Publisher {
    public:
        Publisher();
       static bool SetRate(beginner_tutorials::message_rate::Request & req, 
                    beginner_tutorials::message_rate::Response &resp);
       void SettxRate(int& rate);
        void Publish(const std::string& msg);
    private:
        ros::NodeHandle h_;  // ros handle
        ros::Publisher pub_;  // ros publisher object
        ros::ServiceServer service_; // ros service object 
        static int msg_rate_;
};
