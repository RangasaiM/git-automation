// test_num_islands.c
#include <stdio.h>
#include "../solutions/solution.c"
extern int numIslands(int rows, int cols, char grid[rows][cols]);

void runTest(int rows, int cols, char grid[rows][cols], int expected, int testNum)
{
    printf("Test Case %d: ", testNum);
    int result = numIslands(rows, cols, grid);
    if (result == expected)
    {
        printf("PASSED ✅ (Output: %d)\n", result);
    }
    else
    {
        printf("FAILED ❌ (Output: %d, Expected: %d)\n", result, expected);
    }
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
    char largeGrid[50][50];
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            largeGrid[i][j] = '1';
    char grid8[1][5] = {
        {'1', '0', '1', '0', '1'}};
    char grid9[5][1] = {
        {'1'}, {'0'}, {'1'}, {'0'}, {'1'}};
    char grid10[3][3] = {
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'}};
    char grid11[3][3] = {
        {'1', '1', '1'},
        {'1', '1', '1'},
        {'1', '1', '1'}};
    char grid12[3][3] = {
        {'1', '0', '1'},
        {'0', '1', '0'},
        {'1', '0', '1'}};
    char grid13[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            grid13[i][j] = (i + j) % 2 == 0 ? '1' : '0';
    char grid14[5][5] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
        {'0', '0', '0', '1', '1'}};
    char grid15[1][1] = {{'1'}};
    char grid16[1][1] = {{'0'}};
    char grid17[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            grid17[i][j] = (i + j) % 2 == 0 ? '1' : '0';

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
    runTest(3, 3, grid10, 0, 11);
    runTest(3, 3, grid11, 1, 12);
    runTest(3, 3, grid12, 5, 13);
    runTest(10, 10, grid13, 50, 14);
    runTest(5, 5, grid14, 3, 15);
    runTest(1, 1, grid15, 1, 16);
    runTest(1, 1, grid16, 0, 17);
    runTest(10, 10, grid17, 50, 18);

    printf("All test cases executed.\n");
    return 0;
}
