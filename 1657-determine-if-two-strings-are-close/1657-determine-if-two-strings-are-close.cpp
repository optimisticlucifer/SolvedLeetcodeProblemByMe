class Solution {
public:

    bool closeStrings(string word1, string word2) {

        vector<int>temp1(26);
        vector<int>temp2(26);
        bool flag = true;

        for(int i = 0; i < word1.size();i++){
            temp1[word1[i]-'a']++;
        }

        for(int i = 0; i < word2.size();i++){
            temp2[word2[i]-'a']++;
        }

        for(int i = 0; i < temp1.size();i++){
            if((temp1[i]>0 && temp2[i]==0) || (temp1[i]==0 && temp2[i]>0)){
                return false;
            }
        }

        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());

        for(int i = 0;i < 26;i++){
            if(temp1[i]!=temp2[i]){
                flag = false;
                break;
            }
        }

        return flag;
        
    }
};