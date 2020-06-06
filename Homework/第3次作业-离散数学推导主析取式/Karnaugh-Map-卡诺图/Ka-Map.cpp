#include<bits/stdc++.h>
using namespace std;
class KarnoMap {
	private:
		string formulas;//����ʽ
		vector<int> ans;//��¼��
		int size;//������λ��
		map<char, int>tot;//���
		string simple_s;
		int add_ans(const string& s);//�õ����
		
	public:
		KarnoMap();
		KarnoMap(string s);
		void read_check();//get size
		void calc_val();
		void get_simple_s();
		void print();
		void input();
		string turn_bin_s(int a);//����ֵת���ɶ������ַ� 
};
KarnoMap::KarnoMap(string s) {
	formulas = s;
	size = 0;
}
KarnoMap::KarnoMap() {
	size = 0;//init size in 0;
}
void KarnoMap::read_check() {
	int ch[26];
	memset(ch, 0, sizeof(ch));
	int len = formulas.size();
	while(len--) {
		if(formulas[len] >= 'A' && formulas[len] <= 'Z')
			ch[formulas[len] - 'A']++;//formulas�е������������Ǵ�д��ĸ
	}
	int count = 0;
	for(unsigned i = 0; i < formulas.size(); i++)
		if(ch[i] > 0) {
			size++;//���������������
			tot[i + 'A'] = count++;
		}
	puts(formulas.c_str());
}
int KarnoMap::add_ans(const string& s) {
	int len = 1 << size;//��ȡ���п���
	int ask[size];//��Ҫ��
	memset(ask, -1, sizeof(ask));//��ʼ��Ϊ-1��-1Ϊ��Ҫ��
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= 'a' && s[i] <= 'z')//СдΪ��
			ask[tot[s[i] - ('a' - 'A')]] = 0;
		else ask[tot[s[i]]] = 1;
	}
	while(len--) {
		int bin[size];
		memset(bin, 0, sizeof bin);
		int tm_len = len;
		int i = size;//�Ӻ����¼
		while(tm_len) {
			bin[--i] = tm_len % 2;
			tm_len /= 2;
		}
		bool flag = true;
		for(int i = 0; i < size; i++)
			if(!(ask[i] == -1 || ask[i] == bin[i])) flag = false;//��ƥ��
		if(find(ans.begin(), ans.end(), len) == ans.end() && flag)
			ans.push_back(len);
	}
}
void KarnoMap::calc_val() {
	string temp = "";
	for(int i = 0; i <= formulas.size(); i++) {
		
		if(formulas[i] == '!') { //��Сд��ʾ��
			temp += formulas[i + 1] + ('a' - 'A');
			i++;
		} else if(formulas[i] >= 'A' && formulas[i] <= 'Z') {
			temp += formulas[i];
		} else if(formulas[i] == '*') {
			temp += formulas[i + 1];
			i++;
		} else if(formulas[i] == '+' || formulas[i] == '\0') {
			add_ans(temp);
			temp = "";
		}
		
	}
}
string KarnoMap::turn_bin_s(int a){//
	string ans="";
	while(a){
		ans += a % 2 + '0';
		a /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
} 
void KarnoMap::get_simple_s(){
	
} 
void KarnoMap::print() {
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
}
void KarnoMap::input(){
	printf("������������ʽ:");
	cin >> formulas;
}
void get_kar_map(){//��ŵͼ������ȡʽ
	KarnoMap map("A*B + B*C");
	map.input();
	map.read_check();
	map.calc_val();
	map.print();
} 
void get_kar_simple(){
	KarnoMap map;
	map.input();
	map.read_check();
	map.calc_val();
}
int main() {
	
}
