#ifndef PID_CONTROLLER_HPP
#define PID_CONTROLLER_HPP

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
  double kp; // Proportional gain
  double ki; // Integral gain
  double kd; // Derivative gain

  double setpoint;   // Desired setpoint
  double integral;   // Integral term
  double prev_error; // Previous error for derivative term
} PIDController;

// Function prototypes
void PID_Init(PIDController *pid, double kp, double ki, double kd,
              double setpoint);
double PID_Update(PIDController *pid, double current_value, double dt);

#ifdef __cplusplus
}
#endif

#endif // PID_CONTROLLER_HPP