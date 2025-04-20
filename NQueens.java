import java.util.Scanner;

class NQueens {
    private int N;
    private int[][] board;

    public NQueens(int N) {
        this.N = N;
        this.board = new int[N][N];
    }
    private boolean isSafe(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1) return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) return false;
        }

        for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 1) return false;
        }

        return true;
    }

    // Backtracking function to solve N-Queens
    private boolean solveNQueens(int row) {
        if (row == N) return true; // All queens are placed

        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 1;
                System.out.println("Trying to place Q at (" + row + ", " + col + ")");
                printBoard();
                if (solveNQueens(row + 1)) return true; // Recur to place next queen

                // Backtrack
                board[row][col] = 0;
                System.out.println("Backtracking from (" + row + ", " + col + ")");
                printBoard();
            }
        }
        return false; // No valid placement found
    }

      private void printBoard() {
        for (int[] row : board) {
            for (int cell : row) {
                System.out.print((cell == 1 ? "Q " : ". "));
            }
            System.out.println();
        }
        System.out.println();
    }

    // Solve and display the solution
    public void solve() {
        if (solveNQueens(0)) {
            System.out.println("Solution for " + N + "-Queens:");
            printBoard();
        } else {
            System.out.println("No solution exists for " + N + "-Queens.");
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter value of N: ");
        int N = scanner.nextInt();
        scanner.close();

        NQueens nQueens = new NQueens(N);
        nQueens.solve();
    }
}
