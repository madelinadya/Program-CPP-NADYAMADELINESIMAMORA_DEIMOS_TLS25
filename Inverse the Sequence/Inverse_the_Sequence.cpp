#include <iostream>
#include <vector>
#include <cmath>

// ---=== Function to reverse a single integer ===---
// This function reverses the digits of a number.
// Example: 123 -> 321, -45 -> -54
int reverseInteger(int num) {
    long long reversed_num = 0;
    int sign = (num < 0) ? -1 : 1;
    num = abs(num);

    while (num > 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    // Check for potential overflow before returning
    if (reversed_num > 2147483647 || reversed_num < -2147483648) {
        return 0; // Or handle overflow as needed
    }

    return reversed_num * sign;
}

// ---=== Main Program Logic ===---
int main() {
    // --- Input Section ---
    int n;
    std::cout << "Masukkan jumlah elemen dalam array: ";
    std::cin >> n;

    // Use std::vector for a dynamic array
    std::vector<int> arr(n);
    std::cout << "Masukkan " << n << " elemen array (pisahkan dengan spasi): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // --- Processing Section: Reversing the array sequence ---
    // Using the two-pointer approach
    int start = 0;
    int end = n - 1;
    while (start < end) {
        // Swap elements at start and end pointers
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move pointers towards the center
        start++;
        end--;
    }

    // --- Output Section ---
    std::cout << "\nArray setelah dibalik urutannya: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}