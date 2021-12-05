#include "Long.h"

int main(){
    Long a(cin);
    Long b(cin);
    Long c(0,0);
    if(a != b){
        cout << "Success";
    }
    else{
        cout << "Fail";
    }
}