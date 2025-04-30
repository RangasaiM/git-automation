#include "../solutions/solution.cpp"

#include <bits/stdc++.h>
using namespace std;

// Function to run test cases
void runTest(vector<vector<char>> grid, int expected, int testNum)
{
    Solution sol;
    int result = sol.numIslands(grid);
    cout << "Test Case " << testNum << ": ";
    if (result == expected)
    {
        cout << "PASSED ✅ (Output: " << result << ")" << endl;
    }
    else
    {
        cout << "FAILED ❌ (Output: " << result << ", Expected: " << expected << ")" << endl;
    }
}

int main()
{
    vector<pair<vector<vector<char>>, int>> testCases = {
        {{{'1', '1', '0', '0', '0'},
          {'1', '1', '0', '0', '0'},
          {'0', '0', '1', '0', '0'},
          {'0', '0', '0', '1', '1'}},
         3},

        {{{'1', '0', '1', '0', '1'}}, 3},

        {{{'1'}, {'0'}, {'1'}, {'1'}, {'0'}}, 2},

        {{{'1', '1', '1'},
          {'1', '1', '1'},
          {'1', '1', '1'}},
         1},

        {{{'0', '0', '0'},
          {'0', '0', '0'},
          {'0', '0', '0'}},
         0},

        {{{'1'}}, 1},

        {{{'0'}}, 0},

        {{{'1', '0', '1', '1', '0'},
          {'1', '0', '1', '1', '0'},
          {'0', '0', '0', '0', '1'},
          {'1', '1', '0', '1', '1'}},
         4},

        {vector<vector<char>>(50, vector<char>(50, '1')), 1},

        {{{'1', '0', '1', '0'},
          {'0', '1', '0', '1'},
          {'1', '0', '1', '0'},
          {'0', '1', '0', '1'}},
         8}
    };

    int failed = 0;

    // Run all test cases
    for (size_t i = 0; i < testCases.size(); i++)
    {
        Solution sol;
        int result = sol.numIslands(testCases[i].first);
        cout << "Test Case " << i + 1 << ": ";
        if (result == testCases[i].second)
        {
            cout << "PASSED ✅ (Output: " << result << ")" << endl;
        }
        else
        {
            cout << "FAILED ❌ (Output: " << result << ", Expected: " << testCases[i].second << ")" << endl;
            failed++;
        }
    }

    return failed > 0 ? 1 : 0; // 👈 Return non-zero if any test fails
}

