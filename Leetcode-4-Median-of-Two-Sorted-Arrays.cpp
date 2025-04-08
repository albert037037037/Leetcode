/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1600650636/
 * runtime: 0ms
 */

class TimeMap {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) {
            swap(nums1, nums2);
        }


        int halfLen = (nums1.size()+nums2.size()) / 2;
        int l=0, r=nums1.size()-1;
        int idxA, idxB;
        while(true) {
            idxA = floor((double)(l+r) / 2);
            idxB = halfLen - idxA - 2;
            
            int Aleft = (idxA < 0) ? INT_MIN : nums1[idxA];
            int Aright = (idxA+1 >= nums1.size()) ? INT_MAX : nums1[idxA+1];
            int Bleft = (idxB < 0) ? INT_MIN : nums2[idxB];
            int Bright = (idxB+1 >= nums2.size()) ? INT_MAX : nums2[idxB+1];

            if(Aleft <= Bright && Bleft <= Aright) {
                if((nums1.size() + nums2.size())%2) {
                    return  double(min(Aright, Bright));
                } else {
                    return (double(min(Aright, Bright) + max(Aleft, Bleft)) / 2.0);
                }
            }
            if(Aleft > Bright) {
                r = idxA-1;
            } else if(Bleft > Aright) {
                l = idxA+1;
            }
        }
        return -1;
    }
};