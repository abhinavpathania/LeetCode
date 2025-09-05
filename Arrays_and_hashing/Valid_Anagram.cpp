/* 
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map <char,int> map;
        for(auto ele : s){
            map[ele]++;
        }
        for(auto ele : t){
            if(map.find(ele)!= map.end()){
                map[ele]--;
            }
        }
        for(auto &pair : map){
            if(pair.second != 0){
                return false;
            }
        }
        return true;
    }
};