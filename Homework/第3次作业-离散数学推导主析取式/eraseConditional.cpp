#include"Head.h"
int print(char str[]){
	for(int i=0;i<strlen(str);i++)	
		cout<<str[i];
	cout<<endl;
	return 0;
}
int eraseConditional(char str[]){
	
	stack<char> stk;//处理前端 的stack
	int bi/*储存左指针*/,ei; 
	char ans[10000];
	for(int i=0; i<strlen(str); i++) { //遍历预处理字符
		char fin[1000];//处理前端 
		char fin2[1000];
		if(str[i]=='^') {
			fin[0]='~';//在字符前加~和括号（
			fin[1]='(';
			int l=i,r=i;//l为左指针 r为右指针
			
			//遇到括号 
			if(str[l-1]==')') { 
				int count=2;//作为fin的下标 fin[0]为~，fin[1]为（ 
				l--;
				int bracketNum=0;
				while(str[l]!='('||bracketNum!=1) {//因为第一个')'要入stack所以  =1 
					if (str[l]==')')bracketNum++;
					if(str[l]=='(')bracketNum--;//检查括号匹配 
					stk.push(str[l]);//把左括号之前的入栈 
					//cout<<stk.top()<<endl;
					l--;//左移 
				}
				bi=l;//储存左指针 
				while(!stk.empty()) {
					fin[count++]=stk.top();
					stk.pop();
				}
			} //无括号 
			else {
				fin[1]=str[l-1];
				bi=l-1;
			}// 推的右边有括号
			 
			if(str[r+1]=='(') {
				r++;
				int count=0;
				while(str[r]!=')') {//存在括号匹配问题 
					fin2[count++]=str[r];
					r++;
				}
				ei=r;
				fin2[count]=')';
			} //右边无括号 
			else {
				fin2[0]=str[r+1];
				ei=r+1;
			}
			print(fin);
			print(fin2);
			queue<char> que;//用于最后整合 
			for(int j=0; j<bi; j++)//将bi指针前面未处理部分入队列 
				que.push(str[j]);
			for(int j=0; j<strlen(fin); j++)//将处理好的部分fin(运算符‘^’左边的运算数）入队列 
				que.push(fin[j]);
			que.push('|');//插入‘|’运算符 
			for(int j=0; j<strlen(fin2); j++)//将'^' 右边的运算数入队列 
				que.push(fin2[j]);
			for(int j=ei+1; j<strlen(str); j++)//将ei指针后面未处理部分入队列 
				que.push(str[j]);
			int s=que.size();
			for(int j=0; j<s; j++) {//推出所有队列元素附加给str 
				str[j]=que.front();
				que.pop();
			}
		}
	}
	return 0;
}

