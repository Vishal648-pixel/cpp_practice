#include <iostream>
using namespace std;


// Order of Operations
// Operator precedence according to highest to lowest priority

// () - Parentheses
// *, /, % - Multiplication, Division, Modulus
// +, - - Addition, Subtraction
// >, <, >=, <= - Comparison
// ==, != - Equality
// && - Logical AND
// || - Logical OR
// = - Assignment

int main() {
    int result=(3+4)*2%10-4;
    cout<<"result :"<<result;
        return 0;
}