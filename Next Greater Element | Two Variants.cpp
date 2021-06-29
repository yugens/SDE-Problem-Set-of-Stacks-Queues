//Best Approach having time complexity o(2n+2n)~o(n) and space complexity o(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--)
        {
           while(!st.empty() and st.top()<=nums[i%n])
               st.pop();
            if(i<n)
            {
                if(!st.empty())
                    next[i]=st.top();
            }
            st.push(nums[i%n]);
        }
        return next;
    }
};
