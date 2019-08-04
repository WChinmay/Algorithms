//Including Libraries
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

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
  ifstream infile("data.txt");    //Initialize input file stream with file and open
  ofstream outfile("sortedMerge.txt");    //Initialzie output file stream with path and open
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
  mergeSort(intArray, 0, size-1);   //Sort line using Merge Sort
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
