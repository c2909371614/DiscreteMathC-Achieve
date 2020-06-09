#include"mainHead.h"
#include"Relation.h"

//string s1="{1,3,6,7}",s2="1,2,3",s3="{1,2,3}",s4="23",s5="123456",s6="234",s7="14";
//string re1="123",re2="2",re3="345";
string s1,s2,s3,s4,s5,s6,s7; 
string re1,re2,re3;

void get_data();
void test_set();
void test_relation(); 
void test_operator();
void test_overload(); 

int main()
{
	get_data();//读取信息 
	test_set();
	test_relation();
	test_operator();
	test_overload();
	getchar(); 
	return 0;
}
void get_data()
{
	fstream io("data.txt",ios::in);
	io>>s1>>s2>>s3>>s4>>s5>>s6>>s7;
	io>>re1>>re2>>re3;//从文件中读取信息赋值; 
}
void test_set()
{
	mySet set1(s1),set2(s2),set0,set3(s3);//生成三个集合 
	cout<<"set1=";
	set1.myPrint();
	cout<<"set2=";
	set2.myPrint();
	cout<<"set3=";
	set3.myPrint();
	//set1.Belong();
	mySet sum(set1.sumSet(set2));//合集测试 
	cout<<"set1与set2的合集="; 
	sum.myPrint();
	
	cout<<"set1与set2的交集="; 
	mySet sub(set1.subSet(set2));//生成交集集 
	sub.myPrint();
	
	cout<<"set1与set2的差集="; 
	mySet diff(set1.DiffSet(set2));//差集 
	diff.myPrint();
	cout<<"差集的子集个数为:"<<diff.subNum()<<endl;
	
	cout<<"空集判断set0=@:"; 
	if(set0.isEmpty()==0)//判断是否为空 
		cout<<"empty"<<endl;
	else cout<<"no empty"<<endl;
	
	cout<<"set1与set2的相对差集："; 
	mySet set(set1.oppsDiffSet(set2));//相对差集 
	set.myPrint();
	
	cout<<"判断set2与set3是否相等"<<endl; 
	if(set2.isEqual(set3))//判断是否相等 
		cout<<"equal"<<endl;
	else cout<<"no euqal"<<endl;

 } 
void test_relation()
{
	cout<<endl<<"关系操作"<<endl; 
	Relation rela(re1,re2);//初始化生成AxB 
	
	cout<<"二元关系rela="; 
	rela.myPrint(); 
	
	Relation con;
	cout<<"包含关系测试:";
	string ss[100]={"@","23","324"};//包含关系测试 
	con.get_Con(ss); 
	con.print_Con();
	
	cout<<"rela的逆关系";
	(rela.get_inverse()).myPrint(); //逆关系测试 
	cout<<"rela的dom:"<<rela.dom()<<endl;//定义域 
	cout<<"rela的ran"<<rela.ran()<<endl;//值域 
	cout<<"rela的fld"<<rela.fld()<<endl;//域 
	cout<<"全域关系";
	rela.get_all_A_B(re1,re1);
	rela.myPrint();
	cout<<"恒等关系";
	rela.get_Ia(re1);
	rela.myPrint();
	cout<<"大于关系";
	rela.get_Bigger(re1);
	rela.myPrint();
	cout<<"小于关系";
	rela.get_Smaller(re1);
	rela.myPrint();
	cout<<"整除关系"; 
	rela.get_divide(re1);
	rela.myPrint();
	
}
void test_operator()
{
	
	cout<<endl<<"五种集合与关系之间的操作"<<endl; 
	Relation rela;
	rela.setFirst_Second(re1,re3); //生成关系{<1,3>,<2,4>,<3,5>} 
	cout<<"rela:";
	rela.myPrint();
	mySet set(s4),set2(s5);//生成set{2,3} 
	cout<<"set:";
	set.myPrint();
	cout<<"set2:";
	set2.myPrint();
	cout<<"set对rela的限制="<<limit(rela,set)<<endl; //限制的测试
	
	cout<<"set在rela上的像"<<mirror(rela,set)<<endl;//像的测试 

    cout<<"测试rela是否为set上的二元关系";
	if(isA_Relation(rela,set))cout<<"yes"<<endl;//测试rela是否为set上的二元关系
	else cout<<"no"<<endl;
	cout<<"测试rela是否为set2上的二元关系";
	if(isA_Relation(rela,set2))cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	Relation R;
	cout<<"set的小于关系生成"<<set_smaller_re(R,set)<<endl;//set的小于关系生成
	cout<<"set的恒等关系测试"<<set_equal_re(R,set)<<endl; //set的恒等关系测试 
}
void test_overload()
{
	cout<<endl;
	cout<<"overload:"<<endl;
	mySet set1(s6),set2(s7);
	cout<<"set1+set2="<<toSetString(set1+set2)<<endl;
	cout<<"set1-set2="<<toSetString(set1-set2)<<endl;
	
	Relation R,R1(re1);
	cout<<"exception handling:";
	R1=R;
}
