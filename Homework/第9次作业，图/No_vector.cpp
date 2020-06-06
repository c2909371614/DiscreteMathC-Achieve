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
	int arcs[MAX_NUM][MAX_NUM];//矩阵
	int node_num, edge_num;//节点数,边数
} Graph;
void read_graph() {
	openFile No_vector("No_vector_graph.txt");
	string s;
	No_vector.io>>s;
	for(int i=0; i<s.size(); i++)
		if(s[i]>='0'&&s[i]<='9')//节点为数字
			Graph.node+=s[i];
	string s1;
	No_vector.io>>s1;
	Bin_fun E(s1.c_str());//转换 
	memset(Graph.arcs,0,sizeof(Graph.arcs));//将矩阵初始化 为0
	for(int i=0; i<E.x.size(); i++) {//cout<<"ok"<<endl;
		Graph.arcs[E.x[i]-1-'0'][E.y[i]-1-'0']++;//矩阵从零开始图节点从1开始 
		Graph.arcs[E.y[i]-1-'0'][E.x[i]-1-'0']++;//因为是无向图所以反向也有要记录 
	}
	Graph.node_num=Graph.node.size();
	 
}
//从某点出判断无向图是否有回路（图用邻接矩阵表示）不考虑孤立点调用一次就够了 
bool isClose(int begin, int temp[][MAX_NUM]) {
	bool flag[MAX_NUM];
	int i, j;
	stack <int>stk;
	queue <int> vexQueue;
	for (i = 0; i<Graph.node_num; i++)
		flag[i] = false;
	//从a或b点出发，广度遍历所有点
	//如果该点和之前已访问过的点（除了它父亲）有边，
	//说明有回路
	vexQueue.push(begin);
	flag[begin] = true;
	int father;
	//
	for(int i=0;i<Graph.node.size();i++)
		for(int j=0;j<Graph.node.size();j++)
			if(temp[i][j]>1/*无向图中两节点的回路*/||temp[i][j]!=0&&i==j/*自身的回路*/)// 
				return true; 
	//
	while (vexQueue.empty() == false) {
		father = vexQueue.front();
		vexQueue.pop();
		for (int i = 0; i < Graph.node_num; ++i) {
			if (temp[father][i] != 0 && flag[i] == false) {
				vexQueue.push(i);
				flag[i] = true;
				//看看当前点和其他已访问点是否有边
				for (int j = 0; j < Graph.node_num; ++j) {
					if (temp[i][j] != 0 && j != father && flag[j] == true) {
						return true;//如果有边，说明有回路
					}
				}

			}

		}
	}
	return false;
}
void print_graph(){
	for(int i=0;i<Graph.node_num;i++){
		for(int j=0;j<Graph.node.size();j++)
			cout<<Graph.arcs[i][j]<<" ";
		cout<<endl;
	}
}
int main() {
	read_graph();
	print_graph();
	if(isClose(0,Graph.arcs))
		cout<<"yes"<<endl;
	else cout<<"no" <<endl;
}
