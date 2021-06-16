#include "PID.hpp"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID(double _time_diff)
    : time_diff{_time_diff} {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  parameters = {Kp_, Ki_, Kd_};
  parameter_optimization_step = {0, 0, 0};
  differences = {1, 1, 1};
  optimization = false;
  parameter_index = 0;
  sum_cte = prev_cte = 0;
}

void PID::UpdateError(const double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  prev_cte = cte;
  sum_cte += cte;
}

double PID::GetValue(const double cte) {
  if(optimization) {
    best_err = cte;
    Twiddle(cte);
  }
  return -parameters[0] * cte - ((cte - prev_cte) / time_diff) * parameters[1] - sum_cte * parameters[2];
}

void PID::Twiddle(double cte) {
  if(parameter_optimization_step[parameter_index] == 0) {
    parameters[parameter_index]] += differences[parameter_index];
    parameter_optimization_step[parameter_index] = 1;
  } else if(parameter_optimization_step[parameter_index] == 1) {
    parameters[parameter_index]] *= differences[parameter_index];
  }
}

double PID::TotalError() { return sum_cte; }