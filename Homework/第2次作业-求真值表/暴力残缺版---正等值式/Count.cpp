#include"head.h"
//�����������ĸ�������ӡ��� 
int Count(string s,int m[]){
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
		//	printf("%c\t",i+'a');
		}	
	}
	cout<<s<<endl; //�������ʽ 
	//����������ֵ���� 
	int n=1<<Count;
	string stemp;//���ڴ���s������ 	
	int k=0; 
	while(k<n){
		stemp=s;//stemp��ԭ 
		int ktemp=k;
		for(int i=0;i<Count;i++){
			value[i]=ktemp%2;
			ktemp/=2;
		} 
		int j=0;//��ʼ���±� 
		for(int i=0;i<26;i++){
			if(ch[i]!=0){
				if(value[j++]==0)
					ch[i]='0';
				else ch[i]='1'; //ch�����д�������Ӧ��ĸ����ֵ 
			//	printf("%c\t",ch[i]);//��ӡ��ֵ���ʼֵ 
			}
		}
		for(int i=0;i<stemp.size() ;i++){
			if(stemp[i]>='a'&&stemp[i]<='z')//����Ͱ����Ͱ�ĺż�Ϊ�ַ�����Ϊ��ȴ��ڵ�˼�� 
				stemp[i]=ch[stemp[i]-'a'];//��1��0�滻������ֵ 
		}
		string post;
		post = MidToPost(stemp);
		char ans=GetValuePost(post);
		if(ans=='1')m[turnNumber(k,Count)]++;
		//printf("%c\n",ans);
		k++;
	}
		
	return Count;

}
int turnNumber(int k,int Count){//�����ֵߵ�ת�� 
	int ans=0,power=0;
	while(Count--){
		ans+=(k%2)*(1<<Count);
		k/=2;
	}
	return ans;
}
