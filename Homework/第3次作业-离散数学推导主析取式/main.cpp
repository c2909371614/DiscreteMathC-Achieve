#include"Head.h"
int main(int argc, char** argv) {
	char str[1000];
	cin>>str;
	eraseConditional(str); 
	cout<<str<<endl;
	DeMorgan(str); 
	cout<<str<<endl;//输出蕴含处理结果 
	
//	string s=absorbChar(str);
//	cout<<s<<endl;
	return 0;
}
