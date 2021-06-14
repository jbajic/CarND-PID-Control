#include "PID.hpp"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  prev_cte = cte;
  sum_cte += cte;
}

double PID::GetValue(const double cte, const double timestep) const{
  return -Kp * cte - ((cte - prev_cte) / 0.02) *Kd - sum_cte*Ki;
}

double PID::TotalError() {
  return sum_cte;
}