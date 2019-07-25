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
