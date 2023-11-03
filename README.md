Program that finds all the shortest paths between all the islands, using information about the bridges that connect them. The program:

* reads data from a file. Its name is specified as a command-line argument
* finds all the shortest paths between each combination of two islands
* prints the paths using the FIFO (first) rule for the islands to the standard output.

## Input data
```
5
A-B,11
A-C,10
B-D,5
C-D,6
C-E,15
D-E,4
```
## Output in console 
```
========================================
Path: A -> B
Route: A -> B
Distance: 11
========================================
========================================
Path: A -> C
Route: A -> C
Distance: 10
========================================
========================================
Path: A -> D
Route: A -> B -> D
Distance: 11 + 5 = 16
========================================
========================================
Path: A -> D
Route: A -> C -> D
Distance: 10 + 6 = 16
========================================
========================================
Path: A -> E
Route: A -> B -> D -> E
Distance: 11 + 5 + 4 = 20
========================================
========================================
Path: A -> E
Route: A -> C -> D -> E
Distance: 10 + 6 + 4 = 20
========================================
========================================
Path: B -> C
Route: B -> D -> C
Distance: 5 + 6 = 11
========================================
========================================
Path: B -> D
Route: B -> D
Distance: 5
========================================
========================================
Path: B -> E
Route: B -> D -> E
Distance: 5 + 4 = 9
========================================
========================================
Path: C -> D
Route: C -> D
Distance: 6
========================================
========================================
Path: C -> E
Route: C -> D -> E
Distance: 6 + 4 = 10
========================================
========================================
Path: D -> E
Route: D -> E
Distance: 4
========================================
```
