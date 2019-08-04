// Including necessary libraries
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;			// Namespace declared to shorten code

void optimalActivities(vector<int>startTimes, vector<int>stopTimes, vector<int>activityNumber, int n, vector<int>&result)
{
  int i = 0;
  result.push_back(activityNumber[i]);      //First activity will start the optimal since it is pre-sorted

  for(int j = 1; j < n; j++)
  {
    if(stopTimes[j] <= startTimes[i])      //If the stop time for activity being considered is before the start time of the previous activity
    {
      result.push_back(activityNumber[j]);
      i = j;
    }
  }
}


void insertionSort (vector<int>&arr, int length, vector<int>&stopTimes, vector<int>&activityNumber){
	 	int c, temp;

	for (int i = 0; i < length; i++){    //Looping through each element in the array
		c = i;

		while (c > 0 && arr[c] > arr[c-1]){   //Check if unsorted, based on whether previous element is smaller since the left side should always be sorted
			  temp = arr[c];
			  arr[c] = arr[c-1];   //Cascade through till the element has been placed in its right spot, relies on left half being sorted
			  arr[c-1] = temp;

        temp = stopTimes[c];
        stopTimes[c] = stopTimes[c-1];   //Follow through for stop times
        stopTimes[c-1] = temp;

        temp = activityNumber[c];
        activityNumber[c] = activityNumber[c-1];   //Follow through for activity number
        activityNumber[c-1] = temp;

			  c--;   //Consider previous element for same cycle
			  }
		}
}


// Driver program to test above function
int main()
{
	ifstream infile("act.txt");    // Initialize input file stream with file and open
	ofstream outfile("Activities.txt");    // Initialzie output file stream with path and open
	int a;			// To use for input elements
  int b;      //To use for input elements
  int setCounter = 0;       //Counter for nth set
	string line;			// Will hold a line in the input file
	vector<int>startTimes;					//Vector array of the start times
  vector<int>stopTimes;					//Vector array of the stop times
  vector<int>activityNumber;					//Vector array of the Activities
  vector<int>result;					//Vector array of optimal activities in order from fn OptimalActivities

	while(!infile.eof())				// Parsing till end of file
	{
      setCounter++;
      outfile << "Set " << setCounter << endl;
      getline(infile, line);				// Get first line
			istringstream converter(line);				// Get first element (number) till first whitespace
			converter >> b;
      int i;
      for(i = 0; i < b; i++)
      {
        getline(infile, line);      //Get next line
        istringstream converterr(line);				// Get first element (number) till first whitespace
        converterr >> a;       //Break line along white space
        activityNumber.push_back(a);    //Insert element into activityNumber vector
        converterr >> a;       //Break line along white space
        startTimes.push_back(a);       //Insert start time into vector
        converterr >> a;       //Break line along white space
        stopTimes.push_back(a);       //Insert stop time into vector
      }

      insertionSort(startTimes, startTimes.size(), stopTimes, activityNumber);      //Sort in descending order of start times

      optimalActivities(startTimes, stopTimes, activityNumber, activityNumber.size(), result);     //Get the vector of optimal activites in result

      outfile  << "Number of activities selected = " << result.size() << endl;

      outfile << "Activities: ";
      reverse(result.begin(), result.end());      //Reversing for chronological order
      for(int i = 0; i < result.size(); i++)
      {
        outfile << result[i] << " ";        //Printing out the activities
      }
      outfile << endl << endl;      //Leaving a line of space for organization

			startTimes.clear();			//Flush the vector to be reused again
      stopTimes.clear();			//Flush the vector to be reused again
      activityNumber.clear();			//Flush the vector to be reused again
      result.clear();			//Flush the vector to be reused again
	}

	if(infile.is_open())    // Closing both input and output files if they are open
			infile.close();
	if(outfile.is_open())
			outfile.close();

	return 0;
}
