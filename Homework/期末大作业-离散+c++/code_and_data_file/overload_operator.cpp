#include"Relation.h"

string mySet::operator+(mySet set)
{
	return sumSet(set);
}
string mySet::operator-(mySet set)
{
	return DiffSet(set);
}
mySet mySet::operator=(mySet &set)
{
	(this->element)=set.getEle();
	return *this;
}
Relation Relation::operator=(Relation &R)
{
	try
	{
		if(R.first.size()==0) throw 1;
		this->first=R.first;
		this->second=R.second;
	}
	catch(int)
	{
		cout<<"your class is empty"<<endl;
	}
	return *this;
}

