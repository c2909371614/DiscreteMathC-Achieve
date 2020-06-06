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
    input[total].to=b;//��a��b 
    input[total].next=head[a];//��һ����ֵ��head��a�� 
    head[a]=total;
}
void dfs(int now,int father)
{
    index++;//ʱ���++ 
    int child=0;
    num[now]=index; //��һ�����ʱ��� 
    low[now]=index;//��ǰ���ʱ��� 
    for(int e=head[now];e!=0;e=input[e].next)
    {
        if(num[input[e].to]==0)
        {
            child++;
            dfs(input[e].to,now);//�����ڵݹ�����һ���� 
            low[now]=min(low[now],low[input[e].to]);//ѡ����С�� 
            if(now!=root && low[input[e].to]>=num[now])//��Ŀǰ���ʱ���>=��һ�����ʱ���Ϊ��� 
                book[now]=true;
            if(now==root && child==2)//���ж�������ʽ 
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
