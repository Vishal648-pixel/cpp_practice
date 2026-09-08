#include <iostream>
using namespace std;

int assignment_operator();
int comparision_operator();
int logical_operator();


int main() {//arithermatic operator
    // int a =28;
    // int b=38;
    // cout<<"addition :"<<a+b<<"\n";
    // cout<<"subtraction :"<<a-b<<"\n";
    // cout<<"multiplication :"<<a*b<<"\n";
    // cout<<"division :"<<a/b<<"\n";
    // comparision_operator();
    // assignment_operator();
    logical_operator();
    return 0;
}

// int assignment_operator() {
//     int x=38;
//     int y=43;
//     x+=y;
//     cout<<x<<"x=x+y";
//     return 0;
// }


// int comparision_operator() {
//     int f=24;
//     int g=93;
//     cout<<(g>f);//if g is greater than f then it will print 1 otherwise 0
//
//
//
//     int age=5;
//     cout<<(age>=18);
//     return 0;
// }

int logical_operator() {
    int v=3;
    int f=4;
    int g=5;
    cout<<(v<f && g!=f)<<"\n";//returns true(1) because v is less than f and g is not equals to f
    cout<<(v<f || g==f)<<"\n";//returns true because one codition is true
    cout<<(!(v<f && g!=f))<<"\n"; //returns false(O) because not operator reverses the result
    return 0;
}
