// solution.c
#include <stdio.h>
#include <stdbool.h>

void bfs(int rows, int cols, char grid[rows][cols], bool visited[rows][cols], int i, int j)
{
    int queue[rows * cols][2];
    int front = 0, rear = 0;

    queue[rear][0] = i;
    queue[rear][1] = j;
    rear++;

    visited[i][j] = true;

    int rowDir[] = {-1, 1, 0, 0};
    int colDir[] = {0, 0, -1, 1};

    while (front < rear)
    {
        int r = queue[front][0];
        int c = queue[front][1];
        front++;

        for (int d = 0; d < 4; d++)
        {
            int newRow = r + rowDir[d];
            int newCol = c + colDir[d];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                !visited[newRow][newCol] && grid[newRow][newCol] == '1')
            {
                visited[newRow][newCol] = true;
                queue[rear][0] = newRow;
                queue[rear][1] = newCol;
                rear++;
            }
        }
    }
}

int numIslands(int rows, int cols, char grid[rows][cols])
{
    if (rows == 0 || cols == 0)
        return 0;

    bool visited[rows][cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i][j] = false;

    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                bfs(rows, cols, grid, visited, i, j);
                count++;
            }
        }
    }
    return count;
}
