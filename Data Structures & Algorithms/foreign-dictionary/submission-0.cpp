class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        string ans = "";
        vector<int>adj[26];
        vector<int>present(26);
        vector<int>indegree(26);
        
        for(auto word : words){
            for(char c : word){
                present[c - 'a'] = 1;
            }
        }
        
        
        for(int i = 0;i<n-1;i++){
             string a1 = words[i];
             string b1 = words[i+1];
             
             
             // invalid prefix case
            if(a1.size() > b1.size() && a1.substr(0, b1.size()) == b1)
                return "";
             
             int j = 0;
             while(j<min(a1.size(),b1.size())){
                 if(a1[j] != b1[j]){
                     
                     adj[a1[j] - 'a'].push_back(b1[j] - 'a');
                     break;
                 }
                 j++;
             }
        }
        
        for(int i=0;i<26;i++){
            if(adj[i].size()){
                
                for(auto it : adj[i]){
                    indegree[it]++;
                }
            }
                
        }
        
        queue<int>q;
        for(int i=0;i<26;i++){
            if(present[i] && indegree[i] == 0)
            q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += (node+'a');
            
            for(auto it: adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(present[i]) count++;
        }
        
        if(ans.size() != count)
            return "";  // cycle detected
        
       
        return ans;
        
    }
};
