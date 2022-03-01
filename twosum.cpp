#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// "obvious" solution
// vector<int> twoSum(vector<int>&& nums, int target) {
//     int first, second;
    
//     for(int i = 0; i<nums.size(); i++){
//         first = i;
//         for(int j=i+1; j<nums.size(); j++){
//             second = j;
//             if(nums[first] + nums[second] == target)
//                 return {first, second};
//         }
//     }
    
//     return {};
// }

//use hashmap
vector<int> twoSum(vector<int>&& nums, int target) {
  unordered_map<int, int> imap;

  for (int i = 0; nums.size(); ++i) {
      auto it = imap.find(target - nums[i]);

      if (it != imap.end()) 
          return vector<int> {i, it->second};

      imap[nums[i]] = i;
  }

  return {};
}

int main(){
  vector<int> ans = twoSum(vector<int> {2, 7, 11, 15}, 9);
  cout<<ans[0]<<", "<<ans[1];
}