/**
 * Author: Mayan Bashan
 */

#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <math.h>
using namespace std;
const int mindig = 1;
const int maxdig = 4;

// returns a random number (a valid one)
int random_number(){
	int rand_dig = 0;
	int ans = 0;
	for (int i=8; i>=1; i--){
		rand_dig = rand() % maxdig + mindig;
		ans += rand_dig*(pow(10,i-1));
	}
	return ans;
}

// prints 100 random snowmen
int main() {
	int snowman_number;
	for (int i=0; i<100; i++){
		snowman_number = random_number();
		cout << "Random number is:" << "\t";
		cout << snowman_number << endl;
		cout << "Random snowman is:" << "\t";
		cout << ariel::snowman(snowman_number) + "\n" << endl;
	}
	int user_input;
	int flag = 1;
	while (flag){
		cout << "Above you have multiple examples of snowmen, you can choose one of them, or choose a new one - \nPlease enter 8 digit number: " << endl;
		try{
			cin >> user_input;
			cout << ariel::snowman(user_input) << endl;
			flag=0;
		}
		catch(exception e){
			cout << "You inserted invalid input, please try again" << endl;
		}
	}
	return 0;
}
