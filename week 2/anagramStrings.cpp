#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 someFile.cpp -std=c++17 && ./a.out

*/

using namespace std;

bool isAnagram(string s, string t) {
  if (s.size() != t.size()) return false;

  vector<int> letters(26);

  for (int i = 0; i < s.size(); i++) {
    int index1 = s[i] - 97;
    int index2 = t[i] - 97;
      
    letters[index1]++;
    letters[index2]--;
  }

  for (int j = 0; j < 26; j++) {
    if (letters[j] != 0) return false;
  }

  return true;
};


int main() {

    assert(isAnagram("anagram","nagaram") == true);
    assert(isAnagram("rat","car") == false);

    return 0;
}