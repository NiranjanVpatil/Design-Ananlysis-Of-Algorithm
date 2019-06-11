#include<bits/stdc++.h>
using namespace std;

bool safe(int board[][10],int i,int j,int n)
{
    //Checking the column
    
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    
    //Checking the left diagonal
    int x = i;
    int y = j;
    
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        return false;
        
        x--;
        y--;
    }
    
    //Checking the right diagonal
    x=i;
    y=j;
    
    while(x>=0 && y<n)
    {
        if(board[x][y])
        return false;
        
        x--;
        y++;    }
        
        return true;
    
    
}

bool solvenqueen(int board[][10],int i,int n)
{
    if(i==n)
    {
        
        //Print the board
        //Base case
        
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(board[x][y]==1)
                {
                    cout<<"Q ";
                }
                else
                cout<<"_ ";
            }
            cout<<"\n";
        }
        return true;
    }
    
    //Recursive case
    //Try to place queen in the current row and call on remaining part
    
    for(int j=0;j<n;j++)
    {
        if(safe(board,i,j,n))
        {
            //Place the queen at the position, assuming i,j is correct position
            board[i][j] = 1;
            bool newtq = solvenqueen(board,i+1,n);
            if(newtq)
            {
                return true;
            }
            //We can not place queen in next row back track;
            board[i][j] = 0;
        }
        
     
    }
        
    return false;    
}


int main()
{
    int n;
    cout<<"\n Enter the number of queens for which you want the pattern : ";
    cin>>n;
    
    int board[10][10]={0};
    
  
    solvenqueen(board,0,n);
}

/* OUTPUT

 Enter the number of queens for which you want the pattern : 8
Q _ _ _ _ _ _ _
_ _ _ _ Q _ _ _
_ _ _ _ _ _ _ Q
_ _ _ _ _ Q _ _
_ _ Q _ _ _ _ _
_ _ _ _ _ _ Q _
_ Q _ _ _ _ _ _
_ _ _ Q _ _ _ _

--------------------------------
*/
