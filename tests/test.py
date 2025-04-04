import sys
import os

# Add the solution folder to the Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'solutions')))

from solutions.Solution import Solution


def run_test(grid, expected, test_num):
    sol = Solution()
    result = sol.numIslands(grid)
    print(f"Test Case {test_num}: ", end="")
    if result == expected:
        print(f"PASSED ✅ (Output: {result})")
    else:
        print(f"FAILED ❌ (Output: {result}, Expected: {expected})")

if __name__ == "__main__":
    test_cases = [
        ([['1', '1', '0', '0', '0'],
          ['1', '1', '0', '0', '0'],
          ['0', '0', '1', '0', '0'],
          ['0', '0', '0', '1', '1']], 3),

        ([['1', '0', '1', '0', '1']], 3),
        ([['1'], ['0'], ['1'], ['1'], ['0']], 2),
        ([['1', '1', '1'],
          ['1', '1', '1'],
          ['1', '1', '1']], 1),

        ([['0', '0', '0'],
          ['0', '0', '0'],
          ['0', '0', '0']], 0),

        ([['1']], 1),
        ([['0']], 0),

        ([['1', '0', '1', '1', '0'],
          ['1', '0', '1', '1', '0'],
          ['0', '0', '0', '0', '1'],
          ['1', '1', '0', '1', '1']], 4),

        ([['1'] * 50 for _ in range(50)], 1),

        ([['1', '0', '1', '0'],
          ['0', '1', '0', '1'],
          ['1', '0', '1', '0'],
          ['0', '1', '0', '1']], 8),

        ([], 0)
    ]

    for i, (grid, expected) in enumerate(test_cases, 1):
        run_test(grid, expected, i)
