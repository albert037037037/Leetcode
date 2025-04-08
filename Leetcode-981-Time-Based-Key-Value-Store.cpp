/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/time-based-key-value-store/
 * runtime: 78ms
 */

class TimeMap {
public:
    unordered_map<string, vector<pair<int , string>>> umap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = umap[key].size()-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(umap[key][mid].first == timestamp){
                return umap[key][mid].second;
            } else if(umap[key][mid].first > timestamp) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if(r == -1) return "";
        return umap[key][r].second;
    }
};