#include<bits/stdc++.h>
using namespace std;
string M[4]={"p|q","p|~q","~p|q","~p|~q"};
string m[4]={"p&q","p&~q","~p&q","~p&~q"};
string mat[4]={"M0","M1","M2","M3"};
int flag[4]={0};
string mat1[4]={"m0","m1","m2","m3"};
int Conditional(char str[]); 
int DeMorgan(char str[]);
int DeleBracket(char str[]);
int DeleSame(char str[]);
bool subDeleSame(char );
string turnString(char str[]);
string absorbChar(char str1[]);
void matchM(string str);
string match_m(string str);
int main() {	
	char str[10000]={"((p^q)&q)^p"};
	Conditional(str); 
	cout<<str<<endl;
	DeMorgan(str); 
	cout<<str<<endl;//����̺������� 
	string s=absorbChar(str);
	cout<<s<<endl;
	cout<<endl;
	matchM(s);
	for(int i=0;i<4;i++){
		if(flag[i]==1) cout<<mat[i]<<endl;
	}
	for(int i=0;i<4;i++){
		if(flag[i]==0){
			cout<<mat1[i];
			if(i!=3) cout<<"|";
		} 
	}
	cout<<endl;
//	for(int i=0;i<4;i++){
//		if(flag[i]==1) cout<<M[i]<<endl;
//	}
	for(int i=0;i<4;i++){
		if(flag[i]==0){
			cout<<"(";
			cout<<m[i];
			cout<<")";
			if(i!=3) cout<<"|";
		} 
	}	
	return 0;	
}
int Conditional(char str[]){
	
	stack<char> stk;//����ǰ�� ��stack
	int bi/*������ָ��*/,ei; 
	char ans[10000];
	for(int i=0; i<strlen(str); i++) { //����Ԥ�����ַ�
		char fin[1000];//����ǰ�� 
		char fin2[1000];
		if(str[i]=='^') {
			fin[0]='~';//���ַ�ǰ��~�����ţ�
			fin[1]='(';
			int l=i,r=i;//lΪ��ָ�� rΪ��ָ��
			
			//�������� 
			if(str[l-1]==')') { 
				int count=2;//��Ϊfin���±� fin[0]Ϊ~��fin[1]Ϊ�� 
				l--;
				int bracketNum=0;
				while(str[l]!='('||bracketNum!=1) {//��Ϊ��һ��')'Ҫ��stack����  =1 
					if (str[l]==')')bracketNum++;
					if(str[l]=='(')bracketNum--;//�������ƥ�� 
					stk.push(str[l]);//��������֮ǰ����ջ 
					//cout<<stk.top()<<endl;
					l--;//���� 
				}
				bi=l;//������ָ�� 
				while(!stk.empty()) {
					fin[count++]=stk.top();
					stk.pop();
				}
			} //������ 
			else {
				fin[1]=str[l-1];
				bi=l-1;
			}// �Ƶ��ұ�������
			 
			if(str[r+1]=='(') {
				r++;
				int count=0;
				while(str[r]!=')') {//��������ƥ������ 
					fin2[count++]=str[r];
					r++;
				}
				ei=r;
				fin2[count]=')';
			} //�ұ������� 
			else {
				fin2[0]=str[r+1];
				ei=r+1;
			}
			queue<char> que;//����������� 
			for(int j=0; j<bi; j++)//��biָ��ǰ��δ����������� 
				que.push(str[j]);
			for(int j=0; j<strlen(fin); j++)//������õĲ���fin(�������^����ߵ�������������� 
				que.push(fin[j]);
			que.push('|');//���롮|������� 
			for(int j=0; j<strlen(fin2); j++)//��'^' �ұߵ������������ 
				que.push(fin2[j]);
			for(int j=ei+1; j<strlen(str); j++)//��eiָ�����δ����������� 
				que.push(str[j]);
			int s=que.size();
			for(int j=0; j<s; j++) {//�Ƴ����ж���Ԫ�ظ��Ӹ�str 
				str[j]=que.front();
				que.pop();
			}
		}
	}
	return 0;
}
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
string turnString(char str[]){
	string ans;
	for(int i=0;i<strlen(str);i++)
		ans+=str[i];
	return ans;
}
string absorbChar(char str1[]){
	int begini,endi;
	string str,ans="";
	str=turnString(str1);
	stack<char> stk[27];
	queue<char> que;
	for(int i=0;i<str.size();i++){
		if(str[i]=='('){
			begini=i;
			i++;
			while(str[i]!=')'){
			
				if(str[i]>='a' && str[i]<='z'){
					stk[str[i]-'a'].push(str[i]);
					stk[str[i]-'a'].push(str[i+1]);
				}
				i++;
				endi=i;	
			}
		}

			if(str[i]>='a' && str[i]<='z'){
				if(!stk[str[i]-'a'].empty()){
					if((stk[str[i]-'a'].top()=='&' && str[i-1]=='|')|| (stk[str[i]-'a'].top()=='|' && str[i-1]=='&') ){
						
						for(int j=begini;j<=endi;j++) str[j]=' ';
						str[endi]=str[i];	
						str[i]=' ';
						str[i-1]=' ';
					}
				}	
			}
			
	}
	for(int i=0;i<str.size();i++){
		if(str[i]!=' ') {
			ans+=str[i];
		}
	}
//	cout<<ans<<endl;
	return ans;	
}
int DeleBracket(char str[]){
	
	char str2[10000];
	strcpy(str2,str);
	int len=strlen(str2);
	for(int i=0;i<len;i++){
		if(str2[i]=='(' || str2[i]==')'){
        	len--;
			for(int j=i;j<len;j++) {
				str2[j]=str2[j+1];
			}
		}
	}
	str2[len]='\0';
	strcpy(str,str2);
	cout<<str<<endl;
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
bool subDeleSame(char s){
	switch(s){
		case '^':case '&':case '|':
			return true;
		default:
			return false;
	}
}
void matchM(string str){
	for(int i=0;i<4;i++){
		if(str==M[i]){
			flag[i]=1;
		}
	}
}
string match_m(string str){
	
}
