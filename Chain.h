/* Daouda Sakho
 * Chain.h
 * CSCI335 Assignment 1 Part A
 * Chain template header & implementation file
 * Final Update February 15th, 2011
 */

#ifndef Chain_H
#define Chain_H

#include <iostream>
using std::cout;
using std::ostream;
using std::istream;
using std::cerr;
#include <cstdlib>
using std::exit;


template <typename T>
class Chain {

	//overloaded << operator
	friend ostream& operator<< (ostream& out, const Chain<T> & x) {
		if ( x.empty() )
			out << "\nChain is empty\n";

		else {
	
			out << "\nChain constains " << x.length()
				<< " elements.";
			out << "\n[ ";

			for (int i = 0; i < x.length(); ++i)
				out << x[i] << " ";

			out << "]\n";
		}

		return out;
	}	
	
	//overloaded >> operator
	friend istream& operator>> (istream& in, Chain<T> & x) {
		cout << "\nEnter the size of the chain\n";
		in >> x.size;	

		cout << "Enter the elements of the chain:\n";
	
		for (int i = 0; i < x.size; ++i)
			in >> x[i];
	
		return in;
	}

	public:
		Chain( int initSize = 0) 
			: size(initSize) { a = new T[size]; } 		//constructor
		
		Chain (const Chain<T> & rhs) : a(NULL) 			//copy constructor
			{ operator=( rhs ); }
		
		~Chain() {						//destructor
			delete[] a;
			a = 0;	 
		}
		
		const Chain& operator=(const Chain<T> & rhs) {		//assignment operator
			if(this != &rhs) {
      				
				delete[] a; 					// release space
     				size = rhs.length();    			// reseize this object
     			
				a = new T[ size ];     				 // create space for chain copy
				for (int i = 0; i < length(); i++)
         				a[i] = rhs.a[i];  // copy chain into object
			}
			return *this;	
		}

	
		bool operator==(const Chain<T> & rhs) const {		//equality operator
			if (this->size != rhs.size)
        			return false;        			// chains of diffeent number of elements

     			for (int i = 0; i < size; i++)
         			if (a[i] != rhs[i])
            				return false;      		// array contents are not equal

     			return true;   
		}           // arrays are equal	
		
		

		bool operator!=( const Chain<T> & rhs) const {		//inequality operator
			return !(*this == rhs);      			// invokes Array::operator ==;	
		}
	

		/* Function to return size of chain
		 * Precondition: None
		 * Postcondition: Returns size of chain as int
		*/
		int length() const { return size; }

		/* Function to determine if chain is empty
		 * Precondition: None
		 * Postcondition: Returns value 0 if chain isn;t
		 * empty; returns 1 is it is
		*/
		bool empty() const { return size == 0; }


		T & operator[]( int i ) {				//subscript operator
			if ( i < 0 || i >= size ) {
			//if the subscript is out of range
			//poor man's exception handling :P
        			cerr << "\nError: Subscript "  << i
             			<< " out of range\n";
        			exit(1);
     			} // end if

     			return a[ i ];
		}		
		
		const T operator[]( int i ) const {			//subscript operator
			if ( i < 0 || i >= size ) {
			//if the subscript is out of range
			//poor man's exception handling :p
           			cerr << "\nError: Subscript " << i
                		<< " out of range\n";
           			exit(1);
    			} // end if

    			return a[ i ];		
		}

		/* Overloaded addition operator of 2 chains
		 * Precondition: Both chains are initialized either
		 * through input or a default constructor
		 * Postcondition: Returns chain to the left of the operand
		 * and deallocates the rhs operand
		*/
		Chain operator+(const Chain<T> & x) {
			
			int i, j;
			size = length() + x.length();
			
			Chain<T> y(size);

			operator=( y );
			
			for (i = length() + 1, j = 0; i < size; ++i, ++j) 
				{ y[i] = x[j]; }

			for (i = 0; i < y.length(); ++i)
				{ a[i] = y[i]; }

			return *this;

		}

		/* Overloaded addition operator of a constant object
		 * Precondition: The object is created/initialized
		 * Postcondition: the object is placed as the last
		 * index of the chain
		 */
		Chain operator+(const T& data) const {

			if ( empty() )
				return (a[0] = data);

			a[ length() - 1 ] = data;
			return *this;
		}

		/* Overloaded multipilication operator
		 * Precondition: An interger is used as a scaler
		 * Postcondition: The chain will repeat its elements
		 * i times by the scaler
		 */
		Chain operator*(int i) {
			
			Chain<T> temp;		

			int newSize = size * i;

			for (int i = 0; i <= newSize; ++i) {
				for (int j = 0; j < size; ++j)
					a[j] = temp[j];	
			} // end for
		
			return temp;
		};

	private:
		T * a;		 				//private data for chain
		int size;					//private data for size


}; // end Chain class definition

#endif
