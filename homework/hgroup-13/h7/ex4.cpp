#include "homework.h"
#include<iostream>
using namespace std;
int find(int n,int cnt)
{
    if (n==1)
        return cnt;
    if (n%2==0)
        return find((int)(n/2),cnt+1);
    else return find(3*n+1,cnt+1);
}
void ex4()
{
    //Write code for exercise 4
    int ans,maxn=0,m,maxi,opt;
    cin>>opt>>m;
    if (opt==1)
    {
        ans=find(m,0);
        cout<<ans;
    }
    else
    {
        for (int i=2;i<=m;i++)
        {
            ans=find(i,0);
            if (ans>maxn)
            {
                maxn=ans;
                maxi=i;
            }
        }
        cout<<maxi<<endl;
    }
}

#ifdef JOJ
int main(){
    ex4();
    return 0;
}
#endif