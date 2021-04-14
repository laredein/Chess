#include "board.h"
#include "ui_board.h"

board::board(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::board)
{
    std::vector<std::vector<figure>> oldvec;
    std::vector<std::vector<int>> inttable;
    ChessTable table,basictable;



    ui->setupUi(this);
    initLabels();
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            labelArr[i][j]->show();
        }
    }

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setStyleSheet( "background-image:url(:/board.png);" );
    setFixedSize(800,800);
    showBoard();
}

void board::showBoard()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            setPicture(i,j);
        }
    }
}

void board::setPicture(int i, int j)
{
    figure* curfig=&table.vec[i][j];
    std::string imagename;
    if (antienum(curfig->piece)!="  ")
    {
        imagename=":/pieceimages/"+antienum(curfig->piece)+".png";
    }
    else if ((i+j)%2==0)
    {
        imagename=":/pieceimages/wsquare.png";
    }
    else
    {
        imagename=":/pieceimages/bsquare.png";
    }
    QPixmap pixmap(QString::fromStdString(imagename));
    labelArr[i][j]->setPixmap(pixmap);
    labelArr[i][j]->setMask(pixmap.mask());
}

board::~board()
{
    delete ui;
}

void board::leftClick()
{
    if (odd==false)
    {
        start=cord();
        odd=!odd;
    }
    else if (odd==true)
    {
        finish=cord();
        odd=!odd;
    }

}

void board::rightClick()
{
    odd=false;
}


void board::mousePressEvent(QMouseEvent *event)
{
    pos=QWidget::mapFromGlobal(QCursor::pos());
    if (event->button()==Qt::RightButton)
    {
        rightClick();
    }
    else if (event->button()==Qt::LeftButton)
    {
        if (odd==true)
        {
            leftClick();
            makeTurn();
        }
        else
        {
            leftClick();
        }

    }
}

std::pair<int,int> board::cord()
{
    int x,y;
    y=pos.x()/100;
    x=pos.y()/100;


    return std::make_pair(x,y);
}

void board::makeTurn()
{
    showBoard();
    if (table.checkMate(white))
    {
        this->close();
    }
    x1=start.first;
    y1=start.second;
    x2=finish.first;
    y2=finish.second;
    oldvec=table.vec;
    if ((table.vec[x1][y1].cost()/10!=2 && white==false) || (table.vec[x1][y1].cost()/10!=1 && white==true))
        std::cout<<"unacceptable move"<<std::endl;
    else
    {
        bool realmove=true;
        ourpiece=table.vec[x1][y1].cost();
        std::vector<std::vector<figure>> oldtable=table.vec;
        if (ourpiece%10==1)
        {
            table.vec=table.vec[x1][y1].rookmove(table.vec,x2,y2);
        }
        if (ourpiece%10==2)
        {
            table.vec=table.vec[x1][y1].knightmove(table.vec,x2,y2);
        }
        if (ourpiece%10==3)
        {
            table.vec=table.vec[x1][y1].bishopmove(table.vec,x2,y2);
        }
        if (ourpiece%10==5)
        {
            table.vec=table.vec[x1][y1].queenmove(table.vec,x2,y2);
        }
        if (ourpiece==10)
        {
            table.vec=table.vec[x1][y1].wpawnmove(table.vec,x2,y2);
        }
        if (ourpiece==20)
        {
            table.vec=table.vec[x1][y1].bpawnmove(table.vec,x2,y2);
        }
        if (ourpiece%10==4)
        {
            table.vec=table.vec[x1][y1].kingmove(table.vec,x2,y2);
            table.king(white);
        }

        if (white==true && table.checkToKings().first==true)
        {
            table.vec=oldtable;
        }
        else if (white==false && table.checkToKings().second==true)
        {
            table.vec=oldtable;
        }
        realmove=(table.vec[x1][y1].cost()!=oldvec[x1][y1].cost());
        if (realmove==false)
        {
            std::cout<<"unacceptable move"<<std::endl;
        }
        else
        {
            white=!white;
        }

        showBoard();
    }
}




void board::initLabels()
{
    labelArr.resize(8);
    for(int i=0;i<8;i++)
        labelArr[i].resize(8);
    labelArr[0][0]=ui->label00;
    labelArr[0][1]=ui->label01;
    labelArr[0][2]=ui->label02;
    labelArr[0][3]=ui->label03;
    labelArr[0][4]=ui->label04;
    labelArr[0][5]=ui->label05;
    labelArr[0][6]=ui->label06;
    labelArr[0][7]=ui->label07;
    labelArr[1][0]=ui->label10;
    labelArr[1][1]=ui->label11;
    labelArr[1][2]=ui->label12;
    labelArr[1][3]=ui->label13;
    labelArr[1][4]=ui->label14;
    labelArr[1][5]=ui->label15;
    labelArr[1][6]=ui->label16;
    labelArr[1][7]=ui->label17;
    labelArr[2][0]=ui->label20;
    labelArr[2][1]=ui->label21;
    labelArr[2][2]=ui->label22;
    labelArr[2][3]=ui->label23;
    labelArr[2][4]=ui->label24;
    labelArr[2][5]=ui->label25;
    labelArr[2][6]=ui->label26;
    labelArr[2][7]=ui->label27;
    labelArr[3][0]=ui->label30;
    labelArr[3][1]=ui->label31;
    labelArr[3][2]=ui->label32;
    labelArr[3][3]=ui->label33;
    labelArr[3][4]=ui->label34;
    labelArr[3][5]=ui->label35;
    labelArr[3][6]=ui->label36;
    labelArr[3][7]=ui->label37;
    labelArr[4][0]=ui->label40;
    labelArr[4][1]=ui->label41;
    labelArr[4][2]=ui->label42;
    labelArr[4][3]=ui->label43;
    labelArr[4][4]=ui->label44;
    labelArr[4][5]=ui->label45;
    labelArr[4][6]=ui->label46;
    labelArr[4][7]=ui->label47;
    labelArr[5][0]=ui->label50;
    labelArr[5][1]=ui->label51;
    labelArr[5][2]=ui->label52;
    labelArr[5][3]=ui->label53;
    labelArr[5][4]=ui->label54;
    labelArr[5][5]=ui->label55;
    labelArr[5][6]=ui->label56;
    labelArr[5][7]=ui->label57;
    labelArr[6][0]=ui->label60;
    labelArr[6][1]=ui->label61;
    labelArr[6][2]=ui->label62;
    labelArr[6][3]=ui->label63;
    labelArr[6][4]=ui->label64;
    labelArr[6][5]=ui->label65;
    labelArr[6][6]=ui->label66;
    labelArr[6][7]=ui->label67;
    labelArr[7][0]=ui->label70;
    labelArr[7][1]=ui->label71;
    labelArr[7][2]=ui->label72;
    labelArr[7][3]=ui->label73;
    labelArr[7][4]=ui->label74;
    labelArr[7][5]=ui->label75;
    labelArr[7][6]=ui->label76;
    labelArr[7][7]=ui->label77;

}
