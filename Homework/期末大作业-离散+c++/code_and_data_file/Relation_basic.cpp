#include"Relation.h" 

Relation::Relation()
{
	index=0;
	//cout<<"begin to test other Relation"<<endl;
	first="";
}
Relation::Relation(string first,string second)//ʹ���������Ϲ������ɶ�Ԫ��ϵAxB 
{
	index=0;
	get_all_A_B(first,second);//invoked  get_all_A_B to construct 
 } 
Relation::Relation(string s)
{
	index=0;
	get_all_A_B(s,s); 
}
Relation::Relation(vector<int> a,vector<int> b)
{
	index=0;
	get_all_A_B(a,b);
}
Relation::Relation(vector<int> a)
{
	index=0;
	get_all_A_B(a,a);
}
Relation::Relation(Relation& rela)
{
	index=0;
	rela.first=first;
	rela.second=second;
}
Relation::~Relation() {
	
}
string Relation::getFirst() 
{
	return first;
 } 
string Relation::getSecond()
{
	return second;
}
void Relation::setFirst_Second(string s1,string s2)
{
	first=s1;
	second=s2;
}
template<typename T>
void Relation::get_all_A_B(T first,T second)
{
	for(int i=0;i<first.size();i++){
		for(int j=0;j<second.size();j++){
			this->first+=first[i];
			this->second+=second[j];
		}
	}
}
void Relation::myPrint()
{
	if(first.size()==0)cout<<"@"<<endl;//��Ϊ�ռ� 
	else cout<<toRelaString()<<endl; 
}
string Relation::toRelaString()
{
	stringstream ss;
	ss<<"{";
	for(int i=0;i<first.size();i++)
	{//�����Ԫ��ϵʽ�� 
		ss<<"<"<<first[i]<<","<<second[i]<<">";
		if(i!=first.size()-1)ss<<",";
		else ss<<"}";
	 } 
	 return ss.str();
}
void Relation::print_Con()
{
	cout<<"{";
	for(int i=0;i<index;i++)
	{//�����Ԫ��ϵʽ�� 
		cout<<"<"<<first_set[i]<<","<<second_set[i]<<">";
		if(i!=index-1)cout<<",";
		else cout<<"}"<<endl;
	 }
}
