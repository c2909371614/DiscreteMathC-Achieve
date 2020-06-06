/*����ͼ�Ľ���������ԳƲ�Ƿ�Ϊ�� */ 
#include<bits/stdc++.h>
using namespace std;//nodeС��10�� 
class Graph{
	public:
		int matrix[10][10];//�ڽӱ��ͼ 
		int node;
		Graph(){
			memset(matrix,0,sizeof(matrix)); 
			node=0;
		}
		int get_data(string name){
			fstream io(name.c_str(),ios::in);//��ȡdata 
			char ch=0;//��Ϊ��ȡ���� 
			for(int i=0;;i++){
				for(int  j=0;;j++){
					io>>ch;
					matrix[i][j]=ch-'0';
					if(ch=='#'||ch=='*')//# �� * ��Ϊ�����ı�־        
						break;
				}  
				node++; 
				if(ch=='*')
					break;
			}
			my_print();
			io.close();//�ر�	
		}
		void my_print()
		{
			for(int i=0;i<node;i++){
				for(int j=0;j<node;j++)
					cout<<matrix[i][j]<<" ";
				cout<<endl;
			} 
			cout<<endl;
		}	
};
Graph G_con(const Graph& A,const Graph& B)//�ϼ� 
{
	Graph C;//for return con
	C.node=max(A.node,B.node);
	for(int i=0;i<max(A.node,B.node);i++)	
		 for(int j=0;j<max(A.node,B.node);j++)
		 	C.matrix[i][j]=max(A.matrix[i][j],B.matrix[i][j]);//ȡͼ�нϴ�ı������о���
	return C; 
}
Graph G_inter(const Graph& A,const Graph& B)//���� 
{
	Graph C;//for return con
	C.node=max(A.node,B.node);//�ڵ���� 
	for(int i=0;i<max(A.node,B.node);i++)	
		 for(int j=0;j<max(A.node,B.node);j++)
		 	C.matrix[i][j]=min(A.matrix[i][j],B.matrix[i][j]);//ȡͼ�н�С�ı������о���
	return C; 
}
Graph G_diff(const Graph& A,const Graph& B)//� 
{
	Graph C;//for return con
	C.node=max(A.node,B.node);
	for(int i=0;i<max(A.node,B.node);i++)	
		 for(int j=0;j<max(A.node,B.node);j++)
		 	C.matrix[i][j]=(A.matrix[i][j]>0&&B.matrix[i][j]==0)?A.matrix[i][j]:0;//A�б�B�ޱ� 
	return C; 
}
Graph G_opp_diff(const Graph& A,const Graph& B)//�ԳƲ 
{
	Graph C;//for return con
	C.node=max(A.node,B.node);
	C=G_con(G_diff(A,B),G_diff(B,A)); 
	return C; 
}
bool is_empty(const Graph& A)//�ж��Ƿ�Ϊ��ͼ
{
	int ans=0;//ans Ϊ�ߵĸ��� 
	for(int i=0;i<A.node;i++)
		for(int j=0;j<A.node;j++)
			ans+=A.matrix[i][j];
	return ans==0;//������Ϊ��ͼ 
 } 
int main()
{
	Graph G1,G2;
	G1.get_data("graph_1.txt");
	G2.get_data("graph_2.txt");
	cout<<"�ϼ���"<<endl;
	G_con(G1,G2).my_print();
	cout<<"������"<<endl;
	G_inter(G1,G2).my_print();
	cout<<"���"<<endl;
	G_diff(G1,G2).my_print();
	cout<<"�ԳƲ��"<<endl;
	G_opp_diff(G1,G2).my_print(); 
	if(is_empty(G1))cout<<"G1 is empty"<<endl;
	else cout<<"not empty"<<endl; 
 } 
