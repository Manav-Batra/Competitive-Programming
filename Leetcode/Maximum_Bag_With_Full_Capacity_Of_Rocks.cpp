int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans=0;
        vector<int> v;
        int n=rocks.size();
        for(int i=0;i<n;i++)
        {
            int diff=capacity[i]-rocks[i];
            v.push_back(diff);
        }
        int count=0;
        int m=v.size();
        // for(auto it : v)
        //     cout<<it<<" ";
        cout<<endl;
        sort(v.begin(),v.end());
        // for(auto it : v)
        //     cout<<it<<" ";
        // cout<<endl;
        for(int i=0;i<m;i++)
        {
            ans=ans+v[i];
            
          if(ans>additionalRocks)
          {
              break;
          }
            count++;
            
        
            
        }
        return count;
    }