/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/flood-fill/
 * runtime: 4ms
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldcolor = image[sr][sc];
        if(newColor == oldcolor) return image;
        image[sr][sc] = newColor;
        if(sr+1 < image.size() && image[sr+1][sc] == oldcolor){
            image = floodFill(image, sr+1, sc, newColor);
        }
        if(sc+1 < image[0].size() && image[sr][sc+1] == oldcolor){
            image = floodFill(image, sr, sc+1, newColor);
        }
        if(sr-1 >= 0 && image[sr-1][sc] == oldcolor){
            image = floodFill(image, sr-1, sc, newColor);   
        }
        if(sc-1 >= 0 && image[sr][sc-1] == oldcolor){
            image = floodFill(image, sr, sc-1, newColor);
        }
        return image;
    }
};