/*邻接矩阵存图，第i行表示i->j  matrix[i][j]>0表示i连通j
本程序计算无向图的连通分支数，联通图的联通分支数为1*/
/*memset(matrix,0,sizeof(matrix));
	memset(head,false,sizeof(head));//未访问为false
	matrix[0][1]=1;
	matrix[0][3]=1;
	matrix[1][2]=1;
	matrix[1][0]=1;
	matrix[2][3]=1;
	matrix[2][1]=1;
	matrix[3][2]=1;
	matrix[3][0]=1;*/
#include<bits/stdc++.h>
using namespace std;
bool head[20];//节点访问信息
int matrix[100][100];//邻接矩阵存图
void dfs(int node) {
	head[node]=true;//node设为以访问
	for(int i=0; i<20; i++)
		if(matrix[node][i]>0&&!head[i]) { //如果未访问 且可以访问到
			dfs(i);
		}
}
void dfs_all() {
	int ans=0;
	for(int i=0; i<20; i++) { //对每个顶点i
		if(!head[i]) { //如果i未被访问
			dfs(i);//访问i和i所在的连通块
			ans++;//连通块数+1
		}
	}
	cout<<ans<<endl;
}
void read() {
	fstream io;
	int choice=0;
	cin>>choice;
	switch(choice) {
		case 1:
			io.open("graph1.txt",ios::in);
			break;
		case 2:
			io.open("graph2.txt",ios::in);
			break;
		case 3:
			io.open("graph3.txt",ios::in);
			break;
	}//cout<<"ok"<<endl;
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++) {
			char ch;
			io>>ch; 
			matrix[i][j]=ch-'0';
			cout<<matrix[i][j]; 
		}
		cout<<endl;
	}
	io.close();	
}
int main() {
	read();
	dfs_all();
}
