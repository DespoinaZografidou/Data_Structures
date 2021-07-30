/*Μέλη Ομάδας: Χατζηβασίλη Νίκη, 321/2016215
               Ζωγραφίδου Δέσποινα, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//sunarthsh seiriakhs anazhthshs
void serial_search(int A[], int N, int key){

    int i;
    int flag = 0; //metabliti gia ton elegxo eureshs arithmou

    for(i=0; i<N; i++){

        if(A[i] == key){
            printf("Position of number: %d\n", i); //emfanhsh thesis stoixeiou
            printf("Comparisons: %d\n", i+1); //emfanhsh sugkrisewn
            flag = 1;
        }
    }
    //periptwsh pou den uparxei to stoixeio
    if(flag == 0){
            printf("The element doesn't exist!\n");
            printf("Comparisons: %d\n", i);
        }
}

//sunarhsh duadikhs anazhthshs
int binary_search(int A[], int N, int key, int *comparison){
    *comparison = 0; //gia thn metrhsh sugkrisewn (arxikopoihsh me 0)

    int left = 0;
    int right = N-1;
    int middle;

    while (left <= right){
        *comparison = *comparison + 1; //aujhsh metrhth (gia tis sugkriseis)

        middle = (left+right) / 2; //mesaio stoixeio tou pinaka

        if(A[middle] == key){ //periptwsh pou vrei to stoixeio
            return middle;
         }
        else if(A[middle] > key){
            right = middle - 1; //proxwraei aristera ston pinaka
        }
        else{
            left = middle + 1; //proxwraei dejia ston pinaka
        }
     }
     //periptwsh pou den uparxei to stoixeio
     return -1;
}

int main(){

    int choice;
    int N, i, r;
    int *A;
    int search1, search2;
    int comp; //metablhth gia tis sugkriseis

    //menou
    printf("Please press one of the options below.\n");
    printf("1. Serial search (sorted numbers)\n");
    printf("2. Binary search (without recursive procedure)\n");
    printf("Choice: ");

    scanf("%d", &choice);

    if(choice == 1 || choice == 2){

        printf("Insert the size of table: ");
        scanf("%d", &N);

        A = (int*) malloc (N * sizeof(int)); //desmeush mnhmhs gia thesh pinaka

        srand(time(NULL)); //arxikopoihsh sunarthshs rand(paragwgh tuxaiwn arithmwn me bash ton xrono)

        A[0] = 1 + rand()%4; //dhlwsh prwtou stoixeiou ston pinaka
        printf("\nTable: %d ", A[0]); //ektupwsh prwtou stoixeiou

        for(i=1; i<N; i++){
            A[i] = A[i-1] + 1 + rand()%4; //gemisma pinaka me tuxaies times, apo thn thesh 1 mexri N
            printf("%d ", A[i]); //ektupwsh pinaka
        }

        r = rand() % N+1; //epilogh enos tuxaiou arithmou
        printf("\nSelected number: %d \n", r);

        if(choice == 1){
            serial_search(A, N, r); //kalesma seiriakhs sunartishs
        }
        else if(choice == 2){
            search2 = binary_search(A, N, r, &comp); //kalesma duadikhs sunartishs

            if(search2 == -1){ //periptwsh pou h synarthsh epistrepsei -1 (den brhke to stoixeio)
                printf("The element doesn't exist!\n");
                printf("Comparisons: %d\n", comp+1);
            }
            else{
                printf("Position of number: %d\n", search2); //emfanhsh thesis stoixeiou
                printf("Comparisons: %d\n", comp); //emfanhsh sugkrisewn
            }
        }
    }
    //periptwsh pou den epilejei apo to menu
    else{
        printf("Error!");
        return -1; //epistrefei -1
    }

}
