#include "piece.h"


        figure::figure(int x,int y,pieces _,bool b)
        {
            xcord=x;
            ycord=y;
            piece=_;
            moved=b;
        }
        int figure::cost(){
            return piece;}
        void figure::xy()
        {
            std::cout<<xcord<<"  "<<ycord<<"  "<<piece<<" "<<moved<<std::endl;
        }
        std::vector<std::vector<figure>> figure::wpawnmove(std::vector<std::vector<figure>> vec,int x,int y,pieces _)
        {
            if (xcord==x-1 && ycord==y && x>=0 && x<=7){
                if (vec[x][y].cost()==99){
                    vec[x][y]=vec[xcord][ycord];
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}
                if (x==7 && _!=wking && _!=wpawn)
                {
                    vec[x][y].piece=_;
                }
                    else if (_==wking || _==wpawn)
                    {
                        vec[x][y].piece=wqueen;
                    }
            }
            if (xcord==1 && ycord==y && x==3){
                if (vec[3][ycord].cost()==99 && vec[2][ycord].cost()==99){
                    vec[x][y]=vec[xcord][ycord];
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}
                if (x==7 && _!=wking && _!=wpawn)
                {
                    vec[x][y].piece=_;
                }
                    else if (_==wking || _==wpawn)
                    {
                        vec[x][y].piece=wqueen;
                    }
            }
            if (xcord==x-1 && abs(y-ycord)==1 && x<=7 && x>=0 && y<=7 && y>=0){
                if (vec[x][y].cost()/10==2){
                    vec[x][y]=vec[xcord][ycord];
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}
            if (x==7 && _!=wking && _!=wpawn)
            {
                vec[x][y].piece=_;
            }
                else if (_==wking || _==wpawn)
                {
                    vec[x][y].piece=wqueen;
                }
            }
            return vec;
        }


        std::vector<std::vector<figure>> figure::bpawnmove(std::vector<std::vector<figure>> vec,int x,int y,pieces _)
        {
            if (xcord==x+1 && ycord==y && x>=0 && x<=7){
                if (vec[x][y].cost()==99){
                    vec[x][y]=vec[xcord][ycord];
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}
                if (x==0 && _!=bking && _!=bpawn){
                    vec[x][y].piece=_;}
                else if (_==bking || _==bpawn)
                    vec[x][y].piece=bqueen;}
            if (xcord==6 && ycord==y && x==4){
                if (vec[4][ycord].cost()==99 && vec[5][ycord].cost()==99){
                    vec[x][y]=vec[xcord][ycord];
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}
                if (x==0 && _!=bking && _!=bpawn){
                    vec[x][y].piece=_;}
                else if (_==bking || _==bpawn)
                    vec[x][y].piece=bqueen;
            }
            if (xcord==x+1 && abs(y-ycord)==1 && x<=7 && x>=0 && y<=7 && y>=0){
                if (vec[x][y].cost()/10==1){
                    vec[x][y]=vec[xcord][ycord];
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}
            if (x==0 && _!=bking && _!=bpawn){
                vec[x][y].piece=_;}
            else if (_==bking || _==bpawn)
                vec[x][y].piece=bqueen;


            }
            return vec;
        }

        std::vector<std::vector<figure>> figure::bishopmove(std::vector<std::vector<figure>> vec,int x,int y)
        {
            bool b=false;
            int xdif,ydif,xcopy=xcord,ycopy=ycord;
            if (abs(x-xcord)==abs(y-ycord) && x<=7 && x>=0 && y<=7 && y>=0){
                b=true;
                if (x>xcord)
                    xdif=1;
                else
                    xdif=-1;
                if (y>ycord)
                    ydif=1;
                else
                    ydif=-1;
            while (abs(x-xcopy)>1 && abs(y-ycopy)>1){
                xcopy=xcopy+xdif;
                ycopy=ycopy+ydif;
                if (vec[xcopy][ycopy].cost()!=99)
                    b=false;}}
            if (not b)
                return vec;
            else if (vec[x][y].cost()/10==vec[xcord][ycord].cost()/10)
                return vec;
            else
                {
                    vec[x][y]=vec[xcord][ycord];
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}
            return vec;
        }

        std::vector<std::vector<figure>> figure::rookmove(std::vector<std::vector<figure>> vec,int x,int y)	{
                    bool b=false;
                    int xdif,ydif,xcopy=xcord,ycopy=ycord;
                    if (abs(x-xcord)*abs(y-ycord)==0 && abs(x-xcord)+abs(y-ycord) && x<=7 && x>=0 && y<=7 && y>=0){
                        b=true;
                        if (x>xcord)
                            xdif=1;
                        else if (x<xcord)
                            xdif=-1;
                        else
                            xdif=0;
                        if (y>ycord)
                            ydif=1;
                        else if (y<ycord)
                            ydif=-1;
                        else
                            ydif=0;
                    while (abs(x-xcopy)+abs(y-ycopy)>1){
                        xcopy=xcopy+xdif;
                        ycopy=ycopy+ydif;
                        if (vec[xcopy][ycopy].cost()!=99)
                            b=false;}}
                    if (not b)
                        return vec;
                    else if (vec[x][y].cost()/10==vec[xcord][ycord].cost()/10)
                        return vec;
                    else
                        {
                            vec[x][y]=vec[xcord][ycord];
                            vec[xcord][ycord]=figure(xcord,ycord,space);
                            vec[x][y].xcord=x;
                            vec[x][y].ycord=y;
                    vec[x][y].moved=true;}
                    return vec;}


                std::vector<std::vector<figure>> figure::queenmove(std::vector<std::vector<figure>> vec,int x,int y){
                    bool b=false;
                    int xdif,ydif,xcopy=xcord,ycopy=ycord;
                    if (abs(x-xcord)*abs(y-ycord)==0 && abs(x-xcord)+abs(y-ycord) && x<=7 && x>=0 && y<=7 && y>=0){
                        b=true;
                        if (x>xcord)
                            xdif=1;
                        else if (x<xcord)
                            xdif=-1;
                        else
                            xdif=0;
                        if (y>ycord)
                            ydif=1;
                        else if (y<ycord)
                            ydif=-1;
                        else
                            ydif=0;
                    while (abs(x-xcopy)+abs(y-ycopy)>1){
                        xcopy=xcopy+xdif;
                        ycopy=ycopy+ydif;
                        if (vec[xcopy][ycopy].cost()!=99)
                            b=false;}
                    if (not b)
                        return vec;
                    else if (vec[x][y].cost()/10==vec[xcord][ycord].cost()/10)
                        return vec;
                    else
                        {
                            vec[x][y]=vec[xcord][ycord];
                            vec[xcord][ycord]=figure(xcord,ycord,space);
                            vec[x][y].xcord=x;
                            vec[x][y].ycord=y;}
                    return vec;}
                    else if (abs(x-xcord)==abs(y-ycord) && x<=7 && x>=0 && y<=7 && y>=0){
                        b=true;
                        if (x>xcord)
                            xdif=1;
                        else
                            xdif=-1;
                        if (y>ycord)
                            ydif=1;
                        else
                            ydif=-1;
                    while (abs(x-xcopy)>1 && abs(y-ycopy)>1){
                        xcopy=xcopy+xdif;
                        ycopy=ycopy+ydif;
                        if (vec[xcopy][ycopy].cost()!=99)
                            b=false;}}
                    if (not b)
                        return vec;
                    else if (vec[x][y].cost()/10==vec[xcord][ycord].cost()/10)
                        return vec;
                    else
                        {
                            vec[x][y]=vec[xcord][ycord];
                            vec[xcord][ycord]=figure(xcord,ycord,space);
                            vec[x][y].xcord=x;
                            vec[x][y].ycord=y;}
                    return vec;
                }

        std::vector<std::vector<figure>> figure::knightmove(std::vector<std::vector<figure>> vec,int x,int y)
        {
            if (abs(x-xcord)*abs(y-ycord)==2 && x<=7 && x>=0 && y<=7 && y>=0){
                if (vec[x][y].cost()/10!=vec[xcord][ycord].cost()/10){
                    vec[x][y]=vec[xcord][ycord];
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}}
            return vec;}
        std::vector<std::vector<figure>> figure::kingmove(std::vector<std::vector<figure>> vec,int x,int y)
        {
            if (abs(x-xcord)<=1 && abs(y-ycord)<=1 && x<=7 && x>=0 && y<=7 &&y>=0){
                if (vec[x][y].cost()/10!=vec[xcord][ycord].cost()/10){
                    vec[x][y]=vec[xcord][ycord];
                    vec[x][y].moved=true;
                    vec[xcord][ycord]=figure(xcord,ycord,space);
                    vec[x][y].xcord=x;
                    vec[x][y].ycord=y;}}
            if (xcord==0 && ycord==3 && x==0 && y==0){
                if (vec[xcord][ycord].cost()==14 && vec[xcord][ycord].moved==false && vec[x][y].moved==false && vec[x][y].cost()==11 && vec[0][1].cost()==99 && vec[0][2].cost()==99){
                    vec[0][1]=figure(0,1,wking,true);
                    vec[0][2]=figure(0,2,wrook);
                    vec[0][0]=figure(0,0,space);
                    vec[0][3]=figure(0,3,space);}}
            if (xcord==0 && ycord==3 && x==0 && y==7){
                if (vec[xcord][ycord].cost()==14 && vec[xcord][ycord].moved==false && vec[x][y].moved==false && vec[x][y].cost()==11 && vec[0][6].cost()==99 && vec[0][5].cost()==99 && vec[0][4].cost()==99){
                    vec[0][5]=figure(0,5,wking,true);
                    vec[0][4]=figure(0,4,wrook);
                    vec[0][7]=figure(0,7,space);
                    vec[0][3]=figure(0,3,space);}}
            if (xcord==7 && ycord==3 && x==7 && y==0){
                if (vec[xcord][ycord].cost()==24 && vec[xcord][ycord].moved==false && vec[x][y].moved==false && vec[x][y].cost()==21 && vec[7][1].cost()==99 && vec[7][2].cost()==99){
                    vec[7][1]=figure(7,1,bking,true);
                    vec[7][2]=figure(7,2,brook);
                    vec[7][0]=figure(7,0,space);
                    vec[7][3]=figure(7,3,space);}}
            if (xcord==7 && ycord==3 && x==7 && y==7){
                if (vec[xcord][ycord].cost()==24 && vec[xcord][ycord].moved==false && vec[x][y].moved==false && vec[x][y].cost()==21 && vec[7][6].cost()==99 && vec[7][5].cost()==99 && vec[7][4].cost()==99)
                {
                    vec[7][5]=figure(7,5,bking,true);
                    vec[7][4]=figure(7,4,brook);
                    vec[7][7]=figure(7,7,space);
                    vec[7][3]=figure(7,3,space);}}
            return vec;
        }









std::string antienum(int a)
{
    if (a==11)
        return "wrook";
    if (a==12)
        return "wknight";
    if (a==13)
        return "wbishop";
    if (a==14)
        return "wking";
    if (a==15)
        return "wqueen";
    if (a==10)
        return "wpawn";
    if (a==21)
        return "brook";
    if (a==22)
        return "bknight";
    if (a==23)
        return "bbishop";
    if (a==24)
        return "bking";
    if (a==25)
        return "bqueen";
    if (a==20)
        return "bpawn";
    else
        return "  ";
}
