/*��������ʽ�����ֵ��*/ 
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e3;
class Bool_val {
	private:
		string s;//����ʽ
		int num;//�������ĸ���
		int val[MAX];
	public:
		int Degree(char ch) { //�����������ȼ�
			if(ch == '(') return 6;
			if(ch == '!') return 5;
			if(ch == '*') return 4;
			if(ch == '+') return 3;
			return 0;
		}  //������������Сд��ĸ
		string MidToPost(string c) {    //����ʽ��Ӧ�ĺ�׺���ʽ
			stack<char> s;           //�ַ�����ȥ�ֶ�ȥ�ո�
			string q="";
			int n = c.size() ;
			for (int i = 0; i < n; i++) {
				if (c[i] != ' ') {   // ��ȥ�ո�
					// ���������������ֱ�Ӽ��뵽�����У��ö������ź�׺���ʽ
					if (c[i] >= 'a' && c[i] <= 'z') {
						q += c[i];
					} else if (c[i] == '!'&&!s.empty() && s.top() == '!') {
						s.pop();     // �������������ջ��Ҳ��!��ôֱ�ӵ�����ջ
					} else if (!s.size()) {
						s.push(c[i]);// ���ջΪ�գ����������ֱ����ջ
					} else if (c[i] == ')') {
						// ����������ţ��򵯳���Ӧ������ǰ�����е������ �����뵽������
						while (s.top() != '(') {
							q += s.top();
							s.pop();
						}
						s.pop();      // ����������
						continue;
					} else if (Degree(s.top()) == 6 || (Degree(c[i]) > Degree(s.top()))) {
						s.push(c[i]);  // ���ջ���������ţ����ߵ�ǰ���ȼ��ߣ�����ջ
					} else if (Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
						q += s.top();
						s.pop();              // ������������û��ջ�����������ߣ���ջ
						while (!s.empty() && Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
							q+=s.top();  // ��ջ�е����ȵ�ǰ���ȼ��ߵ������
							s.pop();
						}
						s.push(c[i]);  //����ǰ��������뵽ջ
					}
				}
			}
			while (!s.empty()) {
				q += s.top();      // ���ջ��������Ԫ�ص������뵽����
				s.pop();
			}
			return q;
		}
//�˲������������׺���ʽ
		bool Calc(char c) {//��'F'����Ϊfalse 'T'����Ϊtrue
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
			//��׺���ʽ��ֵ
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
			memset(val, 0, sizeof(val));//��ʼ��λ0
			while(a) {
				val[--temp] = a % 2;
				a /= 2;
			}
		}
		void print() {
			cout << "��ʽ������ a+b a*b ��a+b)*b !b:" << endl;
			cin >> s;
			num = 0;
			printf("           ��ֵ��\n");
			printf("-------------------------------\n");
			int ch[26];
			memset(ch, 0, sizeof(ch));
			for(int i = 0; i < s.size(); i++)
				if(s[i] >= 'a' && s[i] <= 'z' && ch[s[i]-'a'] == 0)
					ch[s[i]-'a']++, num++, printf("%-10c ", s[i]);
			printf("%s\n", s.c_str());
			int kind_m = 1 << num, kind = 0;//����������ܴ�����0��ʼ���ö�Ӧ�Ķ���������ʾ��������ֵ 
			s = MidToPost(s);
//			cout << "Post=" << s << "k " << kind << endl;
			string temp_s = s;
			while(kind < kind_m) {
				int pos = 0;
				s = temp_s;
				getBool(kind);//�õ����ݵ�numλ�����Ʊ��ʽ�Դ���Ϊ��ֵ
				int Char_val[26];
				memset(Char_val, -1, sizeof(Char_val));//��ʼ��Ϊ-1
				for(int i = 0; i < s.size(); i++)
					if(s[i] >= 'a' && s[i] <= 'z') { //����Ӧ����ĸ������ֵȷ��
						if(Char_val[s[i]-'a'] == -1) {
							Char_val[s[i]-'a'] = val[pos++];
							printf("%-10c ", val[pos-1] + '0');
						}
					}

				for(int i = 0; i < s.size(); i++)
					if(s[i] >= 'a' && s[i] <= 'z')
						s[i] = Char_val[s[i]-'a'] + '0';//������ʽ���и�ֵ
				printf("%c\n", GetValuePost(s));
				kind++;//kind����0-kind_m-1 
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
