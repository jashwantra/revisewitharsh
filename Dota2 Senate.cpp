class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.length();
        queue<int> r,d;
        for(int i=0;i<senate.length();i++){
            if(senate[i]=='R')
                r.push(i);
            else
                d.push(i);
        }
        while(1){
            if(r.empty() && !d.empty())
                return "Dire";
            if(d.empty() && !r.empty())
                return "Radiant";
            int a=r.front(),b=d.front();
            r.pop();d.pop();
            if(a<b){
                r.push(n++);
            }
            else{
                d.push(n++);
            }
        }
        return "";
    }
};
