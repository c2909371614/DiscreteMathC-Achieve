#include"head.h"
//�˲������������׺���ʽ 

bool Calc(char c) {//��'0'����Ϊfalse '1'����Ϊtrue 
	if (c == '0') return false;   //  
	else return true;            //  
}

bool conditionalS(bool a,bool b){//a-->b�����㺯�� 
	if(!a||b)return true;
	else return false;
}

bool Equal(bool a,bool b){ //a <--> b�����㺯�� 
	if(a==b)return true;
	else return false;
}
char GetValuePost(string q) {
	//��׺���ʽ��ֵ
	bool r = true;
	char x, y, ans;
	stack<char> s;
	int n = q.size();//cout<<n<<endl;
	for (int i = 0; i < n; i++) {
		if (q[i] == '1' || q[i] == '0') {
			s.push(q[i]);
		}
		 else {
		 	y = s.top();
			s.pop();
		 	if(q[i]=='!') {//!q
				if (Calc(y) == true)
					s.push('0');
				else
					s.push('1');
			}
			else{
				x = s.top();
				s.pop();
				switch(q[i]){
					case '^':r = Calc(x) && Calc(y);break;//'q^p'����Ϊq&&p 
					case '|':r = Calc(x) || Calc(y);break;//qvp��q|p����Ϊq||p 
					case '>':r = conditionalS(Calc(x),Calc(y));break;//���ú������� 
					case '=':r = Equal(Calc(x),Calc(y));break;// 
					default:break;
				}
				if (r == true){
					s.push('1');
				}	
				else{
					s.push('0');
				}
			}
		}
		ans = s.top();
	}
	return ans;
}

