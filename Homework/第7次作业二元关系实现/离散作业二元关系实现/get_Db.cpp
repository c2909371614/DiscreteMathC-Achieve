#include"mainHead.h"
bool Db_flag(int a,int b){//a����b,a��b������ 
	if(a==0||b==0)return false;
	return b%a==0?true:false;
}
string get_Db(){
	openFile Db("binRela.txt");//openFileΪclass 
    string s;
    Db.io>>s;
    //cout<<s<<endl;
    string B;//BΪ����
    for(int i=0; i<s.size(); i++) 
		if(s[i]>='0'&&s[i]<='9')
			B+=s[i];
	string ans("{}");
	int pos=0;//���� ��¼λ�� 
    for(int i=0;i<B.size();i++){
        for(int j=0;j<B.size();j++){
        	if(Db_flag(B[i]-'0',B[j]-'0')==true){
        		stringstream ss;
				ss<<"<"<<B[i]<<","<<B[j]<<">"<<",";           
            	//cout<<ss.str()<<" "<<1+(i*j+j)*6<<endl;
            	ans.insert(1+pos*6,ss.str());
            	pos++;
			}      
        }
    }
    ans.erase(ans.size()-2,1);
    cout<<"Db="<<ans<<endl;//С�ڻ���ڹ�ϵ 
	Db.io<<"Db="<<ans<<endl;
    return ans;  
} 
