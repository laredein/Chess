#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <iostream>

enum pieces
{
    wrook=11,
    wknight=12,
    wbishop=13,
    wking=14,
    wqueen=15,
    wpawn=10,
    brook=21,
    bknight=22,
    bbishop=23,
    bking=24,
    bqueen=25,
    bpawn=20,
    space=99
};

std::string antienum(int a);





class figure
{
    public:
        int xcord,ycord;
        bool moved;
        pieces piece;
        figure(int x,int y,pieces _,bool b=false);
        int cost();
        void xy();
        std::vector<std::vector<figure>> wpawnmove(std::vector<std::vector<figure>> vec,int x,int y,pieces _=wqueen);


        std::vector<std::vector<figure>> bpawnmove(std::vector<std::vector<figure>> vec,int x,int y,pieces _=bqueen);

        std::vector<std::vector<figure>> bishopmove(std::vector<std::vector<figure>> vec,int x,int y);

        std::vector<std::vector<figure>> rookmove(std::vector<std::vector<figure>> vec,int x,int y);

        std::vector<std::vector<figure>> queenmove(std::vector<std::vector<figure>> vec,int x,int y);

        std::vector<std::vector<figure>> knightmove(std::vector<std::vector<figure>> vec,int x,int y);

        std::vector<std::vector<figure>> kingmove(std::vector<std::vector<figure>> vec,int x,int y);
};
#endif // PIECE_H
