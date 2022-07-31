
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> n1(n,-1);
        vector<int> n2(n,-1);
        vector<bool> n11(n,false);
        vector<bool> n22(n,false);
        vector<pair<int,int>> ans;
        int start=0;
        int j=edges[node1];
        
        n1[node1]=start;
        n11[node1]=true;
        while(j!=-1&&!n11[j])
        {
            start++;
            n1[j]=start;
            n11[j]=true;
            j=edges[j];
            
        }
        start=0;
        n2[node2]=start;
        n22[node2]=true;
        j=edges[node2];
                while(j!=-1&&!n22[j])
        {
            start++;
            n2[j]=start;
                    n22[j]=true;
            j=edges[j];
            
        }
        // int ans=INT_MAX,res=-1;
        for(int i=0;i<n;i++)
        {
            if(n1[i]!=-1&&n2[i]!=-1)
            {
                pair<int,int> p;
                int mx=max(n1[i],n2[i]);
                p.first=mx;
                p.second=i;
                ans.push_back(p);
                
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0)
            return -1;
        
        return ans[0].second;
        
        
    }
};