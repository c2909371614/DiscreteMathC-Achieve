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
	int arcs[MAX_NUM][MAX_NUM];//����ֵ��ʾi->j�ıߵĸ��� 
	int node_num, edge_num;//�ڵ���,����
} Graph;
void read_graph(string sa) { //sΪ�ļ��� 
	openFile No_vector(sa.c_str());
	string s;
	No_vector.io>>s;
	for(int i=0; i<s.size(); i++)
		if(s[i]>='0'&&s[i]<='9')//�ڵ�Ϊ����
			Graph.node+=s[i];//��ȡ�ڵ� 
	string s1;
	No_vector.io>>s1;
	Bin_fun E(s1.c_str());//ת�� 
	memset(Graph.arcs,0,sizeof(Graph.arcs));//�������ʼ�� Ϊ0
	for(int i=0; i<E.x.size(); i++) {//cout<<"ok"<<endl;
		Graph.arcs[E.x[i]-1-'0'][E.y[i]-1-'0']++;//������㿪ʼͼ�ڵ��1��ʼ 
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
		for(int j=0;j<Graph.node.size();j++)//����ͼֱ�ӱ������� 
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
	string name[3]={"����","���","��"} ;//0Ϊ�� 1Ϊ�� 2Ϊ��  
	print_graph();
	int degree[2][MAX_NUM];//�ڵ���� 
	Calc_degree(degree);//invoked Calc_degree fun to calc 
	int  max[2]={0,0},min[2]={MAX_NUM,MAX_NUM};//��������� ��С //0Ϊ�� 1Ϊ�� 
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
	
	cout<<"������:"<<max[0]<<endl;
	cout<<"��С����:"<<min[0]<<endl;
	cout<<"������:"<<max[1]<<endl;
	cout<<"��С���:"<<min[1]<<endl;
}
