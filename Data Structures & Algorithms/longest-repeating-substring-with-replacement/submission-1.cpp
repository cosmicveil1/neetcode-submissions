class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxlen=0;
        int maxf=0;
        vector<int> charCounts(26,0);

        while(r<s.size()){
            charCounts[s[r]-'A']++;
            maxf=max(maxf,charCounts[s[r]-'A']);
            while((r-l+1)-maxf>k){
                charCounts[s[l]-'A']--;
                maxf=0;
                for(int i=0;i<26;i++){
                    maxf=max(maxf,charCounts[i]);
                }
                 l=l+1;
            }
            if((r-l+1)-maxf<=k){
                maxlen=max(maxlen,r-l+1);
                r++;
            }
        }
        return maxlen;
    }
};
