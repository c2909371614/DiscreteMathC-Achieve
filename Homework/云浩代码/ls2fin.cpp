#include<bits/stdc++.h>
#define N 105
using namespace std;  
void work(char a[],int l1);//ִ�� 
int getnumber(char a[],int l);//��ȡ�����ĸ���
char calculate(char a[],int l);//�����߼����ʽ��ֵ
int pri(char ch);//�жϷ��ŵ����ȼ�
char c[26];//������¼���ʽ�б����ĸ����Լ�����������
int main()
{		
	  FILE *fp;
	  fp=fopen("D://test.txt","r");	
      char ans1[N],ans2[N];
      int l1;//�������ʽ�ĳ���
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
      char ctemp[26];//�ֱ�λa,b,c����ʱ����
      char atemp[N];
      int x=0;//a,b���ʽ�еı�������
      int n;//����ȡֵ������
      int tempn,max1;
      char list[26];//����ȡֵ��
      x=getnumber(a,l1);
      n=1<<x;//n=2^x 
      for(i=0;i<26;i++){
      	if(c[i] != '0') printf("%c    ",i+'a');
	  }
	  cout<<endl;
      while(n)//����������� 
      {
            getnumber(a,l1);
            strcpy(ctemp,c);
            strcpy(atemp,a);
       
            tempn=n;
       		
            for(i=x;i>=0;i--)//Max1λ����ȡֵ��
            {           
                  list[i]=tempn%2+'0';
                  tempn/=2;
             
            }
            j=1;
            for(i=0;i<26;i++)//���ն����Ƽ����洢 
            {
                  if(ctemp[i]!='0')
                  {
                       ctemp[i]=list[j++];
                       cout<<ctemp[i]<<"    ";
                  }
            }
            for(i=0;i<l1;i++)//��a���ʽ�еı�����Ϊ��Ӧ��ֵ
            {
                  if(atemp[i]>='a'&&atemp[i]<='z'){
                  	atemp[i]=ctemp[atemp[i]-'a'];
				  }

            }
            zhi1=calculate(atemp,l1);//������
            cout<<zhi1<<endl;
            n--;
      }
       
}
int getnumber(char a[],int l)
{
       
      int number=0;//�����ĸ���
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
      //����ջ������ʽתΪ����ʽ
      char fin[N];//ת����ĺ���ʽ
      char result[N];//������������ջ
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

