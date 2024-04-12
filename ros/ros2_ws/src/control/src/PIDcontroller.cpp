#include "control/PIDController.hpp"

void PID_Init(PIDController *pid, double kp, double ki, double kd,
              double setpoint) {
  pid->kp = kp;
  pid->ki = ki;
  pid->kd = kd;
  pid->setpoint = setpoint;
  pid->integral = 0.0;
  pid->prev_error = 0.0;
}

double PID_Update(PIDController *pid, double current_value, double dt) {
  double error = pid->setpoint - current_value;

  pid->integral += error * dt;
  double derivative = (error - pid->prev_error) / dt;

  double output =
      pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;

  pid->prev_error = error;

  return output;
}
