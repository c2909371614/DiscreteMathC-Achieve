#ifndef MAINHEAD
#define MAINHEAD 
#include<bits/stdc++.h>
using namespace std;
class openFile{//���ļ���class 
private:
public:
    fstream io;
    openFile(string filename){
        io.open(filename.c_str(),ios::in|ios::app);
    }
    ~openFile(){
        io.close();
    }
};
string binRela(string s1,string s2); 
string binRela(string s1,string s2,bool flag);
string getA_B();//�����A��B�Ķ�Ԫ��ϵ�Ľ��
string getA_A(); //A�ϵĶ�Ԫ��ϵ��ȫ�� 
string get_Ia();//��ȼ� 
string get_La();//С�ڻ���� 
template <typename T>
bool La_flag(T a,T b);
string get_BigerA();//���� 
template <typename T>
bool BigerA_flag(T a,T b);
string get_Db();//������ϵ 
bool Db_flag(int a,int b);
string get_Ra();//������ϵ 
int mySub(string,string*);
string get_inverse_R(); //���ϵ 
int myFind(string s);
void myNoSame(string&);
string domR();// ������ 
string ranR(); //ֵ�� 
string fldR(); //�� 
#endif



