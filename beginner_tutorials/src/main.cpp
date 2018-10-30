#include <string>
#include "publisher.h"
#include "subscriber.h"
using std::string;
int main(int argc, char **argv) {
    ros::init(argc, argv, "roys_node");

    Subscriber sub_object;
    Publisher pub_object;
    string msg = " the journey of a 1000 miles begins with one step "
    pub_object.publish(msg);

    return 0;
}