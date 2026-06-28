class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>prev(arr.size()),next(arr.size());
        stack<int>st;
        for(int i = 0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>=arr[i])
                st.pop();
            prev[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            next[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        long long total = 0;
        int MOD = 1e9 + 7;
        for(int i = 0;i<arr.size();i++){
            long long left = i - prev[i];
            long long right = next[i] - i;
            total = (total + (1LL * arr[i] * left * right) % MOD) % MOD; 
        }
        return total;
    }
};