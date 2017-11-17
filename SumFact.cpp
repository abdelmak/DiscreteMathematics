//ProgramName:	sumOfInt.cpp
//Author:	Faris Abdel-Maksoud
//Description:	Needed to calculate sum of integers 1 to n
//				and factorials for homework, so I wrote two 
//				simple functions to do it


#include <iostream>
using namespace std;

int sumInt(int);
int factorial(int);

int main(){

	int n;	int x;

	cin >> n;
	x = sumInt(n);
	cout << "Sum of integers 1 to " << n << " = " << x << endl;

	cin >> n;
	x = factorial(n);
	cout << n << "! = " << x << endl;

	return 0;
}

int sumInt(int n){
	if(n==1){
		return n;
	}
	else{
		return n + sumInt(n - 1);
	}
}

int factorial(int n){
	if(n==0){
		return 1;
	}
	else{
		return n * factorial(n - 1);
	}
}
