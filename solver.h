// File: $Id: solver.h, v 3.0 2014/11/25
// Author: Avi Bhagat
// Author: Ankit Bhankharia
// Description: Puzzle solver framework

#ifndef SOLVER_H
#define SOLVER_H
#include <queue>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <stdlib.h>

using namespace std;

/* Name: Solver
 * 
 * Description: It has two function. nexConfig() calculates the next possible config of
 * the puzzle and returns it as vector<int>.
 */

template<class T>
class Solver {
public:
	/*
	 * This methhod will be overriden by the individual solver to
	 * implement in their own way
	 */
	virtual vector<T> nextConfig(T config) = 0;

	/*
	 * This methhod will be overriden by the individual solver to
	 * implement in their own way
	 */
	virtual void display(vector<T> finalList, ostream &os) = 0;

	/*
	 * This methhod will be overriden by the individual solver to
	 * implement in their own way
	 */
	virtual bool isSolved(T config) = 0;

	/* Name: solve
	 *
	 * Description: Function that solves a puzzle using the breadth-first algorithm
	 *				to go through all the possibilities that lead to the goal
	 * Arguments: number, is the number of states
	 *			  initial, the initial state of puzzle
	 *			  final, the final state of puzzle
	 * Returns: sequence that solves the puzzle or problem
	 */

	vector<T> solve(T initial) {

		//the final sequence after the puzzle is solved
		vector<T> sequence;

		//to store the state at each step
		queue<T> configQueue;

		//to mark the configuration we have visited
		map<T, T> visitedConfig;
		T goal;

		//marking the initial configuration
		configQueue.push(initial);

		//marking the initial configuration as seen
		visitedConfig[initial] = initial;

		while (!configQueue.empty() && !isSolved(goal = configQueue.front())) {

			//analyzing the configuration from the queue
			T config = configQueue.front();
			configQueue.pop();

			//getting the next configuration from current configuration
			vector<T> nextConfigurations = nextConfig(config);

			for (int i = 0; i < nextConfigurations.size(); ++i) {
				bool hasTheConfigurationBeenSeen = visitedConfig.find(
						nextConfigurations[i]) != visitedConfig.end();

				if (!hasTheConfigurationBeenSeen) {
					// enqueuing the config
					configQueue.push(nextConfigurations[i]);

					// Mark the config as seen
					visitedConfig[nextConfigurations[i]] = config;
				}
			}
		}

		// If the goal has been reached then it pushes the
		// state values in proper sequence.

		if (isSolved(goal)) {
			T config = goal;
			while (config != initial) {
				sequence.push_back(config);
				config = visitedConfig[config];
				//cout << sequence[config];
			}
			sequence.push_back(initial);
		}
		else {
			cout << "No solution exists";
			exit(0);
		}
		reverse(sequence.begin(), sequence.end());
		return sequence;
	}

};
#endif
