class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num = digits.size();
        int i;
        for (i=num-1;i>-1;i--){
            if(digits[i]!=9){
                digits[i] = digits[i]+1;
                break;
            }
            else {
                digits[i] = 0;
            }
        }
        if(i==-1&&digits[0]==0){
            digits.push_back(0);
            for(int j=num;i>0;j--){
                digits[j]=digits[j-1];
            }
            digits[0]=1;
        }
        return digits;
    }
};
