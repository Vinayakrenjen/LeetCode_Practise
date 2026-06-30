class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string op : operations){
            if(op == "+"){
                int sum = st.top();
                int temp = st.top();
                st.pop();
                sum += st.top();
                st.push(temp);
                st.push(sum); 
            }
            else if(op == "D"){
                st.push(2*st.top());
            }
            else if(op == "C"){
                st.pop();
            }
            else{
                st.push(stoi(op));
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};