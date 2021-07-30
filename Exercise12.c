//Despina Zografidou, 321/2016041

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function for Serial Search
void serial_search(int A[], int N, int key){

    int i;
    int flag = 0; //variable to control the searching

  //searce for the key 
    for(i=0; i<N; i++){
        //if there is an integer that is equal with the key print the following and continue
        if(A[i] == key){
            printf("Position of number: %d\n", i); 
            printf("Comparisons: %d\n", i+1); 
            flag = 1;
        }
    }
    //if there is not any integer that is equal with the key then print the following
    if(flag == 0){
            printf("The element doesn't exist!\n");
            printf("Comparisons: %d\n", i);
        }
}

//Function for Binary Search
int binary_search(int A[], int N, int key, int *comparison){
    *comparison = 0; //variable to count the comparisons

    int left = 0;
    int right = N-1;
    int middle;

    while (left <= right){
        *comparison = *comparison + 1; //add +1 to comparison

        middle = (left+right) / 2; //keep the middle element(integer) 
        
      //if the key is equal to the middle then return the middle
        if(A[middle] == key){ 
            return middle;
         }
      //if the key is smaller than the middle then set the variable right the middle-1 
        else if(A[middle] > key){
            right = middle - 1; 
        }
      //if the key is bigger than the middle then set the variable left the middle+1 
        else{
            left = middle + 1; //proxwraei dejia ston pinaka
        }
     }
     //if there is not an integer that is equal with the key 
     return -1;
}

int main(){

    int choice;
    int N, i, r;
    int *A;
    int search1, search2;
    int comp; 

    //menou
    printf("Please press one of the options below.\n");
    printf("1. Serial search (sorted numbers)\n");
    printf("2. Binary search (without recursive procedure)\n");
    printf("Choice: ");

    scanf("%d", &choice);

    if(choice == 1 || choice == 2){

        printf("Insert the size of table: ");
        scanf("%d", &N);

        A = (int*) malloc (N * sizeof(int)); //commit the memory of the pointer 

        srand(time(NULL)); 

      //set the first element in the table
        A[0] = 1 + rand()%4; 
        printf("\nTable: %d ", A[0]); 
        
      //fill the table with the random elements
        for(i=1; i<N; i++){
            A[i] = A[i-1] + 1 + rand()%4; 
            printf("%d ", A[i]); 
        }

        r = rand() % N+1; //keep a random integer as a key
        printf("\nSelected number: %d \n", r);
  
      //if the user select the serial search
        if(choice == 1){
            serial_search(A, N, r); 
        }
      //if the user select the binary search
        else if(choice == 2){
            search2 = binary_search(A, N, r, &comp); 
            //if there is not an integer that is equal with the key
            if(search2 == -1){ 
                printf("The element doesn't exist!\n");
                printf("Comparisons: %d\n", comp+1);
            }
          //if there is at least one integer that is equal with the key
            else{
                printf("Position of number: %d\n", search2); 
                printf("Comparisons: %d\n", comp); 
            }
        }
    }
    //if the user don't choose a valid choise
    else{
        printf("Error!");
        return -1; //epistrefei -1
    }

}
