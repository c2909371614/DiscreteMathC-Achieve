#ifndef HEAD
#define HEAD
#include<iostream>  
#include<cstdio>  
#include<stack>  
#include<queue>  
#include<cstring>
#include<string>
#include<cstdlib>
#include<fstream>
#define N 200
using namespace std;
 
 
 
int Degree(char c);                // ����ʽ�����ȼ�  
bool Calc(char c);               // �߼����ʽ����ת��
string MidToPost(string c);      // ����ʽ��Ӧ�ĺ�׺���ʽ
char GetValuePost(string c);
bool conditionalS(bool a,bool b);
bool Equal(bool a,bool b);
void Count(string);


#endif
