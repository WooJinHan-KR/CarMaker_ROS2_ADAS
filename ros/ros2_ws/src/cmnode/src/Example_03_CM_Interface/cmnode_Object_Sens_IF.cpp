#include "cmnode_Object_Sens_IF.hpp"

using CMJob::Log;

void Object_Sens_IF_Data_Fill(visualization_msgs::msg::MarkerArray& msg)
{
    msg.markers.clear();  // Clear existing markers in the array

    // Add a marker with DELETEALL action to clear all previous markers
    visualization_msgs::msg::Marker delete_all_marker;
    delete_all_marker.header.frame_id = "Object_example";
    delete_all_marker.header.stamp = rclcpp::Clock().now();
    delete_all_marker.ns = "detected_objects";
    delete_all_marker.action = visualization_msgs::msg::Marker::DELETEALL;
    delete_all_marker.id = -1;
    msg.markers.push_back(delete_all_marker);

    // Assuming you have a loop or some logic to iterate over detected objects
    for (int i = 0; i < ObjectSensor[0].nObsvObjects; i++)
    {
        visualization_msgs::msg::Marker object_marker;
        object_marker.header.frame_id = "Object_example";  // Change the frame_id as per your needs
        object_marker.header.stamp = rclcpp::Clock().now();
        object_marker.ns = "detected_objects";
        object_marker.action = visualization_msgs::msg::Marker::ADD;
        object_marker.pose.orientation.w = 1.0;
        object_marker.id = i;
        object_marker.type = visualization_msgs::msg::Marker::CUBE;
        
        tObjectSensorObj *pOSO = ObjectSensor_GetObjectByObjId(0, ObjectSensor[0].ObsvObjects[i]);

        object_marker.scale.x = pOSO->l;
        object_marker.scale.y = pOSO->w;
        object_marker.scale.z = pOSO->h;

        // Set color (RGBA)
        if (ObjectSensor[0].ObsvObjects[i] == ObjectSensor[0].relvTargetObjId)
        {
            // relevant target object
            object_marker.color.r = 0.0;
            object_marker.color.g = 1.0;
            object_marker.color.b = 0.0;
            object_marker.color.a = 1.0;
        } 
        else if (pOSO->dtct)
        {
            // target inside object sensor
            object_marker.color.r = 1.0;
            object_marker.color.g = 1.0;
            object_marker.color.b = 1.0;
            object_marker.color.a = 0.5;
        }
        else 
        {
            // all other traffic object
            object_marker.color.r = 1.0;
            object_marker.color.g = 1.0;
            object_marker.color.b = 1.0;
            object_marker.color.a = 0.1;
        }
        
        // Calculate the quaternion for the desired rotation
        tf2::Quaternion rotation;
        rotation.setRPY(pOSO->RefPnt.r_zyx[0], pOSO->RefPnt.r_zyx[1], pOSO->RefPnt.r_zyx[2]);

        // Apply rotation to vector pointing to the object's center
        tf2::Vector3 obj_center = tf2::quatRotate(rotation, tf2::Vector3(0.5 * pOSO->l, 0, 0));

        object_marker.pose.position.x = pOSO->RefPnt.ds[0] + obj_center.getX();
        object_marker.pose.position.y = pOSO->RefPnt.ds[1] + obj_center.getY();
        object_marker.pose.position.z = pOSO->RefPnt.ds[2] + obj_center.getZ();
        object_marker.pose.orientation.x = rotation.x();
        object_marker.pose.orientation.y = rotation.y();
        object_marker.pose.orientation.z = rotation.z();
        object_marker.pose.orientation.w = rotation.w();

        msg.markers.push_back(object_marker);

    }

}

int
CMNode_Object_Sens_IF_TestrunStartAtEnd (cm_ros::CMNode *CMNode)
{
    Log("\n");
    Log("Object_Sensor_Count: %d\n", ObjectSensorCount);
    Log("\n");
    
    if(ObjectSensorCount < 1) return 0;

    typedef CMJob::RosPublisher<visualization_msgs::msg::MarkerArray> Object_example;
	rclcpp::Node::SharedPtr nhp = CMNode->getNodeHandle();
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();

    auto job = std::make_shared<Object_example>(nhp, "Object_example");
	job->setCycleTime(16);
    job->setCycleOffset(0);
	job->setCallbackHook(CMJob::CallbackHook::Calc);
	job->registerCallback(&Object_Sens_IF_Data_Fill);
    scheduler.addJob(job);
    
    tf2::Quaternion q;
    double position[3];
    double rotation[3];
    
    position[0] = 4.5;  //x
    position[1] = 0;    //y
    position[2] = 0.4;  //z
    rotation[0] = 0;    //x
    rotation[1] = 0;    //y
    rotation[2] = 0;    //z

    q.setRPY(rotation[0] * (M_PI / 180.0), rotation[1] * (M_PI / 180.0), rotation[2] * (M_PI / 180.0));
    Object_Sens_IF.TF.transform.rotation.x  = q.x();
    Object_Sens_IF.TF.transform.rotation.y  = q.y();
    Object_Sens_IF.TF.transform.rotation.z  = q.z();
    Object_Sens_IF.TF.transform.rotation.w  = q.w();
    Object_Sens_IF.TF.transform.translation.x = position[0];
    Object_Sens_IF.TF.transform.translation.y = position[1];
    Object_Sens_IF.TF.transform.translation.z = position[2];
    Object_Sens_IF.TF.header.frame_id       = "Fr1";
    Object_Sens_IF.TF.child_frame_id        = "Object_example";

    Object_Sens_IF.TF_br = std::make_shared<tf2_ros::StaticTransformBroadcaster>(nhp);
    Object_Sens_IF.TF_br->sendTransform(Object_Sens_IF.TF);

    return 1;
}

int
CMNode_Object_Sens_IF_TestrunEnd (cm_ros::CMNode *CMNode)
{
    CMJob::JobScheduler& scheduler = CMNode->getScheduler();

    scheduler.deleteJob("Object_example");
}
