// File: $Id: water.cpp, v 1.0 2014/11/25
// Author: Avi Bhagat
// Author: Ankit Bhankharia
// Description: Lloyd puzzle problem solver

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "solver.h" // Including the framework
using namespace std;

class Lloyd: public Solver<vector<char> > {

	// width of every row
	int width;
	// height of every column
	int height;
	// input puzzle is stored in a vector
	vector<char> input;
	// output puzzle is stored in a vector
	vector<char> goal;

public:

	// Parameterized constructor
	Lloyd(int width, int height, vector<char> input, vector<char> goal) :
			width(width), height(height), input(input), goal(goal) {
	}

	/* Name: getNextConfig
	 *
	 * Description:	get all the configurations that can be reached from
	 * 				a given configuration. In this case it will find the
	 * 				blank space where bordering block can be moved
	 * Arguments:	vector<char> conf this is the current puzzle
	 * 				configuration.
	 * Returns:		vector<vector<char> > nextConfig, the new configuration
	 * 				that can be achieved from current configuration.
	 */
	vector<vector<char> > nextConfig(vector<char> conf) {
		vector<vector<char> > nextConfig;
		vector<char> tempConf;
		int currentPosition = 0;
		char tempCharacter;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				tempConf = conf;
				// checks if the block on the right is empty.
				// if yes it will swap
				if (j + 1 <= width && tempConf[currentPosition + 1] == '.') {
					tempCharacter = tempConf[currentPosition];
					tempConf[currentPosition] = tempConf[currentPosition + 1];
					tempConf[currentPosition + 1] = tempCharacter;
					// swapped config is pushed into nextConfig
					nextConfig.push_back(tempConf);
				}
				tempConf = conf;
				// checks if the block on the left is empty.
				// if yes it will swap
				if (j - 1 >= 0 && tempConf[currentPosition - 1] == '.') {
					tempCharacter = tempConf[currentPosition];
					tempConf[currentPosition] = tempConf[currentPosition - 1];
					tempConf[currentPosition - 1] = tempCharacter;
					// swapped config is pushed into nextConfig
					nextConfig.push_back(tempConf);
				}
				tempConf = conf;
				// checks if the block exactly below is empty.
				// if yes it will swap
				if (i + 1 <= height
						&& tempConf[currentPosition + width] == '.') {
					tempCharacter = tempConf[currentPosition];
					tempConf[currentPosition] =
							tempConf[currentPosition + width];
					tempConf[currentPosition + width] = tempCharacter;
					// swapped config is pushed into nextConfig
					nextConfig.push_back(tempConf);
				}
				tempConf = conf;
				// checks if the block exactly above is empty.
				// if yes it will swap
				if (i - 1 >= 0 && tempConf[currentPosition - width] == '.') {
					tempCharacter = tempConf[currentPosition];
					tempConf[currentPosition] =
							tempConf[currentPosition - width];
					tempConf[currentPosition - width] = tempCharacter;
					// swapped config is pushed into nextConfig
					nextConfig.push_back(tempConf);
				}
				++currentPosition;
			}
		}
		return nextConfig;
	}

	/* Name: solve
	 *
	 * Description:	calls the solve() of class Solver to solve the puzzle.
	 */
	void solve(ostream &os) {
		vector<vector<char> > result = Solver::solve(input);
		display(result, os);
	}

	/* Name: display
	 *
	 * Description:	displays the sequence of configurations from start to end
	 * Arguments:	vector<vector<char> > v is the sequence of configuration
	 *				we want to display.
	 */
	void display(vector<vector<char> > v, ostream &os) {
		os << "The sequence of Lloyd puzzle " << ":" << endl;

		int count = 0;
		for (int i = 0; i < v.size(); ++i) {
			for (int j = 0; j < v[i].size(); j++) {
				++count;
				if (count > width) {
					os << endl;
					count = 1;
				}
				os << (v[i])[j] << " ";
			}
			count = 0;
			os << endl;
			os << endl;
		}
	}

	/* Name: isSolved
	 *
	 * Description:	returns true is the goal is reached.
	 * Arguments:	vector<char> config, to check for goal.
	 * Returns:		bool, true if goal is reached else it returns false.
	 */
	bool isSolved(vector<char> config) {
		if (config == goal) {
			return true;
		}
		return false;
	}

};


int main(int argc, char *argv[]) {
	if (argc != 3) {
		cerr << "2 args only" << endl;
	} else {
		istream *isp;
		ifstream ifs;
		ostream *osp;
		ofstream ofs;

		if (argv[1][0] == '-' && argv[1][1] == '\0') {
			isp = &cin;
		} else {
			ifs.open(argv[1]);
			isp = &ifs;
		}
		istream &is = *isp;

		if (argv[2][0] == '-' && argv[2][1] == '\0') {
			osp = &cout;
		} else {
			ofs.open(argv[2]);
			osp = &ofs;
		}
		ostream &os = *osp;

		int width, height;
		is >> width >> height;
		vector<char> initial;
		vector<char> final;
		char character;

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				// takes the input and pushes it into the vector<char>
				is >> character;
				initial.push_back(character);
			}
		}

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				is >> character;
				// takes the goal and pushes it into the vector<char>
				final.push_back(character);
			}
		}

		Lloyd llyod(width, height, initial, final);
		llyod.solve(os);

	}
	return 0;
}

