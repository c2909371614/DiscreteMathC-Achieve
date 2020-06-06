#include<bits/stdc++.h>
using namespace std;
bool conditionalS(bool a,bool b){//a-->bµÄÔËËãº¯Êı 
	if(!a||b)return true;
	else return false;
}
int main()
{
	bool a[2][2];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			a[i][j]=i;a[j][i]=j;
			printf("%d %d %d\n",a[i][j],a[j][i],conditionalS(a[i][j],a[j][i])) ;
		}
	
 } 
