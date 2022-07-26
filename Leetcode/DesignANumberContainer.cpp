class NumberContainers {
public:
    unordered_map<int,set<int>> mp;
    unordered_map<int,int> mp1;
    NumberContainers() {
        mp.clear();
        mp1.clear();
    }
    
    void change(int index, int number) {
        if(mp.find(number)==mp.end() && mp1.find(index)==mp1.end())
        {
            mp[number].insert(index);
            mp1[index]=number;
        }
        else if(mp.find(number)!=mp.end()  && mp1.find(index)==mp1.end())
        {
            mp[number].insert(index);
            mp1[index]=number;
        }
        else
        {
            if(mp1.find(index)!=mp1.end())
            {
                int temp=mp1[index];
                mp[temp].erase(index);
                mp[number].insert(index);
                mp1[index]=number;
            }
        }
    }
    
    int find(int number) {
        if(mp.find(number)==mp.end())
            return -1;
        if(mp[number].size()==0)
            return -1;
        return (*mp[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */