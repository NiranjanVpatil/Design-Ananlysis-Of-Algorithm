# include<iostream>

using namespace std;

int partition(int a[],int s[],int f[],int m,int p);

void swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

void quick_sort(int a[],int s[],int f[],int l, int h)
{

        int j;

        if(l<h)
        {
        j = partition(a,s,f,l,h+1);
        quick_sort(a,s,f,l,j-1);
        quick_sort(a,s,f,j+1,h);  
        }



}

int partition(int a[],int s[],int f[],int m,int p)
{
        int pivot,start_pivot,acti_pivot,i,j;
        i = m;
        j = p;
        pivot = f[i];
        start_pivot = s[i];
        acti_pivot = a[i];
        do
        {
                do
        {
                i++;
        }while(pivot > f[i]);

            do
           {
                j--;
           }while(pivot < f[j]);

            if(i < j)
            {
                   swap(f[i],f[j]);
                   swap(s[i],s[j]);
                   swap(a[i],a[j]);
            }

        }while(i<j);

        swap(pivot,f[j]);
        swap(start_pivot,s[j]);
        swap(acti_pivot,a[j]);

        f[m] = pivot;
        s[m] = start_pivot;
        a[m] = acti_pivot;

        return j;

}

void printMaximumAtivities(int a[],int s[],int f[], int n)
{
        int k = 0;

        cout<<"Maximum set of activities that can be executed by a single person is {"<<a[k];
        for(int i = 1; i < n; i++)
        {
                if(s[i] >= f[k])
                {
                        cout<<","<<a[i];
                        k = i;
                }


        }
        cout<<"}";

}

int main()
{
        int n;
        int acti[20];
        int start[20];
        int finish[20];
        cout<<"Enter How many activities : ";
        cin>>n;
        for(int i = 0; i < n; i++)
        {
                cout<<"\n Enter Activity Name  "<<i+1<<"\t";
                cin>>acti[i];
				cout<<"\n Enter Start Time of Activity No  "<<i+1<<"\t";
                cin>>start[i];
                cout<<"\n Enter Finish Time of Activity No "<<i+1<<"\t";
                cin>>finish[i];
        }
        int l,h;
    l = 0;
    h = n-1;

    quick_sort(acti,start,finish,l,h);

    printMaximumAtivities(acti,start,finish, n);
        return 0;
}


 /*
 
Output : 
Enter How many activities : 6

 Enter Activity Name  1 11

 Enter Start Time of Activity No  1     1

 Enter Finish Time of Activity No 1     2

 Enter Activity Name  2 12

 Enter Start Time of Activity No  2     3

 Enter Finish Time of Activity No 2     4

 Enter Activity Name  3 13

 Enter Start Time of Activity No  3     0

 Enter Finish Time of Activity No 3     6

 Enter Activity Name  4 14

 Enter Start Time of Activity No  4     5

 Enter Finish Time of Activity No 4     7

 Enter Activity Name  5 15

 Enter Start Time of Activity No  5     8

 Enter Finish Time of Activity No 5     9

 Enter Activity Name  6 16

 Enter Start Time of Activity No  6     5

 Enter Finish Time of Activity No 6     9

Maximum set of activities that can be executed by a single person is {11,12,14,1
5}
--------------------------------
Process exited after 54.2 seconds with return value 0
Press any key to continue . . .



Time complexity of Activity selection problem

It takes O(n log n) time if input activities may not be sorted. 
It takes O(n) time when it is given that input activities are always sorted.

 */
