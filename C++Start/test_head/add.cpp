//
// Created by lovo on 2021/11/16.
//

#include "add.h"
int add(int a, int b)
{
    cout << "add()..." << endl;
    return a + b;
}

// #include <iostream>

// using namespace std;

// class Person
// {
// public:
//     Person()
//     {
//     }
//     Person(int a, int b) : m_A(a), m_B(b)
//     {
//     }
//     Person operator+(Person& p){
//         Person temp;
//         temp.m_A = this->m_A + p.m_A;
//         temp.m_B = this->m_B + p.m_B;
//         return temp;
//     }
// public:
//     int m_A;
//     int m_B;
// };

// int main()
// {
//     Person p1(10, 10);
//     Person p2(20, 20);
//     Person p3 = p1 + p2;
//     cout << p3.m_A << " " << p3.m_B << endl;
//     return 0;
// }
