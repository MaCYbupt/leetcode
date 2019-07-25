class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval) {
        vector<vector<int>> result;
        if(intervals.size()==0){
            result.push_back(newInterval);
            return result;
        }
        bool insert = false;
        for(int i=0;i<intervals.size();i++) {
            if(intervals[i][1]<newInterval[0]){
                result.push_back(intervals[i]);
                continue;
            }
            insert = true;
            int j=i;
            if(intervals[i][0]>newInterval[1]){
                result.push_back(newInterval);
            }
            else{
                int k=j;
                vector<int>tmp = {min(newInterval[0],intervals[k][0]), newInterval[1]};
                for(;k<intervals.size();k++){
                    if(intervals[k][1]>tmp[1]&&intervals[k][0]<=tmp[1]){
                        tmp[1] = intervals[k][1];
                        k++;
                        break;
                    }
                    else if(intervals[k][1]>tmp[1]&&intervals[k][0]>tmp[1]){
                        break;
                    }
                }
                result.push_back(tmp);
                j=k;
            }
            for(;j<intervals.size();j++){
                result.push_back(intervals[j]);
            }
            break;
        }
        if(insert==false){
            result.push_back(newInterval);
        }
        return result;
    }
};

/*
一个非常粗暴的做法
第一个循环用来查找插入的位置，用insert来是否标记进行了插入操作
*／

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int index = 0;
        while(index < intervals.size() && intervals[index].end < newInterval.start){
            res.push_back(intervals[index++]);
        }
        while(index < intervals.size() && intervals[index].start <= newInterval.end){
            newInterval.start = min(newInterval.start, intervals[index].start);
            newInterval.end = max(newInterval.end, intervals[index].end);
            index++;
        }
        res.push_back(newInterval);
        while(index < intervals.size()){
            res.push_back(intervals[index++]);
        }
        return res;
    }
};
        
