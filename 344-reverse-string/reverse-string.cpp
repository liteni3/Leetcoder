class Solution {
public:
    void swap (vector<char> &s,int start,int end){
        if(start>=end){
            return;
        }
        char ref=s[start];
        s[start]=s[end];
        s[end]=ref;
    }
    void reverseString(vector<char>& s) {
        int j=s.size()-1;
        for(int i=0;i<s.size();i++){
            swap(s,i,j);
            j--;
        }
    }
};