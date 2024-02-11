#include<stdio.h>
#include<stdlib.h>


void foo(int a,int b){
  int *p,*y;

  p=&a;
  y=&b;

  //OUTPUT(From LLVM IR)

  /*
    Points-to information as observed at the last program point in function Foo:
    Pointer Var %5={%3}
    Pointer Var %6={%4}
  
    Alias relationships between the pointers in function Foo:
    		    %5   %6
    Pointer Var %5  Yes  No
    Pointer Var %6  No   Yes
  
  */    

}

int main(){
   int x=10,y=11;
   foo(x,y);
}
