#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double u_next(double c, double dt, double dx, double u_presente, double u_tanterior, double u_xanterior, double u_xnext){
  double u = pow(c*dt/dx,2)*(u_xnext - 2*u_presente+u_xanterior) + 2*u_presente - u_tanterior;
  return u;
}

int main(){
  double T = 40;
  double rho = 10;
  double L = 100;
  double c = sqrt(T/rho);
  double dx = 5;
  double dt = dx/c;
  double t = 200;
  double pi = 3.14159265359;

  int n_x = L/dx + 1;
  int n_t = t/dt;

  double **u = new double*[n_x];
  double *x = new double[n_x];

  for(int i = 0; i<n_x;i++){
    x[i] = i*dx;
    u[i] = new double[n_t];
  }

  for(int i = 0; i<n_x;i++){
    double x_i = x[i];

    if((i == 0) || (i == n_x-1)){
      u[i][0] = 0;
    }
    else if(x_i<=0.8*L){
      u[i][0] = 1.25*x_i/L;
    }
    else{
      u[i][0] = 5 - 5*x_i/L;
    }
  }

  for(int i = 0; i<n_x;i++){
    if((i == 0) || (i == n_x-1)){
      u[i][1] = 0;
    }
    else{
    u[i][1] = pow(c*dt/dx,2)*(u[i+1][0] + u[i-1][0] - 2*u[i][0])/2 + u[i][0];
    }
  }
  
  for(int j = 2; j < n_t; j++){
   
    for(int i = 0; i<n_x;i++){

      if((i == 0) || (i == n_x-1)){
	u[i][j] = 0;
      }
      else{
	u[i][j] = u_next(c,dt,dx,u[i][j-1],u[i][j-2],u[i-1][j-1],u[i+1][j-1]);
      }
      
    }
    
  }

  cout << 0;

  for(int i = 0; i<n_x;i++){
    cout << " " << x[i];
  }

  cout << endl;

  for(int j = 0; j<n_t;j++){
    cout << j*dt; 

    for(int i = 0; i<n_x;i++){
      cout << " " << u[i][j];
    }
    cout << endl;
  }

  return 0;
  
}
