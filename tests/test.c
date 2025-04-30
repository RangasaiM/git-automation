// test_num_islands.c
#include <stdio.h>
#include <stdlib.h>
#include "../solutions/solution.c"
extern int numIslands(char **grid, int gridSize, int *gridColSize);

int runTest(int rows, int cols, char grid[rows][cols], int expected, int testNum)
{
    printf("Test Case %d: ", testNum);
    fflush(stdout);  // Force printing in GitHub CI

    // Dynamically allocate memory for grid
    char **dynamicGrid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
    {
        dynamicGrid[i] = (char *)malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++)
        {
            dynamicGrid[i][j] = grid[i][j];
        }
    }

    // Create array of column sizes
    int *gridColSize = (int *)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++)
        gridColSize[i] = cols;

    int result = numIslands(dynamicGrid, rows, gridColSize);
    int failed = 0;

    if (result == expected)
    {
        printf("PASSED ✅ (Output: %d)\n", result);
    }
    else
    {
        printf("FAILED ❌ (Output: %d, Expected: %d)\n", result, expected);
        failed = 1;
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++)
        free(dynamicGrid[i]);
    free(dynamicGrid);
    free(gridColSize);

    return failed;
}

int main()
{
    int failed = 0;

    // [Same grid declarations as before...]

    printf("Running Test Cases...\n");

    failed |= runTest(1, 1, grid1, 1, 1);
    failed |= runTest(1, 1, grid2, 0, 2);
    failed |= runTest(3, 3, grid3, 1, 3);
    failed |= runTest(3, 3, grid4, 0, 4);
    failed |= runTest(4, 4, grid5, 8, 5);
    failed |= runTest(2, 5, grid6, 2, 6);
    failed |= runTest(5, 5, grid7, 3, 7);
    failed |= runTest(50, 50, largeGrid, 1, 8);
    failed |= runTest(1, 5, grid8, 3, 9);
    failed |= runTest(5, 1, grid9, 3, 10);
    failed |= runTest(10, 10, grid13, 50, 11);

    if (failed)
    {
        printf("Some test cases failed.\n");
        return 1;
    }

    printf("All test cases passed.\n");
    return 0;
}
