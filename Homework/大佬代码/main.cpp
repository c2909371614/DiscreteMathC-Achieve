#include"ImprovedSet.h"
/*
��ʵ�֣�
*1.*���ظ���
 2.*����(����֮���)�����ϵļӷ�����
 3.*����(Ԫ���뼯��)
 4.*����(����֮���)
 5.*����(����֮���)
 6.*һ��(A��B�Ĳ)
 7.*�ռ���ȫ���жϣ�������Ϊ�ռ��ĳ���Ϊ0��ȫ���ĳ���Ϊ1000��ȫ��Ϊ0-999������������
 8.*���ϵ��Ӽ������Ӽ���ǿ����Ӽ�����
 *9.���ϵĳ˷�����(��ʱֻ��������һά�����ϳɶ�ά����)
 10.*�ԳƲ(A��B�Ĳ��B��A�Ĳ)��6�Ƶ�
 11.*���Բ���(~A����A����ȫ��E�Ĳ���)��6�Ƶ�
 12.*nԪ��(���ؼ���Ԫ�ظ���)
 13.*���mԪ�Ӽ�
 14.Ѱ��ָ�������б�nС����󣩵�Ԫ�ظ���
 15.���㼯���б�n��(��С��������Ԫ�ص��Ӽ�����,���Ӽ��ͷǿ����Ӽ������Ӽ���ɣ��ͼ�һ����������
 16.���� ����v1��������v2������Ԫ��(�򼯺�v2��������v1������Ԫ��)  ���Ӽ���
*17*�ݼ���ֻд��һ��v1�ģ�ע��v1��������ô�ССһЩ����Ȼ�ݼ����ʱ����ƻ������
��ʵ�֣�
*/
int main()
{
/*
	cout<<"Please enter the collection source file of v1 and v2 (separated by lines):"<<endl;//���ļ�ɨ�����루��һ�����뷽ʽ��
	string path1;cout<<"v1's path:";cin>>path1;vector<int> v1=scan(path1);
	string path2;cout<<"v2's path:";cin>>path2;vector<int> v2=scan(path2);
*/	

	cout<<"(Note: if the size is too large, the power set will take too long)"<<endl<<"Please input the size of set1 and set2(separated by a space):";
	int x1,x2;cin>>x1>>x2;
	vector<int> v1=randperm("1.txt",x1),v2=initialize(x2);//������������� ָ����С���� ������,����Ԫ�ش����1.txt��2.txt�ڣ��ڶ��� ���뷽ʽ��
	system("pause");
	//cout<<endl;output(v1);cout<<endl;output(v2);//��� v1��v2��������
	
	
	/*cout<<"the numbers of v1:"<<nset(v1)<<endl;cout<<"the numbers of v2:"<<nset(v2)<<endl<<endl;system("pause");//nԪ����ʵ��

	cout<<"Please input a integer for return a random M-element subset:";int m;cin>>m;
	cout<<"Please input a integer for return a whose random M-element subset��1 for v1, 2 for v2��:";int n;cin>>n;
	if(n==1)
	{vector<int> mset=msubset(v1,m);cout<<"a random "<<m<<"-element subset of v1:";output(mset);}
	else if(n==2)
	{vector<int> mset=msubset(v2,m);cout<<"a random "<<m<<"-element subset of v2:";output(mset);}//���mԪ�Ӽ���
	cout<<endl;
	system("pause");

	cout<<"v1:"<<zeroorall(v1)<<endl<<"v2:"<<zeroorall(v2)<<endl<<endl;//�ж�ȫ��/�ռ�
	system("pause");

	string z1=S(v1),z2=S(v2);cout<<"the numbers of v1's subset:"<<z1<<endl<<"the numbers of v2's subset:"<<z2<<endl;//�ж��Ӽ�����
	string z3=PS(v1),z4=PS(v2);cout<<"the numbers of v1's proper subset:"<<z3<<endl<<"the numbers of v2's proper subset:"<<z4<<endl;//�ж����Ӽ���
	string z5=NPS(v1),z6=NPS(v2);cout<<"the numbers of v1's nonvoid proper subset:"<<z5<<endl<<"the numbers of v2's nonvoid proper subset:"<<z6<<endl<<endl;//�жϷǿ����Ӽ���
	system("pause");

	vector<int> vbing=unionset(v1,v2);//����
	cout<<"������"<<endl;if(vbing.size()!=0) output(vbing);else cout<<"Their union set is empty"<<endl<<endl;
	system("pause");

	vector<int> vjiao=intersection(v1,v2);//����
	cout<<"����:"<<endl;if(vjiao.size()!=0) output(vjiao); else cout<<"Their intersection is empty"<<endl<<endl;
	system("pause");

	vector<int> vcha=difference(v1,v2);//�
	cout<<"�:"<<endl;if(vcha.size()!=0) output(vcha); else cout<<"Their difference set is empty"<<endl<<endl;
	system("pause");

	vector<int> vduichencha=SDS(v1,v2);//�ԳƲ
	cout<<"�ԳƲ:"<<endl;if(vduichencha.size()!=0) output(vduichencha); else cout<<"Their Symmetric difference set is empty"<<endl<<endl;
	system("pause");

	vector<int> v1juedui=AS(v1),v2juedui=AS(v2);//v1,v2�ľ��Բ���
	cout<<"v1�ľ��Բ��";output(v1juedui);cout<<"v2�ľ��Բ��";output(v2juedui);cout<<endl;
	system("pause");

	string d=include(v1,v2);//�ж��໥������ϵ
	cout<<d<<endl<<endl;//���������໥������ϵ
	system("pause");

	cout<<ISS(v1,v2)<<endl<<endl;//ʵ�� ���� ����v1��������v2������Ԫ��(�򼯺�v2��������v1������Ԫ��)  ���Ӽ���
	system("pause");


	int number_of_set=0,n_bs=0;//��ʼ�жϼ����бȸ���ֵ��/С�ĸ���
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
	else cout<<"Input Error"<<endl;//�жϼ����бȸ���ֵ��/С�ĸ����Ľ���
	cout<<endl;
	system("pause");


	int x;cout<<"Enter an integer x to determine whether it is in the union of v1 and v2:";cin>>x;
	if(is_element_in_vector(vbing,x))//�ж�x�Ƿ�����v1��v2�Ĳ���
		cout<<x<<" in the union set"<<endl;
	else
		cout<<x<<" not in the union set"<<endl;
	cout<<endl;
	system("pause");
*/
	/*vector<vector<string> > vcheng=multiplication(v1,v2);//���ϵĳ˷�������һ���¼���
	output_double_vector(vcheng);//����¼���
	cout<<endl;
	system("pause");*/

	vector<int>* a1=&v1;//��һ����������ָ��a1ָ��v1
	int t0=GetTickCount();//��ʼ��ʱ��
	int count=0;//��Ϊ�ݼ�����ͳ��ֵ����
	cout<<"v1�ݼ���"<<endl;
	count=qiumiji(a1,v1.size());//���ݼ����������ӡ���ı�C:\Users\13342\Desktop\6.txt��������qiumiji�������޸�
	int t1=GetTickCount();//������ʱ��
	cout<<"v1�ݼ�����:"<<count<<endl;//���v1���ݼ�����
	cout<<"�󳤶�Ϊ"<<v1.size()<<"�ļ��ϵ��ݼ������ѵ�ʱ��Ϊ:"<<t1- t0<<"ms."<<endl;//�������ݼ����ѵ�ʱ��


	/*int s="abcd";
	for(int i=0;i<4;i++)
	{
		int n=s.length();
		cout<<n;
		s.erase(1,1);
	}����int�ĳ����Ƿ�����������ݶ���С*/
	system("pause");
}
