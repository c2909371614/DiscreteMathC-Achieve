#include"mainHead.h"
string getA_A(){
	openFile A_A("binRela.txt");//openFileΪclass 
    string s;
    A_A.io>>s;
//    cout<<s<<endl;
    string A;//A ΪСд��ĸ
    for(int i=0; i<s.size(); i++) 
		if(s[i]>='a'&&s[i]<='z')
			A+=s[i];
	string ans=binRela(A,A);
	A_A.io<<"AXA="<<ans<<endl;
	cout<<"AXA="<<ans<<endl;
	return ans;
}
