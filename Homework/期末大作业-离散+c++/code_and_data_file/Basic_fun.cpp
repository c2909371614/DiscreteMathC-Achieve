
#include "mainHead.h"
mySet::mySet()
{
	element="";
}
mySet::mySet(string s) //不一样既然不报错 
{
	setEle(s);//invoke setEle to construct
}
mySet::mySet(const int a[],int n) 
{
	for(int i=0; i<n; i++)
		element+=a[i];
}
mySet::mySet(mySet &set)
 {
	this->element=set.getEle();
}
mySet::~mySet()
{
	name='s';
	//cout<<"done" <<endl;
}
inline int mySet::myFind_ele(const string &s)//寻找到有效元素 
 {
	for(int i=0; i<s.size(); i++)
		if(s[i]>='a'&&s[i]<'z'||s[i]>='0'&&s[i]<='9')//element only allow to use lower letter and number char
			return i;
	return -1;
}
string mySet::pick_ele(const string &s) //取得有效元素 
{ //pick elements and return ele
	string ele;
	int index=myFind_ele(s);
	for(int i=index; i<s.size(); i+=2) {
		//跳两个便可除去逗号读取到元素
		ele+=s[i];
	}
	return ele;
}
string mySet::getEle()const
 {
	return element;
}
void mySet::setEle(const string s) 
{
	if(s.find(',')==string::npos)
		element=s;
	else element=pick_ele(s);
}
void mySet::myPrint() 
{
	cout<<getSet()<<endl;
}
string mySet::getSet()
{
	return toSetString(element);
}
int mySet::getEleNum()
{
	return element.size();
}

