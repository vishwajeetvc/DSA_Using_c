#include<stdio.h>

void sum(int a , int b){
    printf("%d", a+b);
}
void sub(int a , int b){
    printf("%d", a-b);
}
            // function pointers
void display(void (*ptr)(int,int)){
    ptr(5,5);
}

int main(){

    // function pointer 
    void(*ptrAdd)(int,int) = sum;

    ptrAdd(2,3); // called using pointer



    // display(sum);
    // display(sub);

}


