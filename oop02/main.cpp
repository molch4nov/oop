#include "Long.h"

//literals
//В беззнаковой арифметике unsigned int в пределах от 
//0 до 4294967295
//Например, мы вычитали из числа 2 число 3
//и у нас вышло 4294967294, но так как по заданию
//у нас беззнаковый тип, то наше число будет равно |2-3| = 1
unsigned long long operator "" _tonormal(unsigned long long x){
    unsigned long long ans = 4294967295 - x;
    return ans;
}


int main(){
    Long a(cin);
    Long b(cin);
    Long c(0,0);
    if(a != b){
        cout << "Success" << endl;
    }
    else{
        cout << "Fail0 << endl";
    }
    cout << 4294967294_tonormal << endl;
}