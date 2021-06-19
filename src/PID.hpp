#pragma once

class PID {
public:
  /**
   * Constructor
   */
  PID(const double _dt);

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
  void UpdateError(double cte);

  /**
  * Return the value.
  */
  double GetValue(const double cte) const;

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

private:
  /**
   * PID Errors
   */
  double Kp;
  double Ki;
  double Kd;
  double prev_cte;
  double sum_cte;

  double dt;

};
