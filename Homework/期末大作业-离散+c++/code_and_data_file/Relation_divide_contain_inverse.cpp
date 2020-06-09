#include"Relation.h" 

void Relation::get_divide(string s)
{
	first="";
	second="";
	int count=0;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if((s[j]-'0')%(s[i]-'0')==0){
				this->first+=s[i];
				this->second+=s[j];
			}
		}
	}
}
void Relation::get_Con(string set[100])
{
	int num=0;//num用于得出set数组的有效个数 
	while(set[num].size()>0)
	{
		if(set[num]!="@")sort(set[num].begin(),set[num].end());//@代表空集 
		cout<<set[num]<<endl;
		num++;
	}
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++)
		{//先排序寻找到说明为子集则包含 
			if((set[i]=="@")||(set[j].find(set[i].c_str())!=string::npos)){//空集必定被包含 
				first_set[index]=toSetString(set[i]);
				second_set[index]=toSetString(set[j]);
				index++;
			}
		}
	}
	//cout<<index<<endl;
}
Relation Relation::get_inverse()
{
	Relation rela;
	rela.setFirst_Second(second,first);
	return rela;
 } 
