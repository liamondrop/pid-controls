#include "./PID.h"

PID::PID() {}

PID::~PID() {}

void PID::init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
}

void PID::updateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::totalError() { return -Kp * p_error - Ki * i_error - Kd * d_error; }
