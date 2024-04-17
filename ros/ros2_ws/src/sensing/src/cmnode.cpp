/*!
 ******************************************************************************
 **  Example for a CarMaker ROS Node that communicates with an external node
 **
 **  Copyright (C)   IPG Automotive GmbH
 **                  Bannwaldallee 60             Phone  +49.721.98520.0
 **                  76185 Karlsruhe              Fax    +49.721.98520.99
 **                  Germany                      WWW    www.ipg-automotive.com
 ******************************************************************************
 */

#include "sensing/cmnode.hpp"
#include "sensing/LidarRSI_IF.hpp"
#include "sensing/RadarRSI_IF.hpp"
#include "sensing/Odom_IF.hpp"


using cm_ros::CMNode;
using CMJob::Log;

CMNode::CMNode() {}

int CMNode::userInit() {

	return 1;
}

void CMNode::userDeclQuants() {

}

int CMNode::userTestrunStartAtBegin() {
	return 1;
}

int CMNode::userTestrunStartAtEnd() {
	CMNode_LidarRSI_IF_TestrunStartAtEnd(this);
	CMNode_RadarRSI_IF_TestrunStartAtEnd(this);
	CMNode_Odom_IF_TestrunStartAtEnd(this);
	return 1;
}

int CMNode::userTestrunRampUp() {
	return 1;
}

void CMNode::userIn() {

}

int CMNode::userDrivmanCalc(const double& dt) {
	//printf("\nhihihihihi\n");
	return 1;
}

int CMNode::userVehicleControlCalc(const double& dt) {
	return 1;
}

int CMNode::userCalc(const double& dt) {
	return 1;
}

void CMNode::userOut() {

}

int CMNode::userTestrunEnd() {

	CMNode_LidarRSI_IF_TestrunEnd(this);
	CMNode_RadarRSI_IF_TestrunEnd(this);
	CMNode_Odom_IF_TestrunEnd(this);

	return 1;
}

int CMNode::userEnd() {
	return 1;
}

int CMNode::customFunction(const int input, char* output) {
	strcpy(output, __PRETTY_FUNCTION__);
	return clock_cycle_time_ + input;
}

int CMNode_customFunction(void* intf, const int input, char* output) {
	return reinterpret_cast<CMNode*>(intf)->customFunction(input, output);
}

// Important: Use this macro to register the derived class as an interface with
// the CarMaker C++ Interface Loader module
REGISTER_CARMAKER_CPP_IF(CMNode)
