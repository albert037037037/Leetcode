/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/flood-fill/
 * runtime: 0ms
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;
        image[sr][sc] = newColor;
        if(sr-1 >= 0 && image[sr-1][sc] == oldColor)
            image = floodFill(image, sr-1, sc, newColor);
        if(sr+1 < image.size() && image[sr+1][sc] == oldColor)
            image = floodFill(image, sr+1, sc, newColor);
        if(sc-1 >= 0  && image[sr][sc-1] == oldColor)
            image = floodFill(image, sr, sc-1, newColor);
        if(sc+1 < image[0].size() && image[sr][sc+1] == oldColor)
            image = floodFill(image, sr, sc+1, newColor);
        return image;
    }
};