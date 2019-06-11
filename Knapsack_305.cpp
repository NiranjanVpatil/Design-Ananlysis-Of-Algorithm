//  fractional knapsack problem
#include<iostream>
using namespace std;

int knapsack(int n, float w[], float p[],int I[], float max)      
{
	float tp=0, u=max, x[10];     
	int i;
	
	for(i=0; i<n; i++)    
		x[i] = 0;              
		
	for(i=0; i<n; i++)        
	{
		if(w[i]>u)            // if weight of first element exceeds the capacity of knapsack then break
			break;
		
		else                 
		{
			x[i] = 1.0;      //else include whole first element in knapsack
			u = u - w[i];      //calculate remaining weight in knapsack 
			tp = tp+p[i];    //calculate total profit
		}
	}
	
    if(i<n)        // for fractional part of other elements
	{
		x[i]=u/w[i];
		tp=tp+(x[i]*p[i]);
	}
	
	cout<<"Total Profit : "<< tp<<endl; 
	
	cout<<" Fractions of elements taken in knapsack : "<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"\n "<<x[i]<<" of element I"<<I[i]; 
	}

	return 0;
}	 
	
int main()
{
	int n, i, j;
	int I[10],tempc;
	float w[10],p[10], max, ratio[10], temp;
	
	cout<<"Enter Maximum Capacity of knapsack (in decimal): "<<endl;   
	cin>>max;
	
	cout<<"Enter the Number of Elements : "<<endl;
	cin>>n;
	
	cout<<"Enter the Item name, Profit and Weight of each element : "<<endl;     
	for(i=0; i<n; i++)
	{
		cout<<" I["<<i+1<<"] : I"<<i+1<<endl;
		I[i] = i+1;
		cout<<" P["<<i+1<<"] : ";
		cin>>p[i];
		cout<<" W["<<i+1<<"] : ";
		cin>>w[i];
	}
	
	for(i=0; i<n; i++)                         //Calculate ratios of each element by profit/weight
	{
		ratio[i] = p[i]/w[i];
	}
		
	for(i=0;i<n;i++)                             // Sorting ratios, profits and weigths in descending order
	{		
		for(j=i+1;j<n;j++)
		{
			if(ratio[i]<ratio[j])
			{
				tempc  =I[i];
				I[i]=I[j];
				I[j]=tempc;
				
				temp  =ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp;
				
				temp  =p[i];
				p[i]=p[j];
				p[j]=temp;
				
				temp  =w[i];
				w[i]=w[j];
				w[j]=temp;
			}
		}
	}	

	knapsack(n, w, p, I, max);  // call the knapsack() function by passing arguments
	
	return 0;
}


/*
Enter Maximum Capacity of knapsack (in decimal):
60
Enter the Number of Elements :
5
Enter the Item name, Profit and Weight of each eleme
 I[1] : I1
 P[1] : 30
 W[1] : 5
 I[2] : I2
 P[2] : 40
 W[2] : 10
 I[3] : I3
 P[3] : 45
 W[3] : 15
 I[4] : I4
 P[4] : 77
 W[4] : 22
 I[5] : I5
 P[5] : 90
 W[5] : 25
Total Profit : 230
 Fractions of elements taken in knapsack :

 1 of element I1
 1 of element I2
 1 of element I5
 0.909091 of element I4
 0 of element I3
--------------------------------
Process exited after 26.52 seconds with return value
Press any key to continue . . .



*/

 // 0/1 knapsack problem
#include<iostream>
using namespace std;

int knapsack(int n, float w[], float p[],int I[], float max)      
{
	float tp=0, u=max, x[10];     
	int i;
	
	for(i=0; i<n; i++)    
		x[i] = 0;              
		
	for(i=0; i<n; i++)        
	{
		if(w[i]>u)            // if weight of first element exceeds the capacity of knapsack then break
			break;
		
		else                 
		{
			x[i] = 1.0;      //else include whole first element in knapsack
			u = u - w[i];      //calculate remaining weight in knapsack 
			tp = tp+p[i];    //calculate total profit
		}
	}
	
    
	
	cout<<"Total Profit : "<< tp<<endl; 
	
	cout<<" Fractions of elements taken in knapsack : "<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"\n "<<x[i]<<" of element I"<<I[i]; 
	}

	return 0;
}	 
	
int main()
{
	int n, i, j;
	int I[10],tempc;
	float w[10],p[10], max, ratio[10], temp;
	
	cout<<"Enter Maximum Capacity of knapsack (in decimal): "<<endl;   
	cin>>max;
	
	cout<<"Enter the Number of Elements : "<<endl;
	cin>>n;
	
	cout<<"Enter the Item name, Profit and Weight of each element : "<<endl;     
	for(i=0; i<n; i++)
	{
		cout<<" I["<<i+1<<"] : I"<<i+1<<endl;
		I[i] = i+1;
		cout<<" P["<<i+1<<"] : ";
		cin>>p[i];
		cout<<" W["<<i+1<<"] : ";
		cin>>w[i];
	}
	
	for(i=0; i<n; i++)                         //Calculate ratios of each element by profit/weight
	{
		ratio[i] = p[i]/w[i];
	}
		
	for(i=0;i<n;i++)                             // Sorting ratios, profits and weigths in descending order
	{		
		for(j=i+1;j<n;j++)
		{
			if(ratio[i]<ratio[j])
			{
				tempc  =I[i];
				I[i]=I[j];
				I[j]=tempc;
				
				temp  =ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=temp;
				
				temp  =p[i];
				p[i]=p[j];
				p[j]=temp;
				
				temp  =w[i];
				w[i]=w[j];
				w[j]=temp;
			}
		}
	}	

	knapsack(n, w, p, I, max);  // call the knapsack() function by passing arguments
	
	return 0;
}


/*
Output:
Enter Maximum Capacity of knapsack (in decimal):
60
Enter the Number of Elements :
5
Enter the Item name, Profit and Weight of each el
 I[1] : I1
 P[1] : 30
 W[1] : 5
 I[2] : I2
 P[2] : 40
 W[2] : 10
 I[3] : I3
 P[3] : 45
 W[3] : 15
 I[4] : I4
 P[4] : 77
 W[4] : 22
 I[5] : I5
 P[5] : 90
 W[5] : 25
Total Profit : 160
 Fractions of elements taken in knapsack :

 1 of element I1
 1 of element I2
 1 of element I5
 0 of element I4
 0 of element I3
--------------------------------
Process exited after 20.27 seconds with return va
Press any key to continue . . .









*/



