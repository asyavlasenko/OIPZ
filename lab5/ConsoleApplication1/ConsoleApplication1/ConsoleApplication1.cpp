#include <iostream>
#include <fstream>
using namespace std;

bool isValidInput(int n, int step) {
    if (n < 1) {
        cout << "Error! The value of n must be at least 1." << endl;
        return false;
    }
    if (step <= 0) {
        cout << "Error! Step size must be greater than 0." << endl;
        return false;
    }
    return true;
}

double calculateY(double x, int n) {
    double y = 0;
    if (x < 0) {
        for (int i = 1; i <= n - 1; ++i) {
            for (int j = 1; j <= n; ++j) {
                y += (x - i + j);
            }
        }
    }
    else {
        for (int i = 0; i <= n - 1; ++i) {
            if (i != 0) {
                y += x / i;
            }
        }
    }
    return y;
}

void saveResults(double x, double y, ofstream& outFile) {
    cout << "x = " << x << ", y = " << y << endl;
    outFile << "x = " << x << ", y = " << y << endl;
}

int main() {
    int n, start, stop, step;
    cout << "Enter the start and end of the interval, step size, and value of n: ";
    cin >> start >> stop >> step >> n;

    if (!isValidInput(n, step)) {
        return 1;
    }

    ofstream outFile("results.txt");
    if (!outFile.is_open()) {
        cout << "Error! Could not open file for writing." << endl;
        return 1;
    }

    for (double x = start; x <= stop; x += step) {
        double y = calculateY(x, n);
        saveResults(x, y, outFile);
    }

    outFile.close();
    cout << "Results have been saved to results.txt!" << endl;

    return 0;
}