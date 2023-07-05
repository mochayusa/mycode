#include <iostream>
using namespace std;

class Queue {
  private:
    int front, rear, size;
    int* arr;

  public:
    Queue(int s) {
      front = rear = -1;
      size = s;
      arr = new int[size];
    }

    bool isEmpty() {
      return front == -1;
    }

    bool isFull() {
      return rear == size - 1;
    }

    bool push(int x) {
      if (isFull()) {
        cout << "Queue Overflow" << endl;
        return false;
      } else if (isEmpty()) {
        front = rear = 0;
      } else {
        rear++;
      }
      arr[rear] = x;
      cout << x << " has been added to the queue" << endl;
      return true;
    }

    int pop() {
      if (isEmpty()) {
        cout << "Queue Underflow" << endl;
        return -1;
      } else {
        int x = arr[front];
        if (front == rear) {
          front = rear = -1;
        } else {
          front++;
        }
        cout << x << " has been removed from the queue" << endl;
        return x;
      }
    }

    void display() {
      if (isEmpty()) {
        cout << "Queue is Empty" << endl;
      } else {
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
          cout << arr[i] << " ";
        }
        cout << endl;
      }
    }

    ~Queue() {
      delete[] arr;
    }
};

int main() {
  int size;
  cout << "Enter the size of the queue: ";
  cin >> size;
  Queue q(size);

  int choice = 0;
  while (choice != 4) {
    cout << "Enter 1 to Push, 2 to Pop, 3 to Display or 4 to Exit: ";
    cin >> choice;
    switch (choice) {
      case 1: {
        int val;
        cout << "Enter the value to be pushed: ";
        cin >> val;
        q.push(val);
        break;
      }
      case 2: {
        int x = q.pop();
        if (x != -1) {
          cout << x << " has been removed from the queue" << endl;
        }
        break;
      }
      case 3: {
        q.display();
        break;
      }
      case 4: {
        cout << "Exiting program..." << endl;
        break;
      }
      default: {
        cout << "Invalid choice. Try again." << endl;
        break;
      }
    }
  }
  return 0;
}
