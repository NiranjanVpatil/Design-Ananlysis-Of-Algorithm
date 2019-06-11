/*
Name: Niranjan Vinod Patil.
Batch: B31.		
Roll No: SCETTYB305.
Course: DAA. 
----------------------------------------------------------------------------------------------------------------------------------------
Lab Assignment No: 03

Design and Implement Merge sort algorithm using Divide and conquer. then display the element appear once if array list consist of duplicate elements.

*/
# include<iostream>
using namespace std;

int Merge(int a[], int low, int mid, int high);

int Mergesort(int a[], int low, int high)          // function to split array into two parts.
{
        int mid;
        if(low < high)
        {
                mid = (low+high)/2;
                Mergesort(a,low,mid);
                Mergesort(a,mid+1,high);
                Merge(a,low, mid, high);
        }

}
//  function to merge the two half into a sorted data.
int Merge(int a[], int low, int mid, int high)
{
        int h,i,j;
        int temp[20];
        h = low;
        i = low;
        j = mid+1;
        // Merge the two parts into temp[].
        while(h <= mid && j <= high)
        {
                if(a[h] <= a[j])
                {
                        temp[i] = a[h];
                        h = h + 1;
                }
                else
                {
                        temp[i] = a[j];
                        j = j + 1;
                }
                i = i + 1;
        }


    // Insert all the remaining values from j to high into temp[].
        if(h > mid)
        {
                for(int k = j; k <= high; k++)
                {
                        temp[i] = a[k];
                        i = i + 1;
                }
        }
        // Insert all the remaining values from i to mid into temp[].
        else
        {
                for(int k = h; k <= mid; k++)
                {
                   temp[i] = a[k];
                   i = i + 1;
                }
        }
        // Assign sorted data stored in temp[] to a[].
        for(int k = low; k <= high; k++)
        {
                a[k] = temp[k];
        }
}

int main()
{
        int n;
        int a[20];
        cout<<"Enter How many elements is to be sorted : "<<endl;
        cin>>n;
        cout<<"Enter Elements to be sorted : "<<endl;
        for(int i = 0; i < n; i++)
        {
                cin>>a[i];
        }
        Mergesort(a,0,n-1);          // call for sorting
        cout<<"Elements in sorted order : "<<endl;
        for(int j = 0; j < n; j++)
        {
             int flag = 0;

			for(int k = 0; k < j; k++)
            {
            	if(a[j] == a[k])
            	{
            		flag = 1;
					break;
				}
				
			}
			if(flag == 0)
			{
		      	cout<<a[j]<<endl;				
			}
        }

        return 0;
}


/*
Output:

Enter How many elements is to be sorted :
10
Enter Elements to be sorted :
78
45
99
23
56
19
99
16
46
56
Elements in sorted order :
16
19
23
45
46
56
78
99

--------------------------------
Process exited after 22 seconds with return value 0
Press any key to continue . . .



Time Compexity:

whether it be worst case or average case the merge sort just divide the array 
in two halves at each stage which gives it lg(n) component and the other N component 
comes from its comparisons that are made at each stage. So combining it becomes nearly 
O(nlog n). No matter if is average case or the worst case, lg(n) factor is always present. 
Rest N factor depends on comparisons made which comes from the comparisons done in both cases. 
Now the worst case is one in which N comparisons happens for an N input at each stage. 
So it becomes an O(nlg n).

*/

