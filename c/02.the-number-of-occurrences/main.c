#include<stdio.h>
#include<string.h>

int main()
{
  int max = 0;
  int count = 0;
  char A[5];
  int n;
  scanf("%s", &A);
  scanf("%d", &n);
  char str[10];
  for(int i=1;i<=n;i++)
  {
    count = 0;
    scanf("%s", &str);
      switch(strlen(A))
      {
        case(1):
          for(int k=0;k<=strlen(str)-1;k++)
          {
            if(str[k] == A[0])
            {
              count+=1;
            }
          }
          break;
        case(2):
          for(int k=0;k<=strlen(str)-2;k++)
          {
            
            if (str[k] == A[0] && str[k+1] == A[1])
            {
              count+=1;
            }      
          }
          break;
        case(3):
          for(int k=0;k<=strlen(str)-3;k++)
          {
            if (str[k] == A[0] && str[k+1] == A[1] && str[k+2] == A[2])
            {
              count+=1;
            }      
          }
          break;
        case(4):
          for(int k=0;k<=strlen(str)-4;k++)
          {
            if (str[k] == A[0] && str[k+1] == A[1] && str[k+2] == A[2] && str[k+3] == A[3])
            {
              count+=1;
            }      
          }
          break;
      } 
    
    if (count > max) {
        max = count;
    }
  }

  printf("%d", max);
  return 0;
}
