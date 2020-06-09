#include"Relation.h"

string Relation::dom()
{
	return toSetString(noSame(first));
}
string Relation::ran()
{
	
	return toSetString(noSame(second));
}
string Relation::fld()
{
	string ans(first.c_str());
	ans+=second;
	return toSetString(noSame(ans));
}

