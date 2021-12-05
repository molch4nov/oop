#include "Long.h"
#include <bits/stdc++.h>
using namespace std;
Long::Long(){
    first = 0;
    second = 0;
    cout << "Default has been created" << endl;
}

Long::Long(unsigned long long x, unsigned long long y){
    first = x;
    second = y;
}

void Long::add(Long x, Long y){
    first  = x.first + y.first;
    second = x.second + y.second;
    if(second > 4294967295){
        first += 1;
        second = second - 999999999 + 1;
    }
}

void Long::diff(Long x, Long y){
    if(x.first > y.first && x.second > y.second){
        first = x.first - y.first;
        second = x.second - y.second;
    }
    else if(x.first > y.first && x.second < y.second){
        string str1 = to_string(y.second);
        int cnt = 0;
        for(int i = 0; i < str1.size(); i++){
            cnt += 1;
        }
        int sec = y.second - x.second;
        int ans = 10 * cnt - sec;
        first = x.first - y.first - 1;
        second = ans;
    }
    else if(x.first < y.first && x.second > y.second){
        diff(y, x);
    }
    else if(x.first < y.first && x.second < y.second){
        first = y.first - x.first;
        second = y.second - x.second;
    }
}

void Long::mov(Long x, Long y){
    string strx1 = to_string(x.first);
    string strx2 = to_string(x.second);
    string x_ = strx1 + strx2;

    string stry1 = to_string(y.first);
    string stry2 = to_string(y.second);
    string y_ = stry1 + stry2;

    long long p = stoll(x_);
    long long q = stoll(y_);
    long long r = p * q;

    string ans = to_string(r);
    int h = ans.size() / 2 + 1;
    char f[h - 1];
    char s[h];
    for(int i = 0; i < h; i++){
        if(h > 1){
        f[i] = ans[i];
        s[i] = ans[h + i];
        }
        else{
            f[i] = 0;
            s[i] = ans[i];
        }
    }
    first = atoi(f);
    second = atoi(s);


} 

void Long::sub(Long x, Long y){
    string strx1 = to_string(x.first);
    string strx2 = to_string(x.second);
    string x_ = strx1 + strx2;

    string stry1 = to_string(y.first);
    string stry2 = to_string(y.second);
    string y_ = stry1 + stry2;

    long long p = stoll(x_);
    long long q = stoll(y_);
    long long r = p / q;

    string ans = to_string(r);
    int h = ans.size() / 2;
    char f[h];
    char s[h+1];
    for(int i = 0; i <= h; i++){
        if(h > 1){
        f[i] = ans[i];
        s[i] = ans[h - i];
        }
        else{
            f[i] = 0;
            s[i] = ans[i];
        }
    }
    first = atoi(f);
    second = atoi(s);

}

void Long::Display(){
    cout << toString() << endl;
}

string Long::toString(){ // Первод в строку
    string str1 = to_string(first);
    string str2 = to_string(second);
    string str = str1 + str2;
    return str;
}

bool operator> (Long& x, Long& y){
    if(x.first > y.first){
        return true;
    }
    else{
        return false;
    }
}

bool operator< (Long& x, Long& y){
    if(x.first > y.first){
        return false;
    }
    else{
        return true;
    }
}

bool operator== (Long& x, Long& y){
    if(x.first == y.first && x.second == y.second){
        return true ;
    }
    else{
        return false;
    }
}

bool operator!= (Long& x, Long& y){
    if(x.first == y.first && x.second == y.second){
        return false;
    }
    else{
        return true;
    }
}