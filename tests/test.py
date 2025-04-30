import sys
import os

# Add the solution folder to the Python path
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from solutions.solution import Solution


def run_test(grid, expected, test_num):
    sol = Solution()
    result = sol.numIslands(grid)
    print(f"Test Case {test_num}: ", end="")
    if result == expected:
        print(f"PASSED ✅ (Output: {result})")
        return False  # Not failed
    else:
        print(f"FAILED ❌ (Output: {result}, Expected: {expected})")
        return True  # Test failed


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
    ]

    failed = False

    for i, (grid, expected) in enumerate(test_cases, 1):
        if run_test(grid, expected, i):
            failed = True

    if failed:
        print("\n❌ Some test cases failed.")
        sys.exit(1)
    else:
        print("\n✅ All test cases passed.")
        sys.exit(0)
