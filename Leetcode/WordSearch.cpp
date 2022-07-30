class Solution {
    bool search(vector<vector<char>>& board,int i,int j,string &word,int idx,vector<vector<bool>> &visited)
    {
        if(idx==(word.length()-1))
            return true;
        visited[i][j]=true;
        if(i>0&&visited[i-1][j]==false&&board[i-1][j]==word[idx+1]&&search(board,i-1,j,word,idx+1,visited))
            return true;
          if(j>0&&visited[i][j-1]==false&&board[i][j-1]==word[idx+1]&&search(board,i,j-1,word,idx+1,visited))
              return true;
          if(i<board.size()-1&&visited[i+1][j]==false&&board[i+1][j]==word[idx+1]&&search(board,i+1,j,word,idx+1,visited))
              return true;
          if(j<board[0].size()-1&&visited[i][j+1]==false&&board[i][j+1]==word[idx+1]&&search(board,i,j+1,word,idx+1,visited))
              return true;
              visited[i][j]=false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
       int r=board.size(),c=board[0].size();
        vector<vector<bool>> visited(r,vector<bool> (c,false));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0]&&search(board,i,j,word,0,visited))
                    return true;
            }
        }
        return false;
    }
};