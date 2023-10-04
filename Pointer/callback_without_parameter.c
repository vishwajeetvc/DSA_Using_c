/*
   =====================
     Vishwajeeet kumar
   =====================
*/
#include<stdio.h>

void miss(){
    printf("Miss You");
}
void hate(){
    printf("Hate You");
}
void desire(void (*ptrMiss)(), void(*ptrHate)()){
    int code;
    printf("Enter you code: ");
    scanf("%d",&code);

    if(code == 143){
        ptrMiss();
    } else {
        ptrHate();
    }

}
int main(){

    desire(miss,hate);

}


