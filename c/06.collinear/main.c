// 但你現在的count是存了所有線上有三點以上的線的數量

// 如果要處理重複的情況
// 你要意識到線上有三點的線，和有四點的線、五點的線
// 他們彼此處理重複的方式都是除以Cn取2
// 所以你必須找個方法存3個點的線有幾條、4個點的線有幾條、n個點的線有幾條
// 最後在印出數量時，在個別除以各自的Cn取2，然後加總、印出來
// 就是答案了

#include<stdio.h>


int main(){
  //scan T test cases
  int T;
  scanf("%d", &T);
  for(int t=0;t<T;t++) {
  
    int i,j,k,n,count=0;
    int x[101],y[101],z[101];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
        z[i] = 0;
    }
    
    //3 finite loops to compare any 2 points with the rest points
    for(i=0;i<n;i++)
    {
      if (z[i] == 1) continue;
  
      for(j=i+1;j<n;j++)
      {
        if (z[j] == 1) continue;
  
        //find dots on the same vector between dots[i] and dots[j]
        for(k=0;k<n;k++)
        {
          //printf("DEBUG: i=%d, j=%d, k=%d\n", i, j, k);
  
          if(k==i||k==j) continue;
          // (a.x - b.x) * (a.y - b.y) == (c.x - b.x) * (c.y - b.y)
          else if((x[i]-x[j])*(y[k]-y[j])==(x[k]-x[j])*(y[i]-y[j]))
          {
            if (z[i] == 0 || z[j] == 0) {
              count++;
              //printf("DEBUG: count+=1 when i=%d, j=%d, k=%d\n", i, j, k);
            }
  
            z[i] = 1;
            z[j] = 1;
            z[k] = 1;
  
            //printf("DEBUG: count+=0 when i=%d, j=%d, k=%d\n", i, j, k);
          }       
        }
      } 
    }
    
    printf("%d\n",count);
  }

  return 0;  
}
