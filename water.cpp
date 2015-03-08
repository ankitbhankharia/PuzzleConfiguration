// File: $Id: water.cpp, v 2.0 2014/11/25
// Author: Avi Bhagat
// Author: Ankit Bhankharia
// Description: Water puzzle problem solver

#include <vector>
#include <algorithm>
#include <iostream>
#include "solver.h" // Including the framework

using namespace std;

class Water: public Solver<vector<int> > {
	// The goal to reach
	int goal;

	// The containers stored in vector<int>
	vector<int> inp;

public:

	// Parameterized constructor
	Water(int goal, vector<int> inp) :
			goal(goal), inp(inp) {
	}
	/* Name: getNextConfig
	 *
	 * Description:	get all the configurations that can be reached from
	 * 				a given configuration. In this case the containers can be
	 *				filled, emptied and transfer water from one container to 
	 *				another.
	 * Arguments:	vector<int> configuration this is the current water held
	 *				by containers.
	 * Returns:		vector<vector<int> > nextConfig, that new amount in 
	 *				container will hold after the possible moves.
	 */
	vector<vector<int> > nextConfig(vector<int> conf) {

		vector<vector<int> > nextConfig;
		vector<int> temp;

		// To empty the container
		for (int i = 0; i != inp.size(); ++i) {
			if (conf[i] != 0) {
				temp = conf;
				temp[i] = 0;
				nextConfig.push_back(temp);
			}
		}

		// To fill one container completely
		for (int i = 0; i != inp.size(); ++i) {
			if (conf[i] != inp[i]) {
				temp = conf;
				temp[i] = inp[i];
				nextConfig.push_back(temp);
			}
		}

		// To transfer water from one container to another
		for (int i = 0; i != inp.size(); ++i) {
			for (int j = 0; j != inp.size(); ++j) {
				if (i != j) {
					int amtToTransfer = min(conf[i], inp[j] - conf[j]);
					if (amtToTransfer != 0) {
						temp = conf;
						temp[i] -= amtToTransfer;
						temp[j] += amtToTransfer;
						nextConfig.push_back(temp);
					}
				}
			}
		}
		return nextConfig;
	}

	/* Name: initialZero
	 *
	 * Description:	It sets the initial configuration to 0
	 */
	vector<int> initialZero() {
		return vector<int>(inp.size(), 0);
	}

	/* Name: solve
	 *
	 * Description:	calls the solve() of class Solver to solve the puzzle.
	 */
	void solve() {
		vector<vector<int> > res = Solver::solve(initialZero());
		display(res, cout);
	}

	/* Name: display
	 *
	 * Description:	displays the sequence of transfering water to reach goal.
	 * Arguments:	vector<vector<int> > v is the sequence of configuration
	 *				we want to display.
	 */
	void display(vector<vector<int> > v, ostream &cout) {
		cout << "The sequence of transfering water to reach " << goal << ":"
				<< endl;

		for (int i = 0; i < v.size(); ++i) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << (v[i])[j] << " ";
			}
			cout << endl;
		}
	}

	/* Name: isSolved
	 *
	 * Description:	returns true is the goal is reached.
	 * Arguments:	vector<int> config, the containers to check for goal.
	 * Returns:		bool, if goal is reached in any of the containers
	 *				else it returns false.
	 */
	bool isSolved(vector<int> config) {
		for (int i = 0; i < config.size(); ++i) {
			if (config[i] == goal)
				return true;
		}
		return false;
	}
};

int main(int argc, char *argv[]) {

	if (argc < 3) {
		cout << "Enter valid number of arguments!";
		return -1;
	}

	vector<int> inp;

	for (int i = 2; i < argc; ++i) {
		int t = atoi(argv[i]);
		inp.push_back(t);
	}

	Water aWater(atoi(argv[1]), inp);
	aWater.solve();
	return 0;
}
