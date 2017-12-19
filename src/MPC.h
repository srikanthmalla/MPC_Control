#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

#define DT 0.1 // time step duration dt in s 

// It was obtained by measuring the radius formed by running the vehicle in the
// simulator around in a circle with a constant steering angle and velocity on a
// flat terrain.
//
// Lf was tuned until the the radius formed by the simulating the model
// presented in the classroom matched the previous radius.
//
// This is the length from front to CoG that has a similar radius.
#define LF 2.67

#define NUMBER_OF_STEPS 20
// Set desired cte, epsi and speed
// Both the reference cross track and orientation errors are 0.
#define REF_CTE 0
#define REF_EPSI 0
#define REF_V 40
// Set weights parameters for the cost function
#define W_CTE 2
#define W_EPSI 20
#define W_V 1
#define W_DELTA 100000
#define W_A 20
#define W_DDELTA 0
#define W_DA 0
// Set lower and upper limits for variables.
#define DED25RAD 0.436332 // 25 deg in rad, used as delta bound
#define MAXTHR 1.0 // Maximal a value
#define BOUND 1.0e3 // Bound value for other variables

using namespace std;

class MPC {
 public:
  MPC();

  virtual ~MPC();

  // Solve the model given an initial state and polynomial coefficients.
  // Return the first actuatotions.
  vector<double> Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);
  vector<double> mpc_x;
  vector<double> mpc_y;
};

#endif /* MPC_H */
