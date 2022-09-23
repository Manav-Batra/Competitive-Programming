class Solution {
public:
	vector<int> getCoords(int& n,int& ele) {
		int x=(ele-1)/n;
		int y=(ele-1)%n;
		if(x%2) y=n-y-1;
		x=n-x-1;
		return {x,y};
	}

	int snakesAndLadders(vector<vector<int>>& a) {
		int n=a.size();
		queue<int> q;
		q.push(1);
		vector<int> vis(n*n+1),mp(n*n+1,INT_MAX);
		mp[1]=0;
		while(q.size()) {
			int ele=q.front();
			q.pop();
			if(ele==n*n) return mp[ele];
			if(vis[ele]) continue;
			vis[ele]=1;
			for(int i=1;i<7;i++) {
				int nextEle=i+ele;
				if(nextEle>n*n) break;
				vector<int> coords=getCoords(n,nextEle);
				int x=coords[0];
				int y=coords[1];
				if(a[x][y]!=-1) nextEle=a[x][y];
				if(!vis[nextEle]&&mp[nextEle]>mp[ele]+1) {
					mp[nextEle]=mp[ele]+1;
					if(nextEle==n*n) return mp[nextEle];
					q.push(nextEle);
				} 
			}
		} 
		return -1;
	}
};