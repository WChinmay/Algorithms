// Including necessary libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <fstream>
#include <climits>
#include <list>

using namespace std;    // Namespace declared to shorten code

class Graph     // Class to handle graph operations and data
{
    int **adjacencyMatrix; // graph built using adjacency matrix
    int V; // vertex number

public:
    int **getMatrix()
    {
        return adjacencyMatrix;
    }

    Graph(int V)
    {
        this->V = V; // sets instance V
        adjacencyMatrix = new int*[V]; // creating 2D array for AM
        for(int i = 0; i < V; i++)
        {
            adjacencyMatrix[i] = new int[V];
        }

        for(int u = 0; u < V; u++)
        {
            for(int v = 0; v < V; v++)
            {
                adjacencyMatrix[u][v] = 0; // intializing AM
            }
        }
    }

    ~Graph()
    {
        for (int i = 0; i < V; i++)
        {
            delete [] adjacencyMatrix[i]; // deleting 2D part
        }
        delete [] adjacencyMatrix; // deleting pointer
    }

    void edgeExists(int u, int v)
    {
        adjacencyMatrix[u][v] = 1; //if rivalry exists
    }

    bool bipartiteRunner(int **Graph, int *wrestlerArray)
    {
        // -1 no assignment
        // 1 babyface
        // 0 heels
        for(int i = 0; i < V; i++)
        {
            wrestlerArray[i] = -1;
        }

        // Cycle through all vertices
        for(int i = 0; i < V; i++)
        {
            if(wrestlerArray[i] == -1) // if not assigned to babyface or heels
            {
                if(isBipartite(Graph, i, wrestlerArray) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(int **Graph, int source, int wrestlerArray[])
    {
        wrestlerArray[source] = 1; // babyface assignment to first wrestler

        queue <int> q; // queue to run Breadth first search
        q.push(source);

        // BFS algorithm
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            if(Graph[curr][curr] == 1)
            {
               return false;    // not bipartite if same team for both vertices
            }

            for(int x = 0; x < V; x++)    //Checking for bipartiteness, i.e. split into 2
            {
                if(Graph[curr][x] && wrestlerArray[x] == -1)
                {
                    wrestlerArray[x] = 1 - wrestlerArray[curr]; // assigning alternate state
                    q.push(x);
                }
                // if rivalry is between 2 of the same
                else if(Graph[curr][x] && wrestlerArray[x] == wrestlerArray[curr])
                    return false; // means can't be bipartite
            }
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // check for inputfile being included.
        cout << "Please enter infile file name after executable" << endl;
    }
    else
    {
        ifstream infile(argv[1]);   // Open file passed in
        int numWrestlers = 0, numRivalries = 0, n = 0, v = 0;
        vector<string> babyfaces; // all the babyfaces
        vector<string> heels; // all the heels
        string wrestlerA, wrestlerB;    //Strings for the two inputs on one line for rivalry

        if(infile.good())
        {
            infile >> numWrestlers; // number of wrestlers
            int wrestlerArray[numWrestlers]; // make array of vertices
            string nameArray[numWrestlers]; // names of wrestlers
            for(int i = 0; i < numWrestlers; i++)
            {
                infile >> nameArray[i]; // reads in the names from infile
            }

            Graph wrestlersGraph(numWrestlers); // Graph object
            infile >> numRivalries; // number of rivalries to take in

            // the for loop will run for numRivalries amound of times
            for(int i = 0; i < numRivalries; i++)
            {
                infile >> wrestlerA; // wrestlerA
                infile >> wrestlerB; // wrestlerB

                for(int j = 0; j < numWrestlers; j++)
                {
                    if(wrestlerA == nameArray[j]) // Check whether nameArray[j] matches wrestlerA or B
                        n = j;              // assign the vertex to the adjacencyMatrix
                    else if(wrestlerB == nameArray[j])
                        v = j;
                }
                wrestlersGraph.edgeExists(n, v); // add the edge to the graph
                wrestlersGraph.edgeExists(v, n); // add tabular opposite to make complemetary graph
            }

            if(wrestlersGraph.bipartiteRunner(wrestlersGraph.getMatrix(), wrestlerArray))
            {
                for(int i = 0; i < numWrestlers; i++)
                {
                    if(wrestlerArray[i] == 1)   //Push into specific array based on whethr baby face or heel
                    {
                        babyfaces.push_back(nameArray[i]);
                    }
                    else if(wrestlerArray[i] == 0)
                    {
                        heels.push_back(nameArray[i]);
                    }
                }
                cout << "Yes possible" << endl;
                cout << "Babyfaces: " ;
                // print all the baby faces
                for(int i = 0; i < babyfaces.size(); i++)
                    cout << babyfaces[i] << " ";
                cout << endl;
                cout << "Heels: " ;
                // print all the heels
                for(int i = 0; i < heels.size(); i++)
                    cout << heels[i] << " ";
                cout << endl;
            }
            else
                cout << "IMPOSSIBLE" << endl;   // if not bipartite, print IMPOSSIBLE
        }
    }
    return 0;
}
