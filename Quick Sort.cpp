# include<iostream>
using namespace std;

int partition(int s[],int m,int p);

void swap(int *a, int *b)
{
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

void quick_sort(int s[],int l, int h)
{

        int j;

        if(l<h)
        {
        j = partition(s,l,h+1);
        quick_sort(s,l,j-1);
        quick_sort(s,j+1,h);    
        }

}

int partition(int s[],int m,int p)
{
        int pivot,i,j;
        i = m;
        j = p;
        pivot = s[i];
        do
        {
                do
        {
                i++;
        }while(pivot > s[i]);

            do
           {
                j--;
           }while(pivot < s[j]);

            if(i < j)
            {
                   swap(s[i],s[j]);
            }

        }while(i<j);

        swap(pivot,s[j]);
        s[m] = pivot;

        return j;

}

int main()
{

  int n;
  int s[20];


  cout<<"Enter How many element is to be sorted ?"<<endl;
  cin>>n;

  cout<<"Enter Elements to sorted : "<<endl;

  for(int i = 0; i < n; i++)
  {
        cin>>s[i];
  }
 int l,h;
  l = 0;
  h = n-1;

  quick_sort(s,l,h);

  cout<<"Elements in sorted : "<<endl;

  for(int i = 0; i < n; i++)
  {
        cout<<s[i]<<endl;
  }

  return 0;
}

