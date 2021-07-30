/*Despina Zografidou, 321/2016041 */

#include <stdio.h>

//Brute Force Search for a string
int brute_force(char *f, int N, char *k, int M){
    //*f: the protype string
    //N: the lenght of the protype string
    //*k: the key string
    //M: the lenght of the key string

    int i,j;

    //loop from 0 to N-M (M is always smaller than N )
    for(i=0; i<N-M; i++){
        j=0; 

        //j<M: the counter j must be alway be smaller than the length of the key string 
        //f[i+j]==k[j]: save i(positio on the string), in case that the letter of the key word is the same the letter of the protype word
        while(j<M && f[i+j]==k[j])
              j++; //move to the next letter

        //in case tha comprarisons of every letter of the key word are finished
        if (j == M)
            return i; //return from the first letter of key word
    }
    //if there is not the key word in the protype string
    return -1;
}


int main(){

    char *phrase = "THE DATA AND THEIR STRUCTURES!"; //protype string
    char *key = "THEIR"; //key word-string 1
    char *key2 = "DATABASE"; //key word-string 2

    int N, M;
    int i = 0;
    int search;

    //keep the length of the protype string
    while(phrase[i]!='\0'){
        i++;
    }

    N = i; //save the length of the protype string
    i = 0;

    //keep the length of the key string 1
    while(key[i]!='\0'){
        i++;
    }

    M = i; //save the length of the key string 1

    search = brute_force(phrase, N, key, M); 

    if(search == -1){
        printf("The keyword  %s  doesn't exist!\n", key);
    }
    else{
        printf("Position of keyword  %s  is: %d\n", key, search); 
    }

    N = i;
    i = 0;

   //keep the length of the key string 2
    while(key2[i]!='\0'){
        i++;
    }

    M = i; //save the length of the key string 2

    search = brute_force(phrase, N, key2, M);

    if(search == -1){
        printf("The keyword  %s  doesn't exist!\n", key2);

    }
    else{
        printf("Position of keyword  %s  is: %d\n", key2, search);
    }
}
