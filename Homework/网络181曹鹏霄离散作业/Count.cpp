#include"head.h"
//�����������ĸ�������ӡ��� 
void Count(string s){
	int ch[26],value[30],Count=0;//value���ڸ�ֵ0 or 1 
	memset(ch,0,sizeof(ch));
	memset(value,5,sizeof(value));//��ʼ�� ��ֵ����Ϊ5����debug 
	for(int i=0;i<s.size() ;i++)
		switch(s[i]){
			case '|':case'^':case'=':case'>':case'!':break;
			default:ch[s[i]-'a']++;
		}
	//��ӡ ���������� 
	for(int i=0;i<26;i++){ 
		if(ch[i]!=0){
			Count++;
			printf("%c\t",i+'a');
		}	
	}
	cout<<s<<endl; //�������ʽ 
	//����������ֵ���� 
	int n=1<<Count;
	string stemp;//���ڴ���s������ 
	while(n){
		stemp=s;//stemp��ԭ 
		int ntemp=n;
		for(int i=0;i<Count;i++){
			value[i]=ntemp%2;
			ntemp/=2;
		} 
		int j=0;//��ʼ���±� 
		for(int i=0;i<26;i++){
			if(ch[i]!=0){
				if(value[j++]==0)
					ch[i]='F';
				else ch[i]='T'; 
				printf("%c\t",ch[i]);//��ӡ��ֵ���ʼֵ 
			}
		}
		for(int i=0;i<stemp.size() ;i++){
			if(stemp[i]>='a'&&stemp[i]<='z')//����Ͱ����Ͱ�ĺż�Ϊ�ַ�����Ϊ��ȴ��ڵ�˼�� 
				stemp[i]=ch[stemp[i]-'a'];//��T��F�滻������ֵ 
		}
		string post;
		post = MidToPost(stemp);
		
		printf("%c\n",GetValuePost(post));
		n--;
	}	
	return ;
}

