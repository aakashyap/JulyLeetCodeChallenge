/*

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:

*/

class Solution {
    int rows,cols;
    int util(const vector<vector<int>> &grid,int row,int col) {
        int count = 0;
        if (row - 1 < 0 || !grid[row-1][col]) ++count;
        if (row + 1 >= rows || !grid[row+1][col]) ++count;
        if (col - 1 < 0 || !grid[row][col-1]) ++count;
        if (col + 1 >= cols || !grid[row][col+1]) ++count;
        return count;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int perimeter = 0;
        for (int i = 0;i<rows;++i) {
            for(int j = 0;j<cols;++j) {
                if (grid[i][j]) {
                    perimeter += util(grid,i,j);
                }
            }
        }
        return perimeter;
    }
};