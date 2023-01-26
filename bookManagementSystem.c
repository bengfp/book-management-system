#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

int menu();
void back_menu();
void print_books(int);
void prepopulate_inventory();
void populate_inventory();
void search();
void found();
void process_transaction();
void purchase();
void book_return();
int in_stock();
void delete_record();
void display_books();
void exit_bye();

typedef struct books{
    char ISBN [18];
    char title [35];
    char author [35];
    char publisher [35];
    char genre [30];
    int year;
    int stock;
    float price;
} books;

books book[500];

int k = 0;
int choice, book_index;
char keyword[35];

int main(){
    prepopulate_inventory();

    while(choice != 6){
        system("cls");
        
        switch( menu() ){
            case 1:
                system("cls");
                populate_inventory();
                back_menu();
                break;
            case 2:
                system("cls");
                search();
                found();
                back_menu();
                break;
            case 3:
                system("cls");
                process_transaction();
                back_menu();
                break;
            case 4:
                system("cls");
                delete_record();
                back_menu();
                break;
            case 5:
                system("cls");
                display_books();
                back_menu();
                break;
            case 6:
                system("cls");
                exit_bye();
            default:
                printf("Invalid Number! Try again.");
        }
    }
    return 0;
}

int menu(){
    printf("\n\t BOOK INVENTORY\n\n");
    printf("\tMain Menu Options\n");
    printf("\t-----------------\n");

    printf("1 - Populate the Inventory\n"
            "2 - Search by keywords\n"
            "3 - Process a transaction\n"
            "4 - Delete a book record\n"
            "5 - Display all books in the inventory\n"
            "6 - Exit\n\n");
    do{ 
        printf("Make your choice (1 - 6): ");
        scanf("%d", &choice); 
    } while (choice < 1 || choice > 6);

    return choice;
}

void back_menu(){
    printf("\nPress any key to go back in Main Menu...");
    getch();
}

void print_books(int i){
    printf("ISBN:\t\t%s\n", book[i].ISBN);
    printf("\t\tTitle:\t\t%s\n", book[i].title);
    printf("\t\tAuthor:\t\t%s\n", book[i].author);
    printf("\t\tPublisher:\t%s\n", book[i].publisher);
    printf("\t\tGenre:\t\t%s\n", book[i].genre);
    printf("\t\tYear:\t\t%d\n", book[i].year);
    printf("\t\tStock:\t\t%d\n", book[i].stock);
    printf("\t\tPrice:\t\t%.2f\n\n", book[i].price);
}

void prepopulate_inventory(){
    books b1 = {
        "978-0-12-345678-9", 
        "In Search of Lost Time", 
        "Marcel Proust", 
        "Grasset and Gallimard",
        "Modernist", 
        1913, 
        1, 
        123.00
    };  
    book[0] = b1;
    k++;

    books b2 = {
        "978-1-12-345678-9", 
        "Ulysses", 
        "James Joyce", 
        "Shakespeare and Company",
        "Modernist Novel", 
        1922, 
        4, 
        150.00
    }; 
    book[1] = b2;
    k++;

    books b3 = {
        "978-2-12-345678-9", 
        "Don Quixote", 
        "Miguel de Cervantes", 
        "Francisco de Robles",
        "Novel", 
        1605, 
        3, 
        120.00
    }; 
    book[2] = b3;
    k++;

    books b4 = {
        "978-3-12-345678-9", 
        "One Hundred Years of Solitude", 
        "Gabriel Garcia Marquez", 
        "Editorial Sudamericana", 
        "Magic realism", 
        1967, 
        50, 
        115.00
    }; 
    book[3] = b4;
    k++;

    books b5 = {
        "978-4-12-345678-9",
        "The Great Gatsby", 
        "F. Scott Fitzgerald", 
        "Charles Scribner's Sons", 
        "Tragedy", 
        1925, 
        5, 
        143.00
    }; 
    book[4] = b5;
    k++;
}

void populate_inventory(){
    char ans;
    int num_of_books;

    printf("How many books would you like to add?");
    scanf("%d", &num_of_books);

    for(int i = 0; i < num_of_books; i++){
        do{
            fflush(stdin);
            printf("Enter ISBN: ");
            scanf("%[^\n]%*c", book[i].ISBN);
            
            fflush(stdin);
            printf("Enter Book Title: ");
            scanf("%[^\n]%*c", book[i].title);

            fflush(stdin);
            printf("Enter Author of the book: ");
            scanf("%[^\n]%*c", book[i].author);
            
            fflush(stdin);
            printf("Enter Publisher of the book: ");
            scanf("%[^\n]%*c", book[i].publisher);

            fflush(stdin);
            printf("Enter genre of the book: ");
            scanf("%[^\n]%*c", book[i].genre);

            fflush(stdin);
            printf("Enter year published: ");
            scanf("%d", &book[i].year);

            fflush(stdin);
            printf("Enter number of stock: ");
            scanf("%d", &book[i].stock);

            fflush(stdin);
            printf("Enter price of the book: ");
            scanf("%f", &book[i].price);

            k++;

            printf("\nWould you like to add more books (y/n)? ");
            fflush(stdin);
            scanf("%c", &ans);

            if(ans =='n' || ans =='N')
                break;
        } while (ans == 'y' || ans == 'Y');
        break;
    }
}

void search(){
    printf("Search: ");
    fflush(stdin);
    scanf ("%[^\n]%*c", keyword);
}

void found(){
    bool is_found = false;

    for (int i = 0; i < k; i++){
        if((strstr(book[i].title, keyword)) != NULL || (strstr(book[i].author, keyword)) != NULL || (strstr(book[i].genre, keyword)) != NULL || (strstr(book[i].publisher, keyword)) != NULL){
            printf("\t\t");
            print_books(i);

            book_index = i;
            is_found = true;
            //break;
        }
        else if((strstr(book[i].ISBN, keyword)) != NULL){
            printf("Book Found Deleted\n");
            book_index = i;
            is_found = true;
            break;
        }
    }
    if (is_found == false){
            printf("Book Not Found.\n");
        }
}

void process_transaction(){
    char ans;

    do{
        int choice;

        printf("Transaction Options: \n"
                "1. Purchase\n"
                "2. Return \n\n");
        printf("Choose Transaction (1 or 2): ");
        scanf("%d", &choice);

        search();
        found();

        switch(choice){
            case 1:
                purchase();
                break;
            case 2:
                book_return();
                break;
        }
        printf("\nNumber of stock is now %d\n\n", book[book_index].stock);
        printf("Would you like to do another transaction (y/n)? ");
        fflush(stdin);
        scanf("%c", ans);

        if(ans == 'n' || ans == 'N')
            break;
     } while(ans == 'y' || ans == 'Y');
}

void purchase(){
    int check_stock;
    check_stock = in_stock();

    if(check_stock == 1){
        book[book_index].stock--;
        printf("\nBook Purchased!\n");
    }
    else
        printf("Transaction cannot be done. Out of stock");
}

void book_return(){
    book[book_index].stock++;
    printf("\nBook Returned!\n");
}

int in_stock(){
    for(int i = 0; i < k; i++){
        if(book[i].stock>0){
            return 1;
        }
    }
}

void delete_record(){
    char ans;

    do{
        printf("LOOK FOR ISBN\n");
        search();
        found();
        
        for(int i = book_index; i < k-1; i++){
            book[i]=book[i+1];
        }

        strcpy(book[k - 1].ISBN," ");
        strcpy(book[k - 1].title," ");
        strcpy(book[k - 1].author," ");
        strcpy(book[k - 1].genre," ");
        strcpy(book[k - 1].publisher," ");
        book[k - 1].year = 0;
        book[k - 1].stock = 0;
        book[k - 1].price = 0;

        k--;

        printf("\nWould you like to delete more book (y/n)? ");
        fflush(stdin);
        scanf("%c", &ans);

        if(ans == 'n' || ans == 'N')
            break;
    } while(ans == 'y' || ans == 'Y');
}

void display_books(){
    int book_num = 1;
    for(int i = 0; i < k; i++, book_num++){
        fflush(stdin);
        printf("BOOK %d\t\t", book_num);
        print_books(i);
    }
}

void exit_bye(){
    printf("Bye!");
    exit(1);
}