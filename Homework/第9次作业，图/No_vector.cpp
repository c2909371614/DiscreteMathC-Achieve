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
struct matrix {//�ڽӾ��󴢴� 
	string node;//�ڵ���Ϣ
	int arcs[MAX_NUM][MAX_NUM];//����
	int node_num, edge_num;//�ڵ���,����
} Graph;
void read_graph() {
	openFile No_vector("No_vector_graph.txt");
	string s;
	No_vector.io>>s;
	for(int i=0; i<s.size(); i++)
		if(s[i]>='0'&&s[i]<='9')//�ڵ�Ϊ����
			Graph.node+=s[i];
	string s1;
	No_vector.io>>s1;
	Bin_fun E(s1.c_str());//ת�� 
	memset(Graph.arcs,0,sizeof(Graph.arcs));//�������ʼ�� Ϊ0
	for(int i=0; i<E.x.size(); i++) {//cout<<"ok"<<endl;
		Graph.arcs[E.x[i]-1-'0'][E.y[i]-1-'0']++;//������㿪ʼͼ�ڵ��1��ʼ 
		Graph.arcs[E.y[i]-1-'0'][E.x[i]-1-'0']++;//��Ϊ������ͼ���Է���Ҳ��Ҫ��¼ 
	}
	Graph.node_num=Graph.node.size();
	 
}
//��ĳ����ж�����ͼ�Ƿ��л�·��ͼ���ڽӾ����ʾ�������ǹ��������һ�ξ͹��� 
bool isClose(int begin, int temp[][MAX_NUM]) {
	bool flag[MAX_NUM];
	int i, j;
	stack <int>stk;
	queue <int> vexQueue;
	for (i = 0; i<Graph.node_num; i++)
		flag[i] = false;
	//��a��b���������ȱ������е�
	//����õ��֮ǰ�ѷ��ʹ��ĵ㣨���������ף��бߣ�
	//˵���л�·
	vexQueue.push(begin);
	flag[begin] = true;
	int father;
	//
	for(int i=0;i<Graph.node.size();i++)
		for(int j=0;j<Graph.node.size();j++)
			if(temp[i][j]>1/*����ͼ�����ڵ�Ļ�·*/||temp[i][j]!=0&&i==j/*����Ļ�·*/)// 
				return true; 
	//
	while (vexQueue.empty() == false) {
		father = vexQueue.front();
		vexQueue.pop();
		for (int i = 0; i < Graph.node_num; ++i) {
			if (temp[father][i] != 0 && flag[i] == false) {
				vexQueue.push(i);
				flag[i] = true;
				//������ǰ��������ѷ��ʵ��Ƿ��б�
				for (int j = 0; j < Graph.node_num; ++j) {
					if (temp[i][j] != 0 && j != father && flag[j] == true) {
						return true;//����бߣ�˵���л�·
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
