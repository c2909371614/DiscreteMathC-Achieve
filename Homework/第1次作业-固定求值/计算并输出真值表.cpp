//计算并输出pVq^r-->rVs的真值表 
#include<iostream>
#include<cstdio>
using namespace std;
int disjunction(int a,int b){//aVb
	if(a||b)return 1;
	else return 0;
}
int conjunction(int a,int b){//a^b
	if(a&&b)return 1;
	else return 0;
}
int conditionalS(int a,int b){//a-->b
	if(!a||b)return 1;
	else return 0;
}
int main()
{
	int p,q,r,s;
	printf("1表示真，0表示假；\n"); 
	printf("p\tq\tr\ts\tpVq^r-->rVs\n");
	for(p=1;p>=0;p--)
		for(q=1;q>=0;q--)
			for(r=1;r>=0;r--)
				for(s=1;s>=0;s--){
					printf("%d\t%d\t%d\t%d\t",p,q,r,s);
					printf("%d\n",conditionalS(conjunction(disjunction(p,q),r),disjunction(r,s)));
				}
 } 
