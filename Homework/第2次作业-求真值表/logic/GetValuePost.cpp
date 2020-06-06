#include"head.h"
//此部分用于运算后缀表达式 

bool Calc(char c) {//将'F'定义为false 'T'定义为true 
	if (c == 'F') return false;   //  
	else return true;            //  
}

bool conditionalS(bool a,bool b){//a-->b的运算函数 
	if(!a||b)return true;
	else return false;
}

bool Equal(bool a,bool b){ //a <--> b的运算函数 
	if(a==b)return true;
	else return false;
}
char GetValuePost(string q) {
	//后缀表达式求值
	bool r = true;
	char x, y, ans;
	stack<char> s;
	int n = q.size();//cout<<n<<endl;
	for (int i = 0; i < n; i++) {
		if (q[i] == 'T' || q[i] == 'F') {
			s.push(q[i]);
		}
		 else {
		 	y = s.top();
			s.pop();
		 	if(q[i]=='!') {//!q
				if (Calc(y) == true)
					s.push('F');
				else
					s.push('T');
			}
			else{
				x = s.top();
				s.pop();
				switch(q[i]){
					case '^':r = Calc(x) && Calc(y);break;//'q^p'定义为q&&p 
					case '|':r = Calc(x) || Calc(y);break;//qvp即q|p定义为q||p 
					case '>':r = conditionalS(Calc(x),Calc(y));break;//运用函数运算 
					case '=':r = Equal(Calc(x),Calc(y));break;// 
					default:break;
				}
				if (r == true){
					s.push('T');
				}	
				else{
					s.push('F');
				}
			}
		}
		ans = s.top();
	}
	return ans;
}
