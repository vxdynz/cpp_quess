// Striver A2Z DSA - Strings Easy | Q2
// Problem: Reverse Words in a String
// LeetCode: 151
// Link: https://leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>
using namespace std;

// Approach: Use stringstream to extract words, then reverse the list
// Time Complexity: O(n) | Space Complexity: O(n)

string reverseWords(string s) {
    istringstream iss(s);
    string word, result = "";
    vector<string> words;
    while (iss >> word) words.push_back(word);
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) result += " ";
    }
    return result;
}

int main() {
    cout << reverseWords("the sky is blue") << endl;  // blue is sky the
    cout << reverseWords("  hello world  ") << endl;  // world hello
    return 0;
}
