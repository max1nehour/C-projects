//
//  main.c
//  minesweeper2
//
//  Created by M1HR on 2022/6/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define FLUSH fflush(stdin)
 
void difficulty( void ); //選擇地雷圖的難度
void easy( void );
void medium( void );
void hard( void );
void custom(void);
 
void minemap_generator( void ); //製造地雷圖（將地雷放入隨機位置）
void print_minemap( void ); //顯示遊玩中的地雷圖
void guess( void ); //選擇要踩或標記的地雷
 
void print_lose_minemap( void );
void print_win_minemap( void );
 
void win( void );
void lose( void );
void play_again( void );
void game_over( void );
 
int x, y;
int M, N;
float diff;
int total_mines = 0; // 設定要達到的總地雷數
int mines = 0; //隨機放入的地雷數
int minemap[30][30]; //地雷圖的所有答案
int show_minemap[30][30]; //遊玩中顯示的地雷圖
int lose_minemap[30][30]; //遊戲失敗顯示的地雷圖
int win_minemap[30][30]; //獲勝顯示的地雷圖
 
int main()
{
       printf("\n\n\t\t\033[0;34m\t💣歡迎來到踩地雷遊戲💣\n\n\n");
       difficulty();
     
    }
   
void difficulty( void )
{
    diff = 0;
    while( (diff != 1) && (diff != 2) && (diff != 3) && (diff != 4))
    {
        printf("1️⃣\tLevel.1  9x9  地雷圖   10 個地雷\n2️⃣\tLevel.2\t16x16 地雷圖   40 個地雷\n3️⃣\tLevel.3\t16x30 地雷圖   99 個地雷\n4️⃣\t自訂難度\n");
        printf("\n\n\033[0;34m請選擇遊戲難度，輸入1/2/3/4:");
        scanf("%f", &diff);
        printf("\n");
        FLUSH;
        if( (diff != 1) && (diff != 2) && (diff != 3) && (diff != 4)){
            printf("\t\t\033[0;34m\t請輸入1,2,3或4 !\n");
        }
    }
 
    if( diff == 1 ){
        easy();
    }
    else if( diff == 2 ){
        medium();
    }
    else if( diff == 3 ){
        hard();
    }
    else if( diff == 4){
        custom();
    }
}
 
void easy( void )
{
    M = 9;
    N = 9;
    total_mines = 10;
    minemap_generator();
    guess();
}
 
void medium( void )
{
    M = 16;
    N = 16;
    total_mines = 40;
    minemap_generator();
    guess();
}
 
void hard( void )
{
    M = 16;
    N = 30;
    total_mines = 99;
    minemap_generator();
    guess();
}
 
void custom( void )
{
    M = 0;
    N = 0;
    total_mines = 0;
    printf("\033[0;34m請輸入您想要的地雷區域大小---\n");
    printf("\033[0;34m寬度:");
    scanf("%d", &M);
    printf("\033[0;34m長度:");
    scanf("%d", &N);
    printf("\033[0;34m想要放置幾顆地雷呢？:");
    scanf("%d", &total_mines);
    minemap_generator();
    guess();
}
 
void minemap_generator( void )
{
    int i = 0, j = 0;
    srand( time( NULL ) );
 
    while( j < N )
    {
        while( i < M)
        {
            minemap[i][j] = '-'; //未開啟的格子
            show_minemap[i][j] = minemap[i][j];
            lose_minemap[i][j] = minemap[i][j];
            i++;
        }
        i = 0;
        j++;
    }
    mines = 0;
    while( mines < total_mines )
    {
        i = rand()%(M); //小於M的隨機數字
        j = rand()%(N); //小於N的隨機數字
        if( minemap[i][j] != 'B')
        {
            minemap[i][j] = 'B'; //植入地雷
            lose_minemap[i][j] = minemap[i][j];
            mines++; //植入地雷數加一 直到等於設定欲達到的總地雷數
        }
    }
    i = 0;
    j = 0;
 
    while( j < N )
    {
        while( i < M)
        {
            if( minemap[i][j] != 'B') //如果該座標上不是地雷
            {
                minemap[i][j] = 0; //數字＝0
            }
            if((minemap[i-1][j-1] == 'B') && (minemap[i][j] != 'B'))
                //如果該座標附近九宮格內有地雷 則數字+1
            {
                minemap[i][j]++;
            }
            if((minemap[i-1][j] == 'B') && (minemap[i][j] != 'B'))
            {
                minemap[i][j]++;
            }
            if((minemap[i][j-1] == 'B') && (minemap[i][j] != 'B'))
            {
                minemap[i][j]++;
            }
            if((minemap[i-1][j+1] == 'B') && (minemap[i][j] != 'B'))
            {
                minemap[i][j]++;
            }
            if((minemap[i+1][j-1] == 'B') && (minemap[i][j] != 'B'))
            {
                minemap[i][j]++;
            }
            if((minemap[i+1][j] == 'B') && (minemap[i][j] != 'B'))
            {
                minemap[i][j]++;
            }
            if((minemap[i][j+1] == 'B') && (minemap[i][j] != 'B'))
            {
                minemap[i][j]++;
            }
            if((minemap[i+1][j+1] == 'B') && (minemap[i][j] != 'B'))
            {
                minemap[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}
 
void print_minemap(void)
{
    int i = 0, j = 0, z = 0;
 
    while( z < M )
    {
        if( z == 0 ) //座標0之前要先空一格 之後就不用 所以獨立寫
        {
            printf("\t");
        }
        printf("\033[0;30m|%d|\t", z);
        z++;
    }
    printf("\n\n");
 
    while( j < N )
    {
        printf("\033[0;30m|%d|\t", j);
        
        while( i < M){
            
            if( show_minemap[i][j] == '-'){  //列印未開啟的格子
                    printf("\033[0;30m|%c|\t", show_minemap[i][j]);
                    }
            
            else if( minemap[i][j]==0&&show_minemap[i][j] != 9&&show_minemap[i][j] != 'F'&&show_minemap[i][j] != 10){  //將數字為0的格子 轉為O 並列印
                    show_minemap[i][j] = 'O';
                    printf("\033[0;30m|%c|\t", show_minemap[i][j]);
                    }
            
            else if(show_minemap[i][j] == 9||show_minemap[i][j] == 'F'){
                    //將字母為F或數字為9的格子 轉為F 並列印
                
                    show_minemap[i][j] = 'F';  //F=flag 被標記的格子
                    printf("\033[0;35m|%c|\t", show_minemap[i][j]);
                    }
            
            else {
                    if(show_minemap[i][j] == 10){  //要被取消標記的格子
                        //將數字為10的格子 轉為- 即未開啟的格子 並列印
                        show_minemap[i][j] = '-';
                        printf("\033[0;30m|%c|\t", show_minemap[i][j]);
                    }
                    else
                        printf("\033[0;32m|%d|\t", show_minemap[i][j]);
                 }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}
 
 
void guess( void )
{
int s=0,steps=0,rm=total_mines;
while (s==0){
    
    int act;
    print_minemap();
    printf("\n\033[0;34m請選擇您的動作 - 🚩開啟(1)|標記(2)|取消標記(3)🚩:");
    scanf("%d.", &act);
    FLUSH;
    
    if( (act==1) || (act==2) || (act==3)  ){
    printf("\n\033[0;34m🚩輸入x值, 空白鍵, 輸入y值🚩:");
    scanf("%d %d", &x, &y);
    printf("\n");
    FLUSH;
    }
    
    //輸入錯誤的提醒
    else{
        printf("\n\033[31m⚠️ 請輸入1/2/3 !⚠️\n");
        steps--;
    }
    
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) ){
        printf("\n\033[31m⚠️ 請輸入範圍內的值！⚠️\n");
        s=0;
    }
    
    if( show_minemap[x][y] != '-'&&act==2 ){
       printf("\n\033[31m⚠️ 請輸入可標記的座標！⚠️\n");
        act=4; //輸入動作無用 回去重來
    }
    
    if( show_minemap[x][y] != 'F'&&act==3 ){
       printf("\n\033[31m⚠️ 請輸入可取消標記的座標！⚠️\n");
        act=4;
    }
    
    if( show_minemap[x][y] != '-'&&act==1 ){
        printf("\n\033[31m⚠️ 請勿輸入已開啟的座標！⚠️\n");
        act=4;
    }
    //踩到地雷 呼叫lose函式
    if( minemap[x][y] == 'B'&& act != 2&& act!=3 ){   //當選擇開啟動作時，選到有*的格子
        lose();
        break;
    }
    
    if(act==2){  //選擇標記動作，令show_minemap[x][y] = 9，以列印標記後的地雷圖
    show_minemap[x][y] = 9;
    }
 
    else if(act==3){ //選擇取消標記動作，令show_minemap[x][y] = 10，以列印取消標記後的地雷圖
    show_minemap[x][y] = 10;
    }
 
    
    else if(act==1){
    show_minemap[x][y] = minemap[x][y]; //開啟格子的數字
        
        if( minemap[x][y] == 0 ){ //若格子為0，且其附近九宮格內也有0，則一起開啟
            
            if( minemap[x-1][y-1] == 0 ){
                show_minemap[x-1][y-1] = minemap[x-1][y-1];
            }
            
            if( minemap[x-1][y] == 0 ){
                show_minemap[x-1][y] = minemap[x-1][y];
            }
            
            if( minemap[x][y-1] == 0 ){
                show_minemap[x][y-1] = minemap[x][y-1];
            }
            
            if( minemap[x-1][y+1] == 0 ){
                show_minemap[x-1][y+1] = minemap[x-1][y+1];
            }
            
            if( minemap[x+1][y-1] == 0 ){
                show_minemap[x+1][y-1] = minemap[x+1][y-1];
            }
            
            if( minemap[x+1][y] == 0 ){
                show_minemap[x+1][y] = minemap[x+1][y];
            }
            
            if( minemap[x][y+1] == 0 ){
                show_minemap[x][y+1] = minemap[x][y+1];
            }
            
            if( minemap[x+1][y+1] == 0 ){
                show_minemap[x+1][y+1] = minemap[x+1][y+1];
            }
        }
    }
    
    s=0; //讓while迴圈重來的條件
    if(act!=4){
        steps++; //踩雷次數+1
    }
    if(act==3 && minemap[x][y]=='B'){ //如果取消標記有地雷的格子
       rm++; //剩餘地雷數+1
    }
    
    if(show_minemap[x][y] == 9 && minemap[x][y]=='B'){ //如果標記到有地雷的格子
        rm--; //剩餘地雷數-1
    }
    if( rm == 0){ //剩餘地雷數=0 獲得勝利
        win();
        break;
    }
    printf("\n\033[0;35m👣踩雷次數 : %d\n",steps);
    printf("\n\033[0;35m💣剩餘地雷數 :%d\n\n",rm);
    }
}
void lose( void ){
    print_lose_minemap();
    printf("\n\t\t\033[31m\t💥你在 (%d,%d) 踩到了地雷💥\n\t\t\t\t你輸了!!!!", x, y);
    play_again();
}
    
void print_lose_minemap( void ){
    int i = 0, j = 0, z = 0;
    while( z < M ){
        if( z == 0 ){
            printf("\t");
        }
        printf("\033[0;30m|%d|\t", z);
        z++;
    }
    printf("\n\n");
    while( j < N ){
        printf("|%d|\t", j);
        while( i < M){
            printf("\033[0;30m|\033[31m%c\033[0;30m|\t", lose_minemap[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}
void print_win_minefield( void ){
    int i = 0, j = 0, z = 0;
    while( z < M ){
        if( z == 0 ) {
            printf("\t");
        }
        printf("\033[0;30m|%d|\t", z);
        z++;
    }
    printf("\n\n");
 
    while( j < N ){
        printf("|%d|\t", j);
        
        while( i < M){
            if(minemap[i][j]=='B'){
                minemap[i][j]='F';
                printf("|%c|\t", minemap[i][j]);
            }
            else{
                printf("|%d|\t", minemap[i][j]);
            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}
 
 
void win( void ){
    print_win_minefield();
    printf("\n\n\n\t\t\t\033[31m\t🎉你贏了!!!!!🎉\n\n\n");
    play_again();
}
 
void play_again( void ){
    char option[2]; //宣告字元變數
    printf("\n\t\t\033[0;34m\t🎮再玩一次,是(Y)/否(N)?:");
    scanf("%c", &option[0]);
    FLUSH;
    
    if((option[0] == 'Y') || (option[0] == 'y')){
        difficulty();
    }
    
    else if( (option[0] == 'N') || (option[0] == 'n')){
        game_over();
    }
    else {
        printf("\033[31m\t⚠️請輸入 Y 或 N！⚠️");
        play_again();
    }
}
void game_over(  ){
    printf("\n\n\t\t\033[0;34m\t遊戲結束\n");
    exit(1);
}







