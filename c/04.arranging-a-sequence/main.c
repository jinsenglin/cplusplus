

//When taking the assigned number to the first place, others
// after it will forward one place.
// – The last input will be the first output number

#include<stdio.h>
int n;
int m;
int a[200000];
int b[200000];
int r;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
  scanf("%d %d", &n, &m);
  //store the sequence
  for(int i=0;i<=n-1;i++)
  {
    a[i] = i+1;
    b[i] = -1;
    //printf("%d", a[i]);
  }
  
  //scan the requests m-times
  for(int i=0;i<=m-1;i++)
  {
    // – The last input will be the first output number
    scanf("%d", &r);

    a[r-1] = -1; //make a mark for the 1st array
    b[n-i-1] = r; //save r in the 2nd array
/*
    for(int j=0;j<=n-1;j++)
    {
      
      if(a[j] == r)
      {
        //printf("j=%d\n", j);
        //put a0,a1...aj-1 to the right
        for(int k=j;k>=1; k--)
        {
          //printf("k=%d\n", k);
          a[k] = a[k-1];
          //a[j] = a[j-1];
          //a[1] = a[0];
        }
        //The last input will be the first output number
        a[0] = r;
      }
    }
*/
  }
  //print to check the result
    for(int j=n-1;j>-1;j--)
    {
      if (b[j] != -1) {
        printf("%d\n", b[j]);
      }
    }
    for(int j=0;j<=n-1;j++)
    {
      if (a[j] != -1) {
        printf("%d\n", a[j]);
      }
    }

  return 0;
}
