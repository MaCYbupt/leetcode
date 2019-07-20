class Solution {
public:
    static bool CompareIntervals(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),CompareIntervals);
        int current_positon = 0;
        vector<int> current = {0,0};
        current = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=current[1]){
                current = {current[0], max(intervals[i][1], current[1])};
                intervals[current_positon]=current;
            }
            else{
                current_positon++;
                intervals[current_positon]=intervals[i];
                current = intervals[current_positon];
            }
        }
        while(intervals.size()>current_positon+1){
            intervals.pop_back();
        };
        return intervals;
    }
};

/*
目前思路应该是从最小的数字开始，逐步找最远的范围
current变量可以简化掉
看了下top1的答案大概是返回了一个新的result
用了两重循环，里层循环用来找下一个的位置，skip来跳过下一个之前的部分
所以时间复杂度应该还是O(n)
*/
