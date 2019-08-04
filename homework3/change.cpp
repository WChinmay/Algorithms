// Including necessary libraries
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;			// Namespace declared to shorten code

/*In function:
							 coins is the array of denominations
							 m is the size of the array of denominations
							 V is the value of the money that change is requested for
							 outfile is the output file stream passed as a reference
*/
int minCoins(vector<int> &coins, int m, int V, ofstream& outfile)
{
	int lookupTable[V+1];				// lookupTable[i] stores the best possible change combination
	int result[V+1];			// result[i] stores the value at all the indices to loop back through for all the coins used

	// Base case
	lookupTable[0] = 0;

	// Initialize the lookupTable values to be the maximum value an integer can hold
	for (int i=1; i<=V; i++)
	{
		lookupTable[i] = INT_MAX;
		result[i]= -1;			//result -1 indicates the absence of a possible combination
	}

	// Calculating the minimum number of coins for all lookupTable spots from 1 to V (value provided by user)
	for (int i=1; i<=V; i++)
	{
		for (int j=0; j<m; j++)				// Looping through all the various denominations possible
		if (coins[j] <= i)
		{
			// Finding minimum number of coins for each spot up to V
			if (lookupTable[i] > 1 + lookupTable[i-coins[j]])
			{
				lookupTable[i] = 1 + lookupTable[i-coins[j]];
				result[i] = j;
			}
		}
	}
	if (result[V] == -1)				// This indicates that the coins couldn't be calculated
	{
		outfile << "Error\n" << endl;
	}
	else
	{
		// To find the number of each coin denomination used to get the desired value
		int counter = V;			// Counter to pace through the coins used for minimum number of coins
		int C[m];				// An array to hold the number of each coin used
		for(int a = 0; a < m; a++)
		{
			C[a] = 0;				// The number of times each coin is used is set as 0
		}
		while(counter != 0)				// Cycle through till only 0 is left
		{
			int j = result[counter];
			C[j]++;												// Increment number for whichever coin was used in the array, mathces up with coinArray
			counter = counter - coins[j];			// Deduct value of the coin just used
		}
		for(int a = 0; a < m; a++)
		{
			outfile << coins[a] << " ";				// Print the coins passed in to the function to be displayed on the output file
		}
		outfile << endl;
		outfile << V << endl;								// Print the value desired by the user to output file
		for(int a = 0; a < m; a++)
		{
			outfile << C[a] << " ";						// Print the number of each coin used to attain the value while keeping the total number of coins at a minimum
		}
		outfile << endl;
	}
	return lookupTable[V];					// Return the minimum number of coins required for that value as passed by the user
}

// Driver program to test above function
int main()
{
	ifstream infile("amount.txt");    // Initialize input file stream with file and open
	ofstream outfile("change.txt");    // Initialzie output file stream with path and open
	int a;			// To use for input elements
	string line;			// Will hold a line in the input file
	vector<int>coinArray;					//Vector array of the coins usable

	while(!infile.eof())				// Parsing till end of file
	{
			getline(infile,line);
			istringstream converter(line);			// Break line along whitespace
			while(converter >> a)
			{
				coinArray.push_back(a);				// Push all input coin denomiantions into array
			}

			getline(infile, line);				// Get second line
			istringstream converterr(line);				// Get first element (number) till first whitespace
			converterr >> a;
			outfile << minCoins(coinArray, coinArray.size(), a, outfile) << endl;			// Pass vector array of coins, size of vector, the value to attain and reference to output file
			coinArray.clear();			//Flush the vector to be reused again
	}

	if(infile.is_open())    // Closing both input and output files if they are open
			infile.close();
	if(outfile.is_open())
			outfile.close();

	return 0;
}
