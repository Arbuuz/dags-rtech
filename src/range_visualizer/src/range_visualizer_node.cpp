#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Range.h"

#include <sstream>
sensor_msgs::Range msg;

int main(int argc, char **argv)
{

    msg.header.frame_id = "sensor_range_topic";
    msg.range =0;
    msg.min_range = 0.02;
    msg.max_range = 4;
    msg.field_of_view = 0.785;
  
  ros::init(argc, argv, "range_visualizer_node");

  ros::NodeHandle n;

  
  ros::Publisher range_publisher = n.advertise<sensor_msgs::Range>("sensor_range_topic", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {

    range_publisher.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

