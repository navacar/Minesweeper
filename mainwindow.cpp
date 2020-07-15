#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <iostream>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui (new Ui::MainWindow)
{
    int i,j;

    for(i=0;i<16 ;i++ ){

        for(j=0; j<30; j++){

            board[i][j].Plitka = QImage(":/ABC/images/j10.gif");
            board[i][j].Bomba = QImage(":/ABC/images/j9.gif");
            board[i][j].PustayaPlitka = QImage(":/ABC/images/j0.gif");
            board[i][j].FlagImage = QImage(":/ABC/images/j11.gif");
            board[i][j].FlagImage2 = QImage(":/ABC/images/j12.gif");
            board[i][j].Odin = QImage(":/ABC/images/j1.gif");
            board[i][j].Dva = QImage(":/ABC/images/j2.gif");
            board[i][j].Tree = QImage(":/ABC/images/j3.gif");
            board[i][j].Chetire = QImage(":/ABC/images/j4.gif");
            board[i][j].Pyt = QImage(":/ABC/images/j5.gif");
            board[i][j].Shest = QImage(":/ABC/images/j6.gif");
            board[i][j].Sem = QImage(":/ABC/images/j7.gif");
            board[i][j].Vosem = QImage(":/ABC/images/j8.gif");

        }
    }


    ui->setupUi(this);
    connect(ui->actionSmall, SIGNAL(triggered(bool)),this, SLOT(SlotMenuItem()));
    connect(ui->actionMedium, SIGNAL(triggered(bool)),this, SLOT(SlotMenuItem()));
    connect(ui->actionLarge, SIGNAL(triggered(bool)),this, SLOT(SlotMenuItem()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::Cifra(int A,int B){
    int k=0;

    if (board[A-1][B].EstMina==true){
       k++;
    }

    if (board[A-1][B-1].EstMina==true){
       k++;
    }

    if (board[A][B-1].EstMina==true){
       k++;
    }

    if (board[A+1][B].EstMina==true){
       k++;
    }

    if (board[A+1][B+1].EstMina==true){
       k++;
    }

    if (board[A][B+1].EstMina==true){
       k++;
    }

    if (board[A+1][B-1].EstMina==true){
       k++;
    }

    if (board[A-1][B+1].EstMina==true){
       k++;
    }
    return k;
}

bool MainWindow::Pusto(int A, int B){
    int k=0;
    k=Cifra(A, B);

    if ((k==0)&&(board[A][B].EstMina==false)&&(board[A][B].Flag==false)){

        return true;

    }

    else{

        return false;
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int k=0;

    if (Trigger==0){

        for (i=0; i<16; i++){

            for (j=0; j<30;j ++){

                board[i][j].EstMina=false;
                board[i][j].Press=false;
                board[i][j].PP=false;
                board[i][j].Flag=false;
                board[i][j].DeleteFlag=false;
                board[i][j].marked=false;
            }
        }
    }
    if (Trigger==1){

        for (i=0; i<16; i++){

            for (j=0; j<30;j ++){

                painter.drawImage(i*15, j*15, board[i][j].Plitka);

                if (board[i][j].Press==true){

                    if(board[i][j].EstMina==true)

                        painter.drawImage(i*15, j*15, board[i][j].Bomba);

                    else{

                        k=Cifra(i,j);

                        switch(k){

                        case 0:

                            painter.drawImage(i*15, j*15, board[i][j].PustayaPlitka);

                            break;

                        case 1:
                            painter.drawImage(i*15, j*15, board[i][j].Odin);
                            break;

                        case 2:

                            painter.drawImage(i*15, j*15, board[i][j].Dva);
                            break;

                        case 3:

                            painter.drawImage(i*15, j*15, board[i][j].Tree);
                            break;

                        case 4:

                            painter.drawImage(i*15, j*15, board[i][j].Chetire);
                            break;

                        case 5:

                            painter.drawImage(i*15, j*15, board[i][j].Pyt);
                            break;

                        case 6:

                            painter.drawImage(i*15, j*15, board[i][j].Shest);
                            break;

                        case 7:

                            painter.drawImage(i*15, j*15, board[i][j].Sem);
                            break;

                        case 8:
                            painter.drawImage(i*15, j*15, board[i][j].Vosem);

                        }

                    }

                }

            }
        }
    }
    if (Trigger==2){

        for (i=0; i<16; i++){

            for (j=0; j<16;j ++){

                painter.drawImage(i*15, j*15, board[i][j].Plitka);

                if (board[i][j].Press==true){

                    if(board[i][j].EstMina==true)

                        painter.drawImage(i*15, j*15, board[i][j].Bomba);

                    else{

                        k=Cifra(i,j);

                        switch(k){

                        case 0:

                            painter.drawImage(i*15, j*15, board[i][j].PustayaPlitka);

                            break;

                        case 1:
                            painter.drawImage(i*15, j*15, board[i][j].Odin);
                            break;

                        case 2:

                            painter.drawImage(i*15, j*15, board[i][j].Dva);
                            break;

                        case 3:

                            painter.drawImage(i*15, j*15, board[i][j].Tree);
                            break;

                        case 4:

                            painter.drawImage(i*15, j*15, board[i][j].Chetire);
                            break;

                        case 5:

                            painter.drawImage(i*15, j*15, board[i][j].Pyt);
                            break;

                        case 6:

                            painter.drawImage(i*15, j*15, board[i][j].Shest);
                            break;

                        case 7:

                            painter.drawImage(i*15, j*15, board[i][j].Sem);
                            break;

                        case 8:
                            painter.drawImage(i*15, j*15, board[i][j].Vosem);

                        }

                    }

                }
            }
        }
    }
    if (Trigger==3){
        for (i=0; i<9; i++){

            for (j=0; j<9;j ++){

                painter.drawImage(i*15, j*15, board[i][j].Plitka);

                if (board[i][j].Press==true){

                    if(board[i][j].EstMina==true)

                        painter.drawImage(i*15, j*15, board[i][j].Bomba);

                    else{

                        k=Cifra(i,j);

                        switch(k){

                        case 0:

                           painter.drawImage(i*15, j*15, board[i][j].PustayaPlitka);

                            break;

                        case 1:
                            painter.drawImage(i*15, j*15, board[i][j].Odin);
                            break;

                        case 2:

                            painter.drawImage(i*15, j*15, board[i][j].Dva);
                            break;

                        case 3:

                            painter.drawImage(i*15, j*15, board[i][j].Tree);
                            break;

                        case 4:

                            painter.drawImage(i*15, j*15, board[i][j].Chetire);
                            break;

                        case 5:

                            painter.drawImage(i*15, j*15, board[i][j].Pyt);
                            break;

                        case 6:

                            painter.drawImage(i*15, j*15, board[i][j].Shest);
                            break;

                        case 7:

                            painter.drawImage(i*15, j*15, board[i][j].Sem);
                            break;

                        case 8:
                            painter.drawImage(i*15, j*15, board[i][j].Vosem);

                        }
                    }

                }
            }
        }
    }

    for (i=0; i<16; i++){

        for (j=0; j<30;j ++){

            if (board[i][j].Flag==true&&board[i][j].PP==false){

                painter.drawImage(i*15, j*15, board[i][j].FlagImage);

            }

            if (board[i][j].DeleteFlag==true&&board[i][j].PP==false){

                painter.drawImage(i*15, j*15, board[i][j].Plitka);
                board[i][j].DeleteFlag=false;
                board[i][j].Flag=false;
            }

            if(board[i][j].PP==true){
                board[i][j].DeleteFlag=false;
                board[i][j].Flag=false;
            }

        }
    }

    if (FlagTrigger==1){

        for (i=0; i<16; i++){

            for (j=0; j<30;j ++){

                if(board[i][j].Flag==true){

                    if(board[i][j].EstMina==true&&board[i][j].Flag==true){

                        count2++;
                        painter.drawImage(i*15,j*15,board[i][j].FlagImage2);

                    }
                }

            }
        }

    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    int x,y;
    x=event->x();
    y=event->y();

    i=x/15;
    j=y/15;
    //qDebug("%d", Pusto(i,j));

    if (OSTANOVKA==0){
        if (event->button()==Qt::RightButton){

            if (board[i][j].Flag==true){

                board[i][j].DeleteFlag=true;


            }
            else{

              board[i][j].Flag=true;

            }
        }
     else{
            if(board[i][j].EstMina!=true){

         //board[i][j].Press=true;
         wave(i,j);
            if (board[i][j].PP==false)

             count++;

            board[i][j].PP=true;

         }


         else{

                if(board[i][j].EstMina==true&&board[i][j].Flag==true){
                    count2++;
             }

                FlagTrigger=1;
             board[i][j].Press=true;
                qDebug("GAME OVER!");
                //qDebug("Вы открыли %d полей и раз минировали %d мин!", count, count2); // Требует дороботки
                count=0;
             setFixedSize(1075,650);
             OSTANOVKA=1;

     }

        }
    }

    repaint();
    FlagTrigger=0;
    count2=0;

}

void MainWindow::SlotMenuItem()
{

    QAction *obj = (QAction*)sender();

    if (obj==ui->actionLarge) // Поле 16х30 и 99 мин
    {
        OSTANOVKA=0;
        Trigger=0;
        //qDebug("Нажата кнопка Большой");
        setFixedSize(240,450);
        repaint();
        Trigger=1;
        heightCell=16;
        weightCell=30;

        for (int k=0; k<99; k++){

            i = rand() % 16;
            j = rand() % 30;

            if(board[i][j].EstMina==false){

                board[i][j].EstMina=true;

            }

            else{

                while(board[i][j].EstMina==true){

                    i = rand() % 16;
                    j = rand() % 30;

                }

                board[i][j].EstMina=true;
                //count++;
            }
        }

        repaint();

    }

    if (obj==ui->actionMedium) // Поле 16х16 и 40 мин
    {
        OSTANOVKA=0;
        //qDebug("Нажата кнопка Средний");
        Trigger=0;
        setFixedSize(240,240);
        repaint();
        Trigger=2;
        heightCell=16;
        weightCell=16;

        for (int k=0; k<40; k++){

            i = rand() % 16;
            j = rand() % 16;


            if(board[i][j].EstMina==false){

                board[i][j].EstMina=true;

            }

            else{

                while(board[i][j].EstMina==true){

                    i = rand() % 16;
                    j = rand() % 16;

                }

                board[i][j].EstMina=true;

            }
        }
        repaint();

    }

    if (obj==ui->actionSmall) // Поле размером 9х9 на котором разбросаны 10 мин
    {
        OSTANOVKA=0;
        Trigger=0;
        setFixedSize(135, 135);
        repaint();
        Trigger=3;
        heightCell=9;
        weightCell=9;

        for (int k=0; k<9; k++){

            i = rand() % 9;
            j = rand() % 9;

            if(board[i][j].EstMina==false){

                board[i][j].EstMina=true;

            }

            else{

                while(board[i][j].EstMina==true){
                    i = rand() % 9;
                    j = rand() % 9;
                }

                board[i][j].EstMina=true;

            }
        }
        repaint();

    }
}

void MainWindow::wave(int A, int B){
    int k=0;

    k=Cifra(A,B);

    if(board[A][B].marked==true)
        return;

    board[A][B].marked=true;
    board[A][B].Press=true;

    if(k!=0)
        return;

    for(int g=A-1; g<=A+1; g++){

        for(int h=B-1; h<=B+1; h++){

            if(g==-1||g==heightCell||h==-1||h==weightCell||(g==A&&h==B))
                continue;
            wave(g, h);
        }


    }

}
