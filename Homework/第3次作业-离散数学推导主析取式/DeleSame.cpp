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
		char sameChar='0';//��ͬ�������� ��ʼ��Ϊ�� 
		bool sameCharFlag=false;
		char sameOperator='0';//��ͬ������� ��ʼ��Ϊ��  
		if(sTemp[i]>='a'&&sTemp[i]<='z'){
			sameChar=sTemp[i];
			sameOperator= sTemp[i+1];//�������������һ�������� 
			int sameI=i;//�����±� 
			if(sTemp[i-1]=='~')
				sameCharFlag=true;//ǰ����'~' 
			for(int j=i;j<sTemp.size();j++){
				//���������ǰ���������ͬ���������������ֹͣ 
				if(sTemp[j]!=sameOperator&&subDeleSame(sTemp[j]))
					break;
				if(sTemp[j]==sameChar){
					int NumLeft=3;//�������ɾ������ 
					int NumRight=2;//�� �����ɾ������
					int sameJ=j-1;
					//if();
					if(sameCharFlag==true){
						if(sTemp[j-1]!='~'){//˵��Ϊ~p&p�� 
							//sameJ=j-1;
						}
						else{//˵��Ϊ~p&~p�� 
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
