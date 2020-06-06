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
class myGraph {
	private:
		string node;//节点信息
		int arcs[MAX_NUM][MAX_NUM];//矩阵值表示i->j的边的个数
		int node_num, edge_num;//节点数,边数
	public:
		myGraph(string sa) {
			read_graph(sa);
		}
		void read_graph(string sa) { //s为文件名
			openFile No_vector(sa.c_str());
			string s;
			No_vector.io>>s;
			for(int i=0; i<s.size(); i++)
				if(s[i]>='0'&&s[i]<='9')//节点为数字
					node+=s[i];//读取节点
			string s1;
			No_vector.io>>s1;
			Bin_fun E(s1.c_str());//转换
			memset(arcs,0,sizeof(arcs));//将矩阵初始化 为0
			for(int i=0; i<E.x.size(); i++) {//cout<<"ok"<<endl;
				arcs[E.x[i]-1-'0'][E.y[i]-1-'0']++;//矩阵从零开始图节点从1开始
			}
			node_num=node.size();
		}
		void print_graph() {
			for(int i=0; i<node_num; i++) {
				for(int j=0; j<node.size(); j++)
					cout<<arcs[i][j]<<" ";
				cout<<endl;
			}
		}
		bool isTournament() {
			for(int i=0; i<node.size(); i++)
				for(int j=i+1; j<node.size(); j++)
					if(arcs[i][j]+arcs[j][i]!=1)
						return false;
			return true;
		}
};
int main() {
	myGraph graph1("Tournament_1.txt");
	graph1.print_graph();
	if(graph1.isTournament())cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	myGraph graph2("Tournament_2.txt");
	graph2.print_graph();
	if(graph2.isTournament())cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
