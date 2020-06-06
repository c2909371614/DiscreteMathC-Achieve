#include"mainHead.h"
string domR(){
	openFile domR("R.txt");
	string s;
	domR.io>>s;
	//cout<<s<<endl;
	int pos=myFind(s);//cout<<pos<<":"<<s[pos]<<endl;
	string ans("{");//cout<<"invoked"<<endl;
	stringstream ss;
	while(pos<s.size()){
		ss<<s[pos]<<",";
		ans+=ss.str();
		ss.str("");//清空ss的缓存 
		pos+=6;
	} 
	ans.replace(ans.size()-1,1,"}");
	cout<<"domR="<<ans<<endl;
	domR.io<<"domR"<<ans<<endl; 
	return ans;
}
string ranR(){
	openFile ranR("R.txt");
	string s;
	ranR.io>>s;
	//cout<<s<<endl;
	int pos=myFind(s)+2;//cout<<pos<<":"<<s[pos]<<endl;
	string ans("{");//cout<<"invoked"<<endl;
	stringstream ss;
	while(pos<s.size()){
		ss<<s[pos]<<",";
		ans+=ss.str();
		ss.str("");//清空ss的缓存 
		pos+=6;
	} 
	ans.replace(ans.size()-1,1,"}");
	cout<<"ranR="<<ans<<endl;
	ranR.io<<"ranR"<<ans<<endl; 
	return ans;
}
string fldR(){
	openFile fldR("R.txt");
	string s;
	fldR.io>>s;
	string ansTemp;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			ansTemp+=s[i];
	myNoSame(ansTemp);
	//cout<<ansTemp<<endl;
	string ans("{");
	stringstream ss;
	for(int i=0;i<ansTemp.size();i++){
		ss<<ansTemp[i]<<",";
		ans+=ss.str();
		ss.str("");//清空ss的缓存 
	}
	ans.replace(ans.size()-1,1,"}");
	cout<<"fldR="<<ans<<endl;
	fldR.io<<"fldR="<<ans<<endl;
	return ans; 
}
