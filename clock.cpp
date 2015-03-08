// File: $Id: clock.cpp, v 2.0 2014/11/25
// Author: Avi Bhagat
// Author: Ankit Bhankharia
// Description: Clock puzzle problem solver

#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <list>
#include <stdlib.h>
#include "solver.h" //Including the framework

using namespace std;

class Clock: public Solver<int> {

	// number, no. of hours on dial
	// initial, initial hour on display
	// final, final hour to which the clock has to be set on
	int number, initial, final;

public:

	Clock(int number, int initial, int final) :
			number(number), initial(initial), final(final) {
	}

	/* Name: getNextConfig
	 *
	 * Description:	get all the configurations that can be reached from
	 * 				a given configuration. In this case the hours that we will
	 *				get is one hour before and after the current hour.
	 * Arguments:	int configuration this is the current hand position (hour)
	 *				of the clock.
	 * Returns:		vector<int> hours that follow
	 *				the current hour
	 */
	vector<int> nextConfig(int configuration) {
		vector<int> result;

		//getting the previos hour of the current clock hour
		int back = configuration - 1;

		//making sure that no hour is 0 or negative
		if (back <= 0) {
			back = back + number;
		}

		//getting the next hour of the current clock hour
		int front = (configuration + 1);

		//making sure the it is not greater then the total no.
		//of hours on the clock
		if (front > number) {
			front = front % number;
		}

		//saving the next and previous hours
		result.push_back(back);
		result.push_back(front);

		//return the previous and next hours
		return result;
	}

	/* Name: solve
	 *
	 * Description:	calls the solve() of class Solver to solve the puzzle
	 */

	void solve() {
		display(Solver::solve(initial), cout);
	}

	/* Name: display
	 *
	 * Description:	display a hour out on the screen
	 * Arguments:	list<int> finalList (hour) is the configuration we want to
	 *				display
	 */
	void display(vector<int> finalList, ostream &cout) {
		cout << "The flow of change in clock:" << endl;

		for (int i = 0; i < finalList.size(); ++i) {
			cout << finalList[i] << '\n';
		}
	}

	/* Name: isSolved
	 *
	 * Description:	returns true is the goal is reached.
	 * Arguments:	int check, to check if it is equal to final.
	 * Returns:		bool, if goal is reached else it returns false.
	 */
	bool isSolved(int check) {
		return check == final;
	}
};

int main(int argc, char const *argv[]) {

	if (argc != 4) {
		cout << "Enter valid number of arguments!";
		return -1;
	}

	int number = atoi(argv[1]);
	int initial = atoi(argv[2]);
	int final = atoi(argv[3]);

	if (initial > number || final > number) {
		cout << "Invalid start/end time";
		return -1;
	}

	Clock aClock(number, initial, final);
	aClock.solve();
	return 0;
}
