#include<stdio.h>

void getArr(int *arr, int size);
void printArr(int *arr,int size);
void insInArr(int elm, int pos, int *arr, int *size);

int main(){

    int arr[100];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    getArr(arr, size);
    printf("Your array : ");
    printArr(arr,size);

    int elm;
    int pos;

    printf("\nEnter the element: ");
    scanf("%d", &elm);
    printf("\nEnter the pos: ");
    scanf("%d", &pos);

    insInArr(elm,pos, arr, &size);

    printf("Your array : ");
    printArr(arr,size);
}
void getArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        scanf("%d", arr+i);
    }
}
void printArr(int *arr,int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr+i));
    }

}
void insInArr(int elm, int pos, int *arr, int *size){
    for(int i = *size; i > pos-1; i--){
        *(arr+i) = *(arr+i-1);
    }
    arr[pos-1] = elm;
    *size+=1;
}
