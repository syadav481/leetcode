#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void rearrangeWord(string word) {
  (next_permutation(word.begin(), word.end())) ? cout << word << endl
                                               : cout << "no answer" << endl;
}

int main() {
  rearrangeWord("xy");
  rearrangeWord("abc");
}