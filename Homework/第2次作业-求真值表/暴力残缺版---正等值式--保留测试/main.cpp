#include"head.h"
int main() {
	//char [N];
	FILE *fp;
	fp=fopen("logic_run.txt","r");
	char ch[100];	
	string str;
	int i = 0,count=0;
	int count1=0,count2=0;//�������ĸ��� 
	int m1[100],m2[100];//���ڴ��漫С��// 
	cout<<"��ɢ�γ��߼����ʽ��ֵ�������ļ��������κ��߼����ʽ���ɴ�ӡ������ֵ��"<<endl;//print the introduce
	cout<<"q|p�൱��qvp"<<endl;
	memset(m1,0,sizeof(m1));
	memset(m2,0,sizeof(m2));
	while (~fscanf(fp,"%s",ch)){//read the file put on ch
		for(i=0;i<strlen(ch);i++){ 
			str+=ch[i];
		}
		if((count&1)==0) 
			count1=Count(str,m1);
		else count2=Count(str,m2);//cout<<(count1)<<endl;;cout<<(count)<<endl;} 
		str.clear();//��str���Ԥ���´δ��� 
		count++;//������ż�б� 
	}
//	for(int i=0;i<100;i++){
//		if(m1[i]!=0)cout<<i<<endl;
//		if(m2[i]!=0)cout<<i<<endl;
//	}	
	int j;
	bool flag=true;
	for(j=0;j<(1<<count1);j++){
		if(m1[j]!=0){
			for(int i=j<<(count2-count1);i<=(j<<(count2-count1))+(count2-count1);i++){
				if(m2[i]==0)flag=false;//��������ֵ 
			//	cout<<"i="<<i<<endl; 
			}
		}
		else {
			for(int i=j<<(count2-count1);i<=(j<<(count2-count1))+(count2-count1);i++){
				if(m2[i]!=0)flag=false;//��������ֵ 
			//	cout<<"i="<<i<<endl; 
			}
		}
	} 
	if(!flag){
		cout<<"two logical equivalence are not equal"<<endl; 
	}
	else cout<<"two logical equivalence are equal"<<endl; 
	return 0;
}
