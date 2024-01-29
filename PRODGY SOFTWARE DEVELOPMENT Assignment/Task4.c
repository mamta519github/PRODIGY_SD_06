#include <stdio.h>

#define N 9

// Function to check if a number can be placed in a given position
int isSafe(int grid[N][N], int row, int col, int num)
{
    // Check if the number is not already present in the current row and column
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return 0;
        }
    }

    // Check if the number is not present in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return 0;
            }
        }
    }

    return 1; // If the number can be placed, return true
}

// Function to print the Sudoku grid
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to solve Sudoku using backtracking
int solveSudoku(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num;

                        if (solveSudoku(grid))
                        {
                            return 1; // If a solution is found, return true
                        }

                        // If placing the current number doesn't lead to a solution, backtrack
                        grid[row][col] = 0;
                    }
                }
                return 0; // If no number can be placed, backtrack
            }
        }
    }

    return 1; // If the entire grid is filled, a solution is found
}

int main()
{
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solveSudoku(grid))
    {
        printf("Sudoku solved successfully:\n");
        printGrid(grid);
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}