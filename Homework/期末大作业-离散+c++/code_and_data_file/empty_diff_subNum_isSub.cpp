
#include "mainHead.h"
bool mySet::isEmpty()
{
	return element.size();
}
string mySet::DiffSet(mySet set)
{
	int aTemp[max_len],bTemp[max_len];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));//initalize value with 0
	string diff;
	for(int i=0; i<max(getEleNum(),set.getEleNum()); i++) 
	{
		aTemp[element[i]-'0']++;
		bTemp[set.element[i]-'0']++;//利用桶排序思想除去重复
		//cout<<i<<" ";
	}
	for(int i=0;i<'z';i++){
		if(aTemp[i]!=0&&bTemp[i]==0)
			diff+=i+'0';
	}
	//cout<<diff.size()<<endl;
	return diff;
}
int mySet::subNum()
{//子集个数  	
	return 1<<element.size(); 	
}
bool mySet::isSubSet(mySet set)
{
	int aTemp[max_len],bTemp[max_len];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));
	for(int i=0;i<max((*this).getEleNum(),set.getEleNum());i++)
	{//先转换 
		aTemp[element[i]-'0']++;
		if(set.element[i]>0&&set.element[i]<106)
			bTemp[set.element[i]-'0']++;
	}
	for(int i=0;i<max(getEleNum(),set.getEleNum());i++){
		if(aTemp[i]==0&&bTemp[i]!=0){
		 //	cout<<"is not subSet"<<endl; 
			return false;
		}	
	}
//	cout<<"is subSet"<<endl;
	return true; 
}
