#include"trapezoidal.h"
#include<cmath>
#include <iostream>
using namespace std;

 double line(double x, double (&array)[2]){
 	double y= (array[0])*x + (array[1]);
 	return y;
 }
 
 double quadratic(double x, double (&array)[3]){
 	double y,a,b,c;
 	a=array[0];
 	b=array[1];
 	c=array[2];
 	y = a*x*x+b*x+c;
 	return y;
 }
 
 double trigs(double xValue, double (&array)[3] ){
 	double y= (array[0]) * sin((array[1])*xValue)+(array[2]);
 	return y;
 }
 double* xrange(double xmin, double xmax, int steps){
 	double array[steps]; // need to use the new function or array get deleted
 	for (int i=0; i<steps;i++){
 		array[i]=(xmax-xmin)/steps*(i+1);
 		cout << array[i];
	 }
	 double* pointer
	 return double* array[0];
	 
 }
// double trapezoidal (double (&array)[3], double* xValueArray, int xValueSize );
