#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
  private:
    int top;
    int arr[MAX_SIZE];

  public:
    Stack() {
      top = -1;
    }

    bool push(int x) {
      if (top >= MAX_SIZE - 1) {
        cout << "Stack Overflow" << endl;
        return false;
      } else {
        arr[++top] = x;
        cout << x << " has been added to the stack" << endl;
        return true;
      }
    }

    int pop() {
      if (top < 0) {
        cout << "Stack Underflow" << endl;
        return 0;
      } else {
        int x = arr[top--];
        return x;
      }
    }
};

int main() {
  Stack s;

  s.push(5);
  s.push(10);
  s.push(15);

  cout << s.pop() << " has been removed from the stack" << endl;
  cout << s.pop() << " has been removed from the stack" << endl;

  s.push(20);

  cout << s.pop() << " has been removed from the stack" << endl;
  cout << s.pop() << " has been removed from the stack" << endl;
  cout << s.pop() << " has been removed from the stack" << endl;

  return 0;
}
