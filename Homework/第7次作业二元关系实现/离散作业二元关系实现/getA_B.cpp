#include"mainHead.h"
string getA_B(){
    openFile A_B("binRela.txt");//openFileΪclass 
    string s;
    A_B.io>>s;
    cout<<s<<endl;
    string A,B;//A ΪСд��ĸBΪ����
    for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9')
			B+=s[i];
		else if(s[i]>='a'&&s[i]<='z')
			A+=s[i];
	}
	cout<<A<<B<<endl;
	string ans=binRela(A,B); 
    cout<<"AxB="<<ans<<endl;
    A_B.io<<"AxB="<<ans<<endl;//д���ļ� 
    return ans;
}
