/* 
Given an array of strings s[], you are required to create an algorithm in the encode() function 
that can convert the given strings into a single encoded string, which can be transmitted over the network 
and then decoded back into the original array of strings. The decoding will happen in the decode() function.

You need to implement two functions:
1. encode(): This takes an array of strings s[] and encodes it into a single string. 
2. decode(): This takes the encoded string as input and returns an array of strings containing 
the original array as given in the encode method.

Note: You are not allowed to use any inbuilt serialize method.  

Examples:

Input: s = ["Hello","World"]
Output: ["Hello","World"]
Explanation: The encode() function will have the str as input, it will be encoded by one machine. 
Then another machine will receive the encoded string as the input parameter and then will decode 
it to its original form.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

class Solution {
  public:
    string encode(vector<string>& strs) {
        string result;
        for(const auto &s: strs){
            result+=to_string(s.size()) + '#' + s;
        }
        return result;
    }

    vector<string> decode(string& strs) {
        vector <string> result;
        int i=0;
        while(i<strs.size()){
            int j=i;
            
            while(strs[j]!='#'){
                j++;
            }
            
            int length=stoi(strs.substr(i,j-i));
            
            i=j+1;
            j=i+length;
            result.push_back(strs.substr(i,length));
            i=j;
            
        }
        return result;
    }
};