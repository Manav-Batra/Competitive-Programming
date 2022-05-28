 int maxProfit(vector<int>& prices) {
      int ans=0;
      int min=1e6;
        int index_min;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
                
            }
            int p=prices[i]-min;
            if(ans<p)
                ans=p;
        }
        return ans;
                

    
        
            
    }