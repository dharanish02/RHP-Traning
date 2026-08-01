//Karen and Coffee
import java.util.*;
public class Main{
public static void main(String[] args){
Scanner sc=new Scanner(System.in);
int n=sc.nextInt(), k=sc.nextInt(), q=sc.nextInt();
int max=200000;
int[] diff=new int[max+2], pref=new int[max+2];
for(int i=0; i<n; i++){
int l=sc.nextInt(), r=sc.nextInt();
diff[l]++;
diff[r+1]--;
}
int curr=0;
for(int i=1; i<=max; i++){
curr+=diff[i];
pref[i]=pref[i-1];
if(curr>=k) pref[i]++;
}
while(q>0){
int a=sc.nextInt(), b=sc.nextInt();
System.out.println(pref[b]-pref[a-1]);
q--;
}
}
