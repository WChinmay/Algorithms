#include <iostream>       // Include necessary libraries
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <time.h>

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
  srand (time(NULL));       // Seeding random with time
  cout<<"============PART C============"<<endl;
  int ties = 0, wins = 0;       // Initialize ties and wins counters to 0
  for(int i = 0;i < 500;i++)      // Loop through 500 times for preciseness
  {
    int capacity = rand()%10 + 1;     // Capcity between 1 and 10 randomized
    int numberOfItems = rand()%100 + 1;       // numberOfItems between 1 and 100 randomized
    int items[numberOfItems];       // Array of items to be packed into bins
    int numBinfF, numBinfFD, a;       // Number of bins used for each algorithm
    for(int x = 0;x < numberOfItems;x++)      // Fill up items with randomized weights less than capacity
    {
      a = rand()%capacity;
      items[x] = a;
    }
    numBinfF = firstFit(items, numberOfItems, capacity);      // Call First Fit
    numBinfFD = firstFitDec(items, numberOfItems, capacity);    // Call First Fit Decreasing
    if(numBinfF == numBinfFD)
    {
      ties++;     // Incrementing ties counter if both use same number of bins
    }
    else if(numBinfFD < numBinfF)
    {
      wins++;     // Incrementing if FirstFitDecreasing working better than FirstFit
    }
  }

  cout<<"firstFitDec was more efficient: "<< wins << " out of 500 times."<<endl;
  cout<<"It was a tie: "<< ties << " out of 500 times."<<endl;

  ties = 0;
  wins = 0;
  return 0;
}
