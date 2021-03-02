#include <iostream>
#include "double_array.h" //this might not be right
#include <cstdlib>
#include <string>
using namespace std;

int main(){
	double dArray[10];
	double* tempPoint=dArray;
	srand(42);
	for(int x=0; x<10;x++){			
			double rVal = -1000.0 + 2000.0 * (static_cast<double>(rand()) / static_cast<double> (RAND_MAX));
			*tempPoint =rVal;
			//std::cout << *dArray << ", " << dArray << ", " << *tempPoint << ", " << tempPoint << std::endl;
			tempPoint++;			
		};
	double* pointer=dArray;
	printArray((pointer), 10);
	char c[10];
	
	bool x = double2Char(pointer, &c[0],10);
	printChars(&c[0],10);
	
	char oldString[10][5];
	char *pointer1= oldString[0];
	getCharacters(&c[0], oldString);
		
	return 0;


}
