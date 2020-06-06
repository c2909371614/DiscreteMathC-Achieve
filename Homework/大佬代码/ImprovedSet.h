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
const int N=1000;//ȫ����Ԫ�ظ���
vector<int> scan(string path)//���ļ���ȡ���ϡ�(��������ֻ�����֣���ð�����ȥ�������в���Ҫ���鷳
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
string DTS(int a)//����ת��Ϊ�ַ���digits to string
{
	string res;
    stringstream ss;//������ss����Ҫͷ�ļ�<sstream>
    ss << a;// ������aת������ss
    ss >> res;//����ssת�����ַ���
    return res;
}
vector<vector<string> > multiplication(vector<int> &v1,vector<int> &v2)//�����˷�������һά�����ϳ�Ϊһ����ά������δ�ı�v1,v2
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
void output_double_vector(vector<vector<string> > &v)//�����ά������δ�ı�v
{
	cout<<endl;
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v[i].size(); j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
}
string pow2(const long long n)//����2��n�Σ���Ϊ��̫���������ַ������
{
	int a[10000] = {0};    //�ȶ���һ������
    int i, j;
    a[0] = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[j] *= 2;     //��ÿ��ֵ��2����������
        }
        for (j = 0; j < 10000; j++)   //�������������ֵ
        {
            if (a[j] > 9)
            {
                a[j + 1]++;     //��λ
                a[j] = a[j] % 10;
            }
        }
    }
    j = 9999;
    while (a[j] == 0)     //ȥ�������и�λ�����0����Ȼǰ���кܶ�0
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
string S(vector<int> &v)//�Ӽ��� subset��δ�ı�v
{
	const long long n=v.size();
	return pow2(n);
}
string PS(vector<int> &v)//���Ӽ���proper subset��δ�ı�v
{
	string s=S(v);
	int n=s.length();
	s[n-1]=char(s[n-1]-1);
	return s;
}
string NPS(vector<int> &v)//�ǿ����Ӽ���nonvoid proper subset
{
	string s=PS(v);
	int n=s.length();
	s[n-1]=char(s[n-1]-1);
	return s;
}
string zeroorall(vector<int> &v)//�ռ���ȫ�����жϣ�δ�ı�v
{
	int n=v.size();
	if(n==0)
		return "this set is an empty set";
	else if(n==N)
		return "this set is the universal set";
	else if(n>0&&n<N)
		return "This set is neither empty nor universal";
}
vector<int> single(vector<int> &v)//���ظ���
{
	vector<int> v1=v;
	sort(v1.begin(),v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	return v1;
}
void input(string path,vector<int> &v)//���ļ��ж�ȡ����
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
void output(vector<int> &v)//���һά�����ļ��ϣ�δ�ı�v
{
	const vector<int>V=v;
	int n=V.size();
	cout<<"the elements in this set:";
	for(int i=0;i<n;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}
vector<int> randperm(string path,int Num)//�������������ظ������룩(���һ��������ҵ�Num���ȵ�����vector),д���ļ���д�뼯��
{
	if(Num<=N)
	{
		srand(time(0));
		Sleep(Num);//ͣһ�ᣬ��ֹ�����������������Ԫ��ȫ���
		fstream put;
		put.open(path.c_str(),ios::in|ios::out);
		vector<int> temp;//�м伯��
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
vector<int>  initialize(int Num)//��ʼ������Ԫ��������Ԫ�ز��ظ�
{
	if (Num==N)
	{
		vector<int> v=randperm("2.txt",N);
		cout<<"Done"<<endl;
		return v;
	}
	bool _exist1[N];//�жϸ����Ƿ����
	for(int i=0;i<N;i++)//��ʼ��_exist����
		_exist1[i]=false;

	fstream input1;
	input1.open("2.txt",ios::out|ios::in);
	for(int i=0;i<Num;i++)
	{
		int b=rand()%N;//����0~(N-1)�������
		if(!_exist1[b])//������ڸ�����������һ��,����ͷŵ��ı���ȥ
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
vector<int> unionset(vector<int> &v1,vector<int>&v2)//����������ʱ��v1,v2���óɳ�ʼ������
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
vector<int> intersection(vector<int>&v1,vector<int>&v2)//����������ʱ��v1,v2���óɳ�ʼ������
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
vector<int> difference(vector<int> &v1,vector<int>&v2)//v1-v2=v1-(v1��v2)�������ʱ��v1,v2���óɳ�ʼ������
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
string include(vector<int>&v1,vector<int>&v2)//v1�Ƿ�����v2������ʱ��v1,v2���óɳ�ʼ������
{
	const vector<int> V1=v1,V2=v2;
	vector<int> v=intersection(v1,v2);//��ȡ����
	v1=V1;v2=V2;
	int n1=v1.size(),n2=v2.size(),n=v.size();//��������С��ԭ����С�ж��Ƿ�������������,�������
	if(n1>n2&&n2==n)
		return "v1�����v2";
	else if(n2>n1&&n1==n)
		return "v2�����v1";
	else if(n1==n&&n2==n)
		return "v1����v2";
	else 
		return "v1��v2û�а����뱻������ϵ";
}
bool is_element_in_vector(vector<int> v,int element)//�ж�Ԫ���Ƿ��ڼ����ڣ�����ʱ��v���óɳ�ʼ������
{
	const vector<int> V=v;
    vector<int>::iterator it;//����������
    it=find(v.begin(),v.end(),element);//���ҳɹ�����һ��ָ��ָ��Ԫ�صĵ�����������ʧ�ܷ���end������
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
vector<int> SDS(vector<int> &v1, vector<int> &v2)//�ԳƲSymmetric difference set,������û�ԭ״̬
{
	vector<int> V1=difference(v1,v2),V2=difference(v2,v1);//��ȡ�����v1-v2��v2-v1
	vector<int> v=unionset(V1,V2);//Ȼ��ȡ�������õ��ԳƲ
	v=single(v);
	return v;
}
vector<int> AS(vector<int> &v1)//���Բ��������v1����ȫ���Ĳ���Absolute senders,������û�ԭ״̬
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
vector<int> msubset(vector<int> &v1,int m)//����һ�����mԪ�Ӽ���δ�ı�v1
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
int nset(vector<int> &v1)//���ؼ���Ԫ�ظ�����δ�ı�v1
{
	return v1.size();
}
int Big(vector<int> &v1,int n)//���ؼ����б�n���Ԫ�ظ���,δ�ı�v1
{
	int x=v1.size();
	int sum=0;
	for(int i=0;i<x;i++)
		if(v1[i]>n)
			sum++;
	return sum;
}
int Small(vector<int> &v1,int n)//���ؼ����б�nС��Ԫ�ظ���,δ�ı�v1
{
	int x=v1.size();
	int sum=0;
	for(int i=0;i<x;i++)
		if(v1[i]<n)
			sum++;
	return sum;
}
string Bigsubset(vector<int> &v1,int n)//���ؼ����б�n�������Ԫ�ص��Ӽ�����,δ�ı�v1
{
	const long long s=static_cast<long long>(Big(v1,n));
	return pow2(s);
}
string Smallsubset(vector<int> &v1,int n)//���ؼ����б�nС������Ԫ�ص��Ӽ�����,δ�ı�v1
{
	const long long s=static_cast<long long>(Small(v1,n));
	return pow2(s);
}
string ISS(vector<int> &v1,vector<int> &v2)//includesubset�����Ӽ���δ�ı�v1,v2
{
	vector<int> V1=v1,V2=v2;
	int n1=V1.size(),n2=V2.size();
	vector<int> V3=intersection(V1,V2);//��v1��v2������Ϊ���ж��Ƿ��а�����ϵ
	const long long n3=V3.size();
	if(n3==n2&&n1==n3)//��v1��v2���,����1
		return "v1=v2,����v1����v2���Ӽ�������˵v2����v1���Ӽ�����"+pow2(n3);
	else if(n1==n2&&n1!=n3&&n2!=n3)//��v1��v2������ȵ������ݲ����,����0
		return "v1,v2�ް�����ϵ������v1����v2���Ӽ�����˵v2����v1���Ӽ�����0";
	else if(n1>n2)//��v2��v1��С���ٽ����ж�
	{
		if(n3<n2)//������v3��v2С��˵��v1������v2
			return "v1,v2�ް�����ϵ������v1����v2���Ӽ�����˵v2����v1���Ӽ�����0";
		else if(n3==n2)//������v3=v2��˵��v1����v2
			return "v1�����v2������v1����v2���Ӽ�����"+pow2(n3);
		else//������v3��v2�󣬷���δ֪�������ʾ
			return "Unknown Error";
	}
	else if(n1<n2)//��v1��v2С���ٽ����ж�
	{
		if(n3<n1)//������v3��v1С��˵��v2������v1
			return "v1,v2�ް�����ϵ������v1����v2���Ӽ�����˵v2����v1���Ӽ�����0";
		else if(n3==n1)//������v3=v1��˵��v2����v1
			return "v2�����v1������v2����v1���Ӽ�����"+pow2(n3);
		else//������v3��v1�󣬷���δ֪�������ʾ
			return "Unknown Error";
	}
}
int qiumiji(vector<int> *a,int len)//�������Ӽ��ĺ���,���Ϸ�������a��,����Ϊlen,ֱ����λ����
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
				int s=*(A+j);//����������Ԫ��a[j]�ȼ���*(a+j)��������Ҫ�õ�����
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
