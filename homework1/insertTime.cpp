//Including necessary libraries
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>

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
	int i;
	srand(time(NULL));		//Seeding random number generator with time

  int array5k[5000], array10k[10000], array15k[15000], array20k[20000], array25k[25000], array30k[30000], array35k[35000], array40k[40000], array45k[45000];
  int array50k[50000], array55k[55000], array60k[60000], array65k[65000], array70k[70000];		//Creating arrays for evalauation

  clock_t start, stop;		//Declaring start stops for the timer

	//Populating array with random numbers between 0 and 10,000
  for(i = 0; i < 5000; i++){
    array5k[i] = rand() % 10000;
  }
  start = clock();		//Recording time value for start
  insertionSort(array5k, 5000);		//Sorting using Insertion Sort
  stop = clock();			//Recording time value for stop
  cout << "Size: 5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;		//Using clocks per sec to get time period

  for(i = 0; i < 10000; i++){		//Repeated for all arrays
    array10k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array10k, 10000);
  stop = clock();
  cout << "Size: 10k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 15000; i++){
    array15k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array15k, 15000);
  stop = clock();
  cout << "Size: 15k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 20000; i++){
    array20k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array20k, 20000);
  stop = clock();
  cout << "Size: 20k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 25000; i++){
    array25k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array25k, 25000);
  stop = clock();
  cout << "Size: 25k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 30000; i++){
    array30k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array30k, 30000);
  stop = clock();
  cout << "Size: 30k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 35000; i++){
    array35k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array35k, 35000);
  stop = clock();
  cout << "Size: 35k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 40000; i++){
    array40k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array40k, 40000);
  stop = clock();
  cout << "Size: 40k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 45000; i++){
    array45k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array45k, 45000);
  stop = clock();
  cout << "Size: 45k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 50000; i++){
    array50k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array50k, 50000);
  stop = clock();
  cout << "Size: 50k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 55000; i++){
    array55k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array55k, 55000);
  stop = clock();
  cout << "Size: 55k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 60000; i++){
    array60k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array60k, 60000);
  stop = clock();
  cout << "Size: 60k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 65000; i++){
    array65k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array65k, 65000);
  stop = clock();
  cout << "Size: 65k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 70000; i++){
    array70k[i] = rand() % 10000;
  }
  start = clock();
  insertionSort(array70k, 70000);
  stop = clock();
  cout << "Size: 70k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  return 0;
}
