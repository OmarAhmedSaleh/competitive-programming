#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
string ss;
int z[1000004];
void z_algorithm(){
    int l,r;
    l=r=0;
    for(int i=1;i<ss.size();i++){
        if(i>r){
            l=r=i;
            while(r<ss.size()&&ss[r-l]==ss[r]){r++;}
            z[i]=r-l;
            r--;
        }else{
            int k=i-l;
            if(z[k]<r-i+1){z[i]=z[k];}else{
                l=i;
                while(r<ss.size()&&ss[r-l]==ss[r]){r++;}
                z[i]=r-l;
                r--;
            }
        
        
        }
    
    
    }
    z[0]=(int)ss.size();


}
int tc,q;
int pos;

int main()
{
   scanf("%d",&tc);
    while(tc--)
    {
        memset(z,0,sizeof(z));
        cin>>ss;
        reverse(ss.begin(),ss.end());
        z_algorithm();
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            scanf("%d",&pos);
            printf("%d\n",z[ss.size()-pos]);
        }
    }
    return 0;
}
