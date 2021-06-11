/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/course-schedule-ii/
 * runtime: 16ms
 */

class Solution {
private: 
    bool Success;
    vector<int> ans;
    vector<vector<int>> crs;
    vector<int> visit;
public:
    void dfs(int i, vector<vector<int>>& crs, vector<int>& vis){
        if(vis[i] == 0){
            vis[i] = 1;
            for(auto nbr : crs[i]){
                dfs(nbr, crs, vis);
            }
            ans.push_back(i);
            vis[i] = -1;
        }
        else if(vis[i] == 1) Success = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        crs.resize(numCourses);
        visit.resize(numCourses);
        for(auto req : prerequisites){
            crs[req[0]].push_back(req[1]);
        }
        Success = true;
        for(int i=0; i<numCourses; i++) dfs(i, crs, visit);
        if(!Success) return {};
        return ans;
    }
};