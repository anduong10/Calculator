#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int Calculation(int number_1, int number_2) {
    return number_1 + number_2;
}


double Calculation(double number_1, double number_2) {
    return number_1 * number_2;
}


long Calculation(long number_1, long number_2) {
    return number_1 - number_2;
}
long long Calculation(long long number_1) {
    long long factorial = 1;
    for (int i = 2; i <= number_1; i++) {
        factorial *= i;
    }
    return factorial;
}


float Calculation(float number_1, float number_2) {
    if (number_2 == 0) {
        cout << "Error: Division by zero." << endl;
        return 0;
    }
    return number_1 / number_2;
}

int main() {
    string menu;
    float number_1, number_2;

    cout << "Choose an operation: Add, Subtract, Multiply, Divide, or Factorial" << endl;
    cin >> menu;

    cout << "Number 1: ";
    cin >> number_1;

    if (menu == "Factorial") {
        cout << "Result: " << Calculation((long long)number_1) << endl;
    } else {
        cout << "Number 2: ";
        cin >> number_2;

        if (menu == "Add") {
            cout << "Result: " << Calculation((int)number_1, (int)number_2) << endl;
        } else if (menu == "Subtract") {
            cout << "Result: " << Calculation((long)number_1, (long)number_2) << endl;
        } else if (menu == "Multiply") {
            cout << "Result: " << Calculation((double)number_1, (double)number_2) << endl;
        } else if (menu == "Divide") {
            cout << "Result: " << Calculation((float)number_1, (float)number_2) << endl;
        } else {
            cout << "Error: Invalid input." << endl;
        }
    }

    return 0;
}