
//package main;

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
     static int n ;
     static int []x=new int[100];
     static int []y=new int[100];
     static boolean []seen=new boolean[100];
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); 
        n=in.nextInt();
        for(int i=0;i<n;i++){
            x[i]=in.nextInt();
            y[i]=in.nextInt();
            seen[i]=false;
        }
      int ans=-1;
      for(int i=0;i<n;i++){
         if(!seen[i]){
            dfs(i);
            ans++;
        }
      }
        System.out.println(ans);        
    }
    private static void dfs(int idx) {
        if(seen[idx]){
        return ;
        }
        seen[idx]=true;
        for(int i=0;i<n;i++){
          if(x[idx]==x[i]||y[idx]==y[i]){
             dfs(i);
            }
        }
    }
}
