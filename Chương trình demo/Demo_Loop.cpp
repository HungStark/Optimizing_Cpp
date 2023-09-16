#include <iostream> 
#include <chrono>
#include <cmath> 
using namespace std;

int main() { 
    long long n = 30000;
    long long sum1 = 0, sum2 = 0;
    int x = 8;
    cout << endl;
    auto start1 = chrono::system_clock::now();  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            sum1 += 2 * x + i + j;
        }
        for (int k = 0; k < n; k++) {
            sum2 += 3 * x + i - k;
        }
    }
    auto end1 = chrono::system_clock::now();  
    chrono::duration<double> elapsed_seconds1 = end1 - start1; 
    cout << "Thoi gian thuc hien: " << elapsed_seconds1.count() << " giay" << endl;
    cout << endl;
    auto start2 = chrono::system_clock::now();  
    int a = 2 * x; 
    int b = 3 * x;
    for (int i = 0; i < n/2; i+=2) {
        for (int j = 0; j < n/2; j+=2) {
            sum1 += a + i + i + 1 + j + j + 1;
            sum2 += b + i + i + 1 - j - j - 1;
        }
    }
    auto end2 = chrono::system_clock::now();  
    chrono::duration<double> elapsed_seconds2 = end2 - start2; 
    cout << "Thoi gian thuc hien: " << elapsed_seconds2.count() << " giay" << endl;
    cout << endl;
    return 0;
}

