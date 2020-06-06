#include<bits/stdc++.h>
using namespace std;
void bin(int x){
	if(x / 2 == 0) {
		cout << x % 2 << " ";
		return ;
	}
	bin(x/2);
	cout << x % 2 << " "; 
} 
int main(){
	for(int i = 0; i <= 20; i++){
		cout << i << "&" << i + 1 << "-" << (i&(i + 1))<< endl; 
	}
}
