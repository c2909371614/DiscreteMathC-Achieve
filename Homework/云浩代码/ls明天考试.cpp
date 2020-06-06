#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,m;
int root;
int total=0;
int index=0;
int head[100010];
int book[100010];
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
    input[total].to=b;//从a到b 
    input[total].next=head[a];//下一个的值的head【a】 
    head[a]=total;
}
void dfs(int now,int father)
{
    index++;//时间戳++ 
    int child=0;
    num[now]=index; //下一个点的时间戳 
    low[now]=index;//当前点的时间戳 
    for(int e=head[now];e!=0;e=input[e].next)
    {
        if(num[input[e].to]==0)
        {
            child++;
            dfs(input[e].to,now);//从现在递归至下一个点 
            low[now]=min(low[now],low[input[e].to]);//选择最小点 
            if(now!=root && low[input[e].to]>=num[now])//当目前点的时间戳>=下一个点的时间戳为割点 
                book[now]=true;
            if(now==root && child==2)//特判二叉树形式 
                book[now]=true;
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
    root=1;
    dfs(1,root); 
    for(int i=1;i<=n;i++)
        if(book[i])
            cout<<i<<" ";
}
