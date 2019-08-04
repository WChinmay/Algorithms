#include <iostream>       // Include necessary libraries
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;      // Using namespace for readable code

int firstFit(int weight[], int numberOfItems, int capacity)
{
    int numberOfBinsUsed = 0;     // Initialize to 0
    int spaceInBins[numberOfItems];     // for how much space is left in each bin

    for (int i = 0; i < numberOfItems; i++)     // Storing items
    {
        int j;
        for (j = 0; j < numberOfBinsUsed; j++)      // Searching for viable bin with enough space
        {
            if (spaceInBins[j] >= weight[i])
            {
                spaceInBins[j] = spaceInBins[j] - weight[i];
                break;
            }
        }

        if (j == numberOfBinsUsed)
        {
            spaceInBins[numberOfBinsUsed] = capacity - weight[i];
            numberOfBinsUsed++;       // Create a new bin if none of the created bins have enough space
        }
    }
    return numberOfBinsUsed;
}

/* Function to sort an array using insertion sort*/
void insertionSort (int arr[], int length)
{
	 	int c, temp;

    for (int i = 0; i < length; i++)     //Looping through each element in the array
    {
		    c = i;

		while (c > 0 && arr[c] > arr[c-1])      //Check if unsorted, based on whether previous element is smaller since the left side should always be sorted
    {
			  temp = arr[c];
			  arr[c] = arr[c-1];   //Cascade through till the element has been placed in its right spot, relies on left half being sorted
			  arr[c-1] = temp;
			  c--;   //Consider previous element for same cycle
			  }
		}
}

int firstFitDec(int items[], int numberOfItems, int capacity)
{
    insertionSort(items, numberOfItems);     // Sort the numberOfItems in decreasing order
    return firstFit(items, numberOfItems, capacity);      // Call function to binpack using first algorithm
}

int main()
{
    ifstream infile;
    infile.open("bin.txt");
    int capacity, numberOfItems, numberOfTestCases;

    infile >> numberOfTestCases; // numberOfTestCases the loop iterations

    // loop goes for the number of Test Cases there
    for ( int i = 0; i < numberOfTestCases; i++)
    {

        infile >> capacity; // states the capacity for current set
        infile >> numberOfItems; // states the numberOfItems amount
        int items[numberOfItems]; // create an array numberOfItems sized big.

        //loop goes to fill up the items array
        for ( int j = 0; j < numberOfItems; j++)
        {
            infile >> items[j];
        }

        // calling the firstFit and firstFitDec function

        cout << "Test Case " << i + 1;
        cout << " First Fit : " << firstFit(items, numberOfItems, capacity);
        cout << " - First Fit Decreasing : " << firstFitDec(items, numberOfItems, capacity) << endl;

    }

    return 0;
}
