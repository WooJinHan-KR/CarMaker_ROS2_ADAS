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

// CM ROS example - Topic Interface
#include "std_msgs/String.h"
//!CM ROS example - Topic Interface

#include "cmnode_hellocm.h"

using cm_ros::CMNodeHelloCM;
using CMJob::Log;

CMNodeHelloCM::CMNodeHelloCM() {}

void CMNodeHelloCM::ext2cmCallback(const hellocm_msgs::Ext2CM::ConstPtr& msg) {
  std::stringstream ss;
  ss.setf(std::ios::fixed);
  ss.precision(3);
  ss << "\t[" << ros::WallTime::now();
  if (ros::Time::isSimTime()) {
    ss << ", " << ros::Time::now();
  }
  ss << "]: " << ros::this_node::getName() << ": Sub Msg: ";
  ss << "Time " << msg->time.toSec() << "s, ";
  ss << "Cycle " << msg->cycleno;

  Log::printLog(ss.str());
}

// CM ROS example - Topic Interface
void CMNodeHelloCM::SubscribeCallback(const std_msgs::String::Ptr& msg) {
	Log("SubscribeCallback %s\n", msg->data.c_str());
	
}
//!CM ROS example - Topic Interface

void CMNodeHelloCM::cm2extFillMsg(hellocm_msgs::CM2Ext::Ptr& msg) {
  msg->cycleno = static_cast<uint32_t>(rel_cycle_num_);
  msg->time = ros::Time(SimCore.Time);
  msg->synthdelay = synth_delay_;
  msg->header.stamp = ros::Time(ros::WallTime::now().toSec());
}

// CM ROS example - Topic Interface
void CMNodeHelloCM::PublishCallback(std_msgs::String::Ptr& msg) {
  	msg->data = "CM ROS Interface - publish msg";

}
//!CM ROS example - Topic Interface

int CMNodeHelloCM::userInit() {
  synth_delay_ = 1e-6;
  {  // set up cm2ext publisher + job
    typedef CMJob::RosPublisher<hellocm_msgs::CM2Ext::Ptr> cm2ext_t;
    auto job = std::make_shared<cm2ext_t>(nhp_, "cm2ext");
    job->setCycleTime(15000);
    job->registerCallback(&CMNodeHelloCM::cm2extFillMsg, this);
    scheduler_.addJob(job);
  }

  Log::printLog("  -> Initializing service client /hellocm/init");
  srv_init_ = nhp_->serviceClient<hellocm_msgs::Init>("/hellocm/init");

  return 1;
}

void CMNodeHelloCM::userDeclQuants() {
  tDDefault* df = DDefaultCreate("CMRosIF.HelloCM.");
  DDefULong(df, "CycleNoRel", "ms", &rel_cycle_num_, DVA_None);
  DDefDouble4(df, "SynthDelay", "s", &synth_delay_, DVA_IO_In);
  DDefaultDelete(df);
}

int CMNodeHelloCM::userTestrunStartAtBegin() {
  // Prepare external node for next simulation
  if (!srv_init_.exists()) {
    Log::printError(EC_Sim,
                    "ROS service is not ready! Please start external ROS node "
                    "providing service '" +
                        srv_init_.getService() + "'!");
    node_mode_ = NodeMode::kDisabled;
    return -1;
  }

  Log::printLog("  -> Sending service request");

  hellocm_msgs::Init srv_init;
  if (!srv_init_.call(srv_init)) {
    Log::printError(
        EC_Sim, "Failed to call ROS service '" + srv_init_.getService() + "'!");
    node_mode_ = NodeMode::kDisabled;
    return -1;
  }

  {  // set up ext2cm subscriber + job
    std::string topic = "ext2cm";
    bool synchronize = (sync_mode_ == SyncMode::kTopic);
    CMJob::JobType job_type =
        synchronize ? CMJob::JobType::Cyclic : CMJob::JobType::Trigger;

    int cycle_time;
    nhp_->param("/hellocm/cycletime", cycle_time, 15000);

    typedef CMJob::RosSubscriber<hellocm_msgs::Ext2CM::ConstPtr> ext2cm_t;
    auto job = std::make_shared<ext2cm_t>(job_type, synchronize, nhp_, topic);
    job->setCycleTime(static_cast<unsigned long>(cycle_time));
    job->skipFirstCycles(1);
    job->setTimeoutTime(max_sync_time_);
    job->registerCallback(&CMNodeHelloCM::ext2cmCallback, this);
    scheduler_.addJob(job);

    if (cycle_time % clock_cycle_time_ != 0 ||
        (cycle_time < clock_cycle_time_ && clock_cycle_time_ > 0)) {
      node_mode_ = NodeMode::kDisabled;
      LogErrF(EC_Sim,
              "Ext. ROS node has an invalid cycle time! Expected multiple of "
              "%iums but got %ims",
              clock_cycle_time_, cycle_time);

      return -1;
    }
  }

// CM ROS example - Topic Interface
	typedef CMJob::RosSubscriber<std_msgs::String::Ptr> User_Sub;
	auto job_sub = std::make_shared<User_Sub>(CMJob::JobType::Trigger, 0, nhp_, "User_Sub");
	job_sub->setCallbackHook(CMJob::CallbackHook::In); // Callback Hook - In, DrivMan, Traffic, VehicleControl, Calc, Out
	job_sub->registerCallback(&CMNodeHelloCM::SubscribeCallback, this);
	scheduler_.addJob(job_sub);

	typedef CMJob::RosPublisher<std_msgs::String::Ptr> User_Pub;
	auto job_pub = std::make_shared<User_Pub>(nhp_, "User_Pub");
	job_pub->setCycleTime(100);		// publish per 100 ms
	job_pub->setCycleOffset(0);		// publish at 5ms, 105ms, ...
	job_pub->setCallbackHook(CMJob::CallbackHook::Calc); // Callback Hook - In, DrivMan, Traffic, VehicleControl, Calc, Out
	job_pub->registerCallback(&CMNodeHelloCM::PublishCallback, this);
	scheduler_.addJob(job_pub);
//!CM ROS example - Topic Interface

  return 1;
}

int CMNodeHelloCM::userTestrunEnd() {
  scheduler_.deleteJob("ext2cm");

// CM ROS example - Topic Interface
	scheduler_.deleteJob("User_Sub");
	scheduler_.deleteJob("User_Pub");
//!CM ROS example - Topic Interface

  return 1;
}

int CMNodeHelloCM::customFunction(const int input, char* output) {
  strcpy(output, __PRETTY_FUNCTION__);
  return clock_cycle_time_ + input;
}

int CMNodeHelloCM_customFunction(void* intf, const int input, char* output) {
  return reinterpret_cast<CMNodeHelloCM*>(intf)->customFunction(input, output);
}

// Important: Use this macro to register the derived class as an interface with
// the CarMaker C++ Interface Loader module
REGISTER_CARMAKER_CPP_IF(CMNodeHelloCM)
