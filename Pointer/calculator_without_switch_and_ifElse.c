/*
   =====================
     Vishwajeeet kumar
   =====================
*/
#include<stdio.h>
void add(float a, float b){printf("%f", (a+b));}
void sub(float a, float b){printf("%f", (a-b));}
void mul(float a, float b){printf("%f", (a*b));}
void div(float a, float b){printf("%f", (a/b));}
int main(){
    int a,b,choise;
    // array of function pointers
    void (*ptr[6])(float, float) = {add,sub,mul,div};
    // void (*ptr[6])(float, float) = {&add,&sub,&mul,&div}; /// also valid

    printf("Enter you numbers (seperated by comma) : ");
    scanf("%d,%d", &a, &b);

    printf("Enter you choise  1.Add 2.Sub 3.Mul 4.Div : ");
    scanf("%d", &choise);

    choise--;
    // calculation;
    ptr[choise](a,b);
}


