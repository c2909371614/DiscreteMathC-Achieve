#ifndef IMPROVEDSET_H
#define IMPROVEDSET_H
#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
#include<algorithm>
#include<string>
#include<Windows.h>
#include<stdlib.h>
#include <sstream>//stringstream 
using namespace std;
const int N=1000;//全集的元素个数
vector<int> scan(string path)//从文件读取集合“(”不读，只读数字，最好吧括号去掉以免有不必要的麻烦
{
	fstream output;
	output.open(path.c_str(),ios::in|ios::out|ios::app);
	int sum=0;
	vector<int> v;
	int S;
	while(!output.eof())
	{
		output>>S;
		if(!output.eof())
			v.push_back(S);
		else break;
	}
	cout<<"Done"<<endl;
	output.close();
	return v;
}
string DTS(int a)//数字转化为字符串digits to string
{
	string res;
    stringstream ss;//定义流ss，需要头文件<sstream>
    ss << a;// 将数字a转化成流ss
    ss >> res;//将流ss转化成字符串
    return res;
}
vector<vector<string> > multiplication(vector<int> &v1,vector<int> &v2)//向量乘法，两个一维向量合成为一个二维向量，未改变v1,v2
{
	const vector<int> V1=v1,V2=v2;
	int n1=V1.size(),n2=V2.size();
	vector<vector<string> > v;
	v.resize(n1);
	for(int i=0;i<n1;i++)
	{
		v[i].resize(n2);
		for(int j=0;j<n2;j++)
		{
			string s;
			s.append("("+DTS(V1[i])+","+DTS(V2[j])+")");
			v[i][j].append(s);
		}
	}
	cout<<"the compound set:";
	return v;
}
void output_double_vector(vector<vector<string> > &v)//输出二维向量，未改变v
{
	cout<<endl;
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v[i].size(); j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}
string pow2(const long long n)//计算2的n次，因为其太大所以以字符串输出
{
	int a[10000] = {0};    //先定义一个数组
    int i, j;
    a[0] = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[j] *= 2;     //将每个值乘2放在数组中
        }
        for (j = 0; j < 10000; j++)   //处理数组里面的值
        {
            if (a[j] > 9)
            {
                a[j + 1]++;     //进位
                a[j] = a[j] % 10;
            }
        }
    }
    j = 9999;
    while (a[j] == 0)     //去除数组中高位多余的0，不然前面有很多0
    {
        j--;
    }
	string s;
    for (int i = j; i >= 0; i--)
    {
		s+=char(a[i]+'0');
    }
	return s;
}
string S(vector<int> &v)//子集数 subset，未改变v
{
	const long long n=v.size();
	return pow2(n);
}
string PS(vector<int> &v)//真子集数proper subset，未改变v
{
	string s=S(v);
	int n=s.length();
	s[n-1]=char(s[n-1]-1);
	return s;
}
string NPS(vector<int> &v)//非空真子集数nonvoid proper subset
{
	string s=PS(v);
	int n=s.length();
	s[n-1]=char(s[n-1]-1);
	return s;
}
string zeroorall(vector<int> &v)//空集与全集的判断，未改变v
{
	int n=v.size();
	if(n==0)
		return "this set is an empty set";
	else if(n==N)
		return "this set is the universal set";
	else if(n>0&&n<N)
		return "This set is neither empty nor universal";
}
vector<int> single(vector<int> &v)//无重复律
{
	vector<int> v1=v;
	sort(v1.begin(),v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	return v1;
}
void input(string path,vector<int> &v)//从文件中读取集合
{
	fstream put;
	put.open(path.c_str(),ios::in|ios::out);
	while(!put.eof())
	{
		int a;
		put>>a;
		if(put.eof())
			break;
		v.push_back(a);
	}
}
void output(vector<int> &v)//输出一维向量的集合，未改变v
{
	const vector<int>V=v;
	int n=V.size();
	cout<<"the elements in this set:";
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
vector<int> randperm(string path,int Num)//方法二——不重复（输入）(获得一个随机打乱的Num长度的整型vector),写入文件并写入集合
{
	if(Num<=N)
	{
		srand(time(0));
		Sleep(Num);//停一会，防止两个集合随机产生的元素全相等
		fstream put;
		put.open(path.c_str(),ios::in|ios::out);
		vector<int> temp;//中间集合
		for (int i = 0; i <N; ++i)
		{
			temp.push_back(i);
		}
		random_shuffle(temp.begin(), temp.end());
		vector<int> v;
		for (int i = 0; i < Num; i++)
		{
			put<<temp[i]<<" ";
			v.push_back(temp[i]);
		}
		put.close();
		return v;
	}
	else if (Num>N)
	{
		vector<int> empty;
		cout<<"the maximun set's length is "<<N<<endl;
		while(empty.size()!=0)
			empty.pop_back();
		return empty;
	}
}
vector<int>  initialize(int Num)//初始化集合元素且其内元素不重复
{
	if (Num==N)
	{
		vector<int> v=randperm("2.txt",N);
		cout<<"Done"<<endl;
		return v;
	}
	bool _exist1[N];//判断该数是否存在
	for(int i=0;i<N;i++)//初始化_exist数组
		_exist1[i]=false;

	fstream input1;
	input1.open("2.txt",ios::out|ios::in);
	for(int i=0;i<Num;i++)
	{
		int b=rand()%N;//产生0~(N-1)的随机数
		if(!_exist1[b])//如果存在该数就重新来一遍,否则就放到文本里去
		{
			input1<<b<<" ";
			_exist1[b]=true;
		}
		else
			i--;
	}
	cout<<"Done"<<endl;
	input1.close();
	vector<int> v;
	v=scan("2.txt");
	return v;
}
vector<int> unionset(vector<int> &v1,vector<int>&v2)//并集，结束时将v1,v2重置成初始的样子
{
	const vector<int> V1=v1,V2=v2;
	vector<int> v;
	const vector<int>v3=v1;
	const vector<int>v4=v2;
	int n1=v3.size();
	int n2=v4.size();
	if(n1==0)
		return v2;
	else if(n2==0)
		return v1;
	for(int i=0;i<n1;i++)
	{
		v.push_back(v1[i]);
	}
	for(int i=0;i<n2;i++)
	{
		v.push_back(v2[i]);
	}
	v1=V1;v2=V2;
	v=single(v);
	return v;
}
vector<int> intersection(vector<int>&v1,vector<int>&v2)//交集，结束时将v1,v2重置成初始的样子
{
	const vector<int> V1=v1,V2=v2;
	vector<int> v;
	int n1=v1.size();
	int n2=v2.size();
	for(int i=0;i<n1;i++)
		for(int j=0;j<n2;j++)
			if(v1[i]==v2[j])
				v.push_back(v1[i]);
	v1=V1;v2=V2;
	v=single(v);
	return v;
}
vector<int> difference(vector<int> &v1,vector<int>&v2)//v1-v2=v1-(v1∩v2)差集，结束时将v1,v2重置成初始的样子
{
	const vector<int> V1=v1,V2=v2;
	vector<int> v;
	v2=intersection(v1,v2);
	int n1=v1.size(),n2=v2.size();
	vector<bool> mid;
	for(int i=0;i<n1;i++)
	{
		mid.push_back(true);
		for(int j=0;j<n2;j++)
			if(v1[i]==v2[j])
				mid[i]=false;
		if(mid[i]==true)
			v.push_back(v1[i]);
	}
	v1=V1;v2=V2;
	v=single(v);
	return v;
}
string include(vector<int>&v1,vector<int>&v2)//v1是否属于v2，结束时将v1,v2重置成初始的样子
{
	const vector<int> V1=v1,V2=v2;
	vector<int> v=intersection(v1,v2);//先取交集
	v1=V1;v2=V2;
	int n1=v1.size(),n2=v2.size(),n=v.size();//看交集大小与原集大小判断是否真包含或被真包含,或者相等
	if(n1>n2&&n2==n)
		return "v1真包含v2";
	else if(n2>n1&&n1==n)
		return "v2真包含v1";
	else if(n1==n&&n2==n)
		return "v1等于v2";
	else 
		return "v1和v2没有包含与被包含关系";
}
bool is_element_in_vector(vector<int> v,int element)//判断元素是否在集合内，结束时将v重置成初始的样子
{
	const vector<int> V=v;
    vector<int>::iterator it;//迭代器声明
    it=find(v.begin(),v.end(),element);//查找成功返回一个指向指定元素的迭代器，查找失败返回end迭代器
    if (it!=v.end())
	{
		v=V;
		return true;
	}
    else
   {
	   v=V;
	   return false;
	}
}
vector<int> SDS(vector<int> &v1, vector<int> &v2)//对称差集Symmetric difference set,最后重置回原状态
{
	vector<int> V1=difference(v1,v2),V2=difference(v2,v1);//先取两个差集v1-v2和v2-v1
	vector<int> v=unionset(V1,V2);//然后取并集，得到对称差集
	v=single(v);
	return v;
}
vector<int> AS(vector<int> &v1)//绝对补差，就是求v1关于全集的补集Absolute senders,最后重置回原状态
{
	if(v1.size()==N)
	{
		vector<int> x;
		return x;
	}
	vector<int> V;
	for (int i = 0; i < N; i++)
		V.push_back(i);
	vector<int> v=v1;
	v=difference(V,v);
	return v;
}
vector<int> msubset(vector<int> &v1,int m)//返回一个随机m元子集，未改变v1
{
	vector<int> v;
	v.resize(m,-1);
	const int n=v1.size();
	for(int i=0;i<m;i++)
	{
		int x=rand()%(i+1);
		if(v[x]==-1)
			v[x]=v1[i];
		else
			i--;
	}
	return v;
}
int nset(vector<int> &v1)//返回集合元素个数，未改变v1
{
	return v1.size();
}
int Big(vector<int> &v1,int n)//返回集合中比n大的元素个数,未改变v1
{
	int x=v1.size();
	int sum=0;
	for(int i=0;i<x;i++)
		if(v1[i]>n)
			sum++;
	return sum;
}
int Small(vector<int> &v1,int n)//返回集合中比n小的元素个数,未改变v1
{
	int x=v1.size();
	int sum=0;
	for(int i=0;i<x;i++)
		if(v1[i]<n)
			sum++;
	return sum;
}
string Bigsubset(vector<int> &v1,int n)//返回集合中比n大的所有元素的子集个数,未改变v1
{
	const long long s=static_cast<long long>(Big(v1,n));
	return pow2(s);
}
string Smallsubset(vector<int> &v1,int n)//返回集合中比n小的所有元素的子集个数,未改变v1
{
	const long long s=static_cast<long long>(Small(v1,n));
	return pow2(s);
}
string ISS(vector<int> &v1,vector<int> &v2)//includesubset包含子集，未改变v1,v2
{
	vector<int> V1=v1,V2=v2;
	int n1=V1.size(),n2=V2.size();
	vector<int> V3=intersection(V1,V2);//求v1与v2交集，为了判断是否有包含关系
	const long long n3=V3.size();
	if(n3==n2&&n1==n3)//若v1、v2相等,返回1
		return "v1=v2,所以v1包含v2的子集数或者说v2包含v1的子集数："+pow2(n3);
	else if(n1==n2&&n1!=n3&&n2!=n3)//若v1、v2长度相等但是内容不相等,返回0
		return "v1,v2无包含关系，所以v1包含v2的子集或者说v2包含v1的子集数：0";
	else if(n1>n2)//若v2比v1的小，再进行判断
	{
		if(n3<n2)//若交集v3比v2小，说明v1不包含v2
			return "v1,v2无包含关系，所以v1包含v2的子集或者说v2包含v1的子集数：0";
		else if(n3==n2)//若交集v3=v2，说明v1包含v2
			return "v1真包含v2，所以v1包含v2的子集数："+pow2(n3);
		else//若交集v3比v2大，返回未知错误的提示
			return "Unknown Error";
	}
	else if(n1<n2)//若v1比v2小，再进行判断
	{
		if(n3<n1)//若交集v3比v1小，说明v2不包含v1
			return "v1,v2无包含关系，所以v1包含v2的子集或者说v2包含v1的子集数：0";
		else if(n3==n1)//若交集v3=v1，说明v2包含v1
			return "v2真包含v1，所以v2包含v1的子集数："+pow2(n3);
		else//若交集v3比v1大，返回未知错误的提示
			return "Unknown Error";
	}
}
int qiumiji(vector<int> *a,int len)//找所有子集的函数,集合放在数组a中,长度为len,直接移位操作
{
	ofstream output;
	output.open("6.txt",ios::out);
	int i=0,j=0;
	bool flag=false;
	output<<"{NULL}"<<endl;
	cout<<"{NULL}"<<endl;
	for(i=1;!flag;i++)
	{
		output<<"{";
		cout<<"{";
		flag=true;
		for(j=0;j<len;j++)
		{
			if((i>>j)&1)
			{
				vector<int>::iterator A=a->begin();
				int s=*(A+j);//类似于数组元素a[j]等价于*(a+j)，向量需要用迭代器
				output<<s<<" ";
				cout<<s<<" ";
			}
			else
				flag=false;
		}
		output<<"}"<<endl;
		cout<<"}"<<endl;
	}
	output.close();
	return i;
}
#endif
