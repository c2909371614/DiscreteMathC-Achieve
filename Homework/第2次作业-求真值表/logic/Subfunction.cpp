#include"head.h"
//处理后缀表达式 
int Degree(char c) {
	if (c == '(') return 6;
	if (c == '!') return 5;
	if (c == '^') return 4;   // 相当于q^p
	if (c == '|') return 3;   // 相当于qVp，优先级最低
	if (c == '>') return 2;
	if (c == '=') return 1;
	else
		return 0;
}

string MidToPost(string c) {    //求表达式对应的后缀表达式
	stack<char> s;           //字符串中去手动去空格
	string q="";
	int n = c.size() ;
	for (int i = 0; i<n; i++) {
		if (c[i] != ' ') {   // 除去空格
			// 如果遇到运算数，直接加入到队列中，用队列来放后缀表达式
			if (c[i] == 'F' || c[i] == 'T') {
				q += c[i];
			} 
			else if (c[i] == '!'&&!s.empty() && s.top() == '!') {
				s.pop();     // 如果遇到！而且栈顶也是!那么直接抵消出栈
			} 
			else if (!s.size()) {
				s.push(c[i]);// 如果栈为空，遇到运算符直接入栈	 
			} 
			else if (c[i] == ')') {
				// 如果是右括号，则弹出对应左括号前的所有的运算符 ，加入到队列中
				while (s.top() != '(') {
					q += s.top();
					s.pop();
				}
				s.pop();      // 弹出左括号
				continue;
			} 
			else if (Degree(s.top()) == 6 || (Degree(c[i]) > Degree(s.top()))) {
				s.push(c[i]);  // 如果栈顶是左括号，或者当前优先级高，都入栈
			} 
			else if (Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
				q += s.top();
				s.pop();              // 如果遇到运算符没有栈顶运算符级别高，出栈
				while (!s.empty() && Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
					q+=s.top();  // 从栈中弹出比当前优先级高的运算符
					s.pop();
				}
				s.push(c[i]);  //将当前运算符加入到栈
			}
		}
	}
	while (!s.empty()) {
		q += s.top();      // 最后将栈里面所有元素弹出加入到队列
		s.pop();
	}
	return q;
}
