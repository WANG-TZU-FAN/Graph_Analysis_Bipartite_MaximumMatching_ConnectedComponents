# Graph_Analysis_Bipartite_MaximumMatching_ConnectedComponents

Author: 王梓帆

Date: March, 18, 2022


Description
--------------------
Project 1: Graph is Bipartite

Given input file of the Project:

(1) graph_input.h
* Detailed Declaration of input form is in the report.
# For Graph
vector<vector<bool>> G = {  {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                            {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

# For Bipartite Graph
vector<vector<bool>> bpGraph = {{1, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 0, 1, 0, 0, 0},
                                {0, 0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 1},
                                {0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 1, 0},
                                {1, 0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0, 0}};

# For Edges
vector<vector<int>> edges = {{0, 5},
                             {1, 6},
                             {2, 8},
                             {3, 8},
                             {4, 14},
                             {5, 10},
                             {6, 12},
                             {7, 11},
                             {8, 12},
                             {9, 13}};

Platform information
--------------------
Cygwin Ver. 2.905, OS: Win10, 64-bit



Compilation Guide
------------------

1. File name "Makefile" is for compilation.
2. Enter "make" to create an execution file named "GT_Project_1.exe".
3. Enter "./GT_Project_1.exe" to execute code.
4. Choose which benchmark is input.
