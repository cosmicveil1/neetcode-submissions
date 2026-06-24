class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> stringstack;


        int i=0;
        while(i<s.length()){
            if(isdigit(s[i])){
                int num=0;
                while(isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
                }
                numstack.push(num);
            }
            else if(s[i]==']'){
                string sub="";
                while(!stringstack.empty() && stringstack.top()!="["){
                    sub=stringstack.top()+sub;
                    stringstack.pop();
                }
                //pop out the opening bracket
                if(!stringstack.empty()) stringstack.pop();

                int count=numstack.top();
                numstack.pop();
                string repeat="";
                for(int c=0;c<count;c++){
                  repeat=repeat+sub;
                }
                //push into the stack
                stringstack.push(repeat);
                i++;
            }
            else{
                stringstack.push(string(1,s[i]));
                i++;
            }
        }
       string result="";
       while(!stringstack.empty()){
        result = stringstack.top() + result;
        stringstack.pop();
       }
       return result;
    }
};