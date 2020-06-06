#include"head.h"
int main() {
	//char [N];
	FILE *fp;
	fp=fopen("logic_run.txt","r");
	char ch[100];
	
	char ans;
	int i = 0;
	int count=0;
	cout<<"离散课程逻辑表达式求值，可在文件中输入任何逻辑表达式均可打印出其真值表"<<endl;//print the introduce
	cout<<"q|p相当于qvp"<<endl;
	while (~fscanf(fp,"%s",ch)){//read the file put on ch
		string str;
		for(i=0;i<strlen(ch);i++){ 
			str+=ch[i];
			
		}
		Count(str);
	}
	return 0;
}
