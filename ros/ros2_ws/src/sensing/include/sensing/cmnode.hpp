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

#ifndef CMNODE_HPP
#define CMNODE_HPP

#include "cmrosutils/cmrosif.hpp"
#include "hellocm_msgs/msg/radar_data.hpp"
#include "hellocm_msgs/srv/init.hpp"

namespace cm_ros {
/**
 * @brief The CMNodeHelloCM class serves as an example for a CarMaker ROS Node
 * that communicates with an external node. It derives from the
 * CarMakerROSInterface base class, which already implements the basic CarMaker
 * ROS node functioniality.
 */
class CMNode : public CarMakerROSInterface {
 public:
	CMNode();

	/**
	 * @brief customFunction to demonstrate possibility to exchange
	 * data between interface and CarMaker executable
	 * @param input some constant integer
	 * @param output demangled/prettified function name
	 * @return ROS /clock cycle time + provided input integer
	 */
	int customFunction(const int input, char* output);

	rclcpp::Node::SharedPtr getNodeHandle() const {
		return nhp_;
	}

	CMJob::JobScheduler& getScheduler() const {
		return scheduler_;
	}

 private:
	/**
	 * @brief userInit sets up the ros publisher job and the service client
	 * @return 1
	 */
	int userInit() final;

	/**
	 * @brief userDeclQuants declares some User Accessible Quantities (UAQs) for
	 * data storage in ERG files, data access via e.g. DVA or visualization in
	 * e.g. IPGControl
	 */
	void userDeclQuants() final;

	/**
	 * @brief userTestrunStartAtBegin first calls the service of the external node
	 * to resets it. Then it sets up the ros subscriber job. In case of
	 * synchronized mode the job uses the cycle time of the external node
	 * retrieved via ros parameter server and checks whether it is compatible with
	 * the current clock cycle time.
	 * @return 1 if successful, -1 if otherwise
	 */
	int userTestrunStartAtBegin() final;

	int userTestrunStartAtEnd() final;
	
	int userTestrunRampUp() final;
	
	void userIn() final;
	
	int userDrivmanCalc(const double& dt) final;
	
	int userVehicleControlCalc(const double& dt) final;
	
	int userCalc(const double& dt) final;
	
	void userOut() final;

	/**
	 * @brief userTestrunEnd deletes the subscriber job
	 * @return 1
	 */
	int userTestrunEnd() final;

	int userEnd() final;

};
}  // namespace cm_ros

/**
 * @brief CMNodeHelloCM_customFunction C-interface wrapper for custom user
 * function to be accessed in other sources, e.g. User.c:
 * Use 'CMCppIFLoader_getSymbol("CMNodeHelloCM_customFunction")' to get the
 * symbol.
 * Use 'CMCppIFLoader_getInterfacePtr()' to get instantiated interface object
 * See "lib/cmcppifloader.h" for more information.
 * @param intf void pointer to instantiated CMNodeHelloCM object
 * @param input some constant integer
 * @param output string to be filled by CMNodeHelloCM::customFunction
 * @return value returned by CMNodeHelloCM::customFunction
 */
extern "C" int CMNode_customFunction(void* intf, const int input,
																						char* output);

#endif  // CMNODE_HPP
