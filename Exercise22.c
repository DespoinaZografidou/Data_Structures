 /*Μέλη Ομάδας: Χατζηβασίλη Νίκη, 321/2016215
               Ζωγραφίδου Δέσποινα, 321/2016041 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//dimiourgia aplhs sundedemenis listas
struct Node{
    int value; //dedomena
    struct Node* next; //deikths pou deixnei se kpmbo
};

//dhmiourgia diplhs sundedemenis listas
struct DoubleNode{
    int data;
    struct DoubleNode* prev;
    struct DoubleNode* next;
};

//sunartisi pou prosthetei neo kombo se aplh sundedemenh lista
//head: h lista
//num: ta dedomena
//pos: h thesh
struct Node* addNodeSingle(struct Node* head, int num, int pos){
    struct Node* newNode; //dhlwsh kombou

    newNode = (struct Node*) malloc(sizeof(struct Node)); //desmeush mnhmhs

    newNode->value = num; //h timh tou kombou deixnei ston arithmp pou tha eisagoume

    //eisagwgh stoixeiou sthn arxh ths listas
    if(pos == 0){
        if(head == NULL){ //periptwsh pou h lista einai adeia
            newNode->next = NULL; //to pedio next tou kombou newNode deixnei se NULL
            head = newNode; //h timh tou deikth newNode isoutai me thn timh tou deikth head
        }
        else{
            newNode->next = head; //to pedio next tou kombou newNode deixnei sthn timh pou deixnei kai to head
            head = newNode;
        }
    }
    else if(pos == 1){ //periptwsh pou prosthetw stoixeio sto telos ths listas
        if(head == NULL){ //an h lista einai adeia
            newNode->next = NULL;
            head = newNode;
        }
        else{
            struct Node* temp;
            struct Node* prev;

            //diasxish kombwn
            while(temp != NULL){
                prev = temp;
                temp = temp->next; //proxwraei ston epomeno kombo
            }
            prev->next = newNode; //to pedio next tou kombou prev deixnei sto newNode
            newNode->next = NULL;
        }
    }
    return head; //epistrofh head
};

//sunarthsh pou prosthetei neo kombo se aplh sundedemenh lista se phinousa diatajh
//head: h lista
//num: ta dedomena
struct Node* addDescending(struct Node* head, int num){
    struct Node* newNode;

    newNode = (struct Node*) malloc(sizeof(struct Node*)); //desmeush mnhmhs

    newNode->value = num;

    //periptwsh pou h lista einai adeia
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        struct Node* temp;
        struct Node* prev;

        temp = head;
        prev = temp;

        //elegxos gia thn diatajh arithmwn apo to megalutero sto mikrotero
        while(temp != NULL && temp->value > newNode->value){
            prev = temp;
            temp = temp->next; //proxwraei ston epomeno kombo
        }
        //prosthiki kombou sthn arxh
        if(head == temp){
            newNode->next = head;
            head = newNode;
        }
        //prosthiki kombou sto telos
        else if(temp == NULL){
            prev->next = newNode;
            newNode->next = NULL;
        }
        //prosthiki kombou sth mesh
        else{
            prev->next = newNode;
            newNode->next = temp;
        }
        return head;
    }
};

//sunarthsh pou epistrefei to plhthos twn stoixeiwn ths
//head: h lista
int countList(struct Node* head){
    struct Node* temp = head;

    int counter = 0; //arxikopoihsh metrhth

    //diasxish kombwn
    while(temp != NULL){
        counter++; //aujhsh metrhth
        temp = temp->next; //proxwraei ston epomeno kombo
    }
    return counter; //epistrofh metrhth
}

//sunarthsh gia thn emfanish twn dedomenwn pou einai apothhkeumena stous kombous ths listas
//head: h lista
void displayList(struct Node* head){
    struct Node* temp;

    if(head == NULL){ //periptwsh pou h lista einai adeia
        printf("The list is empty!");
    }
    else{
        temp = head;

        //diasxish kombwn
        while(temp != NULL){
            printf("%d ", temp->value); //ektupwsh kombwn
            temp = temp->next; //proxwraei ston epomeno kombo
        }
    }
}

//sunarthsh pou diagrafei ton teleutaio kombo
//head: h lista
void deleteLast(struct Node* head){

    if(head == NULL){ //periptwsh pou h lista einai adeia
        printf("The list is empty!");
    }
    else{
        struct Node* temp;
        struct Node* prev;

        temp = head;
        prev = temp;

        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL; //sundesh tou kombou prev me NULL

        free(temp); //apodesmeush mnhmhs, diagrafh temp

        printf("\n\nThe last node is deleted! ");
    }
}

//sunarthsh pou diagrafei
//head: h lista
//num: o akeraios gia diagrafh
void deleteNode(struct Node* head, int num){
    if(head == NULL){ //periptwsh pou h lista einai adeia
        printf("The list is empty!");
    }
    else{
        struct Node* temp;
        struct Node* prev;

        temp = head;
        head = head->next;

        //periptwsh pou o head einai o kombos pou theloume na diagrapsoume
        if(temp != NULL && temp->value == num){
            head = temp->next; //allagh head, deixnei ston epomeno kombo

            free(temp); //apodesmeush mnhmhs, diagrafh temp
        }

        //anazhthsh tou akeraiou arithmou
        while(temp != NULL && temp->value != num){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next; //aposundesh tou kombou pou diagrapsame apo th lista

        free(temp); //apodesmeush mnhmhs, diagrafh temp
    }
}

//sunarthsh pou prosthetei neo kombo se diplh sundedemenh lista me akeraious arithmous
struct DoubleNode* addNodeDouble(struct DoubleNode* head, int num, int pos){
    struct DoubleNode* newNode;
    struct DoubleNode* tail;

    newNode = (struct DoubleNode*) malloc(sizeof(struct DoubleNode)); //desmeush mnhmhs

    newNode->data = num;

    newNode->prev = NULL;
    newNode->next = NULL;

    if(pos == 0){ //eisagwgh stoixeiou sthn arxh ths listas
        if(head == NULL){ //periptwsh pou h lista einai adeia
            head = newNode;

            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else{
            newNode->next = head;
            head->prev = newNode;

            head = newNode;
        }
    }
    else if(pos == 1){ //eisagwgh stoixeiou sto telos ths listas
        tail = head;

        if(head == NULL){ //an h lista einai adeia
            head = newNode;

            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else{
            while(tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->prev = tail;
        }
    }
    return newNode; //epistrofh kombou
};

//sunarthsh pou emfanizei ta dedomena stous kombous me anapodh seira
void RiversedisplayList(struct DoubleNode* head, struct DoubleNode* tail){
    tail = head;

    if(tail == NULL){ //periptwsh pou h lista einai adeia
        printf("The list is empty!");
    }
    else{
        while(tail->next != NULL) {
            tail = tail->next;
        }
    }
    //ektupwsh kombwn me antistrofh seira
    while(tail != NULL){
        printf("%d ",tail->data);
        tail = tail->prev;
    }
}

int main(){
    int choice;

    //menou
    printf("Please press one of the options below.\n");
    printf("1. Function addNodeSingle \n");
    printf("2. Function addDescending\n");
    printf("3. Function countList\n");
    printf("4. Function displayList\n");
    printf("5. Function deleteLast\n");
    printf("6. Function deleteNode\n");
    printf("7. Function addNodeDouble\n");
    printf("8. Function ReversedDisplayList\n");
    printf("Choice: ");

    scanf("%d", &choice);

//sunarthsh: addΝodeSingle
    if(choice == 1){
        struct Node* head = NULL; //dhlwsh kombou kai arxikopoihsh

        //prosthhkh arithmwn sthn arxh ths listas, kathws pairnoun thn parametro 0
        head = addNodeSingle(head, 10, 0);
        head = addNodeSingle(head, 50, 0);
        head = addNodeSingle(head, 30, 0);

        printf("\nList: ");

        struct Node* temp = head;

        //an h lista einai adeia
        if(head = NULL){
            printf("The list is empty!");
        }
        else{
            //ektupwsh listas
            while(temp != NULL){
                printf("%d ", temp->value);
                temp = temp->next; //proxwraei ston epomeno kombo
            }
        }

        //prosthhkh arithmwn sto telos ths listas, kathws pairnoun thn parametro 1
        head = addNodeSingle(head, 90, 1);

        temp = head;

        //ektupwsh listas
        while(temp != NULL){
            printf("%d ", temp->value);
            temp = temp->next;
        }
    }
//sunarthsh: addDescending
    else if(choice == 2){
        int i, num;

        struct Node* head = NULL;

        srand(time(NULL)); //arxikopoihsh sunarthshs rand(paragwgh tuxaiwn arithmwn me bash ton xrono)

        for(i=0; i<10; i++){
            num = rand() % 20+1; //paragwgh tuxaiwn arithmwn apo 0 ews 20
            head = addDescending(head, num); //prosthhkh tuxaiwn arithmwn ston kombo
        }

        printf("\nNode in descending order: ");

        struct Node* temp = head;

        //ektupwsh listas
        while(temp != NULL){
            printf("%d ", temp->value);
            temp = temp->next;
        }
    }
//sunarthsh: countList
   else if(choice == 3){
        struct Node* head = NULL;

        int count;

        //prosthhkh arithmwn sthn arxh ths listas, kathws pairnoun thn parametro 0
        head = addNodeSingle(head, 10, 0);
        head = addNodeSingle(head, 50, 0);
        head = addNodeSingle(head, 35, 0);
        head = addNodeSingle(head, 80, 0);

        struct Node* temp = head;

        printf("\nNode: ");

        //ektupwsh listas
        while(temp != NULL){
                printf("%d ", temp->value);
                temp = temp->next;
        }

        count = countList(head); //kalesma sunarthshs countList me parametro to head

        printf("\n\nAmount of elements: %d\n", count); //ektupwsh plhthous stoixeiwn ths listas
    }
//sunarthsh: displayList
   else if(choice == 4){
        struct Node* head = NULL;

        //prosthhkh arithmwn sthn arxh ths listas, kathws pairnoun thn parametro 0
        head = addNodeSingle(head, 10, 0);
        head = addNodeSingle(head, 50, 0);
        head = addNodeSingle(head, 35, 0);
        head = addNodeSingle(head, 80, 0);

        printf("\nList: ");

        displayList(head); //kalesma sunarthshs displayList me parametro to head
    }
//sunarthsh: deleteLast
    else if(choice == 5){
        struct Node* head = NULL;

        //prosthhkh arithmwn sthn arxh ths listas, kathws pairnoun thn parametro 0
        head = addNodeSingle(head, 10, 0);
        head = addNodeSingle(head, 50, 0);
        head = addNodeSingle(head, 35, 0);
        head = addNodeSingle(head, 80, 0);

        printf("\nList: ");
        displayList(head); //ektupwsh listas

        deleteLast(head); //kalesma sunarthshs deleteLast me parametro to head

        printf("\n\nNew List: ");
        displayList(head); //ektupwsh neas listas me thn diagrafh tou teleutaiou kombou
    }
//sunarthsh: deleteNode
    else if(choice == 6){
        struct Node* head = NULL;

        //prosthhkh arithmwn sth lista
        head = addNodeSingle(head, 10, 0);
        head = addNodeSingle(head, 50, 0);
        head = addNodeSingle(head, 30, 0);
        head = addNodeSingle(head, 80, 0);
        head = addNodeSingle(head, 60, 0);

        printf("\nList: ");
        displayList(head); //ektupwsh arxikhs listas

        printf("\n\nNode for deleting is <50>. ");
        deleteNode(head, 50); //kalesma sunarthshs deleteNode me parametro to head kai ton arithmo pros diagrafh

        printf("\n\nNew List: ");
        displayList(head); //ektupwsh listas me thn allagh
    }
//sunarthsh: addNodeDouble
   else if(choice == 7){
        struct DoubleNode* head = NULL;

        //prosthhkh arithmwn sthn arxh ths listas, kathws pairnoun thn parametro 0
        head = addNodeDouble(head, 10, 0);
        head = addNodeDouble(head, 50, 0);
        head = addNodeDouble(head, 40, 0);
        head = addNodeDouble(head, 30, 0);

        struct DoubleNode* temp = head;

        printf("\nNode: ");

        //ektupwsh kombwn
        while(temp != NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }

        //prosthhkh arithmou sto telos ths listas
        head = addNodeDouble(head, 90, 1);

        temp = head;

        //ektupwsh kombwn
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
//sunarthsh: RiversedisplayList
     else if(choice == 8){
        struct DoubleNode* head = NULL;

        //prosthhkh arithmwn sthn arxh ths listas
        head = addNodeDouble(head, 10, 0);
        head = addNodeDouble(head, 50, 0);
        head = addNodeDouble(head, 40, 0);
        head = addNodeDouble(head, 30, 0);

        struct DoubleNode* temp = head;

        printf("\nNode: ");

        //ektupwsh kombwn me thn kanonikh seira
        while(temp != NULL) {
            printf("%d ",temp->data);
            temp = temp->next;
        }

        printf("\n\nRiverse Node: ");
        RiversedisplayList(head, temp); //kalesma sunarthshs RiversedisplayList me parametro to head kai to temp

    }
    //periptwsh epiloghs ektos menou
    else{
        printf("\nWrong choice!");
     }
}

