class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int total=0;
    for(string t:tokens){
        if(t=="+"||t=="-"||t=="/"||t=="*"){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(t=="+")st.push(b+a);
            if(t=="-")st.push(b-a);
            if(t=="*")st.push(b*a);
            if(t=="/")st.push(b/a);

        }else st.push(stoi(t));
    }
    return st.top();
    }
};