// Problem: Reverse Bits
// Approach: Shift 'result' left by 1 each iteration, copy the least significant bit of 'n' using (n & 1),
//           and shift 'n' right by 1 across all 32 bits.
// Time Complexity: O(1) (fixed 32 iterations)
// Space Complexity: O(1)

#include <cstdint>
#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        result <<= 1;      // Shift left to make space for the next bit
        result |= (n & 1); // Extract the least significant bit of n and set it in result
        n >>= 1;           // Shift n right to process the next bit
    }

    return result;
}

int main() {
    uint32_t n = 43261596;
    cout << reverseBits(n) << endl; // Expected output: 964176192

    return 0;
}
