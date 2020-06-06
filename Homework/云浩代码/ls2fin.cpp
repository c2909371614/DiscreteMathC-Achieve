#include<bits/stdc++.h>
#define N 105
using namespace std;  
void work(char a[],int l1);//执行 
int getnumber(char a[],int l);//获取变量的个数
char calculate(char a[],int l);//计算逻辑表达式的值
int pri(char ch);//判断符号的优先级
char c[26];//用来记录表达式中变量的个数以及变量的名称
int main()
{		
	  FILE *fp;
	  fp=fopen("D://test.txt","r");	
      char ans1[N],ans2[N];
      int l1;//两个表达式的长度
      while(~fscanf(fp,"%s",ans1))
      {
      		cout<<endl<<ans1<<endl;
            l1=strlen(ans1);
            work(ans1,l1);
      }
}
void work(char a[],int l1)
{
      int i,j;
      char zhi1;
      char ctemp[26];//分别位a,b,c的临时数组
      char atemp[N];
      int x=0;//a,b表达式中的变量个数
      int n;//所有取值的种数
      int tempn,max1;
      char list[26];//变量取值表
      x=getnumber(a,l1);
      n=1<<x;//n=2^x 
      for(i=0;i<26;i++){
      	if(c[i] != '0') printf("%c    ",i+'a');
	  }
	  cout<<endl;
      while(n)//遍历所有情况 
      {
            getnumber(a,l1);
            strcpy(ctemp,c);
            strcpy(atemp,a);
       
            tempn=n;
       		
            for(i=x;i>=0;i--)//Max1位变量取值表
            {           
                  list[i]=tempn%2+'0';
                  tempn/=2;
             
            }
            j=1;
            for(i=0;i<26;i++)//按照二进制减法存储 
            {
                  if(ctemp[i]!='0')
                  {
                       ctemp[i]=list[j++];
                       cout<<ctemp[i]<<"    ";
                  }
            }
            for(i=0;i<l1;i++)//将a表达式中的变量换为对应的值
            {
                  if(atemp[i]>='a'&&atemp[i]<='z'){
                  	atemp[i]=ctemp[atemp[i]-'a'];
				  }

            }
            zhi1=calculate(atemp,l1);//计算结果
            cout<<zhi1<<endl;
            n--;
      }
       
}
int getnumber(char a[],int l)
{
       
      int number=0;//变量的个数
      int i;
      memset(c,'0',sizeof(c));
      for(i=0;i<l;i++)
      {
            if(a[i]>='a'&&a[i]<='z')
            {
                  c[a[i]-'a']+=1;
            }
      }
      for(i=0;i<26;i++)
      {
            if(c[i]!='0')
            {
                  number++;
            }
      }
      return number;
}
char calculate(char a[],int l)
{
		stack<char> st;
      int i;
      int top=0;
      int j=0;
      char stack[N];
      //利用栈将中序式转为后序式
      char fin[N];//转换后的后序式
      char result[N];//用来保存结果的栈
      char ch;
      fin[0]='#';
      for(i=0;i<=l;i++)
      {
            switch(a[i])
            {
                  case '\0':
                  //cout<<1<<endl;	
                  while(!st.empty())
                  {
                      fin[++j]=st.top();	
                      st.pop();
                      
                  }
                  break;
                   
                  case '(':
                 // cout<<2<<endl;
                  st.push(a[i]);
                  break;
                  
                  case '=': 
                  case '|':       
                  case '^':
                  case '&':
                  case '~':{
                  	if(!st.empty()){
                  	//	cout<<st.top()<<endl;
                  		while(pri(st.top())>pri(a[i]))
                    	{
                      	fin[++j]=st.top();
                      	st.pop();
                    	}
					  }
                  		
                    //cout<<1<<endl;	
                    st.push(a[i]);	
					break;
				  }
                  
                   
                  case ')':
                  //	cout<<4<<endl;
                  while(st.top()!='(')
                  {
                       fin[++j]=st.top();
                       st.pop();
                  }
                  st.pop();
                  break;
                   
                  default:
                  fin[++j]=a[i];
                  break;
            }
      }
      fin[++j]='\0';
      top=0;
      for(i=1;i<j;i++)
      {
            if(fin[i]=='0'||fin[i]=='1')
            {
                  result[top++]=fin[i];
            }
            else
            {
                  switch(fin[i])
                  {
                       case '~':
                       ch=result[--top];
                   	   result[top]=(ch=='1')?'0':'1';
                       top++;
                       break;
                       case '&':
                       	ch=result[--top];   
						result[top-1]=(ch=='1'&&result[top-1]=='1')?'1':'0';
                       break;
                       case '|':
                       	ch=result[--top];
					   	result[top-1]=(ch=='1'||result[top-1]=='1')?'1':'0';
                       break;
                        
                       case '^':
                       	ch=result[--top];   
					   	result[top-1]=(ch=='1' && result[top-1]=='0')? '0':'1';
                       break;
                       case '=':
                       	ch=result[--top];
                       	result[top-1]=(ch==result[top-1]) ? '1' : '0';
                       break;	
                       default:
                       printf("error\n");
                       break;
                  }
            }
      }
  
      return result[0];
}
int pri(char ch)
{
      int num;
      switch(ch)
      {
      		case '=':
      		num=1;
            case '~':
            num=5;
            break;
            case '&':
            num=4;
            break;
            case '^':
            num=2;
            break;
            case '|':
            num=3;
            break;
            default:
            num=0;
            break;
      }
      return num;
}

