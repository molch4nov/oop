#include "Long.h"

int main(){
    Long a(7,3);
    Long b(1,1);
    Long c(0,0);
    if(a != b){
        cout << "Success";
    }
    else{
        cout << "Fail";
    }
}