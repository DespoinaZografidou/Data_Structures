 /*Μέλη Ομάδας: Χατζηβασίλη Νίκη, 321/2016215
                Ζωγραφίδου Δέσποινα, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 //stathera - megethos pinaka table

//sunarthsh dhmiourgias megistou swrou apo ton pinaka, opou
//heap: pinakas swrou
//hs: heap size - megethos heap
void create_heap(int heap[], int hs){
    int i;

    for(i=hs/2; i>=0; i--)
        fix_heap(heap, i, hs); //kalesma sunarthshs fix_heap()
}

//sunarthsh dhmiourgias megistou swrou apo ton pinaka
int fix_heap(int heap[], int i, int hs){
    int largest, left, right;

    largest = i; //arxikopoihsh megaluterou kombou (pateras - root) me i
    left = 2 * i;
    right = 2 * i + 1;

//periptwseis gia na brw ton megalutero
    //periptwsh pou to left stoixeio einai megalutero apo ton patera
    if(left<hs && heap[left]>heap[largest])
        largest = left;

    //periptwsh pou to right stoixeio einai megalutero apo ton patera
    if(right<hs && heap[right]>heap[largest])
        largest = right;

    //periptwsh pou o megaluteros kombos den einai o pateras
    if(largest != i){
        int temp;

        //enallagh twn stoixeiwn heap[i] kai heap[largest]
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        fix_heap(heap, largest, hs); //kalesma sunarthshs fix_heap()
    }
}

//sunarthsh gia thn prosthhkh neou stoixeiou key sto swro, opou
//heap: pinakas swrou
//key: stoixeio pros eisagwgh
//hs: heap size - megethos heap
void insert_heap(int heap[], int key, int hs){
    int i, parent;

    hs = hs + 1;//aujhsh megethous heap kata 1
    i = hs;
    heap[i] = key; //eisagwgh tou neou akeraiou sto telos tou swrou
    parent = i / 2;

    while(i>1 && heap[parent]>heap[i]){
        int temp;

        //enallagh twn stoixeiwn heap[i] kai heap[parent]
        temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;

        i = parent;
        parent = parent / 2;
    }
}

//sunarthsh gia thn emfanish pinaka swrou, opou
//heap: pinakas swrou
//hs: heap size - megethos heap
void display_heap(int heap[], int hs){
    int i;

    if(hs == 0)
        printf("\nHeap is empty!\n");
    else{
        printf("Heap: ");

        for(i=0; i<hs; i++)
            printf("%d ", heap[i]); //ektupwsh swrou
    }
}

//sunaerthsh gia thn tajinomhsh kai emfanish tou tajinomhmenou pinaka, opou
//heap: pinakas swrou
//hs: heap size - megethos heap
void sort_heap(int heap[], int hs){
     int i;

     create_heap(heap, N); //kalesma sunarthshs create_heap()

     hs = N;

     for(i=hs/2; i>=0; i--){
        int temp;

        //enallagh twn stoixeiwn heap[i] kai heap[1]
        temp = heap[i];
        heap[i] = heap[1];
        heap[1] = temp;

        hs--;

        fix_heap(heap, 1, hs); //kalesma sunarthshs fix_heap()
     }
}

int main(){
    int choice;
    int table[N];
    int num;

    //epanalhpsh gia thn sunexh emfanish tou menou
    while(1){
        //menou
        printf("Please press one of the options below.\n");
        printf("1. Create a table of random integers\n");
        printf("2. Create a heap from the table\n");
        printf("3. Insert an integer in the heap\n");
        printf("4. Display table of heap\n");
        printf("5. Sort and Display of sorted table\n");
        printf("6. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

//dhmiourgia pinaka
        if(choice == 1){
            srand(time(NULL)); //arxikopoihsh sunarthshs rand(paragwgh tuxaiwn arithmwn me bash ton xrono)

            printf("Table: ");

            for(int i=0; i<N; i++)
            {
                table[i] = 1 + (rand() % 100); //gemisma pinaka me tuxaies times apo 1 ews 100
                printf("%d ", table[i]); //ektupwsh pinaka
            }
            printf("\n\n");
            //create_table();
        }
        else if(choice == 2){
            create_heap(table, N);
            display_heap(table, N);

            printf("\n\n");
        }
        else if(choice == 3){
            printf("\nInsert an integer: ");
            scanf("%d", &num);

            insert_heap(table, num, N);
            display_heap(table, N);

            printf("\n\n");
        }
        else if(choice == 4){
            display_heap(table, N);
            printf("\n\n");
        }
        else if(choice == 5){
            sort_heap(table, N);
            display_heap(table, N);
            printf("\n\n");
        }
        else if(choice == 6){
            printf("Exit...");
            return printf("\n\n");0; //ejodos
        }
        //periptwsh pou den epilejei o xrhsths apo to menou
        else
            printf("\nWrong choice!");
    }
}
