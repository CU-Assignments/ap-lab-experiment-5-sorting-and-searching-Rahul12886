class Solution {//OPTIMAL, taking boundary indexes earlier - BS-9,,,T-O(LOG N ), S-O(1)
public: //see it like an [] of vallies(pahad) where we have multuple peaks, test for one apply for all 
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), low = 1, high = n-2;
        if(n==0 || n==1) return 0;//for empty []

        //taking boundary cases 
        if(nums[0] > nums[1]) return 0; //peak is 0th index
        if(nums[n-1] > nums[n-2]) return n-1; //peak is last index

        while(low <= high){
            int mid = (low + high)/2;
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid + 1]) return mid;

            if(nums[mid] >= nums[mid-1]) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
};
