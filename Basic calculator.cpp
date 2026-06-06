//I use a stack to store the previous result and sign whenever I encounter a parenthesis, and evaluate the expression in one pass.
class Solution {
public:
    int calculate(string s) {
        long long res = 0;
        int sign = 1;
        long long curr = 0;
        stack<int> st;
        for(char c : s){
            if(isdigit(c)){
                curr = curr * 10 + (c - '0');
            }
            else if(c == '+'){
                res += sign * curr;
                sign = 1;
                curr = 0;
            }
            else if(c == '-'){
                res += sign * curr;
                sign = -1;
                curr = 0;
            }
            else if(c == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(c == ')'){
                res += sign * curr;
                curr = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();          
                }
        }
        res += sign * curr;
        return res;
    }
};
