/*Despoina Zografidou, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//recursive function for sum of digits
int recursion_sum(int N){

    if(N == 0) //in case that the integer is equal with 0
        return 0; //return 0
    else
        return (N%10 + recursion_sum(N/10));
        
}


//recursive function to check if the table is sorted by ascending order
int recursion_sort(int A[], int N, int i){

    //if you checked all the elements in the table then return that the table is sorted
    if (i == 0)
        return 1;
  
    //if A[i-1] > A[i] then the table is not sorted
    else if(A[i-1] > A[i]) 
        return 0;   
    //else continue to the next element
    else
        return recursion_sort(A, N, i-1);  //alliws proxoraei stis prohgoymenes theseis
}

//recursive function for the Binary Search
int binary_search(int A[], int left, int right, int key)//diadikh anazhthsh se tajinomhmeno pinaka
{
    int mid;

    while (left <= right){

    mid = (left+right)/2; 
    
    //if there is an integer that is equal with the key then return the position  
    if (key == A[mid]) 
        return mid;
    
    //if the key is bigger than the A[mid]   
    else if (key > A[mid])
        return binary_search(A, mid+1, right, key);
    //if the key is smaller than the A[mid]  
    else
        return binary_search(A, left, mid-1, key);
    }
    //in case that there is not any element that is equal with the key
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

        if(choice == 1){
            int num;
            int function;

            printf("\nPlease insert an integer: ");
            scanf("%d", &num); 

            function = recursion_sum(num); 

            printf("Sum of digits: %d \n", function);
        }

        else if(choice == 2){
            int *A;
            int N;
            int function1;

            printf("\nInsert the size of the array: ");
            scanf("%d",&N);

            A = (int*) malloc (N * sizeof(int)); 
 
            for(int i=0; i<N; i++){
                printf("Insert the %d integer: ", i);
                scanf("%d", &A[i]);
            }

            printf("\nTable: ");

            for(int j=0; j<N; j++){
                printf("%d ", A[j]);
            }

            function1 = recursion_sort(A, N, N-1); 

            if(function1 == 1)
                printf("\nThe array is sorted.\n");
            else
                printf("\n\nThe array is not sorted!\n");
        }

        else if(choice == 3){
            int A[]= {2,4,6,8,10,12,14,16,18};
            int key;
            int function2;

            printf("\nTable: ");

           
            for(int i=0; i<9; i++){
                printf("%d ",A[i]);
            }

            printf("\n\nInsert an integer to search in the array: ");
            scanf("%d", &key);

            function2 = binary_search(A, 0, 9, key); 

            if (function2 == -1)
                printf("This element does not exist!");

            else
                printf("The element is in the position %d!", function2);
        }
    }
    else{
        printf("Error!");
        return -1; 
    }
}

