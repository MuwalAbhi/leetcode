#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>ans;
int main(){

}
 bool solve(vector<vector<char>>&board,string &word,int m,int n,int i,int j,int ind){
    if(ind>=word.length()) return true;
    if(i>=n||j>=m||i<0||j<0||board[i][j]!=word[ind]) return false;
    char temp= board[i][j];
    board[i][j]='*';
    bool f1=solve(board,word,m,n,i+1,j,ind+1);
    bool f2=solve(board,word,m,n,i,j+1,ind+1);
     bool f3=solve(board,word,m,n,i-1,j,ind+1);
    bool f4=solve(board,word,m,n,i,j-1,ind+1);
    board[i][j]=temp;
    return f1||f2||f3||f4;
   }


      bool isSafe(int row,int col,vector<string>&board,int n){
       int temprow=row;
       int tempcol=col;
       while(col>=0&&row>=0){
           if(board[row][col]=='Q') return false;
           row--;
           col--;
       }
       row=temprow;
       col=tempcol;
       while(col>=0){
           if(board[row][col]=='Q') return false;
           col--;
       }
       row=temprow;
       col=tempcol;
       while(row<n&&col>=0){
           if(board[row][col]=='Q') return false;
           row++;
           col--;
       }
       return true;
   }
   void solve(int col,vector<string>&board,int n){
      if(col==n){
          ans.push_back(board);
          return;
      }
      for(int i=0;i<n;i++){
        
          if(isSafe(i,col,board,n)){
             board[i][col]='Q';
             solve(col+1,board,n);
                board[i][col]='.';
          }
      }
   }