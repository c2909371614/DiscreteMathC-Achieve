#include<iostream>  
#include<cstdio>  
#include<stack>  
#include<queue>  
#include<cstring>
#include<string>
#define N 200
using namespace std;
 
 
 
int f(char c);                // 求表达式的优先级  
bool f2(char c);               // 逻辑表达式数的转换
string MidToPost(char* c);      // 求表达式对应的后缀表达式
char GetValuePost(string c);
 
int main()
{
	char str[N];
	string post;
	char ans;
	int i = 0;
	while (cin>>str)
	{
		i++;
		post = MidToPost(str);
		ans = GetValuePost(post);
		printf("Expression %d: %c\n", i, ans);
	}
}
 
int f(char c) 
{                             
	if (c == '(') return 4;
	if (c == '!') return 3;   
	if (c == '&') return 2;   // 相当于*
	if (c == '|') return 1;   // 相当于+，优先级最低
	else
		return 0;
}
 
bool f2(char c) 
{  
	if (c == 'F') return false;   //  F相当于0
	else return true;            //  V相当于1
}
 
string MidToPost(char* c)      //求表达式对应的后缀表达式   
{                             
	stack<char> s;           //字符串中去手动去空格
	string q="";
	int n = strlen(c);
	for (int i = 0; i<n; i++) 
	{
		if (c[i] != ' ')     // 除去空格 
		{    
							// 如果遇到运算数，直接加入到队列中，用队列来放后缀表达式 
			if (c[i] == 'F' || c[i] == 'V')
			{
				q += c[i];
			}
			else if (c[i] == '!'&&!s.empty() && s.top() == '!')
			{ 
				s.pop();     // 如果遇到！而且栈顶也是!那么直接抵消出栈
			}
			else if (!s.size())
			{
				s.push(c[i]); // 如果栈为空，遇到运算符直接入栈 
			}
			else if (c[i] == ')')
			{                 // 如果是右括号，则弹出对应左括号前的所有的运算符 ，加入到队列中 
				while (s.top() != '(')
				{
					q += s.top();
					s.pop();
				}
				s.pop();      // 弹出左括号
				continue;
			}
			else if (f(s.top()) == 4 || (f(c[i]) > f(s.top())))
			{
				s.push(c[i]);  // 如果栈顶是左括号，或者当前优先级高，都入栈
			}
			else if (f(s.top()) != 4 && f(c[i]) <= f(s.top())) 
			{
				q += s.top();
				s.pop();              // 如果遇到运算符没有栈顶运算符级别高，出栈 
				while (!s.empty() && f(s.top()) != 4 && f(c[i]) <= f(s.top()))
				{                   
					q+=s.top();  // 从栈中弹出比当前优先级高的运算符
					s.pop();
				}
				s.push(c[i]);  //将当前运算符加入到队列 
			}
		}
	}
	while (!s.empty()) 
	{    
		q += s.top();      // 最后将栈里面所有元素弹出加入到队列
		s.pop();
	}
	cout<<"q="<<q<<endl;
	return q;
}
 
char GetValuePost(string q)
{                                //后缀表达式求值   
	bool r = true;
	char x, y, ans;
	stack<char> s;
	int n = q.size();
	for (int i = 0; i < n; i++)
	{
		if (q[i] == 'V' || q[i] == 'F')
		{
			s.push(q[i]);
		}
		else
		{
			if (q[i] == '&')
			{
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				r == f2(x) && f2(y);
				if (r == 1)
					s.push('V');
				else
					s.push('F');
			}
			else if (q[i] == '|')
			{
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				r = f2(x) || f2(y);
				if (r == 1)
					s.push('V');
				else
					s.push('F');
			}
			else
			{
				x = s.top();
				s.pop();
				if (f2(x) == 1)
					s.push('F');
				else
					s.push('V');
			}
		}
		ans = s.top();
		
	}
	return ans;
}

