#include<bits/stdc++.h>//@为属于#为不属于 |为V  &为^   *为U 
using namespace std;
string turnBelong(string& s);
int main(){
	string s="x@A-(B|C)";
	turnBelong(s);
	cout<<s<<endl;
} 
string turnBelong(string& s){
	 s.replace(3,6,"&x#B*C");
	 return s;	 
}
