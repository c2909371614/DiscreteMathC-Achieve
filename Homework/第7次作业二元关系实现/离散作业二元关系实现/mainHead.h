#ifndef MAINHEAD
#define MAINHEAD 
#include<bits/stdc++.h>
using namespace std;
class openFile{//打开文件的class 
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
string getA_B();//计算从A到B的二元关系的结果
string getA_A(); //A上的二元关系的全集 
string get_Ia();//恒等集 
string get_La();//小于或等于 
template <typename T>
bool La_flag(T a,T b);
string get_BigerA();//大于 
template <typename T>
bool BigerA_flag(T a,T b);
string get_Db();//整除关系 
bool Db_flag(int a,int b);
string get_Ra();//包含关系 
int mySub(string,string*);
string get_inverse_R(); //逆关系 
int myFind(string s);
void myNoSame(string&);
string domR();// 定义域 
string ranR(); //值域 
string fldR(); //域 
#endif



