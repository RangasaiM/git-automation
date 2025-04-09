#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> index = {-1, 0, 1, 0, -1};

    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int n, int m, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[0][0] = true;
        while (!q.empty())
        {
            pair<int, int> temp = q.front();
            int i = temp.first, j = temp.second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nexti = i + index[k];
                int nextj = j + index[k + 1];
                if (nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && vis[nexti][nextj] == false && grid[nexti][nextj] == '1')
                {
                    q.push({nexti, nextj});
                    vis[nexti][nextj] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // write your code  here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(grid, vis, n, m, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};