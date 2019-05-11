#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//Funcion utilizando el metodo de Runge Kutta//
void Runge_kutta(double *u1,double *u2,double *u3,double *v1,double *v2,double *v3, double (*forzamiento)(double,double), double dt, int n, double m, double gamma, double k, double omega, double*t, double*maximos, int l){  

double k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,k20,k21,k22,k23,k24;

double max1 = -100;
double max2 = -100;
double max3 = -100;	
	for(int i=1; i<=n; i++){
		t[i]= t[i-1]+dt;
				
		k1 = dt*(1.0/m)*(-gamma*v1[i-1]-2*k*u1[i-1]+k*u2[i-1]+ forzamiento(t[i-1],omega));
		
		k2 = dt*(1.0/m)*(-gamma*v2[i-1]+k*u1[i-1]-2*k*u2[i-1]+ k*u3[i-1]);
		k3 = dt*(1.0/m)*(-gamma*v3[i-1]+k*u2[i-1]-k*u3[i-1]);
		k4 = dt*v1[i-1];
		k5 = dt*v2[i-1];
		k6 = dt*v3[i-1];
		k7 = dt*(1.0/m)*(-gamma*(v1[i-1]+k1/2)-2*k*(u1[i-1]+k4/2)+k*(u2[i-1]+k5/2)+ forzamiento((t[i-1]+dt/2),omega));
		k8 = dt*(1.0/m)*(-gamma*(v2[i-1]+k2/2)+k*(u1[i-1]+k4/2)-2*k*(u2[i-1]+k5/2)+ k*(u3[i-1]+k6/2));
		k9 = dt*(1.0/m)*(-gamma*(v3[i-1]+k3/2)+k*(u2[i-1]+k5/2)-k*(u3[i-1]+k6/2));
		k10 = dt*(v1[i-1]+k1/2);
		k11 = dt*(v2[i-1]+k2/2);
		k12 = dt*(v3[i-1]+k3/2); 
		k13 = dt*(1.0/m)*(-gamma*(v1[i-1]+k7/2)-2*k*(u1[i-1]+k10/2)+k*(u2[i-1]+k11/2)+ forzamiento((t[i-1]+dt/2),omega));
		k14 = dt*(1.0/m)*(-gamma*(v2[i-1]+k8/2)+k*(u1[i-1]+k10/2)-2*k*(u2[i-1]+k11/2)+ k*(u3[i-1]+k12/2));
		k15 = dt*(1.0/m)*(-gamma*(v3[i-1]+k9/2)+k*(u2[i-1]+k11/2)-k*(u3[i-1]+k12/2));
		k16 = dt*(v1[i-1]+k7/3);
		k17 = dt*(v2[i-1]+k8/3);
		k18 = dt*(v3[i-1]+k9/3);
		k19 = dt*(1.0/m)*(-gamma*(v1[i-1]+k13)-2*k*(u1[i-1]+k16)+k*(u2[i-1]+k17)+ forzamiento((t[i-1]+dt),omega));
		k20 = dt*(1.0/m)*(-gamma*(v2[i-1]+k14)+k*(u1[i-1]+k16)-2*k*(u2[i-1]+k17)+ k*(u3[i-1]+k18));
		k21 = dt*(1.0/m)*(-gamma*(v3[i-1]+k15)+k*(u2[i-1]+k17)-k*(u3[i-1]+k18));
		k22 = dt*(v1[i-1]+k13);
		k23 = dt*(v2[i-1]+k14);
		k24 = dt*(v3[i-1]+k15); 



		u1[i] = u1[i-1]+(1.0/6)*(k4+2*k10+2*k16+k22);
		u2[i] = u2[i-1]+(1.0/6)*(k5+2*k11+2*k17+k23);
		u3[i] = u3[i-1]+(1.0/6)*(k6+2*k12+2*k18+k24);
		v1[i] = v1[i-1]+(1.0/6)*(k1+2*k7+2*k13+k19);
		v2[i] = v2[i-1]+(1.0/6)*(k2+2*k8+2*k14+k20);
		v3[i] = v3[i-1]+(1.0/6)*(k3+2*k9+2*k15+k21);
		if (u1[i]>max1){
			max1 = u1[i];
		}
		if (u2[i]>max2){
			max2 = u2[i];
		}
		if (u3[i]>max3){
			max3 = u3[i];
		}
		
		}
		maximos[l*3+0]=max1;
		maximos[l*3+1]=max2;
		maximos[l*3+2]=max3;


		}
//Funcion de forzamiento//
double forzamiento(double t, double omega){
		return sin(omega*t);
		}

int main(){
	double tot_t = 100;
	double dt = 0.1;
	int n = int (tot_t/dt);
	double m = 1000;
	double gamma = 0;
	double k = 2000;
	double omega = sqrt(k/m);
	double *t;
	t = new double [n];
	
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
	t[0]=0;
	double k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,k20,k21,k22,k23,k24;	
	double *omegas;
	omegas = new double[100];
 	omegas[0] = 0.2*sqrt(k/m);
	
	double dif = ((3-0.2)*sqrt(k/m))/100;
	double *maximos;
	maximos = new double[300];
	
	
	Runge_kutta(u1,u2,u3,v1,v2,v3,forzamiento,dt,n,m,gamma,k,omegas[0],t,maximos,0);
//for generando array de omegas//
	for(int l=1; l<100; l++){
		omegas[l] = omegas[l-1]+dif;
		Runge_kutta(u1,u2,u3,v1,v2,v3,forzamiento,dt,n,m,gamma,k,omegas[l],t,maximos,l);
		}
	//genero un archivo de datos con las diferentes frecuencias y los valores maximos correspondientes para cada piso//
	ofstream file;
	file.open("datos.dat");
	for(int j=0; j<100; j++){
		file << omegas[j]<<" "<< maximos[j*3+0] <<" "<< maximos[j*3+1] <<" "<< maximos[j*3+2] <<" "<<u1[j]<<" "<<u2[j]<<" "<<u3[j]<<" "<<t[j]<<endl;
		}
	file.close();
	
//genero datos para los omegas elegidos//
//omega1
	Runge_kutta(u1,u2,u3,v1,v2,v3,forzamiento,dt,n,m,gamma,k,omegas[60],t,maximos,60);

	ofstream file2;
	file2.open("omega1.dat");
	for(int f=0; f<100; f++){
		file2 <<u1[f]<<" "<<u2[f]<<" "<<u3[f]<<" "<<t[f]<<endl;
		}
	file2.close();

//omega2
	Runge_kutta(u1,u2,u3,v1,v2,v3,forzamiento,dt,n,m,gamma,k,omegas[37],t,maximos,37);

	ofstream file3;
	file3.open("omega2.dat");
	for(int f=0; f<100; f++){
		file3 <<u1[f]<<" "<<u2[f]<<" "<<u3[f]<<" "<<t[f]<<endl;
		}
	file3.close();
//omega3
	Runge_kutta(u1,u2,u3,v1,v2,v3,forzamiento,dt,n,m,gamma,k,omegas[10],t,maximos,10);

	ofstream file4;
	file4.open("omega3.dat");
	for(int f=0; f<100; f++){
		file4 <<u1[f]<<" "<<u2[f]<<" "<<u3[f]<<" "<<t[f]<<endl;
		}
	file4.close();
	
//omega4
	Runge_kutta(u1,u2,u3,v1,v2,v3,forzamiento,dt,n,m,gamma,k,omegas[72],t,maximos,72);

	ofstream file5;
	file5.open("omega4.dat");
	for(int f=0; f<100; f++){
		file5 <<u1[f]<<" "<<u2[f]<<" "<<u3[f]<<" "<<t[f]<<endl;
		}
	file5.close();
	delete[] maximos;
	delete[] u1;
	delete[] u2;
delete[] u3;
delete[] v1;
delete[] v2;
delete[] v3;
delete[] t;
	return 0;}

	

