#include<bits/stdc++.h>
using namespace std;
const int MAX_NUM=105;
class openFile { //打开文件的class
	private:
	public:
		fstream io;
		openFile(string filename) {//需要指定文件名
			io.open(filename.c_str(),ios::in|ios::app);//以读取和添加的方式打开
		}
		~openFile() {
			io.close();
		}
};
class Bin_fun { //将读取的字符串形式转化为两个元素字符串
	public:
		string x,y,s;//s为原子符串，x为第一元素，y为第二元素
		Bin_fun(string newS) { //new 为a={(1,2),(2,3)...}
			s=newS;
			int pos=-1;
			for(int i=0; i<s.size(); i++)
				if(s[i]>='0'&&s[i]<='9') {
					pos=i;
					break;
				}
			for(int i=pos; i<s.size(); i+=6) {
				x+=s[i];
				y+=s[i+2];
			}
			//cout<<x<<endl;
			//cout<<y<<endl;
		}
};
string get_D_(int n){//T+ D(d)后续 
	openFile link("link.txt");
	string s;
	link.io>>s;
	string s1;
	link.io>>s1;
	Bin_fun E(s1.c_str());//转换 
	string ans("{") ,ansTemp;//ansTemp用于返回有价值的量 ans用于记录字符结果带 {} 
	for(int i=0;i<E.x.size();i++)
		if(E.x[i]-'0'==n&&ans.find(E.y[i])==string::npos&&n!=E.y[i]-'0'){//cout<<"ok"<<endl;
			ans+=E.y[i];
			ans+=',';
			ansTemp+=E.y[i];
		}
	ans.replace(ans.size()-1,1,"}");//将多余的，号替换 
	cout<<"T+="	<<ans<<endl;
	link.io<<"T+="	<<ans<<endl;	
	
	return ansTemp; 
}
string get_D(int n){//T- D(d)前驱 
	openFile link("link.txt");
	string s;
	link.io>>s;
	string s1;
	link.io>>s1;
	Bin_fun E(s1.c_str());//转换 
	string ans("{") ,ansTemp;//ansTemp用于返回有价值的量 ans用于记录字符结果带 {} 
	for(int i=0;i<E.y.size();i++)
		if(E.y[i]-'0'==n&&ans.find(E.x[i])==string::npos&&n!=E.x[i]-'0'){
			ans+=E.x[i];
			ans+=',';
			ansTemp+=E.x[i];
		}		
	ans.replace(ans.size()-1,1,"}");//将多余的，号替换
	cout<<"T-="	<<ans<<endl;
	link.io<<"T-="	<<ans<<endl;
	return ansTemp; 
}
string ND_d(int n){//邻域  
	openFile link("link.txt");
	string ans("{"),ansTemp;
	string s1=get_D(n),s2=get_D_(n);
	for(int i=0;i<s1.size();i++){
		if(ans.find(s1[i])==string::npos)
			ans+=s1[i];
			ans+=',';
			ansTemp+=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(ans.find(s2[i])==string::npos)
			ans+=s2[i];
			ans+=',';
			ansTemp+=s2[i];
	}
	ans.replace(ans.size()-2,2,"}");//将多余的，号替换
	cout<<"ND_d="<<ans<<endl;
	link.io<<"ND_d="<<ans<<endl;
	return ans; 
}
void ND_d_(int n){//闭邻域 
	openFile link("link.txt");
	string ans=ND_d(n);
	ans.insert(ans.size()-1,1,',');
	ans.insert(ans.size()-1,1,n+'0');
	cout<<"ND_d="<<ans<<endl;
	link.io<<"ND_d="<<ans<<endl;
}
int main() {
	ND_d_(4);
}
