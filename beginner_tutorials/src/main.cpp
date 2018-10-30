/**
 * @file    main.cpp
 * @author  Royneal Rayess
 * @copyright MIT License (c) 2018 Royneal Rayess
 *
 * @brief DESCRIPTION
 * main node program  that instantiates a publisher and subscirber objects.
 *
 */
#include <string>
#include "publisher.h"
#include "subscriber.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "roys_node");

    Publisher pub_object;// create a publisher object
    Subscriber sub_object;// create a subscriber object 

    std::string msg = " be happy "; //message to publish
    pub_object.Publish(msg);// publish message 

    return 0;
}