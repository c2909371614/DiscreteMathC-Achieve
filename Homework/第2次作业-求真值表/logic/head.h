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
 
 
 
int Degree(char c);                // 求表达式的优先级  
bool Calc(char c);               // 逻辑表达式数的转换
string MidToPost(string c);      // 求表达式对应的后缀表达式
char GetValuePost(string c);
bool conditionalS(bool a,bool b);
bool Equal(bool a,bool b);
void Count(string);


#endif
