class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int i=0;
        int s=0;
        int temp=k;
        int zer=0;
        vector<int>location;
        if(k==0){
            for(auto it : nums){
                if(it==1){
                    temp++;
                }
                else{
                    ans=max(ans,temp);
                    temp=0;
                }
            }
            ans=max(ans,temp);
            return ans;
        }
        while(i<nums.size()){
           if(nums[i]==1){
               i++;
           }
           else if(nums[i]==0 && temp>0){
                temp--;
                location.push_back(i);
                i++;
           }
           else{
               ans=max(ans,i-s);
               s=location[zer]+1;
               zer++;
               temp++;
           }
        }
        if(temp>=0){
            ans=max(ans,i-s);
        }
        return ans;
    }
};