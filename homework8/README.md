## Description
In the bin packing problem, items of different weights (or sizes) must be packed into a finite number of bins each with the capacity C in a way that minimizes the number of bins used. The decision version of the bin packing problem(deciding if objects will fit into <= kbins) is NP-complete. There is no known polynomial time algorithm to solve the optimization version of the bin packing problem. This homework examines two greedy approximation algorithms to solve the bin packing problem.
> First-Fit:Put each item as you come to it into the first (earliest opened) bin into which it fits. If there is no available bin then open a new bin.

> First-Fit-Decreasing: First sort the items in decreasing order by size, then use First-Fit on the resulting list.


## Details
Name of Program: `bin.cpp`

Author: Chinmay Wadgaonkar

Compilation: Run command "g++ bin.cpp" in terminal
```
g++ bin.cpp
```

Execution: Run command "a.out" in terminal
```
a.out
```

Output: In terminal. Tells you how many bins were used for each algorithm.


Compilation for comparison: Run command "g++ compare.cpp" in terminal
```
g++ compare.cpp
```

Output: Compares the two algorithms, firstFit and firstFitDec and shows which one is more efficient for bin usage


Compilation for extra credit: Run command "g++ binIP.cpp"

Output: 3 files called `testcase1.ltx`, `testcase2.ltx`, `testcase3.ltx`. These files can be imported into LINDO to run integer programming and get the minimum number of bins used.
