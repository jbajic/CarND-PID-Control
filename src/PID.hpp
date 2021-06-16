#pragma once

#include <vector>

class PID {
public:
  /**
   * Constructor
   */
  PID(double _time_diff);

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(const double cte);

  /**
  * Return the value.
  */
  double GetValue(const double cte);

  /**
  * Change parameters
  */
  void Twiddle(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

  bool optimization;
private:
  double time_diff;
  int parameter_index;
  std::vector<double> parameters;
  std::vector<double> differences;
  std::vector<int> parameter_optimization_step;

  double prev_cte;
  double sum_cte;
  double current_err;
  double best_err;

};
