#include<bits/stdc++.h> 
using namespace std;
class Bin_fun{
	public:
		string x,y,s;//sΪԭ�ӷ�����xΪ��һԪ�أ�yΪ�ڶ�Ԫ�� 
	Bin_fun(string newS){
		s=newS;
		int pos=-1;
		for(int i=0;i<s.size();i++)
			if(s[i]>='0'&&s[i]<='9'){
				pos=i;
				break;
			}	
		for(int i=pos;i<s.size();i+=6){
			x+=s[i];
			y+=s[i+2];
		}
	}	
};
class openFile{//���ļ���class 
private:
public:
    fstream io;
    openFile(string filename){
        io.open(filename.c_str(),ios::in|ios::app);
    }
    ~openFile(){
        io.close();
    }
};
int myFind(string s){//Ѱ�������ַ�������λ�� 
	for(char i='0';i<='9';i++){
		int pos=s.find(i);
		if(pos!=s.npos)
			return pos;
	} 
}
string get_inverse_R(){
	openFile inverse_R("R.txt");
	string s;
	inverse_R.io>>s;
	cout<<s<<endl;
	string ans=s;//������
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

void myNoSame(string& s){
	int a[300];
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++){
		a[s[i]]++;
	}
	s.clear();
	for(int i=0;i<300;i++)
		if(a[i]!=0)
			s+=i;	
}
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
		ss.str("");//���ss�Ļ��� 
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
		ss.str("");//���ss�Ļ��� 
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
		ss.str("");//���ss�Ļ��� 
	}
	ans.replace(ans.size()-1,1,"}");
	cout<<"fldR="<<ans<<endl;
	fldR.io<<"fldR="<<ans<<endl;
	return ans; 
}
string right_combine(string a,string b){//a��b 
	string ans("{}");
	Bin_fun A(a),B(b);
	int  pos=0;//��¼����λ�� 
	for(int i=0;i<A.y.size();i++){
		for(int j=0;j<B.x.size();j++){//��a�ĵڶ�Ԫ�غ�b�ĵ�һԪ�ؽ��бȽ� 
			if(A.y[i]==B.x[j]){
				stringstream ss;
				ss<<"<"<<A.x[i]<<","<<B.y[j]<<">"<<",";           
            	//cout<<ss.str()<<" "<<1+(i*j+j)*6<<endl;
            	ans.insert(1+pos*6,ss.str());
            	pos++;
			}		
		}
	}//cout<<"ok"<<endl;
	ans.erase(ans.size()-2,1);
	//cout<<"a��b:"<<ans<<endl;
	return ans; 
}
void myDelet(string &s,char ch){//ɾ��s�г��ֵ�����ch 
	int pos=-1;
	while(s.find(ch,pos+1)!=s.npos){
		pos=s.find(ch);
		s.erase(pos,1);
	}
	//cout<<s<<" "<<ch<<endl;
}
void get_string_R_A(string &R,string &A,string filename){
	openFile right(filename.c_str());//�ҽ�� 
	right.io>>R;//cout<<"R:"<<R<<endl;
	myDelet(R,'=');
	for(char i='A';i<='Z';i++)
		myDelet(R,i);
	right.io>>A;
	myDelet(A,'=');
	for(char i='A';i<='Z';i++)
		myDelet(A,i);
	cout<<"R:"<<R<<" A:"<<A<<endl;//������R��A�Ķ�ȡ��� 
	
} 
void solve_R_A(){
	openFile right("right_combine.txt");
	string R,A;
	get_string_R_A(R,A,"right_combine.txt");
	//cout<<"R:"<<R<<" A:"<<A<<endl;//������R��A�Ķ�ȡ��� 
	string ans=right_combine(R,A); //����R��A
	cout<<"R��A="<<ans<<endl;
	right.io<< "\nR��A="<<ans<<endl;
}
string get_num_char(string s){//��ȡ���ַ����е������ַ� 
	string ans;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			ans+=s[i];
	return ans;
}
string calc_limit(string R,string A){
	Bin_fun ob_R(R);
	string aTemp=get_num_char(A);
	string ans("{}");
	int pos=0;//���� ��¼λ�� 
    for(int i=0;i<aTemp.size();i++){
        for(int j=0;j<ob_R.x.size();j++){
        	if(ob_R.x[j]==aTemp[i]){//��һԪ�������Ƽ���Ԫ����� 
        		stringstream ss;
				ss<<"<"<<aTemp[i]<<","<<ob_R.y[j]<<">"<<",";           
            	//cout<<ss.str()<<" "<<1+(i*j+j)*6<<endl;
            	ans.insert(1+pos*6,ss.str());
            	pos++;
			}      
        }
    }
    ans.erase(ans.size()-2,1);
    //cout<<"R|A="<<ans<<endl;
    return ans;
}
void solve_limit_R_A(){//R��A�ϵ����� R|A 
	openFile lim("limit.txt");
	string R,A;
	get_string_R_A(R,A,"limit.txt");
//	cout<<"R:"<<R<<" A:"<<A<<endl;//������R��A�Ķ�ȡ��� 
	string ans=calc_limit(R, A);
	cout<<"R|A="<<ans<<endl;
	lim.io<<"R|A="<<ans<<endl;	 
}
string calc_mirror(string R,string A){
	Bin_fun ob_R(R);
	string aTemp=get_num_char(A);
	string ans("{}");
	int pos=0;//���� ��¼λ�� 
    for(int i=0;i<aTemp.size();i++){
        for(int j=0;j<ob_R.x.size();j++){
        	if(ob_R.x[j]==aTemp[i]){//��һԪ�������Ƽ���Ԫ����� 
        		stringstream ss;
				ss<<ob_R.y[j]<<",";           
            	//cout<<ss.str()<<" "<<1+(i*j+j)*6<<endl;
            	ans.insert(1+pos*2,ss.str());
            	pos++;
			}      
        }
    }
    ans.erase(ans.size()-2,1);
    //cout<<"R|A="<<ans<<endl;
    return ans;
}
void solve_mirror_R_A(){//R��A�ϵ����� R|A 
	openFile lim("limit.txt");
	string R,A;
	get_string_R_A(R,A,"limit.txt");
//	cout<<"R:"<<R<<" A:"<<A<<endl;//������R��A�Ķ�ȡ��� 
	string ans=calc_mirror(R, A);
	cout<<"R[A]="<<ans<<endl;
	lim.io<<"R|A="<<ans<<endl;	 
}
int main(){
	get_inverse_R();//���ϵ 
	domR();
	ranR();
	fldR();
	solve_R_A();
	solve_limit_R_A(); 
	solve_mirror_R_A();
}
