// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.Scanner;


class Main {
    int n, solutionCount;
    int[][] board;
    Main(int n){
        this.n=n;
        this.board = new int[n][n];
        this.solutionCount=0;
    }
    
    public  boolean isSafe(int row, int col){
        //previous rows in a column
        for(int i=0; i<row; i++){
            if(board[i][col]==1) return false;
        }
        
        //left diagonal matrix
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j]==1) return false;
        }
        
        //right diagonal matrix
        for(int i=row, j=col; i>=0 && j<n; i--, j++){
            if(board[i][j]==1) return false;
        }
        return true;
    }
    
    public  void solveNQueens(int row){
        if(row==n){
           System.out.println("Solution:-"+(++solutionCount));
           printBoard();
           System.out.println();
           return;
        }
        for(int col=0; col<n; col++){
            if(isSafe(row, col)){
                board[row][col]=1;
                solveNQueens(row+1);
                board[row][col]=0;
            }
        }
    }
    
    public  void solve(){
        solveNQueens(0);
        System.out.println("Total solutions:- "+solutionCount);
    }
    public  void printBoard(){
        for(int[] row: board){
            for(int r: row){
                System.out.print((r==1 ? "Q " : ". "));
            }
            System.out.println();
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows");
        int n=sc.nextInt();
        Main mn = new Main(n);
        mn.solve();
    }
}
