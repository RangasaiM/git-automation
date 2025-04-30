
import solutions.Solution;
import java.util.Arrays;
import java.util.List;

public class Main {

    private static boolean runTest(char[][] grid, int expected, int testNum) {
        Solution sol = new Solution();
        int result = sol.numIslands(grid);
        System.out.print("Test Case " + testNum + ": ");
        if (result == expected) {
            System.out.println("PASSED ✅ (Output: " + result + ")");
            return false; // not failed
        } else {
            System.out.println("FAILED ❌ (Output: " + result + ", Expected: " + expected + ")");
            return true; // failed
        }
    }

    public static void main(String[] args) {
        // Create a large grid of all '1's
        char[][] largeGrid = new char[50][50];
        for (int i = 0; i < 50; i++) {
            Arrays.fill(largeGrid[i], '1');
        }

        List<Object[]> testCases = Arrays.asList(
            new Object[] { new char[][] {
                { '1', '1', '0', '0', '0' },
                { '1', '1', '0', '0', '0' },
                { '0', '0', '1', '0', '0' },
                { '0', '0', '0', '1', '1' }
            }, 3 },

            new Object[] { new char[][] {
                { '1', '0', '1', '0', '1' }
            }, 3 },

            new Object[] { new char[][] {
                { '1' }, { '0' }, { '1' }, { '1' }, { '0' }
            }, 2 },

            new Object[] { new char[][] {
                { '1', '1', '1' },
                { '1', '1', '1' },
                { '1', '1', '1' }
            }, 1 },

            new Object[] { new char[][] {
                { '0', '0', '0' },
                { '0', '0', '0' },
                { '0', '0', '0' }
            }, 0 },

            new Object[] { new char[][] { { '1' } }, 1 },

            new Object[] { new char[][] { { '0' } }, 0 },

            new Object[] { new char[][] {
                { '1', '0', '1', '1', '0' },
                { '1', '0', '1', '1', '0' },
                { '0', '0', '0', '0', '1' },
                { '1', '1', '0', '1', '1' }
            }, 4 },

            new Object[] { largeGrid, 1 },

            new Object[] { new char[][] {
                { '1', '0', '1', '0' },
                { '0', '1', '0', '1' },
                { '1', '0', '1', '0' },
                { '0', '1', '0', '1' }
            }, 8 }
        );

        boolean failed = false;

        for (int i = 0; i < testCases.size(); i++) {
            char[][] grid = (char[][]) testCases.get(i)[0];
            int expected = (int) testCases.get(i)[1];
            if (runTest(grid, expected, i + 1)) {
                failed = true;
            }
        }

        if (failed) {
            System.out.println("\n❌ Some test cases failed.");
            // Uncomment below if you want CI-style exit status
            // System.exit(1);
        } else {
            System.out.println("\n✅ All test cases passed.");
            // System.exit(0);
        }
    }
}
