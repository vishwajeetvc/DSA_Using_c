#include <stdio.h>
void getArr(int *arr, int size){
    printf("Enter the element of the array : \n");
    for(int i = 0; i < size; i++){
        scanf("\t%d", arr+i);
    }
    printf("\n");
}
void printArr(int *arr,int size){
    printf("Your array is : ");
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");

}
int delInArr(int pos,int *arr, int *size){
    for(int i = pos-1; i < *size-1; i++){
        *(arr+i) = *(arr+i+1);
    }
    *size -=1 ;
    return *(arr+pos-1); 
}
int main(){

    int arr[100];
    int size;

    printf("Enter the size of the array : ");
    scanf("%d", &size);

    getArr(arr, size);
    printArr(arr,size);


    int pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    int deleted = delInArr(pos,arr, &size);
    printf("%d", deleted);

    printf("New: ");
    printArr(arr,size);

}

