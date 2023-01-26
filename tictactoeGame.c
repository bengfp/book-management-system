#include<stdio.h> 
#include<stdlib.h>
#include<conio.h>

char board[3][3]; //= {'1','2','3','4','5','6','7','8','9'};
int choice, player;
char mark;
int moves;

void in_board();
void print_board();
void player_move();
void mark_move();
int check_win();


int main(){
    char ans;
    int winner;

    do{
        moves = 0;
        player = 1;

        in_board();
    
        while (moves < 9) {
            print_board();

            player_move();
            mark_move();

            winner=check_win();
            print_board();

            if (winner == -1){
                printf("Player %d, YOU WON!\n", player);
                break;
            }
            else
                printf("It's a draw!\n");

            player++;
            moves++;
        }

        fflush(stdin);
        printf("Would you like to play again? (y/n): ");
        scanf("%c", &ans);
    
    } while (ans == 'y' || ans == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}

void in_board(){
    char n = 48;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            n++;
            board[i][j] = n;
        }
    }
}

void print_board(){
    int i;

    system("cls");
    printf("\t\t\t   TIC TAC TOE\n\n");
    printf("\t\t   Player 1 (X) - Player 2 (O)\n\n");

    for (int i = 0; i < 3; i++){
        printf("\t\t\t  %c  |  %c  |  %c\n", board[i][0], board[i][1], board[i][2]);

        if(i != 2)
        printf("\t\t\t-----|-----|-----\n");
    }

    printf("\n");
}

void player_move(){
    do{
        if(player%2!=0){
            player=1;
            mark='X';
        }
        else
            {player=2;
            mark='O';}
        

        printf("Player %d, enter the number: ",player);
        scanf("%d",&choice);

        if(choice < 1 || choice > 9)
            printf("Invalid Number! Try again.\n");

    } while (choice < 1 || choice > 9);
}

void mark_move (){
    int i, j;
    char n = 49;
    int num = 1; 

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (choice == num && board[i][j] == n){
                board[i][j] = mark;
                break;
            }
            //validation
            if (choice == num && board[i][j]!=n && (board[i][j]=='X' || board[i][j]=='O')){
                printf("Invalid move!\n");
                player--;
                moves--;
                getch();
            }
            n++;
            num++;
        }
    }
}

int check_win(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return -1;

            else if(board[0][j] == board[1][j] && board[0][j] == board[2][j])
                return -1;

            else if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
                return -1;
            
            else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
                return -1;
        }
    }
}