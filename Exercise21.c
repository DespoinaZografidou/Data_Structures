/*Μέλη Ομάδας: Χατζηβασίλη Νίκη, 321/2016215
               Ζωγραφίδου Δέσποινα, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//anadromhkh sunarthsh gia to athroisma pshfiwn
int recursion_sum(int N){

    if(N == 0) //periptwsh pou o arithmos einai 0
        return 0; //epistrefei 0
    else
        return (N%10 + recursion_sum(N/10));
        //xrhsimopoihsame to mod 10 gia na broume posa stoixeia exoume
        //sunthiki termatismou: otan N=0 (den exw alla stoixeia)
}

//anadromhkh sunarthsh gia ton elegxo tajinomhshs stoixeiwn se aujousa seira
//Xronikh Poluplokothta: O(1), den exw epanalipseis
int recursion_sort(int A[], int N, int i){

    //sunthiki termatismou: otan ftasei sto telos tou pinaka kai einai taksinomimenos
    if (i == 0)
        return 1;

    else if(A[i-1] > A[i]) //an to stoixeio ths prohgoumenhs thesh einai megalytero apo thn epomenh
        return 0;   //o pinakas den einai taksinomhmenos

    else
        return recursion_sort(A, N, i-1);  //alliws proxoraei stis prohgoymenes theseis
}

//sunarhsh duadikhs anazhthshs
int binary_search(int A[], int left, int right, int key)//diadikh anazhthsh se tajinomhmeno pinaka
{
    int mid;

    while (left <= right){

    mid = (left+right)/2; //mesaio stoixeio tou pinaka

    if (key == A[mid]) //periptwsh pou vrei to stoixeio
        return mid;

    else if (key > A[mid])
        return binary_search(A, mid+1, right, key);

    else
        return binary_search(A, left, mid-1, key);
    }
    //periptwsh pou den uparxei to stoixeio
    return -1;
}

int main(){
    int choice;

    //menou
    printf("Please press one of the options below. \n");
    printf("1. Recursion Function - add digits of a number \n");
    printf("2. Recursion Function - if numbers are sorted \n");
    printf("3. Recursion Binary Function \n");
    printf("Choice: ");

    scanf("%d", &choice);

    if(choice == 1 || choice == 2 || choice == 3){
//Askhsh 1
        if(choice == 1){
            int num;
            int function;

            printf("\nPlease insert an integer: ");
            scanf("%d", &num); //eisagei aritmo o xrhsths

            function = recursion_sum(num); //kalesma anadromhkhs sunartishs

            printf("Sum of digits: %d \n", function);
        }
//Askhsh 2
        else if(choice == 2){
            int *A;
            int N;
            int function1;

            printf("\nInsert the size of the array: ");
            scanf("%d",&N);

            A = (int*) malloc (N * sizeof(int)); //desmeush mnhmhs gia thesh pinaka

            //gemisma pinaka apo xrhsth
            for(int i=0; i<N; i++){
                printf("Insert the %d integer: ", i);
                scanf("%d", &A[i]);
            }

            printf("\nTable: ");

            //tupwnei pinaka
            for(int j=0; j<N; j++){
                printf("%d ", A[j]);
            }

            function1 = recursion_sort(A, N, N-1); //kalesma sunarthshs

            if(function1 == 1)
                printf("\nThe array is sorted.\n");
            else
                printf("\n\nThe array is not sorted!\n");
        }
//Askhsh 3
        else if(choice == 3){
            int A[]= {2,4,6,8,10,12,14,16,18};
            int key;
            int function2;

            printf("\nTable: ");

            //tupwnei pinaka
            for(int i=0; i<9; i++){
                printf("%d ",A[i]);
            }

            printf("\n\nInsert an integer to search in the array: ");
            scanf("%d", &key);

            function2 = binary_search(A, 0, 9, key); //kalesma sunarthshs

            if (function2 == -1)
                printf("This element does not exist!");

            else
                printf("The element is in the position %d!", function2);
        }
    }
    else{
        printf("Error!");
        return -1; //epistrefei -1
    }
}

