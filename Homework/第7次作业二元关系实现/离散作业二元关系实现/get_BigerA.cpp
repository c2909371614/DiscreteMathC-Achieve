#include"mainHead.h"
template <typename T>
bool BigerA_flag(T a,T b){
	return a>b?true:false;
}
string get_BigerA(){
	openFile BigerA("binRela.txt");//openFileΪclass 
    string s;
    BigerA.io>>s;
   // cout<<s<<endl;
    string A;//A ΪСд��ĸ
    
    for(int i=0; i<s.size(); i++) 
		if(s[i]>='a'&&s[i]<='z')
			A+=s[i];
	string ans("{}");//cout<<A<<endl;
	int pos=0;//���� ��¼λ�� 
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
        	if(BigerA_flag(A[i],A[j])==true){
        		stringstream ss;
				ss<<"<"<<A[i]<<","<<A[j]<<">"<<",";           
            	//cout<<ss.str()<<" "<<1+(i*j+j)*6<<endl;
            	ans.insert(1+pos*6,ss.str());
            	pos++;
			}      
        }
    }
    ans.erase(ans.size()-2,1);
	cout<<"BigerA="<<ans<<endl;//���ڹ�ϵ 
	BigerA.io<<"BigerA="<<ans<<endl;
    return ans;    	
}
