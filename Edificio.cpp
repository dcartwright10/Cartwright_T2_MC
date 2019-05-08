#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double forzamiento(t,omega);
	

int main(){
	double tot_t = 10;
	double dt = 0.1;
	double m = 1000;
	double gamma = 0;
	double k = 2000;
	double omega = sqrt(k/m);
	double *vt;
	vt = new double [n];
	int n = int (tot_t/dt);
	double *u1;
	u1 = new double [n]; 	
	double *u2;
	u2 = new double [n];
	double *u3;
	u3 = new double [n];
	double *v1;
	v1 = new double [n];
	double *v2;
	v2 = new double [n];
	double *v3;
	v3 = new double [n];
	u1[0]=0,u2[0]=0,u3[0]=0;
	v1[0]=0,v2[0]=0,v3[0]=0;
	vt[0]=0;
	double k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,k20,k21,k22,k23,k24;
	
	
	for(int i=1; i<=n; i++){
		vt[i]= vt[i-1]+dt;		
		k1 = dt*(1/m)*(-gamma*u1[i-1]-2*k*u1[i-1]+k*u2[i-1]+ forzamiento(t[i-1],omega);
		k2 = dt*(1/m)*(-gamma*u1[i-1]-2*k*u1[i-1]+k*u2[i-1]+ forzamiento(t[i-1],omega);
		k3 = dt*(1/m)*(-gamma*u1[i-1]-2*k*u1[i-1]+k*u2[i-1]+ forzamiento(t[i-1],omega);
		k4 = v1[i-1];


		k7 = dt*(1/m)*(-gamma*(u1[i-1]+k1/2)-2*k*(u1[i-1]+k4/2)+k*(u2[i-1]+k5/2)+ forzamiento((t[i-1]+dt/2),omega);
		

		u1[i] = u1[i-1]+(1/6)*(k4+2*k10+2*k16+k22)
		u2[i] = u2[i-1]
		}
	ofstream file;
	file.open("datos.dat");
	for(int j=0; j<=n; j++){
		file << vt[i] <<" "<< u1[i] <<" "<< u2[i] <<" "<< u3[i] <<" "<< v1[i] <<" "<< v2[i] <<" "<< v3[i] <<endl;
		}
	file.close();
	return 0;
	}
	double forzamiento(t,omega){
		return sin(omega*t)
	}
	
