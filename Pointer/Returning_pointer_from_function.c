/*
   =====================
     Vishwajeeet kumar
   =====================
*/
#include<stdio.h>

int *choise (int *ptr){
    return ptr+1;
}
int main(){

    int arr[10] = {1,2,3,4,5};
    printf("%d",*choise(arr));

}


