 #include<stdio.h>
#include<stdlib.h>
void initboard(char board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}
void displayboard(char board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c",board[i][j]);
            if(j<2){
                printf("|");
            }
        }
       printf("\n");
        if(i<2){
            printf("_____\n");
        }                                                                                                         
    }
}
    void getinput(char board[3][3],char                     currentplayer ){
        int row,col;
        printf("Enter row (0-2)and column (0-2):");
        scanf("%d%d",&row ,&col);
        if(board[row][col]==' ' && row>=0 && row<3 && col>=0 && col<3){
            board[row][col]=currentplayer;
        }
        else{
            printf("Invalid move\n");
            getinput(board,currentplayer);
        }
    }
    int checkwin(char board[3][3]){
        for(int i=0;i<3;i++){
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' '){
                return 1;
            }
        }
        for(int i=0;i<3;i++){
            if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){
                return 1;
            }
        }
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
            return 1;
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' '){
            return 1;
        }
        return 0;
}
void getRandInput(char board[3][3],char currentplayer){
    // to win the game
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j]=currentplayer;
                if(checkwin(board)){
                return;
            }
            board[i][j]=' ';
        }
    }
    }
    // to block the opponent
    char opponent = (currentplayer=='X')?'O':'X';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j]=currentplayer;
                if(checkwin(board)){
                board[i][j]=currentplayer;
                return;
            }
            board[i][j]=' ';
        }
    }
    }
    int row,col;
    row=rand()%3;
    col=rand()%3;
    if(board[row][col]==' '){
        board[row][col]=currentplayer;
    }
    else{
        getRandInput(board,currentplayer);
    }
}
int main(){
    char board[3][3];
    
    char currentplayer='X',lastplayer;
    int win=0,move=0;       //move is used to check if the game is draw
    initboard(board);
    while(win==0 && move<9){
        displayboard(board);
        if(currentplayer=='X'){
            getinput(board,currentplayer);
        }
        else{
            getRandInput(board,currentplayer);
        }
        win=checkwin(board);
        lastplayer=currentplayer;
        if(currentplayer=='X'){
            currentplayer='O';
    
               
            
        }
        else{
            currentplayer='X';
        }
        move++;
    }
    displayboard(board);
  
    if(win){
        if(lastplayer=='X'){
            printf("X wins\n");
        }
        else{
            printf("O wins\n");
    
    }
    }else{
        printf("Draw\n");
    }
    

        

    return 0;
}