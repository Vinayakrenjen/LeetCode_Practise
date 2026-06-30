class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        for(string op : logs){
            if(op == "../"){
                if(!st.empty())
                    st.pop();
            }
            else if(op == "./")
                continue;
            else{
                st.push(op);
            }
        }
        int i = 0;
        while(!st.empty()){
            st.pop();
            i++;
        }
        return i;
    }
};