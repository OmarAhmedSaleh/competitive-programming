
package main;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

public class Main {
    static int n,k;
    static long []l=new long[1000];
    static long []r=new long[1000];
    static long []cnt=new long[1000];
    static boolean [][]seen=new boolean [1000][1001];
    static double [][]memo=new double [1000][1001];
    static double solve(int idx, int curk){
    if(idx==n){
        if((long)curk*100>=(long)k*n){
        return (double)1;
    }
        return (double)0;
    }
    if(seen[idx][curk]){
    return memo[idx][curk];
    }
    double prob=(double)cnt[idx];
    prob/=(r[idx]-l[idx])+1;
    double ans=solve(idx+1,curk)*((double)1-prob) + (solve(idx+1,curk+1)*prob);
    seen[idx][curk]=true;
    return memo[idx][curk]=ans;
    }
    public static void main(String[] args) {
    Scanner in=new Scanner(System.in);
        n=in.nextInt();
        for(int i=0;i<n;i++){
        l[i]=in.nextLong();
        r[i]=in.nextLong();
        cnt[i]=0;
        long pt=1;
        for(int j=0;j<19;j++){
            long  kk=pt+pt;
            if(pt>r[i]){break;}
            if(pt<=l[i]){
                if(kk>l[i]&&kk<=r[i]){
                    cnt[i]+=kk-l[i];
                }
                if(kk>r[i]){
                    cnt[i]+=(r[i]-l[i])+1;
                }
            }
            if(pt>l[i]){
                if(kk>l[i]&&kk<=r[i]){
                    cnt[i]+=pt;
                }
                if(kk>r[i]){
                    cnt[i]+=(r[i]-pt)+1;
                }
             }
            pt*=10;
           }      
        }
        k=in.nextInt();
        for(int i=0;i<n;i++){
         for(int j=0;j<=n;j++){
            seen[i][j]=false;
            }
        }
        System.out.printf("%.9f\n",solve(0,0));
    }
}
