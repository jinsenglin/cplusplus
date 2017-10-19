#include <stdio.h>
#include <math.h>

int count(int r);
int main()
{
   int t;
   scanf("%d", &t);

   for(int i=0;i<t;i++)
   {  
      int l,r;
      scanf("%d %d", &l, &r);

      int new_counter = 0, max_counter = 0, result = 0;
      // printf("DEBUG sqrt(r) = %f \n", sqrt(r));

      for(int j = l; j<=r; j++)
      {
         new_counter = count(j);
         // printf("DEBUG %d %d\n", j, new_counter);

         if (new_counter > max_counter)
         {
            max_counter = new_counter;
            result = j;
         }
      }

      printf("%d\n", result);
   }


   return 0;
}

//數出每個數字的因數
//要小心完全平方數會少算
int count(int r)
{
   int min_factor = 1;
   int ceil = 1;
   int count = 0;

   float s = sqrt(r);
   for(int i=1; i<=s; i++) {
      if(r % i == 0)
      {
         count++;

         if (min_factor == 1) {
             min_factor = i;
             ceil = r / i;
         }
      }
   }
   if (count == 0) {
      return 2;
   }
   else {
     for(int i=s; i<=ceil;i++)
     {
       if(r % i == 0)
       {  
         count++;
       }
     }
   }

   return count;
}

int perfect_square_check(int temp)
{
      int count = 1;
      while(temp > 0 && temp != 1)
      {
            temp = temp - count;
            count = count + 2;
      }
      if(temp == 0)
      {
            return 1;
      }
      return 0;
}
