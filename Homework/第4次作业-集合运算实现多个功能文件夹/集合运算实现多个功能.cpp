#include<bits/stdc++.h>//5+1+1+1
using namespace std;
int rand_num();//生成100以内的随机数200个
int readSet(int a[],int b[]);//文件读取并返回a和b较长的lenth 
int print_set(const int a[],const int b[]);//打印 
bool Belong(const int a[]);//输入一个数判断是否属于a
int sumSet(int sum[],const int a[],const int b[]);//合集
int subSet(int sub[],const int a[],const int b[]);
bool isEmpty(const int a[]);
int DiffSet(int diff[],const int a[],const int b[]);//差集 
int subNum(const int a[]);
bool isSubSet(const int a[],const int b[]); //b是否为a的子集 
bool isRealSub(const int a[],const int b[]);//b是否为a的真子集 
void oppsDiffSet(int opps[],const int a[],const int b[]);//对称差集 
bool isEqual(const int a[],const int b[]); //判断是否相等 
int a_len=0,b_len=0,sum_len=0,sub_len=0,diff_len=0,opps_len=0;//j_len , k_len ,sum_len and sub_len is a[] , b[] ,sum[] and sub[] lenth;
const int max_len=105;//固定长度的字符常数 
int main() {
	int a[1000],b[1000],sum[1000],sub[1000],diff[1000],opps[1000];
	int choice;
	
	do {
		cout<<"1: rand_num 2:readSet 3:print set a and b 4: judge num belong a"<<endl;
		cout<<"5: get sumSet and put it into a sum.txt 6:subSet 7:isEmpty "<<endl;
		cout<<"8:DiffSet 9:isSubSet 10:is realSub 11:opps 12:isEqual"<<endl;
		cout<<"enter your operator:";		
		cin>>choice;
		switch(choice) {
			case 0:
				break;
			case 1:
				rand_num();
				break;
			case 2:
				readSet(a,b);//文件读取
				break;
			case 3:
				print_set(a,b);//打印到屏幕 
				break;
			case 4:
				Belong(a);//属于 
				break;
			case 5:
				sumSet(sum,a,b);//合集 
				break; 
			case 6:
				subSet(sub,a,b);//交集 
				break;
			case 7:
				isEmpty(a);//judge empty or not
				break;
			case 8:
				DiffSet(diff,a,b);
				break;
			case 9:
				isSubSet(a,sub);
				break; 
			case 10:
				isRealSub(a,sub);
				break;
			case 11:
				oppsDiffSet(opps,a,b);
				break;
			case 12:
				isEqual(a,b);
				break; 
			default:
				cout<<"error intput"<<endl;
		}
		cout<<endl;
	} while(choice);//intput 0 let it down

}
int rand_num() {
	fstream in_a,in_b;
	in_a.open("a.txt",ios::out);
	in_b.open("b.txt",ios::out);//打开文件a.txt and b.txt for produce rand_num
	srand(time(0));//rand seed with time
	for(int i=0; i<200; i++) {
		if(i%20==0&&i!=0)
			in_a<<endl;
		in_a<<rand()%100+1<<" ";
		if(i%20==0&&i!=0)
			in_b<<endl;
		in_b<<rand()%100+1<<" ";
		
	}
	in_a.close();
	in_b.close();
	return 0;
}
int readSet(int a[],int b[]) {
	fstream in_a,in_b;
	in_a.open("a.txt",ios::in);
	in_b.open("b.txt",ios::in);//d=打开指定文件读取数据 
	int aTemp[max_len],bTemp[max_len];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));
	for(int i=0;i<200;i++){
		in_a>>a[i];
		in_b>>b[i];
	} 
	for(int i=0;i<200;i++){
		aTemp[a[i]]++;
		bTemp[b[i]]++;
	}
	
	for(int i=0;i<max_len;i++){
		if(aTemp[i]!=0)	
			a[a_len++]=i;
		if(bTemp[i]!=0)	
			b[b_len++]=i;
	}
	in_a.close();
	in_b.close();
	return 0;
}
int print_set(const int a[],const int b[]){
	cout<<"a:"<<endl;
	for(int i=0;i<a_len;i++){
		if(i%20==0&&i!=0)
			cout<<endl;
		cout<<a[i]<<" ";
		
	}
	cout<<endl;
	cout<<"b:"<<endl;
	for(int i=0;i<b_len;i++){
		if(i%20==0&&i!=0)
			cout<<endl;
		cout<<b[i]<<" ";
		
	}
	cout<<endl;
	return 0;
}
bool Belong(const int a[]){
	
}
int sumSet(int sum[],const int a[],const int b[]){
	int sumTemp[max_len];
	memset(sumTemp,0,sizeof(sumTemp));
	for(int i=0;i<max_len;i++){
		sumTemp[a[i]]++;
		sumTemp[b[i]]++;//利用桶排序思想除去重复 
	}
	for(int i=0;i<max_len;i++){
		if(sumTemp[i]!=0)
			sum[sum_len++]=i;//给sum赋值并计算sum的长度 
	}
	fstream out("sum.txt",ios::out) ;
	for(int i=0;i<sum_len;i++){
		if(i%20==0&&i!=0)//every 20 num turn a row 
			out<<endl;
		out<<sum[i]<<" ";
	}
	out.close();
	//cout<<sum;
	return 0;
}
int subSet(int sub[],const int a[],const int b[]){
	int aTemp[max_len],bTemp[max_len];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));
	for(int i=0;i<max_len;i++){
		aTemp[a[i]]++;
		bTemp[b[i]]++;
	}
	for(int i=0;i<max_len;i++){
		if(aTemp[i]!=0&&bTemp[i]!=0)
			sub[sub_len++]=i;
	}
	fstream out("sub.txt",ios::out) ;
	for(int i=0;i<sub_len;i++){
		if(i%20==0&&i!=0)//every 20 num turn a row 
			out<<endl;
		out<<sub[i]<<" ";//输入文件sub.txt 
	}
	out.close();
	return 0;
}
bool isEmpty(const int a[]){
	for(int i=0;i<100;i++){
		if(a[i]!=0){
			cout<<"not empty"<<endl;//利用数字初始化为0的特点 
			return false;
		}
	}
	cout<<"empty"<<endl;
	return true;
}
int DiffSet(int diff[],const int a[],const int b[]){
	int aTemp[max_len],bTemp[max_len];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));
	for(int i=0;i<max_len;i++){//筛选 
		aTemp[a[i]]++;
		bTemp[b[i]]++;
	}
	for(int i=0;i<max_len;i++){
		if(aTemp[i]!=0&&bTemp[i]==0)
			diff[diff_len++]=i;
	}
	fstream out("diff.txt",ios::out) ;
	for(int i=0;i<diff_len;i++){
		if(i%20==0&&i!=0)//every 20 num turn a row 
			out<<endl;
		out<<diff[i]<<" ";//输入文件diff.txt 
	}
	out.close();
	return 0;
}
int subNum(const int a[]){//子集个数 
	int n=0;
	while(a[n++]);//获取长度 
	
	return 1<<n; 	
}
bool isSubSet(const int a[],const int b[]){
	int aTemp[max_len],bTemp[max_len];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));
	for(int i=0;i<max_len;i++){//先转换 
		aTemp[a[i]]++;
		if(b[i]>0&&b[i]<106)
			bTemp[b[i]]++;
	}
	for(int i=0;i<max_len;i++){
		if(aTemp[i]==0&&bTemp[i]!=0){
		 	cout<<"is not subSet"<<endl; 
			return false;
		}	
	}
	cout<<"is subSet"<<endl;
	return true; 
}
bool isRealSub(const int a[],const int b[]){
	int aTemp[max_len],bTemp[max_len];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));
	for(int i=0;i<max_len;i++){//先转换 
		aTemp[a[i]]++;
		if(b[i]>0&&b[i]<106)
			bTemp[b[i]]++;
	}
	bool flag=false;
	for(int i=0;i<max_len;i++){
		if(aTemp[i]==0&&bTemp[i]!=0){
		 	cout<<"is not isRealSub"<<endl; 
			return false;
		}
		if(aTemp[i]!=0&&bTemp[i]==0)
			flag=true;	
	}
	if(flag){
		cout<<"is isRealSub"<<endl;
		return true; 
	}
	else {
		cout<<"is not isRealSub"<<endl;
		return false; 
	}				
}   
void oppsDiffSet(int opps[],const int a[],const int b[]){
	int aTemp[max_len],bTemp[max_len];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));
	for(int i=0;i<max_len;i++){//筛选 
		aTemp[a[i]]++;
		bTemp[b[i]]++;
	}
	int diff_a_b[1000],diff_b_a[1000];
	memset(diff_a_b,0,sizeof(diff_a_b));
	memset(diff_b_a,0,sizeof(diff_b_a));
	for(int i=0;i<max_len;i++){
		if(aTemp[i]!=0&&bTemp[i]==0)
			diff_a_b[i]++;
		if(bTemp[i]!=0&&aTemp[i]==0)
			diff_b_a[i]++;
	}
	for(int i=0;i<max_len;i++){
		if(diff_a_b[i]!=0||diff_b_a[i]!=0)
			opps[opps_len++]=i;
	}
	fstream out("opps.txt",ios::out) ;
	for(int i=0;i<opps_len;i++){
		if(i%20==0&&i!=0)//every 20 num turn a row 
			out<<endl;
		out<<opps[i]<<" ";//输入文件opps.txt 
	}
	out.close();
	return ;
}
bool isEqual(const int a[],const int b[]){
	int aTemp[1000],bTemp[1000];
	memset(aTemp,0,sizeof(aTemp));
	memset(bTemp,0,sizeof(bTemp));
	for(int i=0;i<max_len;i++){
		aTemp[a[i]]++;
		bTemp[b[i]]++;
	}
	for(int i=0;i<max_len;i++){
		if(aTemp[i]!=bTemp[i]){
			cout<<"not equal"<<endl;
			return false;
		}
	}
	cout<<"equal"<<endl;
	return true;
}
