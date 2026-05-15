// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         sort(nums.begin(),nums.end());

//         int mini=nums[0];

//         return mini;
//     }
// };



//for interview purpose , or interviewer purpose accoding to problem what exactly expected

class Solution {
    public:
     int binarySerarch(int l, int r, vector<int>& nums){
        

        while(1){
            if(l==r){
                return nums[l];
            }

            int mid= (r-l)/2+l;

            if(nums[mid]<nums[r]){
                r=mid;
            }else if(nums[mid]>nums[r]){
                l=mid+1;
            }else if(nums[mid]==nums[r]){
                r--;
            }
        }
     }
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
       
       int mini = binarySerarch(0,n-1,nums);

       return mini;
    }
};