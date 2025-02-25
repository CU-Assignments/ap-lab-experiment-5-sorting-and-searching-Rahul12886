class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int minel=*min_element(nums.begin(),nums.end());
       int maxel=*max_element(nums.begin(),nums.end());
       int num=maxel-minel+1;
       vector<int>v(num);
       for(int i=0;i<nums.size();i++){
            v[nums[i]-minel]++;
       }
       int sum=0;
       for(int i=num-1;i>=0;i--){
        sum=sum+v[i];
            if(sum>=k){
                return i+minel;
            }
       }return -1;
    }
};
