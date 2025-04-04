from collections import deque
__package__ = "solutions"

class Solution:
    def bfs(self, visited, grid, i, j, m, n):
        q = deque([(i, j)])
        visited[i][j] = True

        while q:
            r, c = q.popleft()
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == '1' and not visited[nr][nc]:
                    visited[nr][nc] = True
                    q.append((nr, nc))

    def numIslands(self, grid):
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        count = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not visited[i][j]:
                    self.bfs(visited, grid, i, j, m, n)
                    count += 1
        return count
