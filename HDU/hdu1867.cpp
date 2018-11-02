/*
 * @Author: CucumicsMelon 
 * @Date: 2018-11-02 21:31:37 
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2018-11-02 21:53:23
 */
#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define rep(i,n,m) for(int i=n;i<=m;++i)
#define per(i,n,m) for(int i=n;i>=m;--i)
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
#define maxn 100000+50
#define ll long long
using namespace std;
int nex[maxn];
void  getn(int n,char c[])
{
    int i=0,j=-1;
    nex[0]=-1;
    while(i<n)
    {
        if(c[i]==c[j]||j==-1)
        {
            i++;j++;nex[i]=j;
        }
        else j=nex[j];
    }
}
int kmp(char c1[],char c2[])
{
    int i,j=0,l1,l2;
    l1=strlen(c1);l2=strlen(c2);
    getn(l2,c2);
    rep(i,0,l1-1)
    {
        while(j&&c1[i]!=c2[j]) j=nex[j];
        if(c1[i]==c2[j]) j++;
    }
    return j;
}
int main()
{
   char c1[maxn],c2[maxn];
   while(~scanf("%s%s",c1,c2))
   {
       int l1=strlen(c1),l2=strlen(c2);
       getn(l1,c1);getn(l2,c2);
       int ans1=kmp(c1,c2),ans2=kmp(c2,c1);
       if(ans1>ans2||(ans1==ans2&&strcmp(c1,c2)<0)) printf("%s%s\n",c1,c2+ans1);
       else printf("%s%s\n",c2,c1+ans2);
   }
   return 0;
}