#include"mainHead.h"

bool mySet::isRealSub(mySet set)
{
	if(isSubSet(set)&&set.getEleNum()<element.size())
		return true;
	return false;	
 } 
 string mySet::oppsDiffSet(mySet set)
 {
 	mySet atemp((*this).DiffSet(set));
 	mySet btemp(set.DiffSet(*this)) ;
 	return atemp.sumSet(btemp);
 }
 bool mySet::isEqual(mySet set)
 {
 	if(getEleNum()==set.getEleNum()&&isSubSet(set))
 		return true;
 	return false;
 }
 
