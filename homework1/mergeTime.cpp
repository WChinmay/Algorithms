//Including Libraries
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>

//Namespace declared to shorten code
using namespace std;

//This function merge combines two sorted arrays
void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;   //Size of the 1st half of the array
    int n2 =  right - mid;    //Size of the second half of the array

    /* Left and right holders */
    int leftHalf[n1], rightHalf[n2];

    /* Populating holder arrays */
    for (i = 0; i < n1; i++)
    {
        leftHalf[i] = array[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        rightHalf[j] = array[mid + 1 + j];
    }

    /* Choosing the smallest of the two arrays to put into the merged array */
    int a = 0;    // Counter for first array
    int b = 0;    // Counter for second array
    int c = left;     // Counter for merged subarray
    while (a < n1 && b < n2)
    {
        if (leftHalf[a] <= rightHalf[b])
        {
            array[c] = leftHalf[a];
            a++;
        }
        else
        {
            array[c] = rightHalf[b];
            b++;
        }
        c++;
    }

    /* Inserting leftovers from leftHalf */
    while (a < n1)
    {
        array[c] = leftHalf[a];
        a++;
        c++;
    }

    /* Inserting leftovers from rightHalf */
    while (b < n2)
    {
        array[c] = rightHalf[b];
        b++;
        c++;
    }
}

/* Recursive function to sort the array, takes array, left index and right index */
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left+right)/2;   //Calculates middle index

        mergeSort(array, left, mid);    //Recursively sort left halves
        mergeSort(array, mid+1, right);   //Recursively sort right halves

        merge(array, left, mid, right);   //Join concurrent right and left halves in proper ascending order
    }
}

int main()
{
  int i;
  srand(time(NULL));    //Seeding random number generator with time

  int array5k[5000], array10k[10000], array15k[15000], array20k[20000], array25k[25000], array30k[30000], array35k[35000], array40k[40000], array45k[45000];
  int array50k[50000], array55k[55000], array60k[60000], array65k[65000], array70k[70000];    //Creating arrays for evalauation

  clock_t start, stop;    //Declaring start stops for the timer

  //Populating array with random numbers between 0 and 10,000
  for(i = 0; i < 5000; i++){
    array5k[i] = rand() % 10000;
  }
  start = clock();    //Recording time value for start
  mergeSort(array5k, 0, 5000-1);    //Sorting using Insertion Sort
  stop = clock();     //Recording time value for stop
  cout << "Size: 5k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;    //Using clocks per sec to get time period

  for(i = 0; i < 10000; i++){   //Repeated for all arrays
    array10k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array10k, 0, 10000-1);
  stop = clock();
  cout << "Size: 10k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 15000; i++){
    array15k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array15k, 0, 15000-1);
  stop = clock();
  cout << "Size: 15k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 20000; i++){
    array20k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array20k, 0, 20000-1);
  stop = clock();
  cout << "Size: 20k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 25000; i++){
    array25k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array25k, 0, 25000-1);
  stop = clock();
  cout << "Size: 25k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 30000; i++){
    array30k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array30k, 0, 30000-1);
  stop = clock();
  cout << "Size: 30k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 35000; i++){
    array35k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array35k, 0, 35000-1);
  stop = clock();
  cout << "Size: 35k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 40000; i++){
    array40k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array40k, 0, 40000-1);
  stop = clock();
  cout << "Size: 40k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 45000; i++){
    array45k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array45k, 0, 45000-1);
  stop = clock();
  cout << "Size: 45k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 50000; i++){
    array50k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array50k, 0, 50000-1);
  stop = clock();
  cout << "Size: 50k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 55000; i++){
    array55k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array55k, 0, 55000-1);
  stop = clock();
  cout << "Size: 55k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 60000; i++){
    array60k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array60k, 0, 60000-1);
  stop = clock();
  cout << "Size: 60k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 65000; i++){
    array65k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array65k, 0, 65000-1);
  stop = clock();
  cout << "Size: 65k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  for(i = 0; i < 70000; i++){
    array70k[i] = rand() % 10000;
  }
  start = clock();
  mergeSort(array70k, 0, 70000-1);
  stop = clock();
  cout << "Size: 70k       Time: " << (stop-start)/(CLOCKS_PER_SEC/1000) << " milliseconds." << endl;

  return 0;
}
