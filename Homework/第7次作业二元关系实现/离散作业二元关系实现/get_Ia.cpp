#include"mainHead.h"
string get_Ia(){
	openFile Ia("binRela.txt");//openFileΪclass 
    string s;
    Ia.io>>s;
    //cout<<s<<endl;
    string A;//A ΪСд��ĸ
    for(int i=0; i<s.size(); i++) 
		if(s[i]>='a'&&s[i]<='z')
			A+=s[i];
//	cout<<A<<endl;//
	string ans("{}");
    for(int i=0;i<A.size();i++){       
            stringstream ss;
            ss<<"<"<<A[i]<<","<<A[i]<<">";
            if(i!=A.size()-1)
                ss<<",";
            //cout<<ss.str()<<" "<<5+(i*j+j)*6<<endl;
            ans.insert(1+i*6,ss.str());        
    }
	cout<<"Ia="<<ans<<endl;
	Ia.io<<"Ia="<<ans<<endl;
    return ans;    
}
