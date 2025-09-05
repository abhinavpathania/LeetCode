/* 
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        //1.Frequncy map
        unordered_map <int,int> mp;
        for(auto &it : nums){
            mp[it]++;
        }

        //2. Bucket creation where the frequency is represented by the index and the elements are values
        vector <vector<int>> bucket(n+1);

        for(auto &it : mp){

            int element = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(element);
        }
        //3. Result
        vector<int> result;
        for(int i=n;i>=0;i--){

            if(bucket[i].size()==0){
                continue;
            }
            while(bucket[i].size()>0 && k>0){
                result.push_back(bucket[i].back()); // Take values from last
                bucket[i].pop_back(); //Take out that ele that is used.
                k--;
            }
        }
        return result;
    }
};