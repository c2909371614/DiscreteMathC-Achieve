#include"mainHead.h"
string get_inverse_R(){
	openFile inverse_R("R.txt");
	string s;
	inverse_R.io>>s;
	cout<<s<<endl;
	string ans=s;//½¨Á¢´ğ°¸
	int pos=myFind(ans); 
	while(pos<ans.size()){
		swap(ans[pos],ans[pos+2]);
		pos+=6;
	} 
	ans.erase(0,2);
	cout<<"R^-1="<<ans<<endl;
	inverse_R.io<<"R^-1="<<ans<<endl;
	return ans;
} 
