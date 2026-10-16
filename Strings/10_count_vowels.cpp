// Striver A2Z DSA - Strings Easy | Q10
// Problem: Count Vowels in a String
// Platform: GFG / Custom
// Core pattern: character classification

#include <bits/stdc++.h>
using namespace std;

// Approach: Linear scan, check each character against set of vowels
// Time Complexity: O(n) | Space Complexity: O(1)

int countVowels(string s) {
    string vowels = "aeiouAEIOU";
    int count = 0;
    for (char c : s) {
        if (vowels.find(c) != string::npos)
            count++;
    }
    return count;
}

int main() {
    cout << "Vowels in 'Hello World': " << countVowels("Hello World") << endl;  // 3
    cout << "Vowels in 'programming': " << countVowels("programming") << endl;   // 3
    return 0;
}
