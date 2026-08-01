//to find the length of longest common substring of two strings
import java.util.*;
public class Main{
public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    String s1=sc.nextLine();
    String s2=sc.nextLine();
    int a=s1.length(), b=s2.length(), max=0;
    int[][] dp=new int[a+1][b+1];
    for(int i=1; i<=a; i++){
      for(int j=1; j<=b; j++){
        for(int j=1; j<=b; j++){
          if(s1.charAt(i-1)==s2.charAt(j-1)){
            dp[i][j]=1+dp[i-1][j-1];
            max=Math.max(max, dp[i][j]);
            }
        }
    }
      System.out.println(max);
}
}
};
