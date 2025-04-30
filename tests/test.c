// test_num_islands.c
#include <stdio.h>
#include <stdlib.h>
#include "../solutions/solution.c"
extern int numIslands(char **grid, int gridSize, int *gridColSize);

void runTest(int rows, int cols, char grid[rows][cols], int expected, int testNum)
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

    if (result == expected)
    {
        printf("PASSED ✅ (Output: %d)\n", result);
    }
    else
    {
        printf("FAILED ❌ (Output: %d, Expected: %d)\n", result, expected);
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++)
        free(dynamicGrid[i]);
    free(dynamicGrid);
    free(gridColSize);
}

int main()
{
    char grid1[1][1] = {{'1'}};
    char grid2[1][1] = {{'0'}};
    char grid3[3][3] = {
        {'1', '1', '1'},
        {'1', '1', '1'},
        {'1', '1', '1'}};
    char grid4[3][3] = {
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'}};
    char grid5[4][4] = {
        {'1', '0', '1', '0'},
        {'0', '1', '0', '1'},
        {'1', '0', '1', '0'},
        {'0', '1', '0', '1'}};
    char grid6[2][5] = {
        {'1', '1', '0', '0', '1'},
        {'1', '0', '1', '1', '1'}};
    char grid7[5][5] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
        {'0', '0', '1', '1', '0'}};

    // Large grid of all '1's
    char largeGrid[50][50];
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            largeGrid[i][j] = '1';

    char grid8[1][5] = {
        {'1', '0', '1', '0', '1'}};
    char grid9[5][1] = {
        {'1'}, {'0'}, {'1'}, {'0'}, {'1'}};

    // Alternating 10x10 grid
    char grid13[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            grid13[i][j] = (i + j) % 2 == 0 ? '1' : '0';

    printf("Running Test Cases...\n");
    runTest(1, 1, grid1, 1, 1);
    runTest(1, 1, grid2, 0, 2);
    runTest(3, 3, grid3, 1, 3);
    runTest(3, 3, grid4, 0, 4);
    runTest(4, 4, grid5, 8, 5);
    runTest(2, 5, grid6, 2, 6);
    runTest(5, 5, grid7, 3, 7);
    runTest(50, 50, largeGrid, 1, 8);
    runTest(1, 5, grid8, 3, 9);
    runTest(5, 1, grid9, 3, 10);
    runTest(10, 10, grid13, 50, 11);

    printf("All test cases executed.\n");
    return 0;
}
