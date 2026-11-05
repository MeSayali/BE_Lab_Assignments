
#include <iostream>
using namespace std;

// Recursive function
int fibonacci(int n) {

    if(n == 0) {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

// Non-recursive function
void fibonacciIterative(int n) {

    int a = 0, b = 1, c;

    for(int i = 0; i < n; i++) {

        cout << a << " ";

        c = a + b;
        a = b;
        b = c;
    }
}

int main() {

    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    // Recursive approach
    cout << "\nFibonacci Series (Recursive): ";

    for(int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    // Non-recursive approach
    cout << "\nFibonacci Series (Non-Recursive): ";

    fibonacciIterative(n);

    return 0;
}
