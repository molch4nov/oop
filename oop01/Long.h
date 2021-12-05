#ifndef LONG_H
#define LONG_H
#include <iostream>
using namespace std;
class Long {
    public:
        Long();
        Long(unsigned long long x, unsigned long long y);
        Long(istream &is);
        void Display();
        string toString();
        friend bool operator>(Long& x, Long& y);
        friend bool operator<(Long& x, Long& y);
        friend bool operator==(Long& x, Long& y);
        friend bool operator!=(Long& x, Long& y);
        friend istream& operator>>(istream& is, Long& a);


        void add(Long a, Long b);
        void diff(Long a, Long b);
        void mov(Long a, Long b);
        void sub(Long a, Long b);
       // ~Long();
    private:
        unsigned int first;
        unsigned int second;

};
#endif