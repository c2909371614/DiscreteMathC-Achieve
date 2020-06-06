#include"head.h"
//计算运算数的个数并打印表格 
int Count(string s,int m[]){
	int ch[26],value[30],Count=0;//value用于赋值0 or 1 
	memset(ch,0,sizeof(ch));
	memset(value,5,sizeof(value));//初始化 赋值数组为5用于debug 
	for(int i=0;i<s.size() ;i++)
		switch(s[i]){
			case '|':case'^':case'=':case'>':case'!':break;
			default:ch[s[i]-'a']++;
		}
	//打印 运算数部分 
	for(int i=0;i<26;i++){ 
		if(ch[i]!=0){
			Count++;
		//	printf("%c\t",i+'a');
		}	
	}
	cout<<s<<endl; //输出运算式 
	//给运算数赋值部分 
	int n=1<<Count;
	string stemp;//由于代替s做运算 	
	int k=0; 
	while(k<n){
		stemp=s;//stemp还原 
		int ktemp=k;
		for(int i=0;i<Count;i++){
			value[i]=ktemp%2;
			ktemp/=2;
		} 
		int j=0;//初始化下标 
		for(int i=0;i<26;i++){
			if(ch[i]!=0){
				if(value[j++]==0)
					ch[i]='0';
				else ch[i]='1'; //ch数组中储存了相应字母的真值 
			//	printf("%c\t",ch[i]);//打印真值表初始值 
			}
		}
		for(int i=0;i<stemp.size() ;i++){
			if(stemp[i]>='a'&&stemp[i]<='z')//运用桶排序桶的号即为字符，不为零既存在的思想 
				stemp[i]=ch[stemp[i]-'a'];//用1和0替换命题真值 
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
int turnNumber(int k,int Count){//将数字颠倒转回 
	int ans=0,power=0;
	while(Count--){
		ans+=(k%2)*(1<<Count);
		k/=2;
	}
	return ans;
}
