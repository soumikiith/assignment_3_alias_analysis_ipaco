#include <stdio.h>

void foo(){
  int a=10,b=11;
  int *p,*y;

  p=&a;
  y=&b;

  //OUTPUT(From LLVM IR)

  /*
    Alias information as observed at the last program point in function foo:
    p -> {}
    y -> {}
  
  
  */   

}

void bar(){
  int a=10,b=11;
  int *p,*y;

  if(b%2){
    p=&a;
  }
  else {
    p=&b; 	
  }
  y=&a;
  //OUTPUT(From LLVM IR)

  /*
    Alias information as observed at the last program point in function bar:
    p -> {y}
    y -> {p}
  
  
  */   

}

void fun(){
  int *p,*y,a,b,**p1;

  p=&a;
  y=&b;

  p1=&p;

  *p1=&b;
  //OUTPUT(From LLVM IR)

  /*
    Alias information as observed at the last program point in function fun:
    p -> {y}
    y -> {p}
    p1 -> {}
  
  
  */   

}

void neo(){
  int x = 10, y = 20;
  int *p = &x;
  int *q = &y;
 
  if (x > 5) {
    q = p;
  }

  *p = 30;
  //OUTPUT(From LLVM IR)

  /*
    Alias information as observed at the last program point in function neo:
    p -> {q}
    q -> {p}
  */ 
}

void def(int *x, int *y)
{
  int a1 = 10, b1 = 20;
  int *c = &a1, *d = &b1;
  x = c;
  y = d;
  //OUTPUT(From LLVM IR)

  /*
    Alias information as observed at the last program point in function def:
    x -> {}
    y -> {}
    c -> {}
    d -> {}
  */ 
}

int main()
{
  int a = 5, b = 5;
  foo();
  bar();
  fun();
  neo();
  def(&a, &b);
}
