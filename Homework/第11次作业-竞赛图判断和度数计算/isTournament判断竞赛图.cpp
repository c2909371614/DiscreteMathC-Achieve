#include<bits/stdc++.h>
using namespace std;
const int MAX_NUM=105;
class openFile { //���ļ���class
	private:
	public:
		fstream io;
		openFile(string filename) {//��Ҫָ���ļ���
			io.open(filename.c_str(),ios::in|ios::app);//�Զ�ȡ����ӵķ�ʽ��
		}
		~openFile() {
			io.close();
		}
};
class Bin_fun { //����ȡ���ַ�����ʽת��Ϊ����Ԫ���ַ���
	public:
		string x,y,s;//sΪԭ�ӷ�����xΪ��һԪ�أ�yΪ�ڶ�Ԫ��
		Bin_fun(string newS) { //new Ϊa={(1,2),(2,3)...}
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
		string node;//�ڵ���Ϣ
		int arcs[MAX_NUM][MAX_NUM];//����ֵ��ʾi->j�ıߵĸ���
		int node_num, edge_num;//�ڵ���,����
	public:
		myGraph(string sa) {
			read_graph(sa);
		}
		void read_graph(string sa) { //sΪ�ļ���
			openFile No_vector(sa.c_str());
			string s;
			No_vector.io>>s;
			for(int i=0; i<s.size(); i++)
				if(s[i]>='0'&&s[i]<='9')//�ڵ�Ϊ����
					node+=s[i];//��ȡ�ڵ�
			string s1;
			No_vector.io>>s1;
			Bin_fun E(s1.c_str());//ת��
			memset(arcs,0,sizeof(arcs));//�������ʼ�� Ϊ0
			for(int i=0; i<E.x.size(); i++) {//cout<<"ok"<<endl;
				arcs[E.x[i]-1-'0'][E.y[i]-1-'0']++;//������㿪ʼͼ�ڵ��1��ʼ
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
