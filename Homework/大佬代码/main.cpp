#include"ImprovedSet.h"
/*
已实现：
*1.*无重复律
 2.*交集(集合之间的)即集合的加法运算
 3.*包含(元素与集合)
 4.*并集(集合之间的)
 5.*属于(集合之间的)
 6.*一般差集(A对B的差集)
 7.*空集与全集判断（这里认为空集的长度为0，全集的长度为1000即全集为0-999的正整数集）
 8.*集合的子集与真子集与非空真子集个数
 *9.集合的乘法运算(暂时只适用两个一维向量合成二维向量)
 10.*对称差集(A对B的差集∪B对A的差集)由6推得
 11.*绝对补差(~A，即A关于全集E的补集)由6推得
 12.*n元集(返回集合元素个数)
 13.*随机m元子集
 14.寻找指定集合中比n小（或大）的元素个数
 15.计算集合中比n大(或小）的所有元素的子集个数,真子集和非空真子集还是子集算吧，就减一减二。。。
 16.计算 集合v1包含集合v2内所有元素(或集合v2包含集合v1内所有元素)  的子集数
*17*幂集（只写了一个v1的，注意v1的容量最好大小小一些，不然幂集求解时间估计会过长）
待实现：
*/
int main()
{
/*
	cout<<"Please enter the collection source file of v1 and v2 (separated by lines):"<<endl;//以文件扫描输入（第一种输入方式）
	string path1;cout<<"v1's path:";cin>>path1;vector<int> v1=scan(path1);
	string path2;cout<<"v2's path:";cin>>path2;vector<int> v2=scan(path2);
*/	

	cout<<"(Note: if the size is too large, the power set will take too long)"<<endl<<"Please input the size of set1 and set2(separated by a space):";
	int x1,x2;cin>>x1>>x2;
	vector<int> v1=randperm("1.txt",x1),v2=initialize(x2);//方法二随机生成 指定大小的两 个集合,集合元素存放在1.txt与2.txt内（第二种 输入方式）
	system("pause");
	//cout<<endl;output(v1);cout<<endl;output(v2);//输出 v1和v2两个集合
	
	
	/*cout<<"the numbers of v1:"<<nset(v1)<<endl;cout<<"the numbers of v2:"<<nset(v2)<<endl<<endl;system("pause");//n元集的实现

	cout<<"Please input a integer for return a random M-element subset:";int m;cin>>m;
	cout<<"Please input a integer for return a whose random M-element subset（1 for v1, 2 for v2）:";int n;cin>>n;
	if(n==1)
	{vector<int> mset=msubset(v1,m);cout<<"a random "<<m<<"-element subset of v1:";output(mset);}
	else if(n==2)
	{vector<int> mset=msubset(v2,m);cout<<"a random "<<m<<"-element subset of v2:";output(mset);}//输出m元子集的
	cout<<endl;
	system("pause");

	cout<<"v1:"<<zeroorall(v1)<<endl<<"v2:"<<zeroorall(v2)<<endl<<endl;//判断全集/空集
	system("pause");

	string z1=S(v1),z2=S(v2);cout<<"the numbers of v1's subset:"<<z1<<endl<<"the numbers of v2's subset:"<<z2<<endl;//判断子集个数
	string z3=PS(v1),z4=PS(v2);cout<<"the numbers of v1's proper subset:"<<z3<<endl<<"the numbers of v2's proper subset:"<<z4<<endl;//判断真子集数
	string z5=NPS(v1),z6=NPS(v2);cout<<"the numbers of v1's nonvoid proper subset:"<<z5<<endl<<"the numbers of v2's nonvoid proper subset:"<<z6<<endl<<endl;//判断非空真子集数
	system("pause");

	vector<int> vbing=unionset(v1,v2);//并集
	cout<<"并集："<<endl;if(vbing.size()!=0) output(vbing);else cout<<"Their union set is empty"<<endl<<endl;
	system("pause");

	vector<int> vjiao=intersection(v1,v2);//交集
	cout<<"交集:"<<endl;if(vjiao.size()!=0) output(vjiao); else cout<<"Their intersection is empty"<<endl<<endl;
	system("pause");

	vector<int> vcha=difference(v1,v2);//差集
	cout<<"差集:"<<endl;if(vcha.size()!=0) output(vcha); else cout<<"Their difference set is empty"<<endl<<endl;
	system("pause");

	vector<int> vduichencha=SDS(v1,v2);//对称差集
	cout<<"对称差集:"<<endl;if(vduichencha.size()!=0) output(vduichencha); else cout<<"Their Symmetric difference set is empty"<<endl<<endl;
	system("pause");

	vector<int> v1juedui=AS(v1),v2juedui=AS(v2);//v1,v2的绝对补差
	cout<<"v1的绝对补差：";output(v1juedui);cout<<"v2的绝对补差：";output(v2juedui);cout<<endl;
	system("pause");

	string d=include(v1,v2);//判断相互包含关系
	cout<<d<<endl<<endl;//输出具体的相互包含关系
	system("pause");

	cout<<ISS(v1,v2)<<endl<<endl;//实现 计算 集合v1包含集合v2内所有元素(或集合v2包含集合v1内所有元素)  的子集数
	system("pause");


	int number_of_set=0,n_bs=0;//开始判断集合中比给定值大/小的个数
	cout<<"Please enter two Numbers. The first number represents the serial number of the set (1 represents v1, 2 represents v2),"
		<<"and the second number is used to find the number of Numbers larger or smaller than this number in the corresponding set (separated by two Spaces):";
	cin>>number_of_set>>n_bs;
	int n_Big=0,n_Small=0;
	if(number_of_set==1)
	{
		n_Big=Big(v1,n_bs);
		cout<<"There are "<<n_Big<<" of them in set v1 that are greater than "<<n_bs<<endl;
		cout<<"The number of subsets of all elements greater than "<<n_bs<<" in set v1:"<<Bigsubset(v1,n_bs)<<endl;

		n_Small=Small(v1,n_bs);
		cout<<"There are "<<n_Small<<" of them in set v1 that are less than "<<n_bs<<endl;
		cout<<"The number of subsets of all elements less than "<<n_bs<<" in set v1:"<<Smallsubset(v1,n_bs)<<endl;
	}
	else if(number_of_set==2)
	{
		n_Big=Big(v2,n_bs);
		cout<<"There are "<<n_Big<<" of them in set v2 that are greater than "<<n_bs<<endl;
		cout<<"The number of subsets of all elements greater than "<<n_bs<<" in set v2:"<<Bigsubset(v2,n_bs)<<endl;

		n_Small=Small(v2,n_bs);
		cout<<"There are "<<n_Small<<" of them in set v2 that are less than "<<n_bs<<endl;
		cout<<"The number of subsets of all elements less than "<<n_bs<<" in set v2:"<<Smallsubset(v2,n_bs)<<endl;
	}
	else cout<<"Input Error"<<endl;//判断集合中比给定值大/小的个数的结束
	cout<<endl;
	system("pause");


	int x;cout<<"Enter an integer x to determine whether it is in the union of v1 and v2:";cin>>x;
	if(is_element_in_vector(vbing,x))//判断x是否属于v1，v2的并集
		cout<<x<<" in the union set"<<endl;
	else
		cout<<x<<" not in the union set"<<endl;
	cout<<endl;
	system("pause");
*/
	/*vector<vector<string> > vcheng=multiplication(v1,v2);//集合的乘法，返回一个新集合
	output_double_vector(vcheng);//输出新集合
	cout<<endl;
	system("pause");*/

	vector<int>* a1=&v1;//用一个整型向量指针a1指向v1
	int t0=GetTickCount();//开始的时间
	int count=0;//作为幂集个数统计值变量
	cout<<"v1幂集："<<endl;
	count=qiumiji(a1,v1.size());//求幂集，输出并打印进文本C:\Users\13342\Desktop\6.txt，可以在qiumiji函数里修改
	int t1=GetTickCount();//结束的时间
	cout<<"v1幂集总数:"<<count<<endl;//输出v1的幂集总数
	cout<<"求长度为"<<v1.size()<<"的集合的幂集所花费的时间为:"<<t1- t0<<"ms."<<endl;//输出输出幂集所费的时间


	/*int s="abcd";
	for(int i=0;i<4;i++)
	{
		int n=s.length();
		cout<<n;
		s.erase(1,1);
	}测试int的长度是否随其擦除数据而变小*/
	system("pause");
}
