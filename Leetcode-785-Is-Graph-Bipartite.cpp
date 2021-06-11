/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/is-graph-bipartite/
 * runtime: 16ms
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> color(graph.size(), 0);
        for(int i=0; i<graph.size(); i++){
            if(color[i] != 0) continue;
            else{
                color[i] = 1;
                q.push(i);
            }
            while(!q.empty()){
                int tmp = q.front(); q.pop();
                for(auto nbr : graph[tmp]){
                    if(color[nbr] == 0){
                        color[nbr] = -color[tmp];
                        q.push(nbr);
                    }
                    else{
                        if(color[nbr] == color[tmp]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};