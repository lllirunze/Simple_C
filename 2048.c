#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void init_game();//初始化游戏
void print_board();//展示现有图像

int board[4][4];//游戏面板

int main(int argc, char *argv[]){
    init_game();
    return 0;
}

void init_game(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            board[i][j]=0;
        }
    }
}

void print_board(){

}