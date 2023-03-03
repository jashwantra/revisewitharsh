class Solution {
public:
    vector<string> transaction(string x){
        vector<string> ans;
        string temp="";
        int i=0;
        for(int k=0;k<4;k++){
            while(x[i]!=',' && i<x.length()){
                temp+=x[i];
                i++;
            }
            ans.push_back(temp);
            i++;
            temp="";
        }
        return ans;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> name,city;
        vector<int> time,amount;
        vector<int> invalid(transactions.size(),0);
        for(int i=0;i<transactions.size();i++){
            vector<string> temp=transaction(transactions[i]);
            name.push_back(temp[0]);
            city.push_back(temp[3]);
            time.push_back(stoi(temp[1]));
            amount.push_back(stoi(temp[2]));
        }
        for(int i=0;i<transactions.size();i++){
            if(amount[i]>1000)
                invalid[i]=1;
            for(int j=i-1;j>=0;j--){
                if(name[i]==name[j] && city[i]!=city[j] && abs(time[i]-time[j])<=60){
                    invalid[i]=1;
                    invalid[j]=1;
                }
            }
        }
        vector<string> ans;
        for(int i=0;i<invalid.size();i++)
            if(invalid[i]==1)
                ans.push_back(name[i]+","+(to_string(time[i]))+","+(to_string(amount[i]))+","+city[i]);
        return ans;
    }
};
