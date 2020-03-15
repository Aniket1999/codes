// DFS 


class Solution {
public:
    int l=-1;
    bool dfs(int src, int dest, char pcol, vector<vector<pair<int,char>>> &g, vector<int> &vis, string ans){
        if(src == dest){
            l=ans.size();
            return true;
        }
        
        vis[src]=1;
        
        bool res = false;
        
        for(int i=0;i<g[src].size() && !res;i++){
            if(vis[g[src][i].first] == 0){
                if(g[src][i].second != pcol){
                    res = res || dfs(g[src][i].first, dest, g[src][i].second, g, vis, ans+'l');
                    if(res) return res;
                }
            }
        }
        
        return res;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        
        vector<vector<pair<int,char>>> g(n);
        // 1  - red
        // -1 - blue 
        for(int i=0;i<r.size();i++){
            g[r[i][0]].push_back({r[i][1], 'r'});
        }
        
        for(int i=0;i<b.size();i++){
            g[b[i][0]].push_back({b[i][1], 'b'});
        }
        
        vector<int> ans(n);
        ans[0]=0;
        for(int i=1;i<n;i++){
            vector<int> vis(n,0);
            bool r = dfs(0,i,'z',g,vis,"");
            ans[i]=l;
            l=-1;
        }
        return ans;
    }
};
