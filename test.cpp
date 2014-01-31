//Test file for PCB

#include "PCB.h"
#include <iostream>
using namespace std;

int main( ) {

	int q;

	cout << "How many PCBs?\n\n";
	cin >> q;
	
	PCB* ptr = new PCB[ q ];
	
	for (int i = 0; i <= q; ++i)
		cin >> ptr[ i ];
		
	for (int j = 0; j <= q; ++j)
		cout << ptr[ i ];
		
	return 0;
	
} // end main

