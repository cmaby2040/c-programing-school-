#include "double_array.h"
#include <iostream>
#include <string>
using namespace std;

	void printArray(double* firstP, int size){
		std::cout << "start of the print" <<std::endl;
		double* pointer = firstP;
		for(int i=0; i<size; i++){
			std::cout << *pointer << std::endl;
			pointer++;
		}
		cout << endl;
	}
	bool double2Char(double * firstD, char * firstC, int size){
		double * pointer1=firstD;
		char * pointer2=firstC;
		for(int i=0; i<size;i++){
			int x; 
			x=int(*pointer1); // type conversion of the double to string
			if (x < -128 ){// convert ints to the min value of char
				*pointer1 = -128;
			}if (x >127 ){// convert ints to the max value of char
				*pointer1= 127;
			}
			
			*pointer2 = static_cast<char>(*pointer1);
			if (*pointer2 == static_cast<char>(NULL)){// an interger value of 0 check and no cooresponding char value return 0 or false
				return false;
			}
			//std::cout << *pointer2 << ", " << *pointer1 << ", " << x << std::endl;
			pointer1++;
			pointer2++;
			}
	return true;
	}
	
	void printChars(char* firstP, int size){// print out the values of character array
		std::cout << "start of the print char int array" <<std::endl;
		char* pointer = firstP;
		for(int i=0; i<size; i++){
			std::cout << *pointer << std::endl;
			pointer++;
		}
		cout << endl;
	}
	
	bool getCharacters(char* firstc, char twodChar[10][5]){
		char *pointer1=firstc;
		for(int i=0; i<10; i++){
			int x= static_cast<int>(*pointer1);
			string newString(to_string(x));
			if(x < -99){
				for (int j=0;j<5;j++){
					twodChar[i][j]= newString[j];
				}
			}if(x > 99){
				for (int j=0;j<4;j++){
					twodChar[i][j]= newString[j];
				}
			}
			if((x >-99) && (x<-9)){
				for (int j=0;j<4;j++){
					twodChar[i][j]= newString[j];
				}
			}
			if((x < 99)&& (x>9)){
				for (int j=0;j<3;j++){
					twodChar[i][j]= newString[j];
				}
			}//
			if((x <9) && (x>0)){
				for (int j=0;j<2;j++){
					twodChar[i][j]= newString[j];
				}
			}if((x > -9)&& (x<0)){
				for (int j=0;j<3;j++){
					twodChar[i][j]= newString[j];
				}
			}
			pointer1++;
			
		}
		for (int y=0;y<10;y++){
			cout << "old style string: " << y << " begin print:" << endl;
			for (int q=0;q<4;q++){
				cout << twodChar[y][q] << " ";;
			}
			cout << endl;
		}
		return true;
	}
		
		
		
