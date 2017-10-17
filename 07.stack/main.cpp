//使用堆疊處理資料：新增.刪除.輸出

#include<iostream>
#include<string> 

using namespace std;

#define MAX 5

class Stack {
  private:
    char item[MAX][20];
    int top;
  public:
    Stack();
    void push_f(void); //新增函數
    void pop_f(void); //刪除函數
    void list_f(void); //輸出函數
};

Stack::Stack()
{
  top = -1;
}

//加入一元素於堆疊
void Stack::push_f(void)
{
  if(top >= MAX - 1) {
    cout<<"\n堆疊已滿\n"; //當堆疊已滿則顯示錯誤
  }
  else {
    top++;
    cout<<"\n請輸入一個物件到堆疊: ";

    /* This is bad code */ 
    //cin.getline(item[top], 21);
    cin >> item[top];
  }
}
//刪除一元素於堆疊
void Stack::pop_f(void)
{
  if(top<0) {
    cout<<"\n堆疊是空的\n"; //當堆疊是空的則顯示錯誤
  }
  else {
    cout<<"\npop"<<item[top]<<"from stack\n";
    top--;
  }
}

void Stack::list_f(void)
{
  int count = 0, i;

  if(top<0){
    cout<<"\n堆疊是空的\n";
  }
  else {
    cout<<"\nITEM\n";
    cout<<"-------------------\n";
    cout.setf(ios::left, ios::adjustfield);
    for(i=0;i<=top;i++){
      cout<<" ";
      cout.width(20);
      cout<<item[i]<<"\n";
      count++;
    }
    cout.setf(ios::left, ios::adjustfield);
    cout<<"-------------------\n";
    cout<<"總共有："<<count<<"\n";
  }
}

int main()
{
  Stack obj;
  char option;

  while(1)
  {
    cout<<"\n*********************\n";
    cout<<"    <1>插入(push)\n";
    cout<<"    <2>刪除(pop)\n";
    cout<<"    <3>列出\n";
    cout<<"    <4>退出\n";
    cout<<"*********************\n";
    cout<<"請輸入選項...";

      /* This is bad code */
      //while(cin.get(option)&&option=='\n');
      //cin.get(option);
      cin >> option;
      cout<<option<<endl;

      switch(option) 
      {
        case '1':
          obj.push_f();
          break;
        case '2':
          obj.pop_f();
          break;
        case '3':
          obj.list_f();
          break;
        case '4':
          system("pause");
          return 0;
      }
    
  }
}
