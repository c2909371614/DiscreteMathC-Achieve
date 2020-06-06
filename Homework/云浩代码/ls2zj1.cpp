#include<bits/stdc++.h>
using namespace std;
#define N 105
char c[26];
int pri(char ch) {
	int num;
	switch(ch) {
		case '=':
			num=5;
			break;
		case '~':
			num=4;
			break;
		case '&':
			num=3;
			break;
		case '^':
			num=2;
			break;
		case '|':
			num=1;
			break;
		default:
			num=0;
			break;
	}
	return num;
}

int getnumber(char a[],int l) {
	int number=0;
	int i;
	memset(c,'0',sizeof(c));
	for(int i=0; i<l; i++) {
		if(a[i]>='a' && a[i]<='z') {
			c[a[i]-'a']+=1;

		}
	}
	for(int i=0; i<26; i++) {
		if(c[i]!='0') {
			number++;
		}
	}
	return number;
}
char cal(char a[],int l) {
	int i;
	int top=0,j=0;
	stack<char> st;
	char fin[N],result[N];
	char ch;
	fin[0]='#';
	for(i=0; i<=l; i++) {
		switch(a[i]) {
			case '\0':
				while(!st.empty()) {
					fin[++j]=st.top();
					st.pop();
				}
				break;

			case '(':

				st.push(a[i]);
				break;

			case '=':
			case '|':
			case '^':
			case '&':
			case '~':
				while(pri(st.top())>=pri(a[i])) {
					fin[++j]=st.top();
					st.pop();
					cout<<st.top();
				}
				st.push(a[i]);

				break;

			case ')':
				while(st.top()!='(') {
					fin[++j]=st.top();
					st.pop();
				}
				st.pop();
				break;

			default:
				st.push(a[i]);
				cout<<st.top()<<endl;
				break;
		}

	}
	fin[++j]='\0';
	top=0;
	for(i=1; i<j; i++) {
		if(fin[i]=='0'||fin[i]=='1') {
			result[top++]=fin[i];
		} else {
			switch(fin[i]) {
				case '~':
					ch=result[--top];
					result[top]=(ch=='1')?'0':'1';
					top++;
					break;

				case '&':
					ch=result[--top];
					result[top-1]=(ch=='1'&&result[top-1]=='1')?'1':'0';
					break;
				case '|':
					ch=result[--top];
					result[top-1]=(ch=='1'||result[top-1]=='1')?'1':'0';
					break;

				case '^':
					ch=result[--top];
					result[top-1]=(ch==result[top-1])?'0':'1';
					break;
				case '=':
					ch=result[--top];
					result[top-1]=(ch == result[top-1]) ? '0' :1 ;
				default:
					cout<<fin[i]<<endl;
					printf("error?\n");
					break;
			}
		}
	}

	return result[0];
}

int equal(char a[],char b[],int l1,int l2) {
	int i,j;
	char zhi1,zhi2;
	char ctemp[26];//分别位a,b,c的临时数组
	char atemp[N];
	char btemp[N];
	int x=0,y=0;//a,b表达式中的变量个数
	int n;//所有取值的种数
	int tempn,max;
	char list[26];//变量取值表
	y=getnumber(b,l2);
	x=getnumber(a,l1);
//   printf("变量个数：%d\n",x);
	max=x>y?x:y;//取两个表达式中变量（以多的为准）
	n=pow(2.0,max);//获取取值的总数，如3个变量有2^3种
//   printf("取值种数：%d\n",n);
	while(n) {
		getnumber(a,l1);
		strcpy(ctemp,c);//还原
		strcpy(atemp,a);//还原

		tempn=n;

		for(i=x; i>=0; i--) { //Max位变量取值表
			list[i]=tempn%2+'0';
			tempn/=2;

		}
		j=1;
		for(i=0; i<26; i++) { //构建26位取值表
			if(ctemp[i]!='0') {
				ctemp[i]=list[j++];
			}
		}
		for(i=0; i<l1; i++) { //将a表达式中的变量换为对应的值！比如a换为0，b换为0
			if(atemp[i]>='a'&&atemp[i]<='z')
				atemp[i]=ctemp[atemp[i]-'a'];
		}

		strcpy(btemp,b);//还原
		for(i=0; i<l2; i++) { //将b表达式中的变量换为对应的值！比如a换为0，b换为0
			if(btemp[i]>='a'&&btemp[i]<='z')
				btemp[i]=ctemp[btemp[i]-'a'];
		}
		zhi1=cal(atemp,l1);//计算结果
		zhi2=cal(btemp,l2);
		cout<<zhi1<<" "<<zhi2<<endl;
		if(zhi1!=zhi2) { //判断两个表达式值是否相等
			return 0;
		}
		n--;
	}

	return 1;
}
int main() {
	char ans1[N],ans2[N];
	int l1,l2;//两个表达式的长度
	printf("请输入两个逻辑表达式\n");
	while(scanf("%s%s",ans1,ans2)!=EOF) {
		l1=strlen(ans1);
		l2=strlen(ans2);

		if(equal(ans1,ans2,l1,l2))
			printf("Equivalent\n");
		else
			printf("Different\n");
	}
	return 0;
}
