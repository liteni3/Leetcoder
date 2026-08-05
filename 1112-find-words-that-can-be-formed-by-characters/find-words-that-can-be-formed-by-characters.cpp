class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        //frequency array for characters in chars
        vector<int> charCount(26,0);
        for(char c : chars ){
            charCount[c-'a']++;
        }
        int totalLength=0;
        for(const string & word : words){
            //temp freq array for current word
            vector<int> wordCount(26,0);
            bool isGood=true;
            for(char c : word){
                wordCount[c-'a']++;
                if(wordCount[c-'a']>charCount[c-'a']){
                    isGood=false;
                    break;
                }
            }
            if(isGood){
                totalLength+=word.length();
            }
        }
        return totalLength;
    }
};