//to find the sum of adjacent cells in a grid
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int r=s.nextInt();
        int c=s.nextInt();
        int grid[][]=new int[r][c];
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                grid[row][col]=s.nextInt();
            }
        }
        int row=s.nextInt();
        int col=s.nextInt();
        final int diff[][]={{-1,-1},{-1,0},{-1,1},{0,-1},{1,-1},{1,0},{1,1},{0,1}};
        long sum=0;
        for(int i=0;i<8;i++){
            int adjRow=row+diff[i][0];
            int adjCol=col+diff[i][1];
            if(adjRow>=0 && adjRow<r && adjCol>=0 && adjCol<c){
                sum+=grid[adjRow][adjCol];
            }
        }
        System.out.println(sum);
    }
}