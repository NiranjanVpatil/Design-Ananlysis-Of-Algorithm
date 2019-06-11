# include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int sort(int l[],int n)
        {
        	int temp;

			for(int j=0; j<(n-1); j++)
        {
                for(int k=0; k<(n-j-1); k++)
                {
                        if(l[k] > l[k+1])
                        {
                                temp = l[k];
                                l[k] = l[k+1];
                                l[k+1] = temp;
                        }
                }
        }
		}
		

int random_middle(int x, int y)       // geberate random number
{
 
    return (x + rand() % (y-x+1)); 
}
		
int randomized_Binary_search(int l[],int n,int search)
{
    int mid;
    int lb;
    int ub;
   int flag = 0;
   lb = 0;
    ub = n-1;
                while( lb <= ub)
                {
                         mid = random_middle(lb,ub);

                        if( search < l[mid])
                        {
                                ub = mid - 1 ;
                                
                        }
                        else
                        {
                                lb = mid + 1;
                                
                        }

                        if( l[mid] == search )
           {
                        cout<<search<<" is found and at position "<<mid+1;
                        flag = 1;
                        
           }
                }
        if(flag == 0)
        {
        	cout<<search<<" is not found.";
			} 
		

}

int main()
{
        int n;
        int l[20];
        int search;

        cout<<"Enter How Many Element in list : "<<endl;
        cin>>n;

        cout<<"Enter Element in list :"<<endl;

        for(int i=0; i<n; i++)
        {

                cin>>l[i];
        }
        
        cout<<"Enter Element to search : "<<endl;
        cin>>search;
        sort(l,n);
        randomized_Binary_search(l,n,search);
        
        return 0;

}

