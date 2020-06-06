#include"mainHead.h"
string getA_B(){
    openFile A_B("binRela.txt");//openFile为class 
    string s;
    A_B.io>>s;
    cout<<s<<endl;
    string A,B;//A 为小写字母B为数字
    for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9')
			B+=s[i];
		else if(s[i]>='a'&&s[i]<='z')
			A+=s[i];
	}
	cout<<A<<B<<endl;
	string ans=binRela(A,B); 
    cout<<"AxB="<<ans<<endl;
    A_B.io<<"AxB="<<ans<<endl;//写入文件 
    return ans;
}
