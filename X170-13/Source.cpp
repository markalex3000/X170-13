// X170-12 and 13	Mark R. Alexieff	3/3017
// Bull and Cow game
// Computer generates a list of four integers (0 - 9).  User tries to work out what they are.
// User inputs 4 integers.  Computer responds with a Bull for right digit in right spot.  Cow for right
// digit in wrong spot.
// Input: Ask for four digits
// Input: After each  guess users is asked if they want to guess again or quit
//
// Output: Your guess: X X X X.  Y Bulls, Z Cows.
// Repeat until user quits or four bulls.
//
// Error conditions to check for:
// 1. User input is bad
//		not four digits between 0 and 9 and no repeats


// Start standard opening 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <exception>
#include <random>

using namespace std;

inline void keep_window_open() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	char ch; cin >> ch;
}

inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

bool yes_no(string s) {
	char response{ 'X' };
	cout << s << " (y/n): ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> response;
	switch (response)
	{
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		return false;
	}
};

// function declarations
void gen_code(vector<int>& the_code);
//bool get_guess(vector<int>& the_guess);
//int how_many_bulls(vector<int>& the_code, vector<int>& the_guess);
//int how_many_cows(vector<int>& the_code, vector<int>& the_guess);
void output_vector(vector<int>& vi);


int main() {
	vector<int> the_code{ -1,-1,-1, -1 };
	vector<int> the_guess;
	int bulls{ 0 };
	int cows{ 0 };

	bool play_again{ true };
	bool quiter{ false };

	while (play_again) {
		cout << "Generating the code...\n";
		gen_code(the_code);

		cout << "The code: ";
		output_vector(the_code);

/*		while (!quiter) {
			quiter = get_guess(the_guess);
			bulls = how_many_bulls(the_code, the_guess);
			cows = how_many_cows(the_code, the_guess);
			if (bulls == 4) {
				cout << "You win!\n")
				break;
			}
			cout << "You gueesed: ";
			output_vector(the_guess);
			cout << " Results: " << bulls << " Bulls\t" << cows << " Cows\n";
			quiter = yes_no("Guess again? ");
	}*/	
		play_again = yes_no("Play again? ");
	}
}

void gen_code(vector<int>& the_code) {
	int temp{ -1 };
	bool duplicate{ true };

	// generate computer code
	random_device rd;   // non-deterministic generator  
	mt19937 gen(rd());  // to seed mersenne twister.  
	uniform_int_distribution<> dist(0, 9); // distribute results between 0 and 9 inclusive.  

	for (int i = 0; i < 4; ++i) {
		while (duplicate) {
			duplicate = false;
			temp = dist(gen);
			for (int j = 0; j < i; ++j) {
				if (temp == the_code[j]) duplicate = true;
			}
		}
		the_code[i] = temp;
		duplicate = true;
	}
	return;
}
/*
int how_many_cows(vector<int>& the_code, vector<int>& the_guess)
{
	return 0;
}
*/
void output_vector(vector<int>& vi)
{
	for (int i = 0; i < vi.size(); ++i) cout << vi[i] << " ";
}

