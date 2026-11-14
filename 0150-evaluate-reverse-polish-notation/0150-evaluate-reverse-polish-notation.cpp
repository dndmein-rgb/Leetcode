class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto& t:tokens){
            if(t=="+"||t=="-"||t=="/"||t=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int result=0;
                if(t=="+")result=b+a;
                else if(t=="-")result=b-a;
                else if(t=="*")result=b*a;
                else result=b/a;
                st.push(result);
            }
            else st.push(stoi(t));
        }
        return st.top();
    }
};