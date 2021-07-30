/*Μέλη Ομάδας: Χατζηβασίλη Νίκη, 321/2016215
               Ζωγραφίδου Δέσποινα, 321/2016041 */

#include <stdio.h>

//sunarthsh anazhthshs sumboloseiras
int brute_force(char *f, int N, char *k, int M){
    //*f: protupo keimeno
    //N: megethos tou protupou keimenou
    //*k: protupo pou psaxnw
    //M: megethos tou protupou

    int i,j;

    //epanalhpsh apo 0 mexri N-M(to protupo pou psaxnw na xwraei sto arxiko keimeno)
    for(i=0; i<N-M; i++){
        j=0; //arxikopoihsh

        //j<M: o metrhths j na mhn jepernaei to megethos tou protupou pou psaxnw
        //f[i+j]==k[j]: diathrhsh i(thesh sto keimeno), se periptwsh pou to gramma ths lejhs einai idio me to gramma tou keimenou
        while(j<M && f[i+j]==k[j])
              j++; //aujhsh kata 1 kathe fora sth lejh

        //periptwsh pou h lejh exei teleiswsei
        if (j == M)
            return i; //epistrefei thn thesh tou prwtou grammatos ths lejhs sto keimeno
    }
    //periptesh pou den uparxei
    return -1;
}


int main(){

    char *phrase = "THE DATA AND THEIR STRUCTURES!"; //protupo keimeno
    char *key = "THEIR"; //protupo1
    char *key2 = "DATABASE"; //protupo2

    int N, M;
    int i = 0;
    int search;

    //brhskw megethos protupou keimenou
    while(phrase[i]!='\0'){
        i++;
    }

    N = i; //arxikopoihsh protupou keimenou
    i = 0;

    //brhskw megethos protuphs lejhs
    while(key[i]!='\0'){
        i++;
    }

    M = i; //arxikopoihsh protuphs lejhs

    search = brute_force(phrase, N, key, M); //kalesma brute force

    if(search == -1){
        printf("The keyword  %s  doesn't exist!\n", key);
    }
    else{
        printf("Position of keyword  %s  is: %d\n", key, search); //emfanhsh theshs tou prwtou grammatos
    }

    N = i;
    i = 0;

    while(key2[i]!='\0'){
        i++;
    }

    M = i;

    search = brute_force(phrase, N, key2, M);

    if(search == -1){
        printf("The keyword  %s  doesn't exist!\n", key2);

    }
    else{
        printf("Position of keyword  %s  is: %d\n", key2, search);
    }
}
