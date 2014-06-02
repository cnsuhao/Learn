#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define roof(a, b) (a+b)%b

/*
  记得改掉！！
  Name: 贪食蛇
  Copyright: None
  Author: Xuanwo
  Date: 14-06-03 3:17
  Description: 一个很弱的贪食蛇游戏。。。太弱了以至于刷新都卡>___>
*/

int i,j,a;

/** 游戏场地, 20x30的 **/
int field[20][30];

/** 游戏状态
	0 - 欢迎界面
	1 - 游戏中
	2 - 高分榜
**/
int gameState = 0;

/** 蛇面对的方向
	0 - 上
	1 - 下
	2 - 左
	3 - 右
**/
int snakeFace = 0, faceUpdated = 0;
int snakeX = 0, snakeY = 0;
int score = 0;

void printWelcome()
{
    /** 输出欢迎文字 **/
    if(gameState != 0)
        return;
    printf("===贪食蛇===\n");
    printf("(1) 进入游戏\n");
    printf("(2) 高分排行榜\n");
    printf("(3) 退出游戏\n");
    printf("请按下相应的数字键来选择模式：");
}

void printField()
{
    /** 绘制场地 **/
    system("cls");
    for(i = 0; i <= 20; i++)
    {
        for(j = 0; j < 30; j++)
        {
            if( i == 20 )
            {
                printf("一");
                continue;
            }
            if(field[i][j] == 0)
            {
                printf("　");
            }
            else if(field[i][j] > 0)
            {
                printf("口");
            }
            else
            {
                printf("〇");
            }
        }
        printf("|\n");
    }
    printf("按键：w - 上 | a - 左 | s - 下 | d - 右 | ESC - 退出到主屏\n");
    printf("得分：%i", score);
}

void appendScore()
{
    FILE *fp;
    fp = fopen("results.dat","a");
    if(fp == NULL)
    {
        printf("没办法写入文件，请检查磁盘可写并且你有权限！\n");
        return;
    }
    fprintf(fp, "%d\n",score);
    fclose(fp);
}

void snakeDie()
{
    system("cls");
    appendScore();
    printf("================\n");
    printf("啊啦，你死了。你得到了 %i 分\n 按任意键重新开始游戏...\n", score);
    for(i = 0; i < 20; i++)
        for(j = 0; j < 20; j++)
            field[i][j] = 0;
    score = 0;
    snakeFace = 0;
    snakeX = 0;
    snakeY = 0;
    gameState = 0;
    printf("================\n");
    getch();
}

void generatePellet()
{
    if(score < 450)
    {
        /** 蛇长小于场地75%的时候，随即选食物点 **/
        srand(time(NULL));
        int xycoords = rand() % 600;
        int x = xycoords / 20;
        int y = xycoords % 20;

        while(field[y][x] != 0)
        {
            /** 有东西了，重新生成新的坐标 **/
            xycoords = rand() % 600;
            x = xycoords / 20;
            y = xycoords % 20;
        }
        field[y][x] = -1;
    }
    else
    {
        /** 蛇长大于场地75%了，随机选择可能会产生很多冲撞
        	所以只从剩下的空里面选择
         **/
        int totalSpaces = 0;
        for(i = 0; i < 20; i++)
            for(j = 0; j < 30; j++)
            {
                if(field[i][j] == 0)
                    totalSpaces++;
            }
        if(totalSpaces == 0)
            return; /** 卧槽！你TM玩赢了？！ **/

        /** 从空余的个数里面选一个 **/
        int spaceSelected = rand() % totalSpaces;
        for(i = 0; i < 20; i++)
            for(j = 0; j < 30; j++)
            {
                totalSpaces--;
                if(totalSpaces == spaceSelected)
                    field[i][j] = -1;
            }
    }
}

void moveSnakeBody()
{
    /** 搜索蛇的尾巴并删掉 **/
    int tailX = snakeX, tailY = snakeY, lastX = -1, lastY = -1;
    while(field[tailY][tailX] > 1)
    {
        int ptr = field[tailY][tailX];
        lastX = tailX;
        lastY = tailY;
        tailX = (ptr - 2) / 20;
        tailY = (ptr - 2) % 20;
    }
    field[tailY][tailX] = 0;
    if(lastX >= 0 && lastY >= 0)
        field[lastY][lastX] = 1;
}

void moveSnake()
{
    /** 移动蛇体 **/
    int grow = 0;
    switch(snakeFace)
    {
    case 0:
        if(field[roof(snakeY - 1,20)][snakeX] < 0)
            grow = 1;
        else if(field[roof(snakeY - 1,20)][snakeX] > 0)
        {
            snakeDie();
            return;
        }
        field[roof(snakeY - 1,20)][snakeX] = snakeX * 20 + snakeY + 2;
        snakeY = roof(snakeY - 1,20);

        break;
    case 1:
        if(field[roof(snakeY + 1,20)][snakeX] < 0)
            grow = 1;
        else if(field[roof(snakeY + 1,20)][snakeX] > 0)
        {
            snakeDie();
            return;
        }
        field[roof(snakeY + 1,20)][snakeX] = snakeX * 20 + snakeY + 2;
        snakeY = roof(snakeY + 1,20);
        break;
    case 2:
        if(field[snakeY][roof(snakeX - 1,30)] < 0)
            grow = 1;
        else if(field[snakeY][roof(snakeX - 1,30)] > 0)
        {
            snakeDie();
            return;
        }
        field[snakeY][roof(snakeX - 1,30)] = snakeX * 20 + snakeY + 2;
        snakeX = roof(snakeX - 1,30);
        break;
    case 3:
        if(field[snakeY][roof(snakeX + 1,30)] < 0)
            grow = 1;
        else if(field[snakeY][roof(snakeX + 1,30)] > 0)
        {
            snakeDie();
            return;
        }
        field[snakeY][roof(snakeX + 1,30)] = snakeX * 20 + snakeY + 2;
        snakeX = roof(snakeX + 1,30);
        break;
    }
    faceUpdated = snakeFace;
    if(!grow)
        moveSnakeBody();
    else
    {
        generatePellet();
        score++;
    }
}

int main(void)
{

init: /** 老天大概会谴责我的 **/
    while( gameState == 0 )
    {
        printWelcome();
        char c = getche();
        switch(c)
        {
        case '1':
            gameState = 1;
            goto game;
            break;
        case '2':
            gameState = 2;
            goto highscore;
            break;
        case '3':
            return 0;
        default:
            printf("\n您的输入'%c'有误，请重新输入！\n\n", c);
        }
    }

highscore:
    while( gameState == 2 )
    {
        printf("\n\n下面是最高分TOP 10\n================\n");
        FILE *fp;
        fp = fopen("results.dat", "r");
        if(fp == NULL)
        {
            printf("呵呵，没记录。\n");
        }
        else
        {
            int scores[2048], i, cur = 0;

            while(fscanf(fp, "%d\n", &i) == 1)
            {
                scores[cur] = i;
                cur++;
            }

            //Sort the scores
            for(a = 1; a < cur; a++)
            {
                int val = scores[a];
                int hole = a;
                while(hole > 0 && val > scores[hole - 1])
                {
                    scores[hole] = scores[hole - 1];
                    hole--;
                }
                scores[hole] = val;
            }

            for(a = 0; a < (cur > 10? 10: cur); a++)
            {
                printf("%d: 得分 %d\n", a+1, scores[a]);
            }

            fclose(fp);
        }
        printf("==============\n输入任意键返回菜单...\n");
        char k = getch();
        switch(k)
        {
        default:
            gameState = 0;
            goto init;
        }
    }
    goto init;

game:
    /** 初始化蛇 **/
    field[9][14] = 1;
    snakeX = 14;
    snakeY = 9;
    generatePellet();
    clock_t tlast = clock(), tcurr;
    while( gameState == 1 )
    {
        tcurr = clock();
        clock_t tdiff = tcurr - tlast;
        if(tdiff > 500)
        {
            /** 500ms 绘制场地 **/
            tlast = tcurr;
            printField();
            moveSnake();
        }

        if( kbhit() )
        {
            /** 捕捉键盘 **/
            char ch = getch();
            switch(ch)
            {
            case 'w':
                if(faceUpdated > 1)
                    snakeFace = 0;
                break;
            case 'a':
                if(faceUpdated < 2)
                    snakeFace = 2;
                break;
            case 's':
                if(faceUpdated > 1)
                    snakeFace = 1;
                break;
            case 'd':
                if(faceUpdated < 2)
                    snakeFace = 3;
                break;
            case 27:
                system("cls");
                appendScore();
                printf("========\n分数已经保存，按任意键返回主菜单...\n========\n");
                gameState = 0;
                getch();
                goto init;/** 老天要谴责我了 **/
                break;
            }
        }
    }
    goto init;

    return 0;
}
