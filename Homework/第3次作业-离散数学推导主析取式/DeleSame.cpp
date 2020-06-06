#include"Head.h"
bool subDeleSame(char s){
	switch(s){
		case '^':case '&':case '|':
			return true;
		default:
			return false;
	}
}
int DeleSame(char str[]){//p&~r&~p|r
	string sTemp;
	for(int i=0;i<strlen(str);i++)
		sTemp+=str[i];
	for(int i=0;i<sTemp.size();i++){
		cout<<i<<": ";
		char sameChar='0';//相同的运算数 初始化为零 
		bool sameCharFlag=false;
		char sameOperator='0';//相同的运算符 初始化为零  
		if(sTemp[i]>='a'&&sTemp[i]<='z'){
			sameChar=sTemp[i];
			sameOperator= sTemp[i+1];//储存运算符和下一个运算数 
			int sameI=i;//储存下标 
			if(sTemp[i-1]=='~')
				sameCharFlag=true;//前面有'~' 
			for(int j=i;j<sTemp.size();j++){
				//如果遇到与前面运算符不同的运算运算符搜索停止 
				if(sTemp[j]!=sameOperator&&subDeleSame(sTemp[j]))
					break;
				if(sTemp[j]==sameChar){
					int NumLeft=3;//左运算符删除数量 
					int NumRight=2;//右 运算符删除数量
					int sameJ=j-1;
					//if();
					if(sameCharFlag==true){
						if(sTemp[j-1]!='~'){//说明为~p&p型 
							//sameJ=j-1;
						}
						else{//说明为~p&~p型 
							NumRight++;//delet  &~p 
							sameJ--;//sameJ=j-2;
						}
						sTemp.erase(sameI-1,NumLeft);
						cout<<sTemp<<endl;
						j-=NumLeft;
						sTemp.erase(sameJ,NumRight);
						//j-=NumRight;
					} 
					else if(sameCharFlag==false){
						int sameJ;
						if(sTemp[j-1]=='~'){//p&~p
							NumLeft--;
							NumRight++;
							sameJ--;//sameJ=j-2;
						}
						else{//p&p
							
						}
						sTemp.erase(sameI,NumLeft);//2
						//cout<<sTemp<<endl;
						j-=NumLeft;
						sTemp.erase(sameJ,NumRight);//3
					}
				} 
			}
				
		}
	}
	cout<<sTemp<<endl;
}
