class Solution{
    public:
    bool isSafe(vector<vector<int>> &a,int i,int j,int row,int col,vector<vector<bool>> &visited){
        if((i<row&&i>=0)&&(j>=0&&j<col)&&(visited[i][j]==false)&&(a[i][j]==1)){
            return true;
        }
        else{
            return false;
        }
    }
 void solve(vector<vector<bool>> &visited,vector<string> &ans,vector<vector<int>> &a,int i,int j,int row,int col,string output){
     if(i==row-1&&j==col-1){
         ans.push_back(output);
         return;
     }
     //down path visited
 if(isSafe(a,i+1,j,row,col,visited)){
     visited[i+1][j]=true;
     solve(visited,ans,a,i+1,j,row,col,output+'D');
     visited[i+1][j]=false;
 }
 //Left path visited
 if(isSafe(a,i,j-1,row,col,visited)){
     visited[i][j-1]=true;
     solve(visited,ans,a,i,j-1,row,col,output+'L');
     visited[i][j-1]=false;
 }
 //Right path visited
 if(isSafe(a,i,j+1,row,col,visited)){
     visited[i][j+1]=true;
     solve(visited,ans,a,i,j+1,row,col,output+'R');
     visited[i][j+1]=false;
 }
 //Upper path visited
 if(isSafe(a,i-1,j,row,col,visited)){
     visited[i-1][j]=true;
     solve(visited,ans,a,i-1,j,row,col,output+'U');
     visited[i-1][j]=false;
 }
 }
    vector<string> findPath(vector<vector<int>> &m ,int n) {
        // Your code goes herevector<string> ans;
        int row=n;
        int col=n;
        vector<string> ans;
        string output="";

        vector<vector<bool>> visited(row,vector<bool>(col,false));
        if(m[0][0]==0){
            return ans;
        }
        visited[0][0]=true;
        solve(visited,ans,m,0,0,row,col,output);
        return ans;
        
    }
};