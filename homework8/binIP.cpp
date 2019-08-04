#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main () {
  fstream inFile;                            //Creates a name for opening my datafile named inFile
  inFile.open("binEC.txt");                   //opens data.txt

  int testCases;
  ofstream outFile;

  string filename;
  int fileNumCounter = 1;

  ostringstream converter;

  int capacity;
  int numberOfItems;

  vector<int>items;
  int a;
  //This while loop goes through the data file and pushes the values onto my vector while there is a integer that exists in the file
  inFile>>a;

  testCases = a;

  int answer1;
  int answer2;
  int g = 1;

  string fileNameStart = "testcase";
  string fileExtension = ".ltx";

  while (inFile >> a)
  {
    capacity = a;
    inFile >> a;
    numberOfItems = a;
    for(int i =0;i < numberOfItems;i++)
    {
      inFile >> a;
      items.push_back(a);
    }

    for(int i =0; i<numberOfItems;i++)
    {
      outFile << items[i] << " ";
    }
    outFile << endl;
    items.clear();
    g++;

    fileNameStart = "testcase";
    fileExtension = ".ltx";
    converter << fileNumCounter;
    string filenumber = converter.str();
    filename = fileNameStart + filenumber+ fileExtension;

    converter.str("");
    converter.clear();

    outFile.open(filename.c_str());

    outFile << "min     ";
    for(int i = 1;i <= numberOfItems;i++)
    {
      if(i != numberOfItems)
      {
        outFile<<"Y" << i << " + ";
      }
      else
      outFile << "Y" << i;
    }
    outFile << endl << endl;
    outFile << "ST" << endl;
    outFile << "     ";
    for(int i = 1;i <= numberOfItems;i++)
    {
      if(i != numberOfItems)
      {
        outFile << "Y" << i << " + ";
      }
      else
      outFile << "Y" << i;
    }
    outFile << " >= 1" << endl;
    outFile << endl << endl;

    for(int i=1;i<=numberOfItems;i++)
    {
      outFile<<"     ";
      for(int j =1;j<=numberOfItems;j++)
      {
        if(j != numberOfItems)
        {
          outFile << items[j-1] << "X" << i << j << " + ";
        }
        else
        {
          outFile << items[j-1] << "X" << i << j << " -" << capacity << "Y" << i << "  <= 0";
        }
      }
      outFile << endl;
    }
    outFile << endl << endl;

    for(int i=1;i<=numberOfItems;i++)
    {
      outFile<<"    ";
      for(int j = 1;j <= numberOfItems;j++)
      {
        if(j != numberOfItems)
        {
          outFile << "X" << j << i << " + ";
        }
        else
        {
          outFile << "X" << j << i;
        }
      }
      outFile << "   = " << 1 << endl;
    }

    outFile << endl << endl;

    for(int i=1;i<=numberOfItems;i++)
    {
      outFile << "    " << "Y" << i << " >= 0" << endl;
    }
    outFile<<endl<<endl;
    for(int i=1;i<=numberOfItems;i++){
      outFile<<"    "<<"Y"<<i<<" <= 1"<<endl;
    }
    outFile << endl << endl;
    for(int j = 1;j<=numberOfItems;j++)
    {
      for(int i =1; i<=numberOfItems;i++)
      {
        outFile << "    " << "X" << j << i << "  >= 0  " << endl;
      }
      outFile << endl << endl;
    }

    for(int j = 1;j<=numberOfItems;j++)
    {
      for(int i =1; i<=numberOfItems;i++)
      {
        outFile << "    " << "X" << j << i << "  <= 1  " << endl;
      }
      outFile << endl << endl;
    }

    outFile << endl;
    outFile << "END" << endl << endl;

    for(int i =1;i<=numberOfItems;i++)
    {
      outFile << "   GIN Y" << i << endl;
    }
    outFile << endl;
    for(int j = 1;j<=numberOfItems;j++)
    {
      for(int i =1; i<=numberOfItems;i++)
      {
        outFile << "   GIN X" << j << i << endl;
      }
      outFile << endl << endl;
    }

    fileNumCounter++;
    outFile.close();
  }


}
