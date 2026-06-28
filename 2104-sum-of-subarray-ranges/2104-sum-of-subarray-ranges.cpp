class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>pse(n),nse(n),pge(n),nge(n);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            nse[i] = st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            pge[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()]<nums[i])
                st.pop();
            nge[i] = st.empty()?n:st.top();
            st.push(i);
        }
        long long maxi = 0;
        long long mini = 0;
        for(int i = 0; i < n; i++){
            long long ls = i - pse[i];
            long long rs = nse[i] - i;
            mini += nums[i] * ls * rs;
            long long lg = i - pge[i];
            long long rg = nge[i] - i;
            maxi += nums[i] * lg * rg;
        }
        return maxi - mini;
    }
};