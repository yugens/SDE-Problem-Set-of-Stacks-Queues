class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
              if(!st.empty() and ((s[i]==')' and st.top()=='(') or (s[i]==']' and st.top()=='[') or (s[i]=='}' and st.top()=='{')))
               st.pop();
               else
               st.push(s[i]);
            
        }
        return st.empty();
        
    }
};
