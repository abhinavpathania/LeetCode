/* 
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int,bool> visited;
        for(int num:nums){
            visited[num]=false;
        }
        int maxLength=0;
        for(auto num:nums){
            if(visited[num]==true) continue;
            visited[num]=true;
            int length =1;

            // check left

            int left=num-1;
            while(visited.count(left) && !visited[left]){ //Exists and not visited
                visited[left]=true;
                length++;
                left--;
            }
            // check right

            int right = num+1;
            while(visited.count(right) && !visited[right]){
                visited[right]=true;
                length++;
                right++;
            }
            maxLength=max(maxLength,length);
        }
        return maxLength;   
    }
};