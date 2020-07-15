#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QImage>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    int Cifra(int A, int B);
    bool Pusto(int A, int B);
    void wave(int A, int B);

public slots:
    void SlotMenuItem();

private:
    int Trigger=0, FlagTrigger=0, count=0, count2=0, heightCell=0, weightCell=0, OSTANOVKA=0;
    int i=0,j=0;
    Ui::MainWindow *ui;
    struct Kletka{

           QImage Bomba;
           QImage Plitka;
           QImage PustayaPlitka;
           QImage FlagImage;
           QImage FlagImage2;
           QImage Odin;
           QImage Dva;
           QImage Tree;
           QImage Chetire;
           QImage Pyt;
           QImage Shest;
           QImage Sem;
           QImage Vosem;
           bool EstMina;
           bool Press;
           bool PP;
           bool Flag, DeleteFlag;
           bool marked;

    };
    Kletka board[16][30];
};
#endif // MAINWINDOW_H
