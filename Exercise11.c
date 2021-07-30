/*Despina Zografidou, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function for serial search for a integer that is equal with a key 
void search1(int *ar, int N, int key){

    int i;
    int flag = 0; //variable to control the search 

    //loop to searche every integer in the pointer 
    for(i=0; i<N; i++){
        //if there is a integer that is equal to the key then print the following and break;
        if(ar[i] == key){
                printf("Position of number: %d\n", i); 
                printf("Comparisons: %d\n", i+1);
                flag = 1;
                break; 
        }
    }
    //if there is not an integer that is equal to the key then print the following
    if(flag == 0){
            printf("The element doesn't exist!\n");
            printf("Comparisons: %d\n", i); 
        }
}

//Function for serial search for all the integers that are equal with a key 
void search2(int *ar, int N, int key){

    int j;
    int flag = 0; //variable to control the search 

    //loop to searche every integer in the pointer 
    for(j=0; j<N; j++){
        //if there is a integer that is equal to the key then print the following and continue
        if(ar[j] == key){
            printf("Position of number: %d\n", j); 
            printf("Comparisons: %d\n", j+1); 
            flag = 1;
        }
    }
    //if there is not any integer that is equal with the key then print the following
     if(flag == 0){
            printf("The element doesn't exist!\n");
            printf("Comparisons: %d\n", j);
        }
}

int main(){

    int choice; //variable that save the choise of the user
    int *ar; 
    int N, key, r;//N=size of the table,Key= the key-integer for the searchign
    int i;

    //menu-choices for the user 
    printf("Please press one of the options below.\n");
    printf("1. Serial search (one appearance)\n");
    printf("2. Serial search (multiple appearances)\n");
    printf("Choice: ");

    scanf("%d", &choice);

    //if the user choose the options 1 or 2 
    if(choice == 1 || choice == 2){
        
        //take the size of the table from the user
        printf("Insert the size of table: ");
        scanf("%d", &N); 

        
        ar = (int*) malloc (N * sizeof(int)); //commit memory 

        srand(time(NULL)); //prepare the rand for random integers

        printf("Table: ");
        //fill the table with random integers and print them one by one
        for(i=0; i<N; i++){
            ar[i] = rand() % N+1; 
            printf("%d ", ar[i]); 
        }

        key = rand() % N+1; //keep a random number as a key

        printf("\nSelected number: %d \n", key); //print the key

        //if the user choose the choice 1
        if(choice == 1){
            search1(ar, N, key); 
        }
        //if the user choose the choice 2
        else if(choice == 2){
            search2(ar, N, key); 
        }
    }
    //if the user doesn't choose the choices 1 or 2 
    else{
        printf("Error!");
        return -1; //epistrefei -1
    }
}
