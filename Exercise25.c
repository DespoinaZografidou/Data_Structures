/*Μέλη Ομάδας: Χατζηβασίλη Νίκη, 321/2016215
               Ζωγραφίδου Δέσποινα, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>

//orizw ena parapanw stoixeio apo ekeina pou xreiazomai giati to prwto stoixeio einai to keno
#define N 5

//dhlwsh ouras
struct Queue{
    int data[N];
    int front;
    int rear;
};

//sunarthsh gia thn arxikopoihsh ths ouras
void initQueue(struct Queue* q){
    q->front = 0;
    q->rear = 0;
}

//sunarthsh pou elegxei an h oura einai gemath
int isFull(struct Queue* q){
    //otan to rear brisketai pisw apo to front exei gemisei h oura
    //xrhsimopoiw to %N gia na brw thn thesh
    if((q->rear+1)%N == q->front)
        return 1;
    else
        return 0;
}

//sunarthsh pou elegxei an h oura einai adeia
int isEmpty(struct Queue* q){
    //to rear kai to front deixnoun sto idio shmeio
    if(q->rear == q->front)
        return 1;
    else
        return 0;
}

//sunarthsh gia thn eisagwgh sthn oura
//opou k to stoixeio pou eisagw
void Enqueue(struct Queue* q, int k){
    q->rear = (q->rear+1)%N;
    q->data[q->rear] = k; //eisagwgh stoixeiou k ston pinaka data sth thesh rear
}

//sunarthsh gia thn diagrafh apo thn oura
int Dequeue(struct Queue* q){
    q->front = (q->front+1)%N;
    return q->data[q->front];
}

int main(){
    struct Queue A; //dhlwsh ouras
    int customer_inQueue = 1; //dhlwsh kai arxikopoihsh pelath apo to 1
    int tameio[] = {0, 0, 0, 0}; //dhlwsh kai arxikopoihsh tou arithmou twn tameiwn
    int function1;
    int choice;

    initQueue(&A); //ektelesh sunarthshs initQueue me parametro thn oura A

    do{
        //menou
        printf("Please press one of the options below.\n");
        printf("P. Customer \n");
        printf("T. Cashier\n");
        printf("D. Manager\n");
        printf("Choice: ");

        scanf("%d", &choice);

        //periptwsh pelath
        if(choice == 1){
            //an h oura einai gemath
            if(isFull(&A)){
                printf("Queue is full!");
            }
            else{
                Enqueue(&A, customer_inQueue); //eisagwgh pelath sthn oura
                printf("Customer %d is in queue.\n", customer_inQueue); //ektupwsh pelath pou einai sthn oura

                customer_inQueue++; //aujhsh counter (pelates sthn oura)
            }
        }
        //periptwsh tamia
        else if(choice == 2){
             //an h oura einai adeia
            if(isEmpty(&A)){
                printf("Queue is empty!");
            }
            else{
                int desk;

                do{
                    printf("Choose one of the cash desk (1 until 4): ");
                    scanf("%d", &desk);
                }
                while(desk<1 || desk>4); //elegxos epiloghs tameiou

                function1 = Dequeue(&A); //kalesma sunarthshs gia thn diagrafh pelath apo thn oura

                printf("Customer %d is in %d cash desk.\n", function1, desk); //ektupwsh pelath pou einai sto tameio

                tameio[desk-1]++; //meiwsh kata 1 ths timhs tou tameiou pou ejuphretithike o pelaths
            }
        }
        //periptwsh dieuthinth
        else if(choice == 3){
            int i;
            int max = 0;

            //epanalhpsh mexri ton arithmo tameiwn, dhladh 4
            for(i=0; i<4; i++){
                //euresh tameiou me megaluterh timh, ara exei ejuphrethsei tous perissoterous pelates
                if(tameio[i]>tameio[max])
                    max = i;
            }
            printf("Cash desk which the most customers was served: %d\n", max+1);
            printf("Sum of customers: %d\n", customer_inQueue-1);
            printf("Serviced customers: %d\n", tameio[0] + tameio[1] + tameio[2] + tameio[3]); //osoi pelates htan sto tameio
            printf("Remaining customers: %d\n", customer_inQueue-1 - (tameio[0] + tameio[1] + tameio[2] + tameio[3])); //sunolikoi pelates meiwn ekeinoi pou htan sto tameio
        }
    }
    while(choice>=1 && choice<=3); //gia ton elegxo epiloghs apo menou
}
