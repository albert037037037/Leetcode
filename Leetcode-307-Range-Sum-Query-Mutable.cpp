/**
 * Author: Albert Wang <albert037037037@gmail.com>
 * Problem: https://leetcode.com/problems/range-sum-query-mutable/description/
 * runtime: 59ms
 */

class NumArray {
public:

    vector<int> segtree;
    int size = 0;
		
		/* start, end 代表是這個節點的區段值*/
		/* 因此如果 start == end 代表是來到了 leaf, 因此直接填入值*/
    int build_tree(vector<int>& nums, int node, int start, int end) {
        if(start == end) {
            segtree[node] = nums[start];
            return segtree[node];
        }
        int mid = (start+end) / 2;
        int left_node = 2*node+1;
        int right_node = 2*node+2;

        int left_sum = build_tree(nums, left_node, start, mid);
        int right_sum = build_tree(nums, right_node, mid+1, end);
        segtree[node] = left_sum + right_sum;
        return segtree[node];
    }
		
		/* 若 start == end 代表來到了要改動的 index 因此 start == end == idx */
		/* 若 idx > mid 代表我們要改的是在右邊的節點，反之則為左邊 */
    void update_tree(int node, int start, int end, int idx, int val) {
        if(start == end) {
            segtree[node] = val;
            return ;
        }
        int mid = (start+end) / 2;
        int left_node = 2*node+1;
        int right_node = 2*node+2;
        if(idx > mid) {
            update_tree(right_node, mid+1, end, idx, val);
        } else {
            update_tree(left_node, start, mid, idx, val);
        }
        segtree[node] = segtree[left_node] + segtree[right_node];
    }
		
		/* 我們直接從 root 開始分兩邊找 */
		/* 因此若要求的區間段，完全與現在找的區段不符合，直接 return 0*/
		/* 若現在找的區間段，已經完全在這個要求的區間段內，
			 不再繼續遞迴，因為在這個 node 已有這個區段的值 */
    int tree_sum_range(int node, int start, int end, int L, int R) {
        if(end < L || R < start) {
            return 0;
        } else if (L <= start && end <= R) {
            return segtree[node];
        } else if(start == end) {
            return segtree[node];
        }
        int mid = (start+end) / 2;
        int left_node = 2*node+1;
        int right_node = 2*node+2;
        int left_sum = tree_sum_range(left_node, start, mid, L, R);
        int right_sum = tree_sum_range(right_node, mid+1, end, L, R);
        return left_sum + right_sum;
    }

    NumArray(vector<int>& nums) {
        segtree.assign(nums.size()*4, 0);
        size = nums.size();
        build_tree(nums, 0, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        update_tree(0, 0, size-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return tree_sum_range(0, 0, size-1, left, right);
    }
};