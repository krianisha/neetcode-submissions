class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> s;

        for(int i=0;i<tokens.size();i++){

            if(tokens[i]!="+" && tokens[i]!="-" &&
               tokens[i]!="*" && tokens[i]!="/"){

                s.push(tokens[i]);
            }

            else if(tokens[i]=="+"){
                int a=stoi(s.top()); s.pop();
                int b=stoi(s.top()); s.pop();
                s.push(to_string(b+a));
            }

            else if(tokens[i]=="-"){
                int a=stoi(s.top()); s.pop();
                int b=stoi(s.top()); s.pop();
                s.push(to_string(b-a));
            }

            else if(tokens[i]=="*"){
                int a=stoi(s.top()); s.pop();
                int b=stoi(s.top()); s.pop();
                s.push(to_string(b*a));
            }

            else{
                int a=stoi(s.top()); s.pop();
                int b=stoi(s.top()); s.pop();
                s.push(to_string(b/a));
            }
        }

        return stoi(s.top());
    }
};