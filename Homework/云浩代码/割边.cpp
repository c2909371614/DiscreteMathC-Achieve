#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,m;
int total=0;
int index=0;
int head[100010];
int num[100010],low[100010];
struct edge
{
    int from;
    int to;
    int next;
}input[100010];
void add_edge(int a,int b)
{
    total++;
    input[total].from=a;
    input[total].to=b;
    input[total].next=head[a];
    head[a]=total;
}
void dfs(int now,int father)
{
    index++;
    num[now]=index;
    low[now]=index;
    for(int e=head[now];e!=0;e=input[e].next)
    {
        if(num[input[e].to]==0)
        {
            dfs(input[e].to,now);
            low[now]=min(low[now],low[input[e].to]);
            if(low[input[e].to]>num[now])
                cout<<now<<"->"<<input[e].to<<endl;
                
        }
        else if(input[e].to!=father)
            low[now]=min(low[now],num[input[e].to]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add_edge(a,b); 
        add_edge(b,a);
    }
    dfs(1,1); 
}
