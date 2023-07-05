#include <iostream>
using namespace std;

int main() {
  int a = 10;
  int b = 15;
  int c = 27;
  cout << "Nilai variabel a " << a << endl;
  cout << "Nilai variabel b " << b << endl;
  cout << "Nilai variabel c " << c << endl;
  int *p1, *p2,*p3;
  p1=&a;
  p2=&b;
  cout << "address a/p1 " << &a << endl;
  cout << "address b/p2 " << &b << endl;
  cout << "address c " << &c << endl;

  *p1=c;
  cout << "*p1 = c " << *p1 << endl;
  a=*p2;
  cout << "a = *p2 " << a << endl;
  b=6;
  cout << "Nilai variabel b baru " << b << endl;
  p3=&b;
  cout << "Nilai p3 " << p3 << endl;
  p3=&c;
  cout << "Nilai p3 baru " << p3 << endl;
  *p1=*p3;
  cout << "=====Hasil Akhir====" << endl;
  cout << "Nilai *p1 baru " << *p1 << endl;
  cout << "Nilai *p3 baru " << *p3 << endl;
  cout << "Nilai c baru " << c << endl;
  cout << "Nilai a baru " << a << endl;


  return 0;
}
