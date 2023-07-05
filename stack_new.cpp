#include <iostream>
#include <cstdlib> // digunakan untuk fungsi exit()
using namespace std;

class Stack {
  private:
    int top;
    int* arr;

  public:
    Stack() {
      top = -1;
      arr = new int[1];
    }

    bool push(int x) {
      int* new_arr;
      if (top == -1) {
        arr[0] = x;
        top = 0;
      } else {
        new_arr = new int[top+2];
        for (int i = 0; i <= top; i++) {
          new_arr[i] = arr[i];
        }
        new_arr[top+1] = x;
        top++;
        delete[] arr;
        arr = new_arr;
      }
      cout << x << " telah ditambahkan di stack" << endl;
      return true;
    }

    int pop() {
      if (top == -1) {
        cout << "Stack Underflow" << endl;
        return 0;
      } else {
        int x = arr[top--];
        if (top == -1) {
          delete[] arr;
          arr = new int[1];
        } else {
          int* new_arr = new int[top+1];
          for (int i = 0; i <= top; i++) {
            new_arr[i] = arr[i];
          }
          delete[] arr;
          arr = new_arr;
        }
        cout << x << " telah dihapus dari stack" << endl;
        return x;
      }
    }

    void display() {
      if (top == -1) {
        cout << "Stack kosong" << endl;
      } else {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
          cout << arr[i] << " ";
        }
        cout << endl;
      }
    }

    int get_top() {
      if (top == -1) {
        cout << "Stack kosong" << endl;
        return 0;
      } else {
        return arr[top];
      }
    }

    ~Stack() {
      delete[] arr;
    }
};

int main() {
  Stack s;
  int choice, x;

  while (true) {
    cout << "1. Push element" << endl;
    cout << "2. Pop element" << endl;
    cout << "3. Tampilkan stack" << endl;
    cout << "4. Lihat top element" << endl;
    cout << "5. Keluar" << endl;
    cout << "Masukkan pilihan anda: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Masukkan element yang akan diinput: ";
        cin >> x;
        s.push(x);
        break;

      case 2:
        s.pop();
        break;

      case 3:
        s.display();
        break;

      case 4:
        cout << "Top element: " << s.get_top() << endl;
        break;

      case 5:
        exit(0);
        break;

      default:
        cout << "Pilihan yang anda masukkan salah" << endl;
    }
    cout << endl;
  }

  return 0;
}
