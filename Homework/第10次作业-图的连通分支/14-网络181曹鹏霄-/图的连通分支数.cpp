/*�ڽӾ����ͼ����i�б�ʾi->j  matrix[i][j]>0��ʾi��ͨj
�������������ͼ����ͨ��֧������ͨͼ����ͨ��֧��Ϊ1*/
/*memset(matrix,0,sizeof(matrix));
	memset(head,false,sizeof(head));//δ����Ϊfalse
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
bool head[20];//�ڵ������Ϣ
int matrix[100][100];//�ڽӾ����ͼ
void dfs(int node) {
	head[node]=true;//node��Ϊ�Է���
	for(int i=0; i<20; i++)
		if(matrix[node][i]>0&&!head[i]) { //���δ���� �ҿ��Է��ʵ�
			dfs(i);
		}
}
void dfs_all() {
	int ans=0;
	for(int i=0; i<20; i++) { //��ÿ������i
		if(!head[i]) { //���iδ������
			dfs(i);//����i��i���ڵ���ͨ��
			ans++;//��ͨ����+1
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
