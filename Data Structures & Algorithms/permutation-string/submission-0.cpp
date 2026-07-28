class Solution {
public:

    bool isfreqsame(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        //store the frequency of the characters in the first string s1
        int freq[26]={0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

        int windowSize=s1.length();

        for(int i=0;i<s2.length();i++){
            int windowIndex=0,idx=i;
            int windFrequency[26]={0};
            while(windowIndex<windowSize && idx<s2.length()){
              windFrequency[s2[idx]-'a']++;
              windowIndex++;
              idx++;
            }
            if(isfreqsame(freq,windFrequency)){
                return true;
            }
        }
        return false;

    }
};
