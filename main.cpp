/*
 * main.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: sarahradzihovsky
 */
#include <iostream>
#include <math.h>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

/*This program allows the user to enter a number and
 * outputs all the prime factors of that number (if there are any).
 */

/*Function Prototypes*/
vector<int> findPrimeFactors(int num);

int main(){
	int num;
	cout << "Enter a number: " << endl;
	cin >> num;
	vector<int> primeFactors = findPrimeFactors(num);

	/*prints out list of primeFactors*/
	cout << "These are the prime factors of " << num << ": " << endl;
	for(int i = 0; i < primeFactors.size(); i++){
		cout << primeFactors.at(i) << endl;
	}
}


vector<int> findPrimeFactors(int num){
	vector<int> primeFactors;
	/*divide number by 2 until it is no longer even. Add 2 as an
	 * additional factor each time.
	 */
	while(num % 2 == 0){
		primeFactors.push_back(2);
		num = num / 2;
	}

	/*num should now be odd so we can ignore even elements*/
	for(int i = 3; i < sqrt(num); i = i + 2){
		/*while num is divisible by i, add i as a factor and update n*/
		while(num % i == 0){
			primeFactors.push_back(i);
			num = num / i;
		}
	}

	/*This condition catches nums that are prime number greater than two.*/
	if(num > 2){
		primeFactors.push_back(num);
	}
	return primeFactors;
}

