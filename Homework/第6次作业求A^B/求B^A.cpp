#include<bits/stdc++.h>
using namespace std;
int myReplace(string &s,const string& s1,const string& s2);
int toN_num(int a,int n1,int n2,int diff[]);//将a转化为n1进制储存在diff中 

int main() {
	fstream io("例8.2.txt",ios::in|ios::app);
	string s,s_num,s_alp;//A用数字表示B用字母表示
	io>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9')
			s_num+=s[i];
		else if(s[i]>='a'&&s[i]<='z')
			s_alp+=s[i];
	}
	cout<<s_num<<" "<<s_alp<<endl;
	string f("{}");
	stringstream ss;/*最后的BA={f..fn}*/
	ss<<"BA={";
	for(int i=0; i<pow(s_alp.size(),s_num.size()); i++) {
		f="{}";
		int diff[s_num.size()];
		memset(diff,0,sizeof(diff));
		toN_num(i,s_alp.size(),s_num.size(),diff);//取不同用于赋值 
		for(int j=0; j<s_num.size(); j++) {
			stringstream temp;
			temp<<"<"<<s_num[j]<<","<<s_alp[diff[j]]<<">";
			if(j!=s_num.size()-1)//不为最后一个加逗号 
				temp<<","; 
			f.insert(1+j*6,temp.str());
		//	cout<<i<<"-"<<j<<":"<<temp.str()<<endl;
		}//cout<<endl;
		ss<<"f"<<i;
		if(i!=pow(s_alp.size(),s_num.size())-1)
			ss<<",";
		else ss<<"}";
		cout<<"f"<<i<<":"<<f<<endl;
		io<<"f"<<i<<":"<<f<<endl;
	}
	cout<<ss.str()<<endl;
	io<<ss.str()<<endl;
	return 0;
}
int myReplace(string &s,const string& s1,const string& s2 ) { //用s2替换s中第一个出现的s1
	s.replace(s.find(s1),s1.size(),s2);
	return s.size();
}
int toN_num(int a,int n1,int n2,int diff[]){//将a转化为n1进制储存在diff中 
	int i=n2;
	while(a!=0){
		diff[--i]=a%n1;//取模
		a/=n1;
		
	}
//	for(int i=0;i<n2;i++)
//		cout<<diff[i]<<" "; 
	return i;
}
