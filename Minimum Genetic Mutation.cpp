class Solution {
public:
    vector<string> genegenerate(string gene){
        string x="ACGT";
        vector<string> ans;
        for(int i=0;i<8;i++){
            for(int j=0;j<4;j++){
                string temp=gene;
                if(temp[i]==x[j])
                    continue;
                temp[i]=x[j];
                ans.push_back(temp);
            }
        }
        return ans;
    }
    int minMutation(string startGene, string endGene, vector<string>& Bank) {
        unordered_map<string,bool> visited,bank;
        queue<pair<string,int>> q;
        for(string gene:Bank)
            bank[gene]=true;
        if(bank[endGene]==false)
            return -1;
        q.push({startGene,0});
        visited[startGene]=true;
        while(!q.empty()){
            string gene=q.front().first;
            int level=q.front().second;
            q.pop();
            if(gene==endGene)
                return level;
            vector<string> newgenes=genegenerate(gene);
            for(string newgene:newgenes){
                if(bank.find(newgene)!=bank.end() && visited[newgene]==false){
                    q.push({newgene,level+1});
                    visited[newgene]=true;
                }
            }
        }
        return -1;
    }
};
