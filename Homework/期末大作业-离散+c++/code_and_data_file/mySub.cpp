#include"Relation.h"

string toSetString(string ele)
{
	stringstream ss;
	ss<<"{";
	for(int i=0; i<ele.size(); i++) 
	{
		ss<<ele[i];
		if(i!=ele.size()-1)
			ss<<",";
	}
	ss<<"}";
	return ss.str();
}
string noSame(string s)
{
	string ans;
	for(int i=0;i<s.size();i++)
	{
		if(ans.find(s[i])==string::npos)
			ans+=s[i];
	}
	sort(ans.begin(),ans.end());
	return ans;
}

