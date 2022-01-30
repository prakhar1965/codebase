// https://practice.geeksforgeeks.org/problems/257a9e27fb3e58255622c8dcb06e0919cc1c6c11/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        vector<vector<long>> prefixMat(N,vector<long>(N,0));
        
        FillPrefixMat(mat,prefixMat);
        
        long max_sum = INT_MIN;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                max_sum = max(max_sum, findSumForSubMat(prefixMat,i,j,K));
            }
        }
        return max_sum;
    }
    
    void FillPrefixMat(vector<vector<int>> &mat,vector<vector<long>> &prefixMat){
        
        int N = mat.size();
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                prefixMat[i][j] = mat[i][j];
                if(i>0) prefixMat[i][j] += prefixMat[i-1][j];
                if(j>0) prefixMat[i][j] += prefixMat[i][j-1];
                if(i>0 && j>0)  prefixMat[i][j] -= prefixMat[i-1][j-1];
            }
        }
    }
    
    long findSumForSubMat(vector<vector<long>> &prefixMat,int i,int j,int K){
        int N = prefixMat.size();
        if(i+K > N || j+K > N) return INT_MIN;
        
        long sum =  prefixMat[i+K-1][j+K-1];
        if(i>0 && j>0) sum += prefixMat[i-1][j-1];
        if(i>0) sum -= prefixMat[i-1][j+K-1];
        if(j>0) sum -= prefixMat[i+K-1][j-1];
        
        return sum;
    }
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends