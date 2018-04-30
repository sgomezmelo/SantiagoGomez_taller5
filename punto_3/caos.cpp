#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
double e = 0.001;

double dq1(double p1){
  return p1;
}

double dq2(double p2){
  return p2;
}

double dp1(double q1){
  double u = 4*q1*q1 + e*e;
  double dp = -2*q1*pow(u,-3/2);
  return dp;
}

double dp2(double q1, double q2){
  double x_1 = pow((q1-q2),2)  + pow(e,2)/4;
  double x_2 = pow((q1+q2),2)  + pow(e,2)/4;
  double dp = (q1 - q2)*pow(x_1,-3/2) - (q1 + q2)*pow(x_2,-3/2);
  return dp;
}

int main(){
  double dt = 0.0001;
  double t = 3000;
  int n = t/dt;
  double a = 1/(2*sqrt(2));

  double q1 = a;
  double q1_ant = a;
  double q2 = -a;

  double p1 = 0;
  double p2 = 0;

  for(int i = 0; i < n; i++){
    double k1_q1 = dq1(p1);
    double k1_q2 = dq2(p2);
    double k1_p1 = dp1(q1);
    double k1_p2 = dp2(q1,q2);

    double k2_q1 = dq1(p1+k1_p1*dt/2);
    double k2_q2 = dq2(p2+k1_p2*dt/2);
    double k2_p1 = dp1(q1+k1_q1*dt/2);
    double k2_p2 = dp2(q1+k1_q1*dt/2,q2+k1_q2*dt/2);

    double k3_q1 = dq1(p1+k2_p1*dt/2);
    double k3_q2 = dq2(p2+k2_p2*dt/2);
    double k3_p1 = dp1(q1+k2_q1*dt/2);
    double k3_p2 = dp2(q1+k2_q1*dt/2,q2+k2_q2*dt/2);

    double k4_q1 = dq1(p1+k3_p1*dt);
    double k4_q2 = dq2(p2+k3_p2*dt);
    double k4_p1 = dp1(q1+k3_q1*dt);
    double k4_p2 = dp2(q1+k3_q1*dt,q2+k3_q2*dt);

    double k_q1 = (dt/6.0)*(k1_q1+2*k2_q1+2*k3_q1+k4_q1); 
    double k_q2 = (dt/6.0)*(k1_q2+2*k2_q2+2*k3_q2+k4_q2);
    double k_p1 = (dt/6.0)*(k1_p1+2*k2_p1+2*k3_p1+k4_p1);
    double k_p2 = (dt/6.0)*(k1_p2+2*k2_p2+2*k3_p2+k4_p2);

    q1 += k_q1;
    q2 += k_q2;
    p1 += k_p1;
    p2 += k_p2;

    /*cout << i*dt << " " << p2 << " " << q2 << " " << q1 << endl;*/

    if( ((q1 > 0) && (q1_ant < 0)) || ((q1 < 0) && (q1_ant > 0)) ){
      cout << q2 << " " << p2 << endl;
      }
    q1_ant = q1;
    }

  return 0;

}
