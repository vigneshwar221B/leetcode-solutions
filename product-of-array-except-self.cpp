#include<iostream>
#include<vector>

using namespace std;

// 1st approach
// vector<int> productExceptSelf(vector<int>& nums) {
        
//   vector<int> res;
//   int prod = 1;
//   for(int i=0; i<nums.size(); i++)
//     prod *= nums[i];

//   for(int i=0; i<nums.size(); i++)
//     res.push_back(prod/nums[i]);
  
//   return res;
// }

// 2nd approach
// inp: [1, 2, 3, 4]
// out: [24, 12, 8, 6]
// soln:
// left: [1, 1, 2, 6]
// right: [24, 12, 4, 1]

// vector<int> productExceptSelf(vector<int>& nums) {
        
//   int n=nums.size();
//   vector<int> left(n);
//   vector<int> right(n);
  
//   left[0]=1;
//   for(int i=1;i<n;i++)
//     left[i]=left[i-1]*nums[i-1];
  
//   right[n-1]=1;
//   for(int i=n-2;i>=0;i--)
//     right[i]=right[i+1]*nums[i+1];
  
//   vector<int> res(n);
//   for(int i=0;i<n;i++)
//     res[i]=left[i]*right[i];
  
//   return res;
// }

//3rd approach - O(1) space 
vector<int> productExceptSelf(vector<int>& nums) {      
  int n=nums.size();
  vector<int> res(n,1);
  
  for(int i=1;i<n;i++)
    res[i] = res[i-1]*nums[i-1];
  
  int tright = 1;
  for(int i=n-1;i>=0;i--){
    res[i] *= tright;
    tright *= nums[i];
  }
  
  return res;
}

int main(){
  vector<int> inp = {1, 2, 3, 4};
  for(auto it: productExceptSelf(inp)){
    cout<<it<<" ";
  }
}