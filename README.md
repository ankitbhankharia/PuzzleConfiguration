# PuzzleConfiguration
C++ framework that could solve multiple puzzles

Puzzle Solver:

This is a solver that takes in initial configuration, traverses through the configurations required to reach the final configuration and ultimately reaches the final configuration if at all it is possible.

Algorithm:
Create an initially empty queue of configurations (configQueue)
    Insert the initial configuration into the queue (initial)
    While
      the queue is not empty (configQueue) and
      the first configuration and the last configuration in the queue does not meet the goal,
    loop:
        Take the first element from the next configuration (nextConfig) and check whether it is present in the seen configuration which is a map(visitedConfig).
	If present then go back to the loop.
	If not present then add it to the visited config and also to the queue of configurations(visitedConfig and configQueue).
	And then go back to the loop.
        end-loop.
    end-loop.
    The acceptable configuration is now at the head of the queue.
	
	Now store all the states(starting from final to the initial state) from the seen configuration into a new list(sequence).
    	Display the list

Clock Problem:

It takes in three inputs from the user i.e. total number of hours on a clock, initial time and end time.
The nextConfig method returns all the possible hours that can be reached from the current time i.e. 1 position back and forward.

The solve method takes the next value of hour that can be reached and checks if it already present in the visited time.

If yes then it will go to the next time again.
If not then it will add the current time to the visited time and the configuration queue.

It will keep on doing so till all the configurations are covered or till we find our final time.
It will then store all the hours in a list that are required to reach the final time which is then displayed on the screen.

example:
Total hours - 10
Initial time - 2
Final time - 10

So it will store 2 in the configuration queue.
It will then store 2 in the seen configuration, then check whether we have reached 10 or not.
Since we haven't, it will take next possible configurations i.e. 1 and 3 and store it in next config. It will check whether 1 and 3 are present in visited configuration.
Since we haven't it will store 1 and 3 in visited configuration.
It will again check whether we reached final. Since we haven't, we will take next config of 1 i.e. 10 and 2.
Since 10 is the final time, it means we have reached final configuration.

Now we will start from 2 and keep on storing values in a sequence list until we hit 10.
So the sequence list will now contain 2 1 10.

Now using the display function, we will iterate through the sequence list and display 2 1 10.

Water Problem:

It takes in the quantity of water required as an input along with the size of the containers. It stores all the container sizes into a vector of int.

It then passes the vector to the solve function which checks whether the goal has been met or not. If not then it will store the vector into map of vectors(visitedConfig) and checks the next possible configurations. After getting the next configuration it will check whether the goal has been met or not. If not then again it will store the configurations in the visitedConfig(if not already present in visited config).

The loop will keep on executing till we reach the final configuration.
Once we reach our goal, it will then store all the visited configurations in a vector which is then displayed using the display function.

example:

Final - 4
Containers - 3 5
So first it will start with empty containers. (0 0)
Fill 5 ltr Container. (0 5)
Pour 3ltr from the 5 ltr container into 3 (3 2)
Empty 3 ltr container (0 2)
Pour the 2 ltr from 5 ltr container into 3 (2 0)
Fill 5 ltr container (2 5)
Pour 1 ltr from 5 ltr container into 3 ltr container (3 4)

So we reached our final configuration. Then using the display function we will print all the configurations we visited to reach goal.


Lloyd Problem:

It asks the user whether the initial and final configuration should be read/stored in a file or read/displayed in a stantard way.
This program initially takes in two argumemts.

The name of the input file to read for the initial configuration data. If this name is "-" then the initial configuration data is read from the standard input.

The name of the output file where the solution is to be written. If this name is "-" then the solution is written to the standard output.

It takes in the width, height and the initial configuration. It stores the initial configuration in a vector of char.

It then passes the vector to the solve function which checks whether the goal has been met or not. If not then it will store the vector into map of vectors(visitedConfig) and checks the next possible configurations. After getting the next configuration it will check whether the goal has been met or not. If not then again it will store the configurations in the visitedConfig(if not already present in visited config).

The loop will keep on executing till we reach the final configuration.
Once we reach our goal, it will then store all the visited configurations in a vector which is then displayed using the display function.

example:
width 4 Height 1
Initial  . . x y
Final    x y . .

so first it will pass the initial config to the solve function and check whether the goal has been met.
Since we havent reached our goal, it will pass the current config to nextConfiguration and will return next possible configurations.
So the flow will be as follows:

. . x y
. x . y
x . . y
x . y .
x y . .

So we reached our final configuration. Then using the display function we will print all the configurations we visited to reach goal.


vClock Problem:

It takes any number of inputs(more than 3) from the user i.e. total number of hours on a clock, initial time, end time and additional arguments (which may be positive or negative) that indicate how many hours the clock can be advanced (or set back if negative)..
The nextConfig method returns all the possible hours that can be reached from the current time i.e. ptsition back and forward.

The solve method takes the next value of hour that can be reached and checks if it already present in the visited time.

If yes then it will go to the next time again.
If not then it will add the current time to the visited time and the configuration queue.

It will keep on doing so till all the configurations are covered or till we find our final time.
It will then store all the hours in a list that are required to reach the final time which is then displayed on the screen.

example:
Total hours - 20
Initial time - 2
Final time - 7
Additional argumets - 3,2

So it will store 2 in the configuration queue.
It will then store 2 in the seen configuration, then check whether we have reached 10 or not.
Since we haven't, it will take next possible configurations i.e. 5,4 and store it in next config. It will check whether 5 and 4 are present in visited configuration.
Since we haven't it will store 5 and 4 in visited configuration.
It will again check whether we reached final. Since we haven't, we will take next config of 5 and 4.
From 5 we can reach 8 and 7.
Since 7 is the final time, it means we have reached final configuration.

Now we will start from 2 and keep on storing values in a sequence list until we hit 7.
So the sequence list will now contain 2 5 7.

Now using the display function, we will iterate through the sequence list and display 2 5 7.

