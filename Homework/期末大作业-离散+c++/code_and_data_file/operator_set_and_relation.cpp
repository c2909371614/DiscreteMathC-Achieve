#include"Relation.h"

string limit(Relation &R,mySet &A)
{
	Relation R_A;//cout<<"ok"<<endl;
	for(int i=0;i<R.first.size();i++)
	{
		if(A.element.find(R.first[i])!=string::npos)//找到说明为限制的量 
		{
			R_A.first+=R.first[i];
			R_A.second+=R.second[i];
			
		}		
	}
	return R_A.toRelaString();
}
string mirror(const Relation &R,const mySet &A)
{
	mySet Mirror;//cout<<"ok"<<endl;
	for(int i=0;i<R.first.size();i++)
	{
		if(A.element.find(R.first[i])!=string::npos)//找到说明为像 
		{
			Mirror.element+=R.second[i];	//找到把值加入像集合元素 
		}		
	}
	return toSetString(Mirror.getEle());
 } 
 bool isA_Relation(Relation &R,mySet &A) 
 {
 	if(R.first.size()==0)return true;//空集为任何集合上的二元关系
 	mySet R_set(R.fld());//获取关系的域集合 
 	cout<<"fld:"<<R_set.getEle()<<" A:"<<A.getEle()<<endl;//test
 	if(A.isSubSet(R_set))return true;//关系的域是否为集合A的子集,不是则不是A上的二元关系 
	return false;
 }
 string set_smaller_re(Relation &R,mySet &A)
 {
 	R.get_Smaller(A.getEle());
 	//cout<<A.getEle()<<endl;
 	return R.toRelaString();
 }
 string set_equal_re(Relation &R,mySet &A)
 {
 	R.get_Ia(A.getEle());
 	return R.toRelaString();
 }


