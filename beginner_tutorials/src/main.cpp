/**
 * @file    main.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * main node program  that calls a publisher and subscirber objects.
 *
 */
#include <string>
#include "publisher.h"
#include "subscriber.h"
using std::string;
int main(int argc, char **argv) {
    ros::init(argc, argv, "roys_node");

    Subscriber sub_object;
    Publisher pub_object;
    const string msg = " be happy ";
    pub_object.Publish(msg);

    return 0;
}