#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public: 
	vector<int> decode(vector<int>& encoded, int first){
		encoded.insert(encoded.begin(), first); 
		for (int i = 1; i < encoded.size(); ++i) {
			encoded[i] = encoded[i] ^ encoded[i - 1]; 
		}
		return encoded; 
	}
}; 
int main() {}
