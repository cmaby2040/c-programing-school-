#include <iostream>
#include<cmath>
#include "trapezoidal.h"

using namespace std;

int main(){
	int functionType, steps;
	double aValue,bValue,cValue;
	double x, xmin, xmax;
	cout << "Select a function from below: " << endl;
	cout << "1) y= ax+b " << endl;
	cout << "2) ax^2 + bx + c" << endl;
	cout << "3) a sin(bx) + c" <<endl;
	cout << "Enter 1, 2 or 3: ";
	cin >> functionType;
	if (functionType==1){
		cout << "Enter parameter a: ";
		cin >> aValue;
		cout << "Enter parameter b: ";
		cin >> bValue;
		cout  << "Enter x: ";
		cin >> x;
		double array[2] {aValue,bValue};
		double t=line(x, array);
		}else if(functionType==2 || functionType==3){
		cout << "Enter parameter a: ";
		cin >> aValue;
		cout  << "Enter parameter b: ";
		cin >> bValue;
		cout  << "Enter parameter c: ";
		cin >> cValue;
		cout  << "Enter x: ";
		cin >> x;
		double array[3] {aValue,bValue,cValue};
		if (functionType==2){
			double z= quadratic(x, array);
			cout << z;
		}if (functionType==3){
			double z = trigs(x, array);
			cout << z;
		}
		
		
	}
	cout << "Enter xmin xmax nSteps: ";
	cin >> xmin >> xmax >> steps;
	
	
	//cout << xmin << xmax << steps;
	return 0;
	
}
