package solutions;

import java.util.*;

//code     1

public class Solution {
    private void bfs(boolean[][] visited, char[][] grid, int i, int j, int m, int n) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] { i, j });
        visited[i][j] = true;

        int[] rowDir = { -1, 1, 0, 0 }; // Up, Down
        int[] colDir = { 0, 0, -1, 1 }; // Left, Right

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int r = curr[0], c = curr[1];

            for (int d = 0; d < 4; d++) {
                int newRow = r + rowDir[d];
                int newCol = c + colDir[d];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                        !visited[newRow][newCol] && grid[newRow][newCol] == '1') {
                    visited[newRow][newCol] = true;
                    queue.offer(new int[] { newRow, newCol });
                }
            }
        }
    }

    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0)
            return 0;

        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(visited, grid, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
}
