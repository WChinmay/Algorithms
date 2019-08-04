//Including necessary libraries
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;    //Namespace declared to shorten code

void insertionSort (int arr[], int length){
	 	int c, temp;

	for (int i = 0; i < length; i++){    //Looping through each element in the array
		c = i;

		while (c > 0 && arr[c] < arr[c-1]){   //Check if unsorted, based on whether previous element is bigger since the left side should always be sorted
			  temp = arr[c];
			  arr[c] = arr[c-1];   //Cascade through till the element has been placed in its right spot, relies on left half being sorted
			  arr[c-1] = temp;
			  c--;   //Consider previous element for same cycle
			  }
		}
}

int main()
{
  ifstream infile("data.txt");    //Initialize input file stream with file and open
  ofstream outfile("sortedInsert.txt");    //Initialzie output file stream with path and open
int size;   //size of each line in input file
while(!infile.eof())    //Loops till end of lines
{
  size = 0;   //Initialize size, necessary to prevent last line of garbage values
  infile >> size;   //Get size as first number from line
  int intArray[size];   //Create array of proper size
  for(int i = 0; i < size; i++)
  {
    infile >> intArray[i];    //Populate array with numbers on the line
  }
  insertionSort(intArray, size);   //Sort line using Insertion Sort
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
