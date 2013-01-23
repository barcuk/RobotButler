#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sensor_msgs/Joy.h>

ros::Publisher cmd_pub;

void joyCallback(const sensor_msgs::Joy::ConstPtr& msg)
{
std::stringstream s;
s << msg->axes[4];

geometry_msgs::Twist cmd;
cmd.linear.x = msg->axes[5];
cmd.angular.z = msg->axes[4];
cmd_pub.publish(cmd);

ROS_INFO(s.str().c_str());
}

int main(int argc, char **argv)
{

ros::init(argc, argv, "teleop");

ros::NodeHandle n;

cmd_pub =  n.advertise<geometry_msgs::Twist>("/PioneerBase/cmd_vel", 1);
ros::Subscriber sub = n.subscribe("joy", 1000, joyCallback);

ros::Rate loop_rate(10);

int count = 0;

bool called = false;

while (ros::ok())
{

ros::spinOnce();
}

 return 0;
}

