/* ProgramName: GCD.cpp
 * Description: Euclidean Algorithm for calculating 
 * 		greatest common divisor, and extended Euclidean 
 * 		Algorithm that returns GCD as a linear combination
 * Author: Faris Abdel-Maksoud
 * Date Created: 11/7/17
 * Date Modified: 11/18/17
*/

#include <iostream>
#include <assert.h>

using namespace std;

//Euclidean Algorthim for calculating greatest common divisor
//pre:	a >= b >= 0
//post:	return d = gcd(a,b)
int GCD(int a, int b){
	assert(a != 0 || b != 0);
	assert(a >= b);

	if(b == 0){
		return a;
	}
	else if(b == 1){	//checks for relative primality
		return b;
	}
	else{
		return GCD(b, a % b);
	}
}

//Extended Euclidean Algorithm
//pre:	a and b !=0, a >= b
//post:	return d = GCD(a, b), s, t, by reference
//	s & t are set so that return_value = a*s + b*t
int ExtendedGCD(int a, int b, int &s, int &t){
	assert(a !=0 || b != 0);
	assert(a >= b);

	if(b==0){
		s = 1;
		t = 0;
		return a;	//a = s*a + t*b
	}
	else{
		int q = a/b;	//q = a/b
		int r = a%b;	//r = a - b*q
		int s1, t1;		//temp values

		int d = ExtendedGCD(b, r, s1, t1);
			s = t1;
			t = s1 - t1*q;
				//d = ExtendedGCD(b,r)
				//	= s1*b + t1*r
				//  = s1*b + t1*(a-b*q)
				//  = s1*b + t1*a - t1*q*b
				//  = t1*a + (s1-t1*q)*b
		return d;	//d = s*a + t*b
	}
}

//BEGIN MAIN
int main(){

	int a = 660; int b = 340;
	int d; int s; int t;

	d = GCD(a,b);
	cout << "GCD(" << a << "," << b << ") = " << d << endl;

	d = ExtendedGCD(a,b,s,t);
	cout << "ExtendedGCD(" << a << "," << b << ") = " << d
		 << " = " << a << "*(" << s << ") + " << b << "*(" << t << ")" << endl;

	return 0;
}


