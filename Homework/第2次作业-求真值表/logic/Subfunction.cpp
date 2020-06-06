#include"head.h"
//�����׺���ʽ 
int Degree(char c) {
	if (c == '(') return 6;
	if (c == '!') return 5;
	if (c == '^') return 4;   // �൱��q^p
	if (c == '|') return 3;   // �൱��qVp�����ȼ����
	if (c == '>') return 2;
	if (c == '=') return 1;
	else
		return 0;
}

string MidToPost(string c) {    //����ʽ��Ӧ�ĺ�׺���ʽ
	stack<char> s;           //�ַ�����ȥ�ֶ�ȥ�ո�
	string q="";
	int n = c.size() ;
	for (int i = 0; i<n; i++) {
		if (c[i] != ' ') {   // ��ȥ�ո�
			// ���������������ֱ�Ӽ��뵽�����У��ö������ź�׺���ʽ
			if (c[i] == 'F' || c[i] == 'T') {
				q += c[i];
			} 
			else if (c[i] == '!'&&!s.empty() && s.top() == '!') {
				s.pop();     // �������������ջ��Ҳ��!��ôֱ�ӵ�����ջ
			} 
			else if (!s.size()) {
				s.push(c[i]);// ���ջΪ�գ����������ֱ����ջ	 
			} 
			else if (c[i] == ')') {
				// ����������ţ��򵯳���Ӧ������ǰ�����е������ �����뵽������
				while (s.top() != '(') {
					q += s.top();
					s.pop();
				}
				s.pop();      // ����������
				continue;
			} 
			else if (Degree(s.top()) == 6 || (Degree(c[i]) > Degree(s.top()))) {
				s.push(c[i]);  // ���ջ���������ţ����ߵ�ǰ���ȼ��ߣ�����ջ
			} 
			else if (Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
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
