## Presentation - Parentheses Balance
### Miklos Moreno
### Description:

This is a solution to the "Dark Roads" UVA problem on https://onlinejudge.org/. Problem ID 11631.

### Files

|   #   | File                | Description                                     |
| :---: | ------------------- | ----------------------------------------------- |
|   1   | [11631](p11631.pdf) | Problem statement and guidelines                |
|   2   | [main](main.cpp)    | Main driver of my program which solves problem. |
|   3   | [input](uDebug.txt) | Input from uDebug                               |
|   4   | [output](out.txt)   | Output from uDebug input                        |


### Instructions

- Just compile main.cpp, then run the executable from the command line but be sure to redirect
input and output to the correct files.

- Example Command:
    - `g++ main.cpp -o main`
    - `./main < <inputfile> > <outputfile>`

### Steps to Solution (chatGPT)

Certainly! The problem "Dark Roads" (UVa 11631) involves finding the minimum cost to connect all the cities in a network using a minimum spanning tree. Here's a high-level solution:

1. **Read Input:**
   - Read the number of cities and the number of roads.
   - Read the details of each road, including the cities it connects and its cost.

2. **Build Graph:**
   - Represent the cities and roads as a graph where each city is a node and each road is an edge with a corresponding weight.

3. **Minimum Spanning Tree (MST):**
   - Use a minimum spanning tree algorithm (e.g., Kruskal's or Prim's) to find the minimum cost of connecting all the cities.
   - These algorithms ensure that the resulting tree spans all the cities with the minimum possible total cost.

4. **Calculate Savings:**
   - Find the total cost of all roads in the original network.
   - Subtract the minimum cost found in the MST step from the total cost to get the savings achieved by removing some roads.

5. **Output Result:**
   - Print the calculated savings.

The key concept here is to recognize that removing some roads to create a minimum spanning tree results in cost savings. By finding the minimum spanning tree of the original network, you effectively identify the essential roads that connect all cities with the minimum total cost. The savings are then calculated by subtracting this minimum cost from the total cost of the original network.

