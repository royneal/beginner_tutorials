/**
 * @file    publisher.h
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
#include "tf/transform_broadcaster.h"

/**
 * @brief      A class for publishing to a ros topic
 */
class Publisher {
    public:
        Publisher();
       static bool SetRate(beginner_tutorials::message_rate::Request & req,
                    beginner_tutorials::message_rate::Response &resp);
        void SettxRate(const int& rate);
        void Publish(const std::string& msg);
    private:
        ros::NodeHandle h_;  // ros handle
        ros::Publisher pub_;  // ros publisher object
        ros::ServiceServer service_;  // ros service object
        static int msg_rate_;
        tf::TransformBroadcaster br_;
        tf::Transform transform_;
};
