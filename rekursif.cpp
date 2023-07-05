#include <iostream>
using namespace std;

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

void printMenu() {
  cout << "Enter 1 for Factorial, 2 for Fibonacci or 3 to Exit: ";
}

int main() {
  int choice = 0;
  while (choice != 3) {
    printMenu();
    cin >> choice;
    switch (choice) {
      case 1: {
        int n;
        cout << "Enter a number to find its factorial: ";
        cin >> n;
        int result = factorial(n);
        cout << "The factorial of " << n << " is " << result << endl;
        break;
      }
      case 2: {
        int n;
        cout << "Enter a number to find its Fibonacci value: ";
        cin >> n;
        int result = fibonacci(n);
        cout << "The Fibonacci value of " << n << " is " << result << endl;
        break;
      }
      case 3: {
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
