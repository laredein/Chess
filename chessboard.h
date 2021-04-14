#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piece.h"
class ChessTable
{
    public:
        std::vector<std::vector<figure>> vec;
        figure whiteking=figure(0,3,wking,false),blackking=figure(7,3,bking,false);

        ChessTable();
        void king(bool white);
        std::pair<bool,bool> checkToKings();
        bool checkMate(bool white);

};
#endif // CHESSBOARD_H
