#include"mainHead.h"//�Ѷ���Ϊ�ռ� 
int mySub(string s,string subS[]){
	int pos=s.find('{')+1;
	int num=0;//int test=0;
	for(int i=pos;i<s.size();){
		if(s[i]=='{'){
			while(s[i+1]!='}'){//cout<<"test:"<<test++<<endl;
				if(i+1>s.size())break;
				subS[num]+=s[i+1];
				i++;
			}
			num++;//��i���Ӽ�
			i++;
		}
		else if(s[i]=='@'){//���ռ� 
			subS[num]="@";
			num++;
			i++;//cout<<s[i];
		} 
		else {//cout<<s[i];
			i++;	
		}		
	}
	//cout<<"num="<<num<<endl;
	return num;
} 
bool Ra_flag(string a,string b){//b����a���ж����� 
	if(a=="@")return true;
	return b.find(a)!=b.npos?true:false;
}
string get_Ra(){
	openFile Ra("get_Ra.txt"); 
	string s,*subS=new string[100];
	Ra.io>>s;
	//cout<<s<<endl;
	int len=mySub(s,subS);	//Ԫ�ظ��� 
	for(int i=0;i<len;i++){//�����ȡ���ļ���Ԫ�� 
		//cout<<subS[i]<<endl;
	}
	string ans("{");//�� 
	int pos=0;//���� ��¼λ�� 
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
        	if(Ra_flag(subS[i],subS[j])==true){
        		stringstream ss;
				ss<<"<"<<"{"<<subS[i]<<"}"<<","<<"{"<<subS[j]<<"}"<<">"<<",";           
            	//cout<<ss.str()<<" "<<endl;
            	ans+=ss.str();
            	pos++;
			}      
        }
    }
    ans.append("}");
    ans.erase(ans.size()-2,1);
    cout<<"Ra="<<ans<<endl;//С�ڻ���ڹ�ϵ 
   
	Ra.io<<"Ra="<<ans<<endl;
	return s;
} 
