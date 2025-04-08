/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/course-schedule/description/
 * runtime: 0ms
 */

class Solution1 { // DFS with path tracker
public:
    bool dfs(int node, vector<vector<bool>> &graph, vector<bool> &vis, vector<bool> &pathVis) {
        if(vis[node] && pathVis[node]) return true;
        else if(vis[node] && !pathVis[node]) return false;
        vis[node] = true;
        for(int j=0; j<graph[node].size(); j++) {
            if(graph[node][j]) {
                pathVis[node] = true;
                if(dfs(j, graph, vis, pathVis)) {
                    return true;
                }
                pathVis[node] = false;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        for(vector<int> &preReq : prerequisites) {
            graph[preReq[1]][preReq[0]] = true;
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        for(int i=0; i<numCourses; i++) {
            if(dfs(i, graph, vis, pathVis)) {
                return false;
            }
        }
        return true;
    }
};


class Solution2 { // Topo sort with cycle detection
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto preReq : prerequisites) {
            indegree[preReq[0]]+=1;
            adj[preReq[1]].push_back(preReq[0]);
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(auto adj : adj[node]){
                indegree[adj] -= 1;
                if(indegree[adj] == 0) q.push(adj);
            }
            topo.push_back(node);
        }
        if(topo.size() != numCourses) return false;
        else return true;
    }
};