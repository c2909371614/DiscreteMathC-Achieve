#include"mainHead.h"
string binRela(string A,string B){//����AxB 
	string ans("{}");
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
            stringstream ss;
            ss<<"<"<<A[i]<<","<<B[j]<<">";
            if(i!=A.size()-1||j!=B.size()-1)
                ss<<",";
            //cout<<ss.str()<<" "<<5+(i*j+j)*6<<endl;
            ans.insert(1+(i*B.size()+j)*6,ss.str());
        }
    }//cout<<ans<<endl;
    return ans;    
}
string binRela(string A,string B,bool flag){//����AxB A��B�����ϵflag 
	string ans("{}");
	int pos=0;//���� ��¼λ�� 
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B.size();j++){
        	if(flag==true){
        		stringstream ss;
				ss<<"<"<<A[i]<<","<<B[j]<<">"<<",";           
            	//cout<<ss.str()<<" "<<1+(i*j+j)*6<<endl;
            	ans.insert(1+pos*6,ss.str());
            	pos++;
			}      
        }
    }
    ans.erase(ans.size()-2,1);
	cout<<ans<<endl;
    return ans;    
}
int myFind(string s){//Ѱ�������ַ�������λ�� 
	for(char i='0';i<='9';i++){
		int pos=s.find(i);
		if(pos!=s.npos)
			return pos;
	} 
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
