#include"Head.h"
int DeMorgan(char str[]){
	
	int bi/*������ָ��*/,ei/*������ָ��*/;
	int len=strlen(str);//��ȡ���� 
	char str2[10000]; 
	char a[]="";
	queue<char> que;
	char ans[10000];
	strcpy(str2,str);//����Ԥ�����ַ����浽str2 
	for(int i=0;i<len;i++){
		char fin[1000];
		if(str2[i]=='~' && str2[i+1]=='('){//����~�� 
			bi=i-1;//��ָ�� 
			int j=i+2,cnt=0;// 
			
			int bracketNum=0;// �������ƥ�� 
			while(str2[j]!=')'||bracketNum!=0/*j=j+2  '('������*/){//û������������ 
				if (str[j]=='(')bracketNum++;
				if(str[j]==')')bracketNum--;//�������ƥ�� 
				if(str2[j]>='a' && str2[j]<='z') {
					fin[cnt++]='~';
					fin[cnt++]=str[j];//����ĸǰ���'~' 
				}
				else if(str2[j]=='|') fin[cnt++]='&';
				else if(str2[j]=='&')fin[cnt++]='|';
				else fin[cnt++]=str2[j];//'~'�ճ� 
				j++;//ָ�����ɨ 
			}
			ei=j+1;//eiָ������δ����Ĳ��� 
			for(int j=0;j<=bi;j++)//biǰ���δ����Ĳ�������� 
				que.push(str2[j]);
			for(int j=0;j<strlen(fin);j++)//������õĲ�������� 
				que.push(fin[j]);
			for(int j=ei;j<len;j++){//eiָ������δ����Ĳ���
				que.push(str2[j]);
			}
			strcpy(str2,a);
			int qLen=que.size();
			for(int j=0;j<qLen;j++){
//				cout<<que.front();
    			ans[j]=que.front();
    			que.pop();
			}
//			cout<<endl;
			cout<<ans<<endl;
			strcpy(str2,a);
			strcpy(str2,ans);
		}
	}
	int len1=strlen(ans);
	for(int i=0;i<len1;i++){
		if(ans[i]=='~' && ans[i+1]=='~'){
          len1=len1-2;
			for(int j=i;j<len1;j++) {
				ans[j]=ans[j+2];
			}
		}
	}
	ans[len1]='\0';//���Ͻ�β��ʶ�� /0 
	//cout<<ans<<endl;
	strcpy(str,ans); 

}
