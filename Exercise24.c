/*Μέλη Ομάδας: Χατζηβασίλη Νίκη, 321/2016215
               Ζωγραφίδου Δέσποινα, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//dhmiourgia aplhs listas
struct Node{
    int value; //gia ton arithmo mnhsthra
    struct Node* next; //deikths pou deixnei se epomeno mnistira
};

//sunarthsh gia thn emfanish twn dedomenwn pou einai apothhkeumena stous kombous ths listas
//head: h lista
void displayList(struct Node* head){
    struct Node* temp;

    if(head == NULL){ //periptwsh pou h lista einai adeia
        printf("The list is empty!");
    }
    else{
        temp = head;
        printf("%d ", temp->value);
        temp = temp->next;

        //diasxish kombwn
        while(temp != head){
            printf("%d ", temp->value); //ektupwsh kombwn
            temp = temp->next; //proxwraei ston epomeno kombo
        }
    }
}

int main(){
    struct Node *head, *newNode, *prev, *temp, *delNode; //dhlwsh kombwn
    int count;

    head = NULL; //arxikopoihsh

    printf("Insert number for suitors: ");
    scanf("%d",&count);

    head = (struct Node*) malloc(sizeof(struct Node*)); //desmeush mnhmhs

    head->value = 1; //to pedio value tou kombou head deixnei se 1 (prwtos mnhsthras)
    prev = head; //krataei thn timh tou head

    if(count == 1){
        printf("Only one suitor want you!");
        printf("\nLucky is the suitor 1");
        return 0;
    }

    //epanalhpsh apo ton 2o mnhsthra mexri oso dhlwsei o xrhsths
    for(int i=2; i<=count; i++){
        newNode = (struct Node*) malloc(sizeof(struct Node*));
        newNode->value = i; //h timh tou kombou deixnei ston arithmp mnhsthrwn

        prev->next = newNode; //to pedio next tou kombou prev deixnei sto newNode
        prev = newNode; //diathrhsh thesis
    }
    newNode->next = head; //sundesh head me to pedio next tou kombou newNode

    displayList(head); //ektupwsh arkikhs listas

    temp = head;

    printf(" Initial list. Start from: %d\n", temp->value);

    int d;

    //epanalhpsh mexri na apomeinei 1 arithmos sth lista
    while(1){ //panta true
        prev = temp->next; //proxwraei ston epomeno kombo
        delNode = prev->next; //proxwraei ston epomeno kombo tou prev

        prev->next = delNode->next; //sundeei to pedio next tou kombou prev me ton epomeno kombo tou delNode

        //periptwsh pou to head einai to stoixeio pros diagraphi
        if(head == delNode)
            head = head->next; //orizei to neo head

        d = delNode->value; //apothikeush ths timhs tou kombou delNode sth metablith d (gia thn ektupwsh tou argotera)

        free(delNode); //apodesmeush mnhmhs, diagrafh delNode

        temp = prev->next;

        displayList(head); //ektupwsh neas listas
        printf("Suitor %d is rejected. ", d);

        if (head->next != head){
            printf("The count will continue from node %d.\n", temp->value);
        }
        else{
            printf("The lucky one is: %d!\n", head->value);
            break; //ejodos
        }
    }
}
