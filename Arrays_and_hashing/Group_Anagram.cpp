/* 
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n=strs.size();

        vector<vector<string>> result;
        unordered_map <string , vector<string>> anagramGroups;

        for(int i=0;i<n;i++){
            string sortedString = strs[i];
            sort(sortedString.begin(),sortedString.end());

            anagramGroups[sortedString].push_back(strs[i]);
        }
        for(auto str : anagramGroups){
            result.push_back(str.second);
        }

       return result;
    }
};