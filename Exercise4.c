/*Μέλη Ομάδας: Χατζηβασίλη Νίκη, 321/2016215
               Ζωγραφίδου Δέσποινα, 321/2016041 */

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//struct anaparastashs komvou
struct node
{
    int id;
    char name[10];
    char lastname[20];
    int year;
    float aver_grade;

    struct node *left,*right;
};
//dhmiourgia neou foithth
struct node* Add_student(int id)
{
    struct node *new_student=(struct node*)malloc(sizeof(struct node));//desmeush mnhmhs

    //eisagvgh stoixeiwn

    new_student->id=id;

    char nm[10];
    printf("Give me the student's name:  ");
    scanf("%s",nm);
    strcpy(new_student->name,nm);

    char lnm[20];
    printf("Give me the student's lastname:  ");
    scanf("%s",lnm);
    strcpy(new_student->lastname,lnm);

    int yr;
    printf("Give me the registration year of the student:  ");
    scanf("%d",&yr);
    new_student->year=yr;

    float av_grade;
    printf("Give me the average grade of the student:  ");
    scanf("%f",&av_grade);
    new_student->aver_grade=av_grade;

    new_student->left=NULL;
    new_student->right=NULL;


    return new_student;
}

//synarthsh tupwshs foithtwn(komvwn)
void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d  %s  %s  %d  %f \n", root->id,root->lastname,root->name,root->year,root->aver_grade);
        Inorder(root->right);
    }

}
//synarthsh epistrofhs foithtwn me th seira (synarthsh gia input sto arxeio)
void Sortedlist(struct node* root, FILE *outfile)
{
	 if (root != NULL)
    {
	    Sortedlist(root->left,outfile);
	    //grapse taksinomimena olous tous foitites sto arxeio
	fwrite (root, sizeof(struct node), 1, outfile);
	    Sortedlist(root->right,outfile);
	}
	//molis teleiwsei h diadikasia steile to katallhlo munhma
	if(fwrite != 0)  //an to arxeio den einai adeio
        printf("contents to file written successfully !\n"); 
    else //an einai adeio
        printf("error writing file !\n"); 
	
}
//struct gia prosthikh foithth kai taksinomhsh me vash ton arithmo mhtrown
struct node* Insert(struct node* node,int id )
{
    //an h lista einai kenh tote dhmhourghse kai epestrepse ena neo foithth
    if (node == NULL )
        return Add_student(id);

    //allws topothethse swsta ton neo foithth(komvo)
    if (id < node->id && id != node->id)
        node->left = Insert(node->left, id);
    if(id > node->id && id != node->id)
        node->right = Insert(node->right, id);
    if (id == node->id)
        printf("There is all ready a student with this id !!! \n");

    return node;

}

//epistrefei ton arithmo twn komvwn pou uparxoun sto dentro
int Count_students(struct node * root,int num_of_students)
{

    if (root != NULL)
    {
        Count_students(root->left,num_of_students++);
        Count_students(root->right,num_of_students++);
    }
    return num_of_students;
}

//epistrefei ton foithth me ton megaluterh mesh vathmologia
struct node* Max_aver_grade(struct node * root)
{
    struct node *leftroot=root->left;
    struct node *rightroot=root->right;

    if (root != NULL)
    {


        if (root->aver_grade>leftroot->aver_grade)
            return root;
        if (root->aver_grade<leftroot->aver_grade)
            return Max_aver_grade(root->left);
        if (root->aver_grade>rightroot->aver_grade)
            return root;
        if (root->aver_grade<rightroot->aver_grade)
            return Max_aver_grade(root->right);

    }
}

//sunarthsh gia thn euresh foithth me vash ton arithmo mhtrwou
void Search(struct node *root,int id)
{

    if (root==NULL)
        printf("There is not exist this student on the list! \n");
    if (id == root->id)
        printf("%d  %s  %s  %d  %f \n", root->id,root->lastname,root->name,root->year,root->aver_grade);
    else if(id < root ->id)
    {
        return Search(root ->left, id);
    }
    else // if(id > root->id)
    {
        return Search(root ->right, id);
    }

}

//evresh kai epistrofh tou foithth me to mikrotero aritmo id
struct node * Minimum_id(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

//evresh kai epistrofh tou foithth me to megalutero aritmo id
struct node * Maximum_id(struct node* node)
{
    struct node* current = node;

    while (current->right != NULL)
        current = current->right;

    return current;
}

//diagrafh foithth (komvou)
struct node* Delete(struct node* root, int id)
{
    //an h lista einai kenh
    if (root == NULL)
        return root;
	//an h lista den einai kenh metakinhte sto dentro mexri na vrei to id pou tou edwse o xrhsths
    if (id < root->id)
        root->left = Delete(root->left, id);

    else if (id > root->id)
        root->right = Delete(root->right, id);

    else//an vrei to id 
    {
		
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        
        struct node* temp = Minimum_id(root->right);

        root->id = temp->id;

        //diagrafh tou diadoxou
        root->right = Delete(root->right, temp->id);
    }
    return root;
}

//sunarthsh ektupwshw menu
void display_menu()
{
    printf("\n       MENU            \n");
    printf("0. EXIT \n");
    printf("1. Insert a new student on the list \n");
    printf("2. Delete a student from the list \n");
    printf("3. Show the sorted list of students dy DDA \n");
    printf("4. Show me the youngest student on the list(with the bigger id ) \n");
    printf("5. Show me the student with the biggest average grade \n");
    printf("6. Search a student on the list by the id \n");
    printf("7. Show me the number of the students on the list \n");
    printf("Epelekse (0-7):");
}
//synarthsh epiloghs menu kai elegxou timhs
int menu()
{
    int x;
    display_menu();
    scanf("%d",&x);
    while(x<0 || x>7)
    {
        printf("Lathos epilogh %d\n",x);
        display_menu();
        scanf("%d",&x);
    }
    return x;
}


int main()
{

    FILE *outfile; 
    
    struct node *list = NULL;//deikths listas (diadiko dentro)
    int id;
    struct node *maxid;//deikth sugrathshs foititi me to megalutero id
    struct node *maxgrade;//deikth sugrathshs foititi me to megalutero vathmo 
    int x;
    
    
    //emfanish menu
    x = menu();

    while(x != 0) //oso de patithike eksodos
    {
        //eisagwgh neou foithth sto dentro
        if(x == 1)
        {
            printf("\nGive me the student's id number:  ");
            scanf("%d",&id);
            list = Insert(list, id);
        }
		//diagrafh foithth apo to diadiko dentro
        else if(x == 2)
        {
            printf("\nGive me the id of the student: ");
            scanf("%d",&id);
            list = Delete(list, id);

        }
        //ektupwsh taksinomhmenhs listas(diadiko dentro )
        else if(x == 3)
        {
            printf("\n        THE LIST       \n");

            Inorder(list);
            printf("\n");
        }
        //ektupvsh stoixeivn tou foithth me to megalutero id
        else if(x == 4)
        {
            maxid=Maximum_id(list);
            printf("\n%d  %s  %s  %d  %f \n",  maxid->id, maxid->lastname, maxid->name, maxid->year, maxid->aver_grade);
        }
        //ektupvsh stoixeivn tou foithth me to megalutero vathmo
        else if(x == 5)
        {
            maxgrade=Max_aver_grade(list);
            printf("\n%d  %s  %s  %d  %f \n",  maxgrade->id, maxgrade->lastname, maxgrade->name, maxgrade->year, maxgrade->aver_grade);
        }
        //anazhthsh foititi me vash to id
        else if(x == 6)
        {
            printf("Give me the id of the student: ");
            scanf("%d",&id);
            Search(list, id);
        }
        //ektupwsh ariumou foititwn sth list
        else if(x == 7)
        {
            printf("The number of the students is: %d \n",Count_students(list,0));

        }
        x = menu();
    }
    
    //kata thn eksodo apothikeuei ta stoixeia tvn foithtwn
    
    outfile = fopen ("students_bst.txt", "w"); //orismos arxeiou eisagwgh stoixeiwn twn foititwn
    //an den uparxei arxeio me tetoio onoma ston fakelo tuponei munima lathous
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    } 
    
  Sortedlist(list, outfile);//sunarthsh eisagwghs tvn stoixeivn wn foithtvn sto arxeio
    return 0;
}
