#include"Head.h"
int DeMorgan(char str[]){
	
	int bi/*储存左指针*/,ei/*储存右指针*/;
	int len=strlen(str);//获取长度 
	char str2[10000]; 
	char a[]="";
	queue<char> que;
	char ans[10000];
	strcpy(str2,str);//复制预处理字符储存到str2 
	for(int i=0;i<len;i++){
		char fin[1000];
		if(str2[i]=='~' && str2[i+1]=='('){//遇到~（ 
			bi=i-1;//左指针 
			int j=i+2,cnt=0;// 
			
			int bracketNum=0;// 检查括号匹配 
			while(str2[j]!=')'||bracketNum!=0/*j=j+2  '('不包含*/){//没有遇到右括号 
				if (str[j]=='(')bracketNum++;
				if(str[j]==')')bracketNum--;//检查括号匹配 
				if(str2[j]>='a' && str2[j]<='z') {
					fin[cnt++]='~';
					fin[cnt++]=str[j];//在字母前面加'~' 
				}
				else if(str2[j]=='|') fin[cnt++]='&';
				else if(str2[j]=='&')fin[cnt++]='|';
				else fin[cnt++]=str2[j];//'~'照抄 
				j++;//指针向后扫 
			}
			ei=j+1;//ei指针后面的未处理的部分 
			for(int j=0;j<=bi;j++)//bi前面的未处理的部分入队列 
				que.push(str2[j]);
			for(int j=0;j<strlen(fin);j++)//将处理好的部分入队列 
				que.push(fin[j]);
			for(int j=ei;j<len;j++){//ei指针后面的未处理的部分
				que.push(str2[j]);
			}
			strcpy(str2,a);
			int qLen=que.size();
			for(int j=0;j<qLen;j++){
//				cout<<que.front();
    			ans[j]=que.front();
    			que.pop();
			}
//			cout<<endl;
			cout<<ans<<endl;
			strcpy(str2,a);
			strcpy(str2,ans);
		}
	}
	int len1=strlen(ans);
	for(int i=0;i<len1;i++){
		if(ans[i]=='~' && ans[i+1]=='~'){
          len1=len1-2;
			for(int j=i;j<len1;j++) {
				ans[j]=ans[j+2];
			}
		}
	}
	ans[len1]='\0';//加上结尾标识符 /0 
	//cout<<ans<<endl;
	strcpy(str,ans); 

}
