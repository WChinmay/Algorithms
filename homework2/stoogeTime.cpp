//Including necessary libraries
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;    //Namespace declared to shorten code

void stoogeSort(int arr[], int l, int h)
{
		int length = h - l + 1;		//Length will be last index - first index + 1 to account for the zero index
    if (arr[l] > arr[h])			//Swapping first and last elements if first element is bigger than last element
       swap(arr[l], arr[h]);

    if(length > 2)			//If the base case of two elements in the array is not satisfied
    {
        int t = length / 3;			//To break the array up into the "3 stooges"

        stoogeSort(arr, l, h-t);			// Recursively sort first 2/3 elements

        stoogeSort(arr, l+t, h);			// Recursively sort last 2/3 elements

        stoogeSort(arr, l, h-t);			// Recursively sort first 2/3 elements again to confirm
    }
}

int main()
{
	int i;
	srand(time(NULL));		//Seeding random number generator with time

  int array5k[500], array10k[1000], array15k[1500], array20k[2000], array25k[2500], array30k[3000], array35k[3500], array40k[4000], array45k[4500];
  int array50k[5000], array55k[5500], array60k[6000], array65k[6500], array70k[7000];		//Creating arrays for evalauation

  clock_t start, stop;		//Declaring start stops for the timer

	//Populating array with random numbers between 0 and 10,000
  for(i = 0; i < 500; i++){
    array5k[i] = rand() % 10000;
  }
  start = clock();		//Recording time value for start
  stoogeSort(array5k, 0, 500 - 1);		//Sorting using Stooge Sort
  stop = clock();			//Recording time value for stop
  cout << "Size: .5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;		//Using clocks per sec to get time period

  for(i = 0; i < 1000; i++){		//Repeated for all arrays
    array10k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array10k, 0, 1000 - 1);
  stop = clock();
  cout << "Size: 1.0k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 1500; i++){
    array15k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array15k, 0, 1500 - 1);
  stop = clock();
  cout << "Size: 1.5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 2000; i++){
    array20k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array20k, 0, 2000 - 1);
  stop = clock();
  cout << "Size: 2.0k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 2500; i++){
    array25k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array25k, 0, 2500 - 1);
  stop = clock();
  cout << "Size: 2.5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 3000; i++){
    array30k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array30k, 0, 3000 - 1);
  stop = clock();
  cout << "Size: 3.0k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 3500; i++){
    array35k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array35k, 0, 3500 - 1);
  stop = clock();
  cout << "Size: 3.5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 4000; i++){
    array40k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array40k, 0, 4000 - 1);
  stop = clock();
  cout << "Size: 4.0k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 4500; i++){
    array45k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array45k, 0, 4500 - 1);
  stop = clock();
  cout << "Size: 4.5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 5000; i++){
    array50k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array50k, 0, 5000 - 1);
  stop = clock();
  cout << "Size: 5.0k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 5500; i++){
    array55k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array55k, 0, 5500 - 1);
  stop = clock();
  cout << "Size: 5.5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 6000 ; i++){
    array60k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array60k, 0, 6000 - 1);
  stop = clock();
  cout << "Size: 6.0k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 6500; i++){
    array65k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array65k, 0, 6500 - 1);
  stop = clock();
  cout << "Size: 6.5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 7000; i++){
    array70k[i] = rand() % 10000;
  }
  start = clock();
  stoogeSort(array70k, 0, 7000 - 1);
  stop = clock();
  cout << "Size: 7.0k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  return 0;
}
