#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers are not palindromes (e.g., -121 -> 121-)
    // Non-zero numbers ending in 0 are not palindromes (e.g., 10 -> 01)
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // For even length: x == reversedHalf (e.g., 1221 -> x=12, reversedHalf=12)
    // For odd length: x == reversedHalf / 10 (e.g., 121 -> x=1, reversedHalf=12)
    return x == reversedHalf || x == reversedHalf / 10;
}