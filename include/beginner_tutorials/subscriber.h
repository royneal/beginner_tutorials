/**
 * @file    subscriber.h
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
 * Class for demonstrating subscribing to a topic in ROS.
 *
 */

#pragma once

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/message_rate.h"
/**
 * @brief      A class for subscribing to a ros topic
 */

class Subscriber {
    public:
        Subscriber();
        void Chattercallback(const std_msgs::String::ConstPtr& msg);
        void ServiceRequest(beginner_tutorials::message_rate::Request & req,
                    beginner_tutorials::message_rate::Response &res);
    private:
        ros::NodeHandle h_;  // ros handle
        ros::Subscriber sub_;  // ros subscriber object
        ros::ServiceClient client_;
};
