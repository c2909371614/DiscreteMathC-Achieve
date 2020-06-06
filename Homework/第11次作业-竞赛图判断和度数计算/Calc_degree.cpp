#include<bits/stdc++.h>
using namespace std;
const int MAX_NUM=105;
class openFile { //打开文件的class
	private:
	public:
		fstream io;
		openFile(string filename) {//需要指定文件名
			io.open(filename.c_str(),ios::in|ios::app);//以读取和添加的方式打开
		}
		~openFile() {
			io.close();
		}
};
class Bin_fun { //将读取的字符串形式转化为两个元素字符串
	public:
		string x,y,s;//s为原子符串，x为第一元素，y为第二元素
		Bin_fun(string newS) { //new 为a={(1,2),(2,3)...}
			s=newS;
			int pos=-1;
			for(int i=0; i<s.size(); i++)
				if(s[i]>='0'&&s[i]<='9') {
					pos=i;
					break;
				}
			for(int i=pos; i<s.size(); i+=6) {
				x+=s[i];
				y+=s[i+2];
			}
			//cout<<x<<endl;
		}
};
struct matrix {//邻接矩阵储存 
	string node;//节点信息
	int arcs[MAX_NUM][MAX_NUM];//矩阵值表示i->j的边的个数 
	int node_num, edge_num;//节点数,边数
} Graph;
void read_graph(string sa) { //s为文件名 
	openFile No_vector(sa.c_str());
	string s;
	No_vector.io>>s;
	for(int i=0; i<s.size(); i++)
		if(s[i]>='0'&&s[i]<='9')//节点为数字
			Graph.node+=s[i];//读取节点 
	string s1;
	No_vector.io>>s1;
	Bin_fun E(s1.c_str());//转换 
	memset(Graph.arcs,0,sizeof(Graph.arcs));//将矩阵初始化 为0
	for(int i=0; i<E.x.size(); i++) {//cout<<"ok"<<endl;
		Graph.arcs[E.x[i]-1-'0'][E.y[i]-1-'0']++;//矩阵从零开始图节点从1开始 
	}
	Graph.node_num=Graph.node.size();
	 
}
void print_graph(){
	for(int i=0;i<Graph.node_num;i++){
		for(int j=0;j<Graph.node.size();j++)
			cout<<Graph.arcs[i][j]<<" ";
		cout<<endl;
	}
}
void Calc_degree(int degree[][MAX_NUM]) 
{
	//int (*degree)[2]=new int[node.size()][2];
	for(int i=0;i<2;i++)
		memset(degree[i],0,sizeof(degree[i]));
	for(int i=0;i<Graph.node.size();i++)
	{
		for(int j=0;j<Graph.node.size();j++)//有向图直接遍历就行 
		{
			//cout<<degree[i][j]<<" ";
			degree[0][i]+=Graph.arcs[i][j];
			degree[1][j]+=Graph.arcs[i][j]; 
			//cout<<"test:"<<Graph.arcs[i][j]<<endl;
		 } 
		//cout<<endl;
	}
	//return degree;
 } 

int main() {
	read_graph("Calc_node_degree.txt");
	string name[3]={"出度","入度","度"} ;//0为出 1为入 2为和  
	print_graph();
	int degree[2][MAX_NUM];//节点度数 
	Calc_degree(degree);//invoked Calc_degree fun to calc 
	int  max[2]={0,0},min[2]={MAX_NUM,MAX_NUM};//最大出度入度 最小 //0为出 1为入 
	for(int i=0;i<3;i++)
	{ 
		cout<<name[i]<<":"; 
		for(int j=0;j<Graph.node.size();j++)
		{
			if(i!=2){
				cout<<degree[i][j]<<" ";
				if(degree[i][j]>max[i])max[i]=degree[i][j];
				if(degree[i][j]<min[i])min[i]=degree[i][j];
			}
			else cout<<degree[0][j]+degree[1][j]<<" ";
		}
			
		cout<<endl;
	 }
	
	cout<<"最大出度:"<<max[0]<<endl;
	cout<<"最小出度:"<<min[0]<<endl;
	cout<<"最大入度:"<<max[1]<<endl;
	cout<<"最小入度:"<<min[1]<<endl;
}
