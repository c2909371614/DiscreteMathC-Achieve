#include"mainHead.h"
template <typename T>
bool La_flag(T a,T b){
	return a<=b?true:false;
}
string get_La(){
	openFile La("binRela.txt");//openFileΪclass 
    string s;
    La.io>>s;
    //cout<<s<<endl;
    string A;//A ΪСд��ĸ
    for(int i=0; i<s.size(); i++) 
		if(s[i]>='a'&&s[i]<='z')
			A+=s[i];
	string ans("{}");
	int pos=0;//���� ��¼λ�� 
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
        	if(La_flag(A[i],A[j])==true){
        		stringstream ss;
				ss<<"<"<<A[i]<<","<<A[j]<<">"<<",";           
            	//cout<<ss.str()<<" "<<1+(i*j+j)*6<<endl;
            	ans.insert(1+pos*6,ss.str());
            	pos++;
			}      
        }
    }
    ans.erase(ans.size()-2,1);
	cout<<"La="<<ans<<endl;//С�ڻ���ڹ�ϵ 
	La.io<<"La="<<ans<<endl;
    return ans;    	
}

