#include "chessboard.h"

        ChessTable::ChessTable()
        {
            std::vector<figure> vec_;
                vec_.push_back(figure(0,0,wrook));
                vec_.push_back(figure(0,1,wknight));
                vec_.push_back(figure(0,2,wbishop));
                vec_.push_back(figure(0,3,wking,false));
                vec_.push_back(figure(0,4,wqueen));
                vec_.push_back(figure(0,5,wbishop));
                vec_.push_back(figure(0,6,wknight));
                vec_.push_back(figure(0,7,wrook));
                vec.push_back(vec_);
                vec_={};
                for(int j=0;j<8;j++){
                    vec_.push_back(figure(1,j,wpawn));}
                vec.push_back(vec_);
                vec_={};
                for (int i=2;i<6;i++){
                    for(int j=0;j<8;j++){
                        vec_.push_back(figure(i,j,space));}
                        vec.push_back(vec_);
                        vec_={};}
                for(int j=0;j<8;j++){
                    vec_.push_back(figure(6,j,bpawn));}
                vec.push_back(vec_);
                vec_={};
                vec_.push_back(figure(7,0,brook));
                vec_.push_back(figure(7,1,bknight));
                vec_.push_back(figure(7,2,bbishop));
                vec_.push_back(figure(7,3,bking,false));
                vec_.push_back(figure(7,4,bqueen));
                vec_.push_back(figure(7,5,bbishop));
                vec_.push_back(figure(7,6,bknight));
                vec_.push_back(figure(7,7,brook));
                vec.push_back(vec_);
                vec_={};
                }
        void ChessTable::king(bool white){
            if (white==true){
                for (int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        if (vec[i][j].cost()==14){
                            whiteking=vec[i][j];
                            break;}}}}
            if (white==false){
                for (int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        if (vec[i][j].cost()==24){
                            blackking=vec[i][j];
                            break;}}}}}
        std::pair<bool,bool> ChessTable::checkToKings()
        {
            std::vector<std::vector<figure>> checkvector=vec;
            int ourpiece;
            int bcheck=0;
            int wcheck=0;
            int x1=whiteking.xcord,y1=whiteking.ycord,x2=blackking.xcord,y2=blackking.ycord;

            for(int i=0;i<8;i++){

                for(int j=0;j<8;j++)
                {
                    ourpiece=vec[i][j].cost();
                    if (ourpiece/10==1)
                    {
                        if (ourpiece%10==1){
                            bcheck=bcheck+(vec[x2][y2].cost()!=checkvector[i][j].rookmove(checkvector,x2,y2)[x2][y2].cost());

                        }
                        if (ourpiece%10==2){
                            bcheck=bcheck+(vec[x2][y2].cost()!=checkvector[i][j].knightmove(checkvector,x2,y2)[x2][y2].cost());
                        }
                        if (ourpiece%10==3){
                            bcheck=bcheck+(vec[x2][y2].cost()!=checkvector[i][j].bishopmove(checkvector,x2,y2)[x2][y2].cost());

                        }
                        if (ourpiece%10==5){
                            bcheck=bcheck+(vec[x2][y2].cost()!=checkvector[i][j].queenmove(checkvector,x2,y2)[x2][y2].cost());
                        }
                        if (ourpiece==10){
                            bcheck=bcheck+(vec[x2][y2].cost()!=checkvector[i][j].wpawnmove(checkvector,x2,y2,wqueen)[x2][y2].cost());

                        }
                        if (ourpiece%10==4){
                            bcheck=bcheck+(vec[x2][y2].cost()!=checkvector[i][j].kingmove(checkvector,x2,y2)[x2][y2].cost());
                        }
                    }
                    if (ourpiece/10==2)
                    {
                        if (ourpiece%10==1){
                            wcheck=wcheck+(vec[x1][y1].cost()!=checkvector[i][j].rookmove(checkvector,x1,y1)[x1][y1].cost());
                        }
                        if (ourpiece%10==2){
                            wcheck=wcheck+(vec[x1][y1].cost()!=checkvector[i][j].knightmove(checkvector,x1,y1)[x1][y1].cost());
                        }
                        if (ourpiece%10==3){
                            wcheck=wcheck+(vec[x1][y1].cost()!=checkvector[i][j].bishopmove(checkvector,x1,y1)[x1][y1].cost());
                        }
                        if (ourpiece%10==5){
                            wcheck=wcheck+(vec[x1][y1].cost()!=checkvector[i][j].queenmove(checkvector,x1,y1)[x1][y1].cost());
                        }
                        if (ourpiece==20){
                            wcheck=wcheck+(vec[x1][y1].cost()!=checkvector[i][j].bpawnmove(checkvector,x1,y1,bqueen)[x1][y1].cost());
                        }
                        if (ourpiece%10==4){
                            wcheck=wcheck+(vec[x1][y1].cost()!=checkvector[i][j].kingmove(checkvector,x1,y1)[x1][y1].cost());
                        }
                    }
                }
            }
            return std::make_pair((wcheck>0),(bcheck>0));
        }

///8^6
bool ChessTable::checkMate(bool white)
{
    auto oldvec=vec;
    if (white)
    {
        if (checkToKings().first==false)
            return false;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                int ourpiece=vec[i][j].cost();
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {

                        if (ourpiece==11)
                        {
                            vec=vec[i][j].rookmove(vec,k,l);
                        }
                        if (ourpiece==12)
                        {
                            vec=vec[i][j].knightmove(vec,k,l);
                        }
                        if (ourpiece==13)
                        {
                            vec=vec[i][j].bishopmove(vec,k,l);
                        }
                        if (ourpiece==15)
                        {
                            vec=vec[i][j].queenmove(vec,k,l);
                        }
                        if (ourpiece==10)
                        {
                            vec=vec[i][j].wpawnmove(vec,k,l,bqueen);
                        }
                        if (ourpiece==14)
                        {
                            vec=vec[i][j].kingmove(vec,k,l);
                        }
                        if (checkToKings().first==false)
                        {
                            vec=oldvec;
                            return false;
                        }
                        vec=oldvec;
                    }
                }
            }
        }
    }
    else
    {
        if (checkToKings().second==false)
            return false;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                int ourpiece=vec[i][j].cost();
                for(int k=0;k<8;k++)
                {
                    for(int l=0;l<8;l++)
                    {

                        if (ourpiece==21)
                        {
                            vec=vec[i][j].rookmove(vec,k,l);
                        }
                        if (ourpiece==22)
                        {
                            vec=vec[i][j].knightmove(vec,k,l);
                        }
                        if (ourpiece==23)
                        {
                            vec=vec[i][j].bishopmove(vec,k,l);
                        }
                        if (ourpiece==25)
                        {
                            vec=vec[i][j].queenmove(vec,k,l);
                        }
                        if (ourpiece==20)
                        {
                            vec=vec[i][j].bpawnmove(vec,k,l,bqueen);
                        }
                        if (ourpiece==24)
                        {
                            vec=vec[i][j].kingmove(vec,k,l);
                        }
                        if (checkToKings().second==false)
                        {
                            vec=oldvec;
                            return false;
                        }
                        vec=oldvec;
                    }
                }
            }
        }
    }
    return true;
}
