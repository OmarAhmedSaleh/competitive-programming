// https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if(a.score != b. score){
            return a.score < b.score ? -1 : 1;
        }
        int mnLength = min((int)a.name.size(), (int)b.name.size());
        for(int i = 0;i < mnLength; i++){
            if(a.name[i] > b.name[i]){
                return -1;
            }
            if(a.name[i] < b.name[i]){
                return 1;
            }
        }
        if((int)a.name.size() != (int)b.name.size()){
            return (int)a.name.size() > (int)b.name.size() ? -1 : 1;
        }
        // a == b
        return 0;
    }
};

