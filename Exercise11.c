/*Despina Zografidou, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//sunarthsh anazhthshs arithmou gia mia emfanisi
void search1(int *ar, int N, int key){

    int i;
    int flag = 0; //metabliti gia ton elegxo eureshs arithmou

    //epanalhpsh  mexri ton aritho pou dhlwse o xrhsths
    for(i=0; i<N; i++){

        if(ar[i] == key){
                printf("Position of number: %d\n", i); //emfanhsh thesis stoixeiou
                printf("Comparisons: %d\n", i+1); //emfanhsh sugkrisewn
                flag = 1;
                break; //diakopi for
        }
    }
    //periptwsh pou den uparxei to stoixeio
    if(flag == 0){
            printf("The element doesn't exist!\n");
            printf("Comparisons: %d\n", i); //tha exei sugkrinei ola ta stoixeia
        }
}

//sunarthsh anazhthshs arithmou gia pollaples emfaniseis
void search2(int *ar, int N, int key){

    int j;
    int flag = 0; //metabliti gia ton elegxo eureshs arithmou

    //epanalhpsh  mexri ton aritho pou dhlwse o xrhsths
    for(j=0; j<N; j++){

        if(ar[j] == key){
            printf("Position of number: %d\n", j); //emfanhsh thesis stoixeiou (pollaples emfaniseis)
            printf("Comparisons: %d\n", j+1); //emfanhsh sugkrisewn
            flag = 1;
        }
    }
    //periptwsh pou den uparxei to stoixeio
     if(flag == 0){
            printf("The element doesn't exist!\n");
            printf("Comparisons: %d\n", j);
        }
}

int main(){

    int choice; //dhlwsh metablhths gia thn epilogh menou
    int *ar; //dhlwsh deikth
    int N, key, r;
    int i;

    //menou
    printf("Please press one of the options below.\n");
    printf("1. Serial search (one appearance)\n");
    printf("2. Serial search (multiple appearances)\n");
    printf("Choice: ");

    scanf("%d", &choice);

    if(choice == 1 || choice == 2){
        printf("Insert the size of table: ");
        scanf("%d", &N); //eisagwgh thmhs gia to megethos pinaka

        ar = (int*) malloc (N * sizeof(int)); //desmeusi mnhmhs gia thesh pinaka

        srand(time(NULL)); //arxikopoihsh sunarthshs rand(paragwgh tuxaiwn arithmwn me bash ton xrono)

        printf("Table: ");

        for(i=0; i<N; i++){
            ar[i] = rand() % N+1; //gemisma pinaka me tuxaies times
            printf("%d ", ar[i]); //ektupwsh pinaka
        }

        key = rand() % N+1; //epilogh enos tuxaiou arithmou

        printf("\nSelected number: %d \n", key); //ektupwsh tuxaiou arithmou

        if(choice == 1){
            search1(ar, N, key); //kalesma sunartishs1
        }

        else if(choice == 2){
            search2(ar, N, key); //kalesma sunartishs2
        }
    }
    //periptwsh pou den epilejei apo to menu
    else{
        printf("Error!");
        return -1; //epistrefei -1
    }
}
