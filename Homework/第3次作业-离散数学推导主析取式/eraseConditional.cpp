#include"Head.h"
int print(char str[]){
	for(int i=0;i<strlen(str);i++)	
		cout<<str[i];
	cout<<endl;
	return 0;
}
int eraseConditional(char str[]){
	
	stack<char> stk;//����ǰ�� ��stack
	int bi/*������ָ��*/,ei; 
	char ans[10000];
	for(int i=0; i<strlen(str); i++) { //����Ԥ�����ַ�
		char fin[1000];//����ǰ�� 
		char fin2[1000];
		if(str[i]=='^') {
			fin[0]='~';//���ַ�ǰ��~�����ţ�
			fin[1]='(';
			int l=i,r=i;//lΪ��ָ�� rΪ��ָ��
			
			//�������� 
			if(str[l-1]==')') { 
				int count=2;//��Ϊfin���±� fin[0]Ϊ~��fin[1]Ϊ�� 
				l--;
				int bracketNum=0;
				while(str[l]!='('||bracketNum!=1) {//��Ϊ��һ��')'Ҫ��stack����  =1 
					if (str[l]==')')bracketNum++;
					if(str[l]=='(')bracketNum--;//�������ƥ�� 
					stk.push(str[l]);//��������֮ǰ����ջ 
					//cout<<stk.top()<<endl;
					l--;//���� 
				}
				bi=l;//������ָ�� 
				while(!stk.empty()) {
					fin[count++]=stk.top();
					stk.pop();
				}
			} //������ 
			else {
				fin[1]=str[l-1];
				bi=l-1;
			}// �Ƶ��ұ�������
			 
			if(str[r+1]=='(') {
				r++;
				int count=0;
				while(str[r]!=')') {//��������ƥ������ 
					fin2[count++]=str[r];
					r++;
				}
				ei=r;
				fin2[count]=')';
			} //�ұ������� 
			else {
				fin2[0]=str[r+1];
				ei=r+1;
			}
			print(fin);
			print(fin2);
			queue<char> que;//����������� 
			for(int j=0; j<bi; j++)//��biָ��ǰ��δ����������� 
				que.push(str[j]);
			for(int j=0; j<strlen(fin); j++)//������õĲ���fin(�������^����ߵ�������������� 
				que.push(fin[j]);
			que.push('|');//���롮|������� 
			for(int j=0; j<strlen(fin2); j++)//��'^' �ұߵ������������ 
				que.push(fin2[j]);
			for(int j=ei+1; j<strlen(str); j++)//��eiָ�����δ����������� 
				que.push(str[j]);
			int s=que.size();
			for(int j=0; j<s; j++) {//�Ƴ����ж���Ԫ�ظ��Ӹ�str 
				str[j]=que.front();
				que.pop();
			}
		}
	}
	return 0;
}

