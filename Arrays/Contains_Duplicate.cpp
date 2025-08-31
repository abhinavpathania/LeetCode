/*
Question: Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> set;
        for(auto num : nums){
            if(set.find(num) != set.end()){
                return true;
            }
            else{
                set.insert(num);
            }
        }
        return false;
    }
};