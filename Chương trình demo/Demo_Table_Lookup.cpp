#include <iostream> 
#include <chrono>
#include <cmath> 
using namespace std;

int main() { 
    int n = 1000000;
    int m = n;
    
    string res = "";
    int x;
    auto start1 = chrono::system_clock::now();  
    string a[16];
    a[0] = "0000";
    a[1] = "0001";
    a[2] = "0010";
    a[3] = "0011";
    a[4] = "0100";
    a[5] = "0101";
    a[6] = "0110";
    a[7] = "0111";
    a[8] = "1000";
    a[9] = "1001";
    a[10] = "1010";
    a[11] = "1011";
    a[12] = "1100";
    a[13] = "1101";
    a[14] = "1110";
    a[15] = "1111";
    for (int i = 0; i < 80000; i++) { 
        x = m % 16;
        res = a[x] + res;
        m /= 16;
    }
    auto end1 = chrono::system_clock::now();  
    chrono::duration<double> elapsed_seconds1 = end1 - start1; 
    cout << endl << "Thoi gian thuc hien: " << elapsed_seconds1.count() << " giay" << endl;
    res = "";
    m = n;
    auto start2 = chrono::system_clock::now();  
    string b[2];
    b[0] = "0";
    b[1] = "1";
    for (int i = 0; i < 320000; i++) { 
        x = m % 2;
        res = b[x] + res;
        m /= 2;
    }
    auto end2 = chrono::system_clock::now();  
    chrono::duration<double> elapsed_seconds2 = end2 - start2; 
    cout << endl << "Thoi gian thuc hien: " << elapsed_seconds2.count() << " giay" << endl;
    cout << endl << "Chenh lech khong gian bo nho: " << sizeof(a) - sizeof(b) << " bytes\n" ;
    return 0;
}

