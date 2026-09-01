#include <iostream>
#include <vector>
#include <windows.h> // 支援 Windows 終端機 API

using namespace std;

// 1. 演算法：判斷是否為質數 (必須放在 main 前面)
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 2. 演算法：計算第 n 個費氏數列數字 (必須放在 main 前面)
long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    // 強制設定 Terminal 輸入/輸出頁碼為 UTF-8
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "請輸入數字: ";
    int a;
    cin >> a;
    cout << "你輸入的數字是: " << a << endl;

    cout << "\n=== 演算法計算結果 ===" << endl;

    // 執行質數判斷
    if (isPrime(a)) {
        cout << "[1] " << a << " 是質數 (Prime Number)" << endl;
    } else {
        cout << "[1] " << a << " 不是質數" << endl;
    }

    // 執行費氏數列計算
    if (a >= 0 && a <= 90) { // 避免數字過大造成溢位
        cout << "[2] 費氏數列第 " << a << " 項的值為: " << fibonacci(a) << endl;
    } else {
        cout << "[2] 數字過大或為負數，跳過費氏數列計算" << endl;
    }

    cout << "\nHello World!" << endl;
    return 0;
}