#include"head.h"
int main() {
	//char [N];
	FILE *fp;
	fp=fopen("logic_run.txt","r");
	char ch[100];
	
	char ans;
	int i = 0;
	int count=0;
	cout<<"��ɢ�γ��߼����ʽ��ֵ�������ļ��������κ��߼����ʽ���ɴ�ӡ������ֵ��"<<endl;//print the introduce
	cout<<"q|p�൱��qvp"<<endl;
	while (~fscanf(fp,"%s",ch)){//read the file put on ch
		string str;
		for(i=0;i<strlen(ch);i++){ 
			str+=ch[i];
			
		}
		Count(str);
	}
	return 0;
}
