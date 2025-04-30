package solutions;

import java.util.*;

class Pair{
    int row,col;
    public Pair(int r,int c)
    {
        this.row = r;
        this.col = c;
    }
}

public class Solution {
    public void bfs(boolean visited[][], char[][] grid, int i,int j,int m, int n)
    {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(i,j));
        visited[i][j]=true;
        while(!q.isEmpty())
        {
            Pair curr = q.poll();
            int r = curr.row;
            int c = curr.col;
            if(r>0 && grid[r-1][c] == '1' && !visited[r-1][c])
            {
                visited[r-1][c] = true;
                q.add(new Pair(r-1,c));
            }
            if(r<m-1 && grid[r+1][c] == '1' && !visited[r+1][c])
            {
                visited[r+1][c] = true;
                q.add(new Pair(r+1,c));
            }
            if(c>0 && grid[r][c-1] == '1' && !visited[r][c-1])
            {
                visited[r][c-1] = true;
                q.add(new Pair(r,c-1));
            }
            if(c<n-1 && grid[r][c+1] == '1' && !visited[r][c+1])
            {
                visited[r][c+1] = true;
                q.add(new Pair(r,c+1));
            }

        }
    }
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int cnt = 0;
        boolean visited[][] = new boolean[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    bfs(visited,grid,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
