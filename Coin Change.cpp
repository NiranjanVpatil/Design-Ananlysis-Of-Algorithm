#include<iostream>
using namespace std;

int coinchange(int d[],int amount,int c[],int s[])
        {
          int coin;
          int min;
          coin = 0;
          c[0] = 0;
          s[0] = 0;
    // min = minimum no. of coins required for making change for amount p
    // coin = first index of the coin in the solution
          for( int p = 1; p <= amount; p++ )
         {

            min = 9999;
            for(int i = 1; i < 5; i++ )
            {
                if(d[i] <= p)
                {
                        if((1+c[p-d[i]]) < min)
                        {
                                min = 1+c[p-d[i]];
                                coin = i;
                                }
                        }
                }
                c[p] = min;
                s[p] = coin;
            }
        }

int displaycoin(int d[],int s[],int amount)
{
  int i =1;
  while(amount > 0)
  {
    
    cout<<i<<"\t coin \t"<<d[s[amount]]<<endl;
    amount = amount - d[s[amount]];
    i = i + 1;
  }
}
int main()
{
        int amount;
        int d[5] = {0,1,2,5,10};
        // Available denominations are Rs. 1 coins, Rs. 2 coins, 5 coins and Rs. 10 coins.
        int c[amount+1],s[amount+1];
        // C[p] denotes the minimum number of coins required to make change for an amount p using given denomination coins.
        // S[p] will contain the index of the first coin in an optimal solution for making change of an amount p.
        cout<<"Enter amount you have change for it : ";
        cin>>amount;
        coinchange(d,amount,c,s);
        cout<<"Following minimum Coins are required for make change of amount Rs."<<amount<<endl;
        displaycoin(d,s,amount);
        cout<<"c[p]"<<endl;
        for(int i = 0; i < amount; i++)
        {
                cout<<c[i]<<"\t";
        }
        cout<<endl;
        cout<<"s[p]"<<endl;
        for(int i = 0; i < amount; i++)
        {
                cout<<s[i]<<"\t";
        }

        return 0;

}

/*
Time Complexity - 

Time complexity of this algorithm is O(nA) where n 
is the total number of different denomination of the coins 
and A is the amount for which we are making change.

OUTPUT - 

Enter amount you have change for it : 14                                                                                       
Following minimum Coins are required for make change of amount Rs.14                                                           
1        coin   2                                                                                                              
2        coin   2                                                                                                              
3        coin   10                                                                                                             
c[p]                                                                                                                           
0       1       1       2       2       1       2       2       3       3       3
s[p]                                                                                                                           
0       1       2       1       2       3       1       2       1       2       1
                                                                                                                               
...Program finished with exit code 0                                                                                           
Press ENTER to exit console. 

*/
