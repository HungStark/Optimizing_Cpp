#include <iostream>
#include <chrono>
#include <cmath> 

using namespace std;

// Quy hoạch động
long long dynamic(int n, int &x)
{
    if (n == 0) return 0;
    long long a[n + 1];
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    x = sizeof(a);
    return a[n];
}

// Đệ quy
long long recuse(int n)
{
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    return recuse(n - 1) + recuse(n - 2);
}

int main() { 
    int n;
    cin >> n;
    auto start1 = chrono::system_clock::now();  
    recuse(n);
    auto end1 = chrono::system_clock::now();  
    chrono::duration<double> elapsed_seconds1 = end1 - start1; 
    cout << endl << "Thoi gian thuc hien: " << elapsed_seconds1.count() << " giay" << endl;
    
    auto start2 = chrono::system_clock::now(); 
    int x;
    dynamic(n,x);
    auto end2 = chrono::system_clock::now();  
    chrono::duration<double> elapsed_seconds2 = end2 - start2; 
    cout << endl << "Thoi gian thuc hien: " << elapsed_seconds2.count() << " giay" << endl;
    cout << endl << "Khong gian bo nho: " << x << " bytes" << endl;
    return 0;
}