#include <bits/stdc++.h>
#ifdef _WIN32   
    #define CLEAR "cls"
#elif defined __unix__
    #define CLEAR "clear"
#endif


using namespace std;

void drawBoard(vector<char> &board){
    //clear the console
    system(CLEAR);
    
    //draw the board
    cout << "Player 1 (X) \t Player 2 (O)"<<endl;

    
    cout<< " " << board[0]<<" | " << board[1]<<" | "<<board[2]<<endl;
    cout << "- - - - - - "<<endl;

    cout<< " " << board[3]<<" | " << board[4]<<" | "<<board[5]<<endl;
    cout << "- - - - - - "<<endl;

    cout<< " " << board[6]<<" | " << board[7]<<" | "<<board[8]<<endl;
    
}

int checkWin(vector<char> &board){
    //subroutine to check a win
    if((board[0]==board[1] && board[1]==board[2])|| (board[3]==board[4] && board[4]==board[5])|| (board[6]==board[7] && board[7]==board[8])|| (board[0]==board[3] && board[3]==board[6])|| (board[1]==board[4] && board[4]==board[7])|| (board[2]==board[5] && board[5]==board[8])|| (board[0]==board[4] && board[4]==board[8])|| (board[6]==board[4] && board[4]==board[2])){
        return 1;
    }else{
        //check if all the postions are used
        for(int i=0;i<9;i++){
            if(!(board[i]=='X' || board[i]=='O')){
                return 0;
            }
        }
        return -1;
    }


}

int main(){
    //initialize the board
    vector<char> board(9);
    for(int i=0;i<9;i++){
        board[i]= i+49;
    }
    bool player = true;
    while(1){

        //draw the board
        drawBoard(board);

        int input;
        //ask for players input
        cout << "Player ";
        player ? cout << "1": cout<<"2";
        cout << "_ ";
        cin >> input;
        player ? board[input-1]='X':board[input-1]='O';
        
        //check if player has won
        int res = checkWin(board);
        
        //draw condition
        if(res == -1){
            drawBoard(board);
            cout << "DRAW"<<endl;
            break;
        }
        
        //win condition
        else if(res == 1){
            drawBoard(board);
            cout << "Player ";
            player ? cout << "1": cout<<"2";
            cout << " WINS"<<endl;
            break;
        }

        //no win condition
        player = !player;
    }
    return 0;
}