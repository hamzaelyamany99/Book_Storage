#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct book {
    char title[20];
    char auteur[20];
    int price;
    int qnt;
};

struct book b1[100];
int counter = 0;
int choice;


int main(){
    int i, choice;
    
do{
    printf("#####################################################\n");
    printf("#   1 - Ajouter un livre                            #\n");
    printf("#   2 - Afficher tous les livres disponibles        #\n");
    printf("#   3 - Rechercher un livre par son titre           #\n");
    printf("#   4 - Mettre à jour la quantité d'un livre        #\n");
    printf("#   5 - Supprimer un livre                          #\n");
    printf("#   6 - Afficher le nombre total de livres en stock #\n");
    printf("#   7 - EXIT                                        #\n");
    printf("#####################################################\n");

    scanf("%d",&choice);
    
switch(choice){
        case 1:
         addBook();
            break;
        case 2:
        listAll();
            break;
        case 3:
        findBook();
            break;
        case 4:
        editBook();
            break;
        case 5:
        deleteBook();
            break;
        /*case 6:
        showTotal();
            break;
        case 7:
        quitProg();
            break
        */
        default: printf("NO action taking\n");
        break;
    }
}while(!(choice >= 1 && choice <= 6));
return 0;
}

int addBook(){
    int i;
    int n;
    
    printf("How much books you wanna add:\n");
    scanf("%d", &n);
    
    for(i=0 ; i<n;i++){
    printf("Enter the book's name N° %d:\n", counter+1);
    scanf(" %[^\n]s", &b1[i].title);
    printf("Enter the book's author:\n");
    scanf(" %[^\n]s", &b1[i].auteur);
    printf("Enter the book's price:\n");
    scanf("%d", &b1[i].price);
    printf("Enter the quantity in the stock:\n");
    scanf("%d",&b1[i].qnt);
    printf("**********************************\n");

    counter++;
    }
    main();
}
int listAll(){
    int i;
    
    if(counter == 0)
    {
    printf("******** There are NO books ******** \n");
    printf("                     \n");

    }
    for(i=0; i<counter ;i++){
        printf("Book number N°=%d \n", counter);
        printf("Book title :%s\n", b1[i].title);
        printf("Author :%s \n", b1[i].auteur);
        printf("Price :%d \n", b1[i].price);
        printf("Quantity :%d \n", b1[i].qnt);
    }
    main();
}

int findBook(){
    char find[20];
    int i;

    if(counter == 0)
    {
        printf("No book in the library"); 
    }
    else if(counter > 0){
    for(i = 0 ; i < counter ; i++){
        printf("Enter book name:\n");
        scanf("%s",&find);
        if(strcmp(b1[i].title, find) == 0){
            printf("Book name is: %s\n", b1[i].title);
            printf("Author is :%s\n",b1[i].auteur);
            printf("The price :%d\n",b1[i].price);
            printf("The quantity :%d",b1[i].qnt);
            break;
        }
        else 
        printf("Book not found\n");
        }
    }
}

int editBook(){
    char name[20];
    int i;

    for(i = 0 ; i < counter ; i++){
        printf("Enter book name:\n");
        scanf("%s",&name);
        if(strcmp(b1[i].title, name) == 0){
            printf("The new quantity :\n");
            scanf("%d",&b1[i].qnt);
        }
        }
        main();
}