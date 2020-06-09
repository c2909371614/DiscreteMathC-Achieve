#include"Relation.h"

void Relation::get_Ia(string s)
{
	first="";
	second="";
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){//关系判断 
			if(s[i]==s[j]){
				this->first+=s[i];
				this->second+=s[j];
			}
		}
	}
}
void Relation::get_Bigger(string s)
{
	first="";
	second="";
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){//关系判断 
			if(s[i]>s[j]){
				this->first+=s[i];
				this->second+=s[j];
			}
		}
	}
}
void Relation::get_Smaller(string s)
{
	first="";
	second="";
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){//关系判断 
			if(s[i]<s[j]){
				this->first+=s[i];
				this->second+=s[j];
			}
		}
	}
	//cout<<toRelaString()<<endl;
 } 

