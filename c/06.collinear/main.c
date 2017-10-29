// 但你現在的count是存了所有線上有三點以上的線的數量

// 如果要處理重複的情況
// 你要意識到線上有三點的線，和有四點的線、五點的線
// 他們彼此處理重複的方式都是除以Cn取2
// 所以你必須找個方法存3個點的線有幾條、4個點的線有幾條、n個點的線有幾條
// 最後在印出數量時，在個別除以各自的Cn取2，然後加總、印出來
// 就是答案了

#include<stdio.h>


int main(){
  int i,j,k,n,count=0;
  int x[10],y[10];
  scanf("%d",&n);
  for(i=0;i<n;i++){
      scanf("%d",&x[i]);
      scanf("%d",&y[i]);
  }
  
  //3 finite loops to compare any 2 points with the rest points
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      //find dots on the same vector between dots[i] and dots[j]
      for(k=0;k<n;k++)
      {
        if(k==i||k==j) continue;
        // (a.x - b.x) * (a.y - b.y) == (c.x - b.x) * (c.y - b.y)
        else if((x[i]-x[j])*(y[k]-y[j])==(x[k]-x[j])*(y[i]-y[j]))
        {
          count++;
          break;
        }       
      }
    } 
  }
    printf("%d",count);
  return 0;
  
  
}
