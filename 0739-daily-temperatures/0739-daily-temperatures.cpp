class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>nge(temperatures.size());
        stack<int>st;
        for(int i = temperatures.size() - 1; i >= 0 ; i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
                st.pop();
            nge[i]=st.empty()?0:st.top()-i;
            st.push(i);
        }
        return nge;
    }
};