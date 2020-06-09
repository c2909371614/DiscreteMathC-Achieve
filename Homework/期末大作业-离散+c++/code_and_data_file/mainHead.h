#ifndef MAINHEAD
#define MAINHEAD
#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;
class Relation;//提前声明Relation是一个class 
class mySet {
	private:
		char name;//Set name no define
		string element;//储存元素字符
		vector<int> ele;
		string pick_ele(const string &s);//提取元素 
	
	friend string limit(Relation &R,mySet &A); //关系与集合之间的运算 1.A对R的限制 
	friend string mirror(const Relation &R,const mySet &A);//2.A在R下的像 
	friend bool isA_Relation(Relation &R,mySet &A);//R是否为A上的二元关系 无法判定包含关系 
	friend string set_smaller_re(Relation &R,mySet &A);//生成set上的小于关系Relation
	friend string set_equal_re(Relation &R,mySet &A);//生成set上的恒等关系 
	public:
		mySet();
		mySet(const string s); //s={a,b,c}
		mySet(const int a[],int n);//Initialize object by Array  n is lenth of array
		mySet(mySet &set);
		mySet operator=(mySet &set);
		~mySet();
		string getEle()const;
		void setEle(const string s);//带逗号或者纯元素进行initalize 
		void myPrint();
		//声明为inline 
		int myFind_ele(const string &s);//1 return the first element index of s
		int getEleNum();//2
		string getSet();//3 return set 形式string 
		bool Belong();//4 输入一个数判断是否属于set		
		string sumSet(mySet set);//5 合集
		string operator+(mySet set);
		string subSet(mySet set);//6 subSet子集 
		bool isEmpty();//7 
		string DiffSet(mySet set);//8 差集
		string operator-(mySet set);
		int subNum();//9 子集个数
		bool isSubSet(mySet set); //10 是否为mySet的子集
		bool isRealSub(mySet set);//11 是否为mySet的真子集
		string oppsDiffSet(mySet set);//12 对称差集
		bool isEqual(mySet set); //13 判断是否相等
};
string toSetString(string ele);
string noSame(string s);
const int max_len=205;//lenth 

#endif
