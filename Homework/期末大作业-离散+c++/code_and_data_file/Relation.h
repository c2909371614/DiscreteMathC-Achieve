#ifndef RELATION
#define RELATION
#include"mainHead.h"
class Relation //当关系元素为空时，定为空集 ：表示为@ 
{
	private:
		string first,second;  
		string first_set[100],second_set[100];
		int index;//index记录第一元素和第二元素个数  
	friend string limit(Relation &R,mySet &A); //关系与集合之间的运算 1.A对R的限制 
	friend string mirror(const Relation &R,const mySet &A);//2.A在R下的像 
	friend bool isA_Relation(Relation &R,mySet &A);//3.R是否为A上的二元关系 
	friend string set_smaller_re(Relation &R,mySet &A);//4.生成set上的小于关系Relation
	friend string set_equal_re(Relation &R,mySet &A);//5.生成set上的恒等关系 
	public:
		Relation();
		Relation(string first,string second);
		Relation(string s);//可存储数据 
		Relation(vector<int> a,vector<int> b); //vector的使用 
		Relation(vector<int> a);//vector方式初始化 
		Relation(Relation& rela);//复制构造 
		~Relation(); 
		
		string getFirst();//第一元素的读取 
		string getSecond();//第二元素的读取 
		void setFirst_Second(string s1,string s2);//1 直接设定第一第二元素 
		void myPrint();
		string toRelaString();
		template<typename T>
		void get_all_A_B(T first,T second);//2 全域关系 
		void get_Ia(string s);//3 恒等关系
		void get_Bigger(string s);//4 大于关系 
		void get_Smaller(string s);//5 小于关系
		
		void get_divide(string s);//6 整除关系 
		void get_Con(string set[100]);//7 包含关系,元素为set数组 
		void print_Con(); //8 打印包含关系 
		Relation get_inverse();//9 逆关系 
		
		string dom();//10 定义域 
		string ran();// 11 值域
		string fld();//12 域 
		Relation operator=(Relation &R);
};

#endif
