#include"head.h"
int main() {
	//char [N];
	FILE *fp;
	fp=fopen("logic_run.txt","r");
	char ch[100];	
	string str;
	int i = 0,count=0;
	int count1=0,count2=0;//运算数的个数 
	int m1[100],m2[100];//用于储存极小项// 
	cout<<"离散课程逻辑表达式求值，可在文件中输入任何逻辑表达式均可打印出其真值表"<<endl;//print the introduce
	cout<<"q|p相当于qvp"<<endl;
	memset(m1,0,sizeof(m1));
	memset(m2,0,sizeof(m2));
	while (~fscanf(fp,"%s",ch)){//read the file put on ch
		for(i=0;i<strlen(ch);i++){ 
			str+=ch[i];
		}
		if((count&1)==0) 
			count1=Count(str,m1);
		else count2=Count(str,m2);//cout<<(count1)<<endl;;cout<<(count)<<endl;} 
		str.clear();//将str清空预备下次储存 
		count++;//用于奇偶判别 
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
				if(m2[i]==0)flag=false;//两个不等值 
			//	cout<<"i="<<i<<endl; 
			}
		}
		else {
			for(int i=j<<(count2-count1);i<=(j<<(count2-count1))+(count2-count1);i++){
				if(m2[i]!=0)flag=false;//两个不等值 
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
