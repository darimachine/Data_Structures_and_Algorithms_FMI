
class Solution {
public:
    vector<int> result;
    int suspicionsAddedCounter=0;
    
    void suspiciousFinderDfs(unordered_map<int,unordered_set<int>>& graph,
     unordered_set<int>& suspicious,int start)
     {
        suspicious.insert(start);

        for(auto& el :graph[start])
        {
            if(suspicious.count(el)==0)
            {
                suspiciousFinderDfs(graph,suspicious,el);
            }
        }
     }
    void bfs(unordered_map<int,unordered_set<int>>& graph,unordered_set<int>& visited,unordered_set<int>& suspicious, int idx)
    {
        queue<int> q;
        if(suspicious.count(idx)!=0){
            return;
        }
        else{
            result.push_back(idx);
        }
        q.push(idx);
        while(!q.empty()) 
        {
            int node = q.front();
            q.pop();
            for(auto& el : graph[node]){
                if(visited.count(el)==0)
                {
                    visited.insert(el);
                    if(suspicious.count(el)!=0)
                    {
                        result.push_back(el);
                        suspicionsAddedCounter++;
                    }
                    q.push(el);
                }
            }
        }  
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> suspicious;
        unordered_map<int,unordered_set<int>> graph;
        for(auto& el :invocations)
        {
            int first=el[0];
            int second=el[1];
            graph[first].insert(second);
        }
        
        unordered_set<int> visited;
        suspiciousFinderDfs(graph,suspicious,k);
        
        for(int i=0;i<n;i++)
        {
            bfs(graph,visited,suspicious,i);
        }
        if(suspicionsAddedCounter == 0 || suspicionsAddedCounter == suspicious.size())
        {
            return result;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
