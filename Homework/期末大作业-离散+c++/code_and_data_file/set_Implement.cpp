#include"mainHead.h"

bool mySet::Belong()
{
	char ch;
	cout<<"enter a char :";
	cin>>ch;
	if(element.find(ch)!=string::npos) {
		cout<<ch<<" is belong the set"<<endl;
		return true;
	}
	cout<<"ch is not belong the set"<<endl;
	return false;
}
string mySet::sumSet(mySet set) 
{
	int sumTemp[max_len];
	string sum;//add result
	memset(sumTemp,0,sizeof(sumTemp));
	for(int i=0; i<max(getEleNum(),set.getEleNum()); i++) {
		sumTemp[element[i]-'0']++;
		sumTemp[set.element[i]-'0']++;//利用桶排序思想除去重复
		//cout<<i<<" ";
	}
	for(int i=0; i<max_len; i++) {
		if(sumTemp[i]!=0){
			sum+=i+'0';
		}
			//给sum赋值
	}
	//cout<<sum.size()<<endl;
	return sum;//return result
}
string mySet:: subSet(mySet set)//交集 返回交集set 
{
	int aTemp[max_len],bTemp[max_len];
	string sub;
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));//initialize to 0 
	for(int i=0;i<max(getEleNum(),set.getEleNum());i++)
	{
		aTemp[element[i]-'0']++;//upper one by one if across
		bTemp[set.element[i]-'0']++;
	}
	for(int i=0;i<max_len;i++){
		if(aTemp[i]!=0&&bTemp[i]!=0)
			sub+=i+'0';
	}	
	return sub;
}
