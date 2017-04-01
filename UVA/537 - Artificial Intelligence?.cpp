#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include <complex>

using namespace std;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

int t;
string s;
// p=u*i;
double p , I, u;

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>t;
	cin.ignore();

	for(int tt=1;tt<=t;tt++){
		getline(cin,s);
		int sz=s.size();
		bool ok[3]={0,0,0};
		for(int i=0;i<sz;i++){
		if(s[i-1]=='U'&&s[i]=='='){
			ok[1]=1;
			i++;
			int j=i;
			string temp="";
			int mm=0,Mm=0,K=0;
			for(j=i;j<sz;j++){
				if(s[j]=='V'){break;}
				if(s[j]=='='){continue;}

				if(s[j]=='m'){
					mm=1;
					continue;

				}
				if(s[j]=='M'){
					Mm=1;
					continue;

				}
				if(s[j]=='k'){
					K=1;
					continue;
				}

				temp+=s[j];

			}
			i=j;
			u=0;
					int d=1;
					bool dot=0;
					for(int j=0;j<temp.size();j++){
						if(temp[j]=='.'){dot=1; continue;}
						int aa=temp[j]-'0';
						if(dot){
							d*=10;
						}
						u*=10;
						u+=aa;
					}
					u/=d;
					if(mm){
						u/=1000;
					}
					if(K){
									u*=1000;
								}
					if(Mm){
									u*=1000;
									u*=1000;
								}
		}

		if(s[i-1]=='P'&&s[i]=='='){
					ok[0]=1;
					int j=i;
					string temp="";
					int mm=0,Mm=0,K=0;
					for(j=i;j<sz;j++){
						if(s[j]=='='){continue;}
						if(s[j]=='W'){break;}
						if(s[j]=='m'){
							mm=1;
							continue;

						}
						if(s[j]=='M'){
							Mm=1;
							continue;

						}
						if(s[j]=='k'){
							K=1;
							continue;
						}

						temp+=s[j];

					}
					i=j;
					p=0;
							int d=1;
							bool dot=0;
							for(int j=0;j<temp.size();j++){
								if(temp[j]=='.'){dot=1; continue;}
								int aa=temp[j]-'0';
								if(dot){
									d*=10;
								}
								p*=10;
								p+=aa;
							}
							p/=d;
							if(mm){
								p/=1000;
							}
							if(K){
											p*=1000;
										}
							if(Mm){
											p*=1000;
											p*=1000;
										}
				}
		if(s[i-1]=='I'&&s[i]=='='){
					ok[2]=1;

					int jj=i;
					string temp="";
					int mm=0,Mm=0,K=0;
					for(jj=i;jj<sz;jj++){
						if(s[jj]=='='){continue;}
						if(s[jj]=='A'){break;}
						if(s[jj]=='m'){
							mm=1;
							continue;

						}
						if(s[jj]=='M'){
							Mm=1;
							continue;

						}
						if(s[jj]=='k'){
							K=1;
							continue;
						}

						temp+=s[jj];

					}
					i=jj;
					I=0;
							int d=1;
							bool dot=0;
							for(int j=0;j<temp.size();j++){
								if(temp[j]=='.'){dot=1; continue;}
								int aa=temp[j]-'0';
								if(dot){
									d*=10;
								}
								I*=10;
								I+=aa;
							}
							I/=d;
							if(mm){
								I/=1000;
							}
							if(K){
								I*=1000;
								}
							if(Mm){
									I*=1000;
								I*=1000;
										}
				}

		}
		double ans=0;
		printf("Problem #%d\n",tt);
	if(!ok[0]){
		ans=I*u;
		printf("P=%.2lf%c\n",ans,'W');

	}
	if(!ok[1]){
		ans=p/I;
		printf("U=%.2lf%c\n",ans,'V');


	}
	if(!ok[2]){
		ans=p/u;
		printf("I=%.2lf%c\n",ans,'A');


	}
	printf("\n");

	}


	return 0;
}
