#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double phi(double phi_xant,double phi_xnext,double phi_ynext, double phi_yant){
  double p = (1.0/4.0)*(phi_xant + phi_xnext + phi_ynext + phi_yant);
  return p;
}
int main(){
  double L = 5.0;
  double l = 2.0;
  double d = 1.0;
  double h = 5.0/512.0;
  double Vo = 100;

  int N_iter = (L/h)*(L/h)/5;
  int n = L/h + 1;

  double *x = new double[n];
  double *y = new double[n];
  double **V = new double*[n];
  double **Ex = new double*[n];
  double **Ey = new double*[n];

  x[0] = -L/2;
  y[0] = -L/2;

  for(int i = 0; i<n;i++){
    V[i] = new double[n];
    Ex[i] = new double[n];
    Ey[i] = new double[n];
    if(i > 0){
      y[i] = y[i-1] + h;
      x[i] = x[i-1] + h;
    }
  }
  int j_placainf = 0;
  int j_placasup = 0;

  for(int i = 0; i<n;i++){
    V[i][0] = 0;
    V[0][i] = 0;
    V[i][n-1] = 0;
    V[n-1][i] = 0;


    Ex[i][0] = 0;
    Ex[0][i] = 0;
    Ex[i][n-1] = 0;
    Ex[n-1][i] = 0;


    Ey[i][0] = 0;
    Ey[0][i] = 0;
    Ey[i][n-1] = 0;
    Ey[n-1][i] = 0;

    for(int j = 0; j<n; j++){
      if((x[i] <= l/2) && (x[i] >= -l/2) && (y[j] <= d/2) && (y[j+1] > d/2)){
	j_placasup = j;
	V[i][j] = Vo/2;
      }

      else if((x[i] <= l/2) && (x[i] >= -l/2) && (y[j] >= -d/2) && (y[j-1] < -d/2)){
        j_placainf = j;
        V[i][j] = -Vo/2;
      }

      else if((i>0) && (i<n-1) && (j>0) && (j<n-1) && (j != j_placainf) && (j != j_placasup)){
	V[i][j] = 1;
      }
    }

  }

  int iter = 0;
  /*double error = 1;
  double tol = 0.000005;*/

  while((iter <= N_iter) /*&& (error > tol)*/){
    double suma = 0;
    for(int i = 1; i < n-1; i++){
      for(int j = 1; j < n-1; j++){
	double phi_ij = phi(V[i-1][j],V[i+1][j],V[i][j+1],V[i][j-1]); 

	/*suma += (phi_ij - V[i][j])*(phi_ij - V[i][j]);*/

	if((j == j_placasup) && (x[i] <= l/2) && (x[i] >= -l/2)){
	  V[i][j] = V[i][j];
	}
	else if((j == j_placainf) && (x[i] <= l/2) && (x[i] >= -l/2)){
          V[i][j] = V[i][j];
        } 

	else{
	  V[i][j] = phi_ij;
	}
      }
    }
    iter += 1;
    /*error = pow(suma,1.0/2.0)/((n-1)*(n-1));*/
  }

  for(int i = 1; i < n-1; i++){
    for(int j = 1; j < n-1; j++){
      Ex[i][j] = -(V[i+1][j] - V[i-1][j])/(2*h);
      Ey[i][j] = -(V[i][j+1] - V[i][j-1])/(2*h);
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << V[i][j] << " "; 
    }
    cout << endl;
    }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << Ex[i][j] << " ";
    }
    cout << endl;
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << Ey[i][j] << " ";
    }
    cout << endl;
  }




  return 0;
}
