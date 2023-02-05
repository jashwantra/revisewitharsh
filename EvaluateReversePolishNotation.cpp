class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        long long int x,y;
        for(string str:tokens){
            if(str=="+"){
                y=st.top();st.pop();x=st.top();st.pop();
                st.push(x+y);    
            }
            else if(str=="-"){
                y=st.top();st.pop();x=st.top();st.pop();
                st.push(x-y);  
            }
            else if(str=="*"){
                y=st.top();st.pop();x=st.top();st.pop();
                st.push(x*y); 
            }
            else if(str=="/"){
                y=st.top();st.pop();x=st.top();st.pop();
                st.push(x/y); 
            }
            else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
