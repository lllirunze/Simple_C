#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void init_game();//初始化游戏
void print_board();//展示现有图像
void game_over();//游戏结束

int board[4][4];//游戏面板

int main(int argc, char *argv[]){

    init_game();
    
    //游戏内容
    
    game_over();

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

void game_over(){
    return 0;
}