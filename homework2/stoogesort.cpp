//Including necessary libraries
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;    //Namespace declared to shorten code

// Function to implement stooge sort, logic partially borrowed from https://www.geeksforgeeks.org/cpp-program-for-stooge-sort/
void stoogeSort(int arr[], int l, int h)
{
		if(l >= h)			//Exit condition when array is done sorting
			return;
		int length = h - l + 1;		//Length will be last index - first index + 1 to account for the zero index
    if (arr[l] > arr[h])			//Swapping first and last elements if first element is bigger than last element
       swap(arr[l], arr[h]);

    if(length > 2)			//If the base case of two elements in the array is not satisfied
    {
        int t = ceil(length / 3);			//To break the array up into the "3 stooges"

        stoogeSort(arr, l, h-t);			// Recursively sort first 2/3 elements

        stoogeSort(arr, l+t, h);			// Recursively sort last 2/3 elements

        stoogeSort(arr, l, h-t);			// Recursively sort first 2/3 elements again to confirm
    }
}

int main()
{
  ifstream infile("data.txt");    //Initialize input file stream with file and open
  ofstream outfile("sortedStooge.txt");    //Initialzie output file stream with path and open
int size;   //size of each line in input file
while(!infile.eof())    //Loops till end of lines
{
  size = 0;   //Initialize size, necessary to prevent last line of garbage values
  infile >> size;   //Get size as first number from line
  int intArray[(int)size];   //Create array of proper size
  for(int i = 0; i < size; i++)
  {
    infile >> intArray[i];    //Populate array with numbers on the line
  }
  stoogeSort(intArray, 0, size - 1);   //Sort line using Insertion Sort
  for(int i = 0; i < size; i++)
  {
    outfile << intArray[i];   //Print out sorted numbers in output file
    outfile << " ";
  }
  outfile << endl;    //Move to new line in output file for new line of numbers from input file
}

  if(infile.is_open())    //Closing both input and output files if they are open
      infile.close();
  if(outfile.is_open())
      outfile.close();

    return 0;
}
