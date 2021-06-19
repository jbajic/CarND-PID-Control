# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Project

This project uses PID controller for steering and throttle to drive a car around the track.

The PID controller consists of three components:

 - P => proportional component
 - I => integral component
 - D => derivative component

Each of the components has a gain which says how it is calculated:
 - `Kp` => proportional gain
 - `Ki` => integral gain
 - `Kd` => derivative gain

And the error is presented as CTE (cross-track error) which is given to us by the simulator and its being used in PID for steering,, while the difference between desired speed and the current is being used for throttle controller.

Both steering and throttle PID are working with PID formula:

`value(t) = -Kp * CTE - Kd * (CTE - CTE_prev) / dt - Ki*CTE_sum`

where CTE_prev is cte from previous step and CTE_sum is a sum of all CTE so far.

The final parameters were chosen by manual tuning and there are:
| PID controller | Kp | Kd | Ki |
| -------------- | -- | -- | -- |
| Steering | 0.15 | 0.00005 | 3.45 |
| Throttle | 0.1 | 0.0015 | 0.00001 |

The problem with twiddling or any optimization algorithm is having a clean run. I believe an attempt could be made by automatically finding these parameters but a better way of starting the simulation has to be found.
