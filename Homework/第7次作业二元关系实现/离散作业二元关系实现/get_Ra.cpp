#include"mainHead.h"//把定义为空集 
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
			num++;//第i个子集
			i++;
		}
		else if(s[i]=='@'){//检测空集 
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
bool Ra_flag(string a,string b){//b包含a的判断条件 
	if(a=="@")return true;
	return b.find(a)!=b.npos?true:false;
}
string get_Ra(){
	openFile Ra("get_Ra.txt"); 
	string s,*subS=new string[100];
	Ra.io>>s;
	//cout<<s<<endl;
	int len=mySub(s,subS);	//元素个数 
	for(int i=0;i<len;i++){//输出提取到的集合元素 
		//cout<<subS[i]<<endl;
	}
	string ans("{");//答案 
	int pos=0;//用于 记录位置 
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
    cout<<"Ra="<<ans<<endl;//小于或等于关系 
   
	Ra.io<<"Ra="<<ans<<endl;
	return s;
} 
