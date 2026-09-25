class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]!=9){
            digits[n-1]++;
            return digits;
        }
        else{
            int ptr=n-1;
            while(ptr>=0 && digits[ptr]==9){
                digits[ptr]=0;
                ptr--;
            }
            if(ptr>=0){
                digits[ptr]++;
            }
            else{
                digits.push_back(1);
                reverse(digits.begin(),digits.end());
            }
            return digits;
        }
        return {};
    }
};
