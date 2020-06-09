#ifndef RELATION
#define RELATION
#include"mainHead.h"
class Relation //����ϵԪ��Ϊ��ʱ����Ϊ�ռ� ����ʾΪ@ 
{
	private:
		string first,second;  
		string first_set[100],second_set[100];
		int index;//index��¼��һԪ�غ͵ڶ�Ԫ�ظ���  
	friend string limit(Relation &R,mySet &A); //��ϵ�뼯��֮������� 1.A��R������ 
	friend string mirror(const Relation &R,const mySet &A);//2.A��R�µ��� 
	friend bool isA_Relation(Relation &R,mySet &A);//3.R�Ƿ�ΪA�ϵĶ�Ԫ��ϵ 
	friend string set_smaller_re(Relation &R,mySet &A);//4.����set�ϵ�С�ڹ�ϵRelation
	friend string set_equal_re(Relation &R,mySet &A);//5.����set�ϵĺ�ȹ�ϵ 
	public:
		Relation();
		Relation(string first,string second);
		Relation(string s);//�ɴ洢���� 
		Relation(vector<int> a,vector<int> b); //vector��ʹ�� 
		Relation(vector<int> a);//vector��ʽ��ʼ�� 
		Relation(Relation& rela);//���ƹ��� 
		~Relation(); 
		
		string getFirst();//��һԪ�صĶ�ȡ 
		string getSecond();//�ڶ�Ԫ�صĶ�ȡ 
		void setFirst_Second(string s1,string s2);//1 ֱ���趨��һ�ڶ�Ԫ�� 
		void myPrint();
		string toRelaString();
		template<typename T>
		void get_all_A_B(T first,T second);//2 ȫ���ϵ 
		void get_Ia(string s);//3 ��ȹ�ϵ
		void get_Bigger(string s);//4 ���ڹ�ϵ 
		void get_Smaller(string s);//5 С�ڹ�ϵ
		
		void get_divide(string s);//6 ������ϵ 
		void get_Con(string set[100]);//7 ������ϵ,Ԫ��Ϊset���� 
		void print_Con(); //8 ��ӡ������ϵ 
		Relation get_inverse();//9 ���ϵ 
		
		string dom();//10 ������ 
		string ran();// 11 ֵ��
		string fld();//12 �� 
		Relation operator=(Relation &R);
};

#endif
