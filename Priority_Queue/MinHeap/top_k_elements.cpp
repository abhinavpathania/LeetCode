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
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //1. Create frequency map
        unordered_map <int,int> mp; // Value , Frequency
        for(auto &it : nums){
            mp[it]++;
        }

        //2. Create min_Heap
        typedef pair<int,int> P; //Frequency , Value 
        priority_queue <P , vector<P> , greater<P>> minHeap;

        //3. Push element in minHeap and maintain the k size of min Heap
        for(auto &it: mp){
            int value=it.first;
            int frequency=it.second;

            minHeap.push({frequency,value});

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        //4. Store in result
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }

};

// TC:
// 