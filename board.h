#ifndef BOARD_H
#define BOARD_H

#include <QDialog>
#include <iostream>
#include <vector>
#include <QMouseEvent>
#include <QPoint>
#include "piece.h"
#include "chessboard.h"
#include <utility>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QBitmap>
#include <QLabel>
#include <QThread>
#include <QString>

namespace Ui {
class board;
}

class board : public QDialog
{
    Q_OBJECT

public:
    explicit board(QWidget *parent = nullptr);
    ~board();


private:
    void initLabels();
    std::vector<std::vector<QLabel*>> labelArr;
    std::pair<int,int> start,finish;
    QPoint pos;
    std::pair<int,int> cord();
    bool odd=false;
    void mousePressEvent(QMouseEvent *event) override;
    void rightClick();
    void leftClick();
    void makeTurn();
    Ui::board *ui;
    bool white=true;
    std::vector<std::vector<figure>> oldvec;
    std::vector<std::vector<int>> inttable;
    int ourpiece;
    int x1,x2,y1,y2,check;
    ChessTable table,basictable;
    void showBoard();
    void setPicture(int i ,int j);
    QGraphicsScene scene;





};




#endif // BOARD_H
