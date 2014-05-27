#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <ctype.h>

#define LEN sizeof(struct list)
#define uchar unsigned char
int n,sco,r,t,speed=8800;
uchar i,a,x1,y1,hit,long1=16,cycy=0,str1[200],xisu;

/* 核心的链表结构 */
struct list
{
    int x,y;
    struct list * next,* last;
};
struct list * p1,* p2,* head,* eof1;


void up(void); /* 按下上键后的操作  */

void down();/* 按下下键后的操作  */
void left();     /* 按下左键后的操作  */

void right();/* 按下右键后的操作  */
void unit(uchar,uchar,uchar);  /* 画一个小方块  */

void score();/* 计算并显示得分  */
void dl(int);  /* 进行延时  */

void save1();/* 保存当前状态  */
void load1();/* 加载上一次保存的状态  */

void save(); /* 保存分数  */

main()
{
    int driver=VGA,mode=VGAHI;
    unsigned char ss[8];


    initgraph(&driver,&mode,"c://tc");/*图形模式初始化*/


    setfillstyle(1,8);/*设置填充模式*/
    setcolor(8);/*设置颜色*/
    bar(2,2,600,400);/*按设置的模式，画一个长方形*/

    setfillstyle(1,7);
    setcolor(7);
    bar(117,117,170,140);


    setfillstyle(1,8);
    setcolor(8);
    bar(118,118,170,140);


    setcolor(14);
    /* settextstyle(2,0,5);*/
    sprintf(ss,"enter");
    outtextxy(120,125,ss);/*在指定位置显示指定的字符串*/

    setcolor(0);
    line(118,141,171,141);/* 画一条线 */
    line(118,142,172,142);
    line(171,118,171,141);
    line(172,118,172,142);



    /*  画出3个选项，提供速度选择：快速，正常，慢速。使用Tab键进行切换选项。 */
    setfillstyle(1,14);
    setcolor(14);

    circle(15,15,10);
    sprintf(ss,"  fast");     /* 画一个圆－－代表单选框，右边标注“fast” */
    outtextxy(30,15,ss);
    circle(15,55,10);
    sprintf(ss,"  normol");/* 画一个圆－－代表单选框，右边标注“normol” */
    outtextxy(30,55,ss);
    circle(15,95,10);
    sprintf(ss,"  slow");/* 画一个圆－－代表单选框，右边标注“slow” */
    outtextxy(30,95,ss);
    circle(15,15,6);
    floodfill(15,15,14);
    xisu=0;

    do
    {
        a=getch();/* 等待用户键入 */


        if(a==9)        /* Tab  ：使用Tab键切换速度选项 */
        {
            setcolor(14);
            setfillstyle(1,14);
            a=8;
            xisu++;
            circle(15,15+(xisu%3)*40,6);
            floodfill(15,15+(xisu%3)*40,14);
            setfillstyle(1,7);
            setcolor(7);
            circle(15,15+((xisu-1)%3)*40,6);
            floodfill(15,15+((xisu-1)%3)*40,7);
        }
        if((a==76)||(a==108))       /* 'L'or'l' ：加载上一次保存的状态 */
        {
            load1();
            xisu=2;
            goto LOOP;/* 直接跳转到运行界面 */
        }
    }
    while(a!=13);/* 收到回车键，确认速度选项，进入下一个界面 */

    setcolor(8);
    line(118,141,171,141);
    line(171,118,171,141);
    dl(speed);

    p2=(struct list *)malloc(LEN);
    hit=1;          /* head of snake */
    p1=p2;
    head=p2;
    p2->x=20;
    p2->y=20;
    p2->last=NULL;
    p2->next=NULL;
    rectangle(0,0,600,450);
    setfillstyle(1,0);
    setcolor(0);
    bar(1,1,599,449);
    setfillstyle(1,14);
    setcolor(14);
    speed=speed*(xisu%3+1);/* 根据系数计算速度 */

    for(i=0; i<15; i++)                             /* 创建16个块－－初始的蛇体 */
    {
        p2=(struct list *)malloc(LEN);
        p2->x=21+i;
        p2->y=20;
        unit(21+i,20,14);
        p1->next=p2;
        p2->last=p1;
        p2->next=NULL;
        eof1=p2;
        p1=p2;
    }

    unit(head->x,head->y,14);



LOOP:
    while(1)  /* 主循环 */
    {
        if(hit==1)      /* 创建一个随机点，即贪吃蛇的食物*/
        {
            randomize();

            x1=random(30);
            y1=random(20);
            x1=x1+3;
            y1=y1+3;
            p2=head;
            p1=p2;

            while(p1->next!=NULL)
            {
                if((x1==p2->x)&&(y1==p2->y))  /* 创建的食物不能在蛇体上 */
                {
                    x1=random(30)+3;
                    y1=random(20)+3;
                    p2=head;
                    p1=p2;
                } /* if in,new */
                else
                {
                    p1=p2;
                    p2=p1->next;
                }
            }

            unit(x1,y1,14);
            hit=0;
        }

        if(kbhit()!=0)/* 是否有键按下 */
            a=getch();/* 读取用户键入 */

        switch(a)                /* 根据用户按键，进行相应处理 */
        {
        case 72 :
            up();
            break;
        case 80 :
            down();
            break;
        case 75 :
            left();
            break;
        case 77 :
            right();
            break;
        case 83 :
        case 115:
            dl(500);
            save1();
            break;  /*'S'or's' save status and exit */
        }

        if(cycy==1)/* 若设置了退出标志，退出 */
            break;
    }


    do
    {
        a=getch();
    }
    while((a>14)||(a<13));    /* 当用户键入回车，退出*/

    closegraph();/* 关闭图形模式 */
}


void up(void)/* 按下上键后的操作  */
{
    p2=head->next;
    p1=p2;

    while(p1->next!=NULL)
    {
        if((head->x==p2->x)&&(head->y-1==p2->y)) /*如果撞上自己的身体，记分并设置退出标志 */
        {
            score();
            break;
        }
        else
        {
            p1=p2;
            p2=p1->next;
        }
    }

    if((hit==0)&&(head->x==x1)&&(head->y-1==y1))  /* 如果吃了食物，身体加长－－所吃的点成为新的蛇头 */
    {
        p2=(struct list *)malloc(LEN);
        p2->x=x1;
        p2->y=y1;
        p2->next=head;
        head->last=p2;
        head=p2;
        hit=1;
        long1++;
    }
    else
    {
        p2=eof1;
        eof1=p2->last;
        /*p2->last=NULL;*/
        eof1->next=NULL; /* eof1 disappear,head add 1 unit */
        unit(p2->x,p2->y,0);/* 消除最后面的点*/

        p2->x=head->x;
        p2->y=head->y-1;
        p2->next=head;
        head->last=p2;
        head=p2;
        head->last=NULL;
        unit(p2->x,p2->y,14);/* 画最前面的点*/
        if(p2->y<1)/* 如果撞到顶，记分并设置退出标志 */
            score();
    }
    dl(speed);
}


void down(void)/* 按下下键后的操作  */
{
    p2=head->next;
    p1=p2;
    while(p1->next!=NULL)
    {
        if((head->x==p2->x)&&(head->y+1==p2->y))  /*如果撞上自己的身体，记分并设置退出标志 */

        {
            score();
            break;
        }
        else
        {
            p1=p2;
            p2=p1->next;
        }
    }
    if((hit==0)&&(head->x==x1)&&(head->y+1==y1))  /* 如果吃了食物，身体加长－－所吃的点成为新的蛇头 */

    {
        p2=(struct list *)malloc(LEN);
        p2->x=x1;
        p2->y=y1;
        p2->next=head;
        head->last=p2;
        head=p2;
        hit=1;
        long1++;
    }
    else
    {
        p2=eof1;
        eof1=p2->last;
        eof1->next=NULL;
        unit(p2->x,p2->y,0);/* 消除最后面的点*/

        p2->next=head;
        head->last=p2;
        p2->x=head->x;
        p2->y=head->y+1;
        head=p2;
        head->last=NULL;
        unit(p2->x,p2->y,14);/* 画最前面的点*/
        if(p2->y>=30)             /* 如果撞到边界，记分并设置退出标志 */
            score();
    }
    dl(speed);/* 按照速度选项进行延时 */
}

void left(void)/* 按下左键后的操作  */
{
    p2=head->next;
    p1=p2;
    while(p1->next!=NULL)
    {
        if((head->x-1==p2->x)&&(head->y==p2->y))/*如果撞上自己的身体，记分并设置退出标志 */
        {
            score();
            break;
        }
        else
        {
            p1=p2;
            p2=p1->next;
        }
    }

    if((hit==0)&&(head->x-1==x1)&&(head->y==y1))/* 如果吃了食物，身体加长－－所吃的点成为新的蛇头 */
    {
        p2=(struct list *)malloc(LEN);
        p2->x=x1;
        p2->y=y1;
        p2->next=head;
        head->last=p2;
        head=p2;
        hit=1;
        long1++;
    }
    else
    {
        p2=eof1;
        eof1=p2->last;
        eof1->next=NULL;
        unit(p2->x,p2->y,0);/* 消除最后面的点*/

        p2->next=head;
        head->last=p2;
        p2->x=head->x-1;
        p2->y=head->y;
        head=p2;
        head->last=NULL;
        unit(p2->x,p2->y,14);/* 画最前面的点*/

        if(p2->x<1)/* 如果撞到边界，记分并设置退出标志 */
            score();
    }
    dl(speed);/* 按照速度选项进行延时 */
}


void right(void)/* 按下右键后的操作  */
{
    p2=head->next;
    p1=p2;
    while(p1->next!=NULL)
    {
        if((head->x+1==p2->x)&&(head->y==p2->y))/*如果撞上自己的身体，记分并设置退出标志 */
        {
            score();
            break;
        }
        else
        {
            p1=p2;
            p2=p1->next;
        }
    }
    if((hit==0)&&(head->x+1==x1)&&(head->y==y1))/* 如果吃了食物，身体加长－－所吃的点成为新的蛇头 */
    {
        p2=(struct list *)malloc(LEN);
        p2->x=x1;
        p2->y=y1;
        p2->next=head;
        head->last=p2;
        head=p2;
        hit=1;
        long1++;
    }
    else
    {
        p2=eof1;
        eof1=p2->last;
        eof1->next=NULL;
        unit(p2->x,p2->y,0);/* 消除最后面的点*/

        p2->next=head;
        head->last=p2;
        p2->x=head->x+1;
        p2->y=head->y;
        head=p2;
        head->last=NULL;
        unit(p2->x,p2->y,14);/* 画最前面的点*/
        if(p2->x>=40)/* 如果撞到边界，记分并设置退出标志 */
            score();
    }
    dl(speed);/* 按照速度选项进行延时 */
}

void dl(int a)/* 进行延时  */
{
    int r,n;
    for(r=0; r<a; r++)
        for(n=0; n<6000; n++)
        {
            n++;
            n--;
        }
}

void unit(uchar x,uchar y,uchar color)/* 画一个小方块  */
{
    setfillstyle(1,color);
    setcolor(color);
    bar(x*15,y*15,(x+1)*15-2,(y+1)*15-2);
}

void score(void)/* 计算并显示得分  */
{
    uchar ss[20];

    if(long1>50)
        sco=(long1-50)*3+(long1-30)*2+14;
    else if(long1>30)
        sco=(long1-30)*2+14;
    else
        sco=long1-16;

    sprintf(ss,"your score is %d",sco);
    outtextxy(50,50,ss);
    cycy=1;

    save();

}

void save(void)/* 保存分数  */
{
    FILE * fp;
    int i;
    i=0;
    fp=fopen("snascore.txt","rb+");
    i=(int)(fgetc(fp))-48;
    if(fp==NULL)
        i=0;
    fclose(fp);

    if(i<sco)
    {
        fp=fopen("snascore.txt","wb+");
        fprintf(fp,"%d",sco);
        fclose(fp);
        printf("/n");
        printf("Your score: %d are the highest!",sco);
    }
    /* getch();*/
}

void save1()/* 保存当前状态  */
{
    FILE *fl1;
    i=0;
    dl(1500);
    p1=head;
    p2=p1;
    while(p1!=NULL)
    {
        str1[i]=(char)(p1->x+30);
        str1[i+1]=(char)(p1->y+30);
        i=i+2;
        p2=p1;
        p1=p2->next;
    }
    dl(1500);

    fl1=fopen("snasave.txt","w+");
    if(fl1!=NULL)
    {
        fwrite(str1,i,1,fl1);
        dl(1500);
        fclose(fl1);
    }
    else
        printf("bad/n");

    dl(1500);
    cycy=1;
}

void load1()/* 加载上一次保存的状态  */
{
    FILE *fl1;
    int cc;
    i=0;
    fl1=fopen("snasave.txt","r");
    if(fl1!=NULL)
    {
        fseek(fl1,0,SEEK_SET);
        while(feof(fl1)==0)
        {
            str1[i++]=fgetc(fl1);
        }
        cc=i-1;
        /* fread(str1,200,1,fl1);*/
        cc=ftell(fl1);
        fclose(fl1);
    }
    else
        printf("bad/n");

    setcolor(8);
    line(118,141,171,141);
    line(171,118,171,141);
    dl(speed);

    p2=(struct list *)malloc(LEN);
    hit=1;
    p1=p2;
    head=p2;
    p2->x=(int)(str1[0])-30;
    p2->y=(int)(str1[1])-30;
    p2->last=NULL;
    p2->next=NULL;
    rectangle(0,0,600,450);
    setfillstyle(1,0);
    setcolor(0);
    bar(1,1,599,449);
    setfillstyle(1,14);
    setcolor(14);
    xisu=1;
    speed=speed*(xisu%3+1);

    for(i=2; i<cc; i+=2)
    {
        p2=(struct list *)malloc(LEN);
        p2->x=(int)(str1[i])-30;
        p2->y=(int)(str1[i+1])-30;
        unit(p2->x,p2->y,14);
        p1->next=p2;
        p2->last=p1;
        p2->next=NULL;
        eof1=p2;
        p1=p2;
    }
    long1=cc/2;
    unit(head->x,head->y,14);

}
