/*输入运算式输出真值表*/ 
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e3;
class Bool_val {
	private:
		string s;//运算式
		int num;//运算数的个数
		int val[MAX];
	public:
		int Degree(char ch) { //定义运算优先级
			if(ch == '(') return 6;
			if(ch == '!') return 5;
			if(ch == '*') return 4;
			if(ch == '+') return 3;
			return 0;
		}  //运算数必须是小写字母
		string MidToPost(string c) {    //求表达式对应的后缀表达式
			stack<char> s;           //字符串中去手动去空格
			string q="";
			int n = c.size() ;
			for (int i = 0; i < n; i++) {
				if (c[i] != ' ') {   // 除去空格
					// 如果遇到运算数，直接加入到队列中，用队列来放后缀表达式
					if (c[i] >= 'a' && c[i] <= 'z') {
						q += c[i];
					} else if (c[i] == '!'&&!s.empty() && s.top() == '!') {
						s.pop();     // 如果遇到！而且栈顶也是!那么直接抵消出栈
					} else if (!s.size()) {
						s.push(c[i]);// 如果栈为空，遇到运算符直接入栈
					} else if (c[i] == ')') {
						// 如果是右括号，则弹出对应左括号前的所有的运算符 ，加入到队列中
						while (s.top() != '(') {
							q += s.top();
							s.pop();
						}
						s.pop();      // 弹出左括号
						continue;
					} else if (Degree(s.top()) == 6 || (Degree(c[i]) > Degree(s.top()))) {
						s.push(c[i]);  // 如果栈顶是左括号，或者当前优先级高，都入栈
					} else if (Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
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
//此部分用于运算后缀表达式
		bool Calc(char c) {//将'F'定义为false 'T'定义为true
			if (c == '0') return false;   //
			else return true;            //
		}
		bool add(char a, char b) { //a + b
			return Calc(a) || Calc(b) ? true : false;
		}
		bool product(char a, char b) {
			return Calc(a) && Calc(b) ? true : false;
		}
		char GetValuePost(string q) {
			//后缀表达式求值
			bool r = true;
			char x, y, ans;
			stack<char> s;
			int n = q.size();//cout<<n<<endl;
			for (int i = 0; i < n; i++) {
				if (q[i] == '0' || q[i] == '1') {
					s.push(q[i]);
				} else {
					y = s.top();
					s.pop();
					if(q[i] == '!') {//!q
						if (Calc(y) == true)
							s.push('0');
						else
							s.push('1');
					} else {
						x = s.top();
						s.pop();
						switch(q[i]) {
							case '+':
								r = add(x, y);
								break;//a+b
							case '*':
								r = product(x, y);
								break;//a*b
						}
						if (r == true) {
							s.push('1');
						} else {
							s.push('0');
						}
					}
				}
				ans = s.top();
			}
			return ans;
		}
		void getBool(int a) {
			int temp = num;
			memset(val, 0, sizeof(val));//初始化位0
			while(a) {
				val[--temp] = a % 2;
				a /= 2;
			}
		}
		void print() {
			cout << "格式类似于 a+b a*b （a+b)*b !b:" << endl;
			cin >> s;
			num = 0;
			printf("           真值表\n");
			printf("-------------------------------\n");
			int ch[26];
			memset(ch, 0, sizeof(ch));
			for(int i = 0; i < s.size(); i++)
				if(s[i] >= 'a' && s[i] <= 'z' && ch[s[i]-'a'] == 0)
					ch[s[i]-'a']++, num++, printf("%-10c ", s[i]);
			printf("%s\n", s.c_str());
			int kind_m = 1 << num, kind = 0;//最多的运算可能次数从0开始，用对应的二进制数表示运算数的值 
			s = MidToPost(s);
//			cout << "Post=" << s << "k " << kind << endl;
			string temp_s = s;
			while(kind < kind_m) {
				int pos = 0;
				s = temp_s;
				getBool(kind);//得到数据的num位二进制表达式以此作为其值
				int Char_val[26];
				memset(Char_val, -1, sizeof(Char_val));//初始化为-1
				for(int i = 0; i < s.size(); i++)
					if(s[i] >= 'a' && s[i] <= 'z') { //将相应的字母进行数值确定
						if(Char_val[s[i]-'a'] == -1) {
							Char_val[s[i]-'a'] = val[pos++];
							printf("%-10c ", val[pos-1] + '0');
						}
					}

				for(int i = 0; i < s.size(); i++)
					if(s[i] >= 'a' && s[i] <= 'z')
						s[i] = Char_val[s[i]-'a'] + '0';//对运算式进行赋值
				printf("%c\n", GetValuePost(s));
				kind++;//kind递增0-kind_m-1 
			}
		}
};

int main() {
	while(1) {
		Bool_val Test;
		Test.print();
		system("pause");
	} 
}
