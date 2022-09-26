

/* so basically the main idea is that first we create the vector name dp in which we store the number of element less than to that particular number int the array and after that we create the segment tree 

Now we iterate over the nums array and query for that particular number in segment tree and update all the numbers greater than that particular number like in updation we decrement the count of that number in segment tree and append the answer from query part into the final array ans

*/

class Solution {
public:
    
    
    
    
    
    
/*    segment tree with lazy propogation for range query updation */
    
    
    
    struct segmenttree{
        vector<int> st,lazy;
        int n;
        
        void init(int _n)
        {
            this->n=_n;
            st.resize(4*n,0);
            lazy.resize(4*n,0);
            
        }
        
        void build(int start,int end,int node,vector<int> &v)
        {
            if(start==end)
            {
                st[node]=v[start];
                return ;
                
            }
            
            int mid=(start+end)/2;
            build(start,mid,2*node+1,v);
            build(mid+1,end,2*node+2,v);
            st[node]=st[2*node+1]+st[2*node+2];
        }
        void build(vector<int> &v)
        {
            build(0,n-1,0,v);
        }
        int query(int start,int end,int l,int r,int node)
        {
            if(start>r or end<l)
                return 0;
            
            if(lazy[node]!=0)
            {
                st[node]+=lazy[node]*(end-start+1);
                if(start!=end)
                {
                    lazy[2*node+1]+=lazy[node];
                    lazy[2*node+2]+=lazy[node];
                }
                lazy[node]=0;
            }
            
            if(start>=l and end<=r)
                return st[node];
            
            int mid=(start+end)/2;
            int q1=query(start,mid,l,r,2*node+1);
            int q2=query(mid+1,end,l,r,2*node+2);
            return q1+q2;
        }
        int query(int l,int r)
        {
           return  query(0,n-1,l,r,0);
        }
        void update(int start,int end,int node,int l,int r,int value)
        {
            if(start>r or end<l)
                return ;
            
            if(lazy[node]!=0)
            {
                st[node]+=lazy[node]*(end-start+1);
                if(start!=end)
                {
                    lazy[2*node+1]+=lazy[node];
                    lazy[2*node+2]+=lazy[node];
                }
                lazy[node]=0;
            }
            
            if(start>=l and end<=r)
            {
                st[node]+=value*(end-start+1);
                if(start!=end)
                {
                    lazy[2*node+1]+=value;
                    lazy[2*node+2]+=value;
                }
                return ;
            }
            
            int mid=(start+end)/2;
            update(start,mid,2*node+1,l,r,value);
            update(mid+1,end,2*node+2,l,r,value);
            
            st[node]=st[2*node+1]+st[2*node+2];
        }
        void update(int l,int r,int value)
        {
            update(0,n-1,0,l,r,value);
        }
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        unordered_map<int,int> mp,ind;
        for(auto it : nums)
            mp[it]++;
        set<int> s;
        for(auto it : nums)
            s.insert(it);
        vector<pair<int,int>> v;
    

        
        int i=0;
        for(auto it : s)
        {
            v.push_back({it,i});
            i++;
        }
                for(auto it : v)
        {
        
            ind.insert({it.first,it.second});
        }
        
       int n=v.size();
        vector<int> dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int temp=mp[v[i-1].first];
            dp[i]=dp[i-1]+temp;
            
            
        }
/*       above this is the vector dp creation part */
        
        
        int m=nums.size();
         vector<int> ans(m);
        
        segmenttree tree;
        tree.init(n);
        tree.build(dp);
        
        
/*    simple main logic implementation */
        
        
       for(int i=0;i<m;i++)
       {
           int idx=ind[nums[i]];
           int temp=tree.query(idx,idx);
           ans[i]=temp;
           tree.update(idx+1,n-1,-1);
           
       }
        return ans;
        
    }
};