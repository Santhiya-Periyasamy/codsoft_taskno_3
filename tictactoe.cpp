#include<iostream>
using namespace std;
 char board[3][3];
 int row,col;
 int a,b;
char show()
{
     cout<<"----------"<<endl;
    for(int i=0;i<3;i++)
    {
     cout<<"| ";
     for(int j=0;j<3;j++)
     {
        cout<<board[i][j]<<"| ";
     }
       cout<<endl<<"----------";
       cout<<endl;
    }
    return 0;
}
void get(char player)
{
    int choice;
    if(player == 'X') {
      cout<<"Player X it's your turn : ";
    }
    else{
      cout<<"Player O it's your turn : ";
    }
    cin>>choice;
    switch(choice)
    {
        case 1:
           row = 0; col = 0;
           break;
        case 2:
           row = 0; col = 1;
           break;
        case 3:
           row = 0; col = 2;
           break;
        case 4:
           row = 1; col = 0;
           break;
        case 5:
           row = 1; col = 1;
           break;
        case 6:
           row = 1; col = 2;
           break;
        case 7:
           row = 2; col = 0;
           break;
        case 8:
           row = 2; col = 1;
           break;
        case 9:
           row = 2; col = 2;
           break;
        default:
        cout<<"\nEnetr correct choice.";
    }
    if(player == 'X'&& board[row][col]!='X' && board[row][col]!='O')
    { board[row][col]='X';}
   else if(player == 'O'&&board[row][col]!='X'&& board[row][col]!='O')
   {
     board[row][col]='O';
   }
    else
   {
     cout<<"\nIt is already occupied.";
      get(player);
   }
}

 bool check(char player)
{
    for(int i=0;i<3;i++)
    {
    if(board[0][i]==player&&board[1][i]==player&&board[2][i]==player)
     return true;
    if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
     return true; 
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
     return true;
    if(board[0][2]==player &&board[1][1]==player && board[2][0]==player)
     return true;
    }
    return false;
    }

int main()
 {
    char player = 'X';
    int turn;
    cout<<"---------WELCOME TO TIC-TAC-TOE  -------------";
    cout<<"| 1| 2| 3|\n----------\n| 4| 5| 6|\n----------\n| 7| 8| 9|\n";
    for(turn = 0;turn<9;turn++)
    {
     get(player);
     show();
     while(check(player))
     { cout<<"Congratulations !! Player "<<player<<" wins.";
      break;
      }
     if(check(player)==true)
      break;
     if(turn == 8 && check(player)==false)
        {cout<<"It's a draw";}
     player = (player == 'X')?'O':'X';
    }
 return 0;
 }