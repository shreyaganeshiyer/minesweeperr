#include "allheader.h"

#define N 12
static int dx[8]={-1, -1, -1, 0, 0, 1, 1, 1};    //for x co-ordinate   // for(0,0)
static int dy[8]={-1, 0, 1, -1, 1, -1, 0, 1};  // corresponding y co-ordinate

void bfsReveal(Board *board,bool isRevealed[N][N],int startRow,int startCol){
    
    int qx[144],qy[144];//max can be 12*12

    int front=0,rear=0;
    qx[rear]=startRow;
    qy[rear]=startCol;
    rear++;

    isRevealed[startRow][startCol]=true;

    while(front<rear){
        int r=qx[front];
        int c=qy[front];
        front++;

        if(countMine(board,r,c)!=0){
            continue;
        }

        for(int i=0;i<8;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];///increments and checks all 8 neighbours

            if(nr>=0 && nr<12 && nc>=0 && nc<12){//checks bound condition

                if(!(isRevealed[nr][nc])){
                    isRevealed[nr][nc]=true;//reveal it
                    qx[rear]=nr;//push into queue
                    qy[rear]=nc;
                    rear++;//increment
                }
            }

        }
    }


}