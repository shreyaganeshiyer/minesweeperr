#include "assets.h"
int number;
int size = 12;

Board mydesk;


// ---------------------main()--------------------------------------
int main(){
    Vector2 click;
    int value=0; int pixrow=0,pixcol=0;
    bool flagarr[12][12] = {false};  // store flags
    bool highlight[12][12]={false};
    bool isMine[12][12]={false}; 
    srand(time(NULL));             // seed once at start of the game

    InitWindow(50*12, 50*12, "Easylevel");
    LoadGameAssets();
    init_table(&mydesk);
    placeMines(&mydesk);
  

    // -------------------------- while()  ---------------------
    while(!WindowShouldClose()){
        BeginDrawing();  ClearBackground(RAYWHITE);
       
       for (int row = 0; row < 12; row++){
            for (int col = 0; col < 12; col++){
                pixcol = col * 50;   // convert row/col to pixel
                pixrow = row * 50;
                DrawRectangle(pixcol, pixrow, 48, 48, BLUE);


                if (flagarr[row][col])
                    DrawTexture(Flag, pixcol, pixrow, WHITE);

                if (highlight[row][col]){
                    DrawRectangle(pixcol, pixrow, 48, 48, PINK);
                    value=mydesk.grid[row][col];
                    if(value==-1) DrawTexture(Mine, pixcol, pixrow, WHITE);

                 else{
                    number=countMine(row,col,&mydesk);
                    char buff[2];
                    buff[0]= '0'+number; buff[1]='\0';
                        DrawText(buff,pixcol+18,pixrow+10,30,BLACK);
                 } 
                }

        // now use that value if needed
    }
}
    
 //-------------------------- left click highlight--------------------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            click = GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;

            highlight[row][col]=true;

        }

        //------------------------- right click toggle flag----------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
            click = GetMousePosition();
            int col = click.x / 50;
            int row = click.y / 50;
         
            if(col >= 0 && col < 12 && row >= 0 && row < 12){
                flagarr[row][col] = !flagarr[row][col]; // true->false or false->true
                //initially false
            }
        }
        
        EndDrawing();
    }
    UnloadGameAssets();
    CloseWindow();
    }


