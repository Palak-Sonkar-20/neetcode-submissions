class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string ch : tokens) {

            // If it is a number
            if (ch != "*" && ch != "/" && ch != "+" && ch != "-") {
                st.push(stoi(ch));
            }
            else {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int result = 0;

                if (ch == "+")
                    result = b + a;

                else if (ch == "-")
                    result = b - a;

                else if (ch == "*")
                    result = b * a;

                else if (ch == "/")
                    result = b / a;

                st.push(result);
            }
        }

        return st.top();
    }
};