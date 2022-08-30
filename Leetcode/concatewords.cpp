class Solution {
public:
    unordered_map<string, int> mp;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
     
        vector<string> res;
        int size=words.size();
        for(int i=0;i<size;i++)  //INSER IN A MAP .
            mp[words[i]]=1;;
        
        for(int i=0;i<size;i++){            // CHECK FOR EACH WORD
            int n=words[i].size();
            int ans=helper(words[i], 0,0, n, words );
            if(ans>=2)
                res.push_back(words[i]);
        }
        
        return res;
    }
    
    
    int  helper(string&s, int index, int count, int n,vector<string>& words ){
        
        if(index>=n)         
           return count;        // DFS IMPLEMENTATION
        
        
        string temp="";
        for(int i=index;i<n;i++){
            temp+=s[i];
            cout<<temp<<" ";
            if(mp.find(temp)!=mp.end()){
                cout<<count<<" ";
                int ans=helper(s, i+1, count+1, n, words);
             cout<<ans<<endl;
                if(ans>=2)
                    return ans;
            }
        }
        
    return -1;
        
    }  
};