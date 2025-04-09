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
         3}, // Test Case 1

        {{{'1', '0', '1', '0', '1'}}, 3}, // Test Case 2

        {{{'1'}, {'0'}, {'1'}, {'1'}, {'0'}}, 2}, // Test Case 3

        {{{'1', '1', '1'},
          {'1', '1', '1'},
          {'1', '1', '1'}},
         1}, // Test Case 4

        {{{'0', '0', '0'},
          {'0', '0', '0'},
          {'0', '0', '0'}},
         0}, // Test Case 5

        {{{'1'}}, 1}, // Test Case 6

        {{{'0'}}, 0}, // Test Case 7

        {{{'1', '0', '1', '1', '0'},
          {'1', '0', '1', '1', '0'},
          {'0', '0', '0', '0', '1'},
          {'1', '1', '0', '1', '1'}},
         4}, // Test Case 8

        {vector<vector<char>>(50, vector<char>(50, '1')), 1}, // Test Case 9

        {{{'1', '0', '1', '0'},
          {'0', '1', '0', '1'},
          {'1', '0', '1', '0'},
          {'0', '1', '0', '1'}},
         8}, // Test Case 10

        {{}, 0} // Test Case 11 (Empty Grid)
    };

    // Run all test cases
    for (size_t i = 0; i < testCases.size(); i++)
    {
        runTest(testCases[i].first, testCases[i].second, i + 1);
    }

    return 0;
}
