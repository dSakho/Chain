/* Daouda Sakho

 * Main.cpp

 * To Compile: g++ -Wall -o  hw1prt1 main.cpp Chain.h

 * CSCI335 Assignment 1 Part A

 * Main Program to emulate Chain operations

 * Final Update Februay 15th, 2011

 */

#include "Chain.h"
#include <iostream>
using namespace std;

int main() {
	
	Chain<int> a, b, c;

	cin >> a;	

	cout << a;

	cin >> b;

	cout << b;

	a = a + 2;
	
	cout << a;
	
	return 0;
}
