#include <DialogKeyboard.h>
#include <QtWidgets>
#include <drone_object_ros.h>
#include <iostream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "drone_keyboard");

  ros::V_string output;

  ros::removeROSArgs(argc, argv, output);

  QApplication app(argc, argv);

  std::string ns;

  if(output.size() >= 2){
    ns = "/" + output[1];
  }else{
    ns = "";
  }

  ns += "/";
  
  ros::NodeHandle node(ns);

  for(auto i: output){
    ROS_INFO(i.c_str());
  }

  ROS_INFO("The Keyboard namespace:");
  ROS_INFO(ns.c_str());

  DroneObjectROS drone(node, ns);
  drone.velMode(true);
  DialogKeyboard dlg_keyboard;
  dlg_keyboard.setDrone(drone);
  dlg_keyboard.show();

  return app.exec();
}
