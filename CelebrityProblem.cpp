class Solution {
    private:
    bool knows(vector<vector<int> >& mat,int a,int b,int n){
        if(mat[a][b] == 1)
          {
              return true;
              
          }
          
        else{
            return false;
        }  
    }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        stack<int>s;
        
        //push all element in stack 
        for(int i=0;i<n;i++){
            s.push(i);
        }
        //check element are knows each other or not
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(mat,a,b,n)){
                s.push(b);
    
            }
            else{
                s.push(a);
                
            }
            
        }
        
       // for row check
        int candidate = s.top();
        int zeroCount = 0;
        for(int i=0;i<n;i++){
            if(mat[candidate][i] == 0)
               {
                   zeroCount++;
               }
             
        }
    
        
        //for col
        int oneCount=0;
        for(int i =0;i<n;i++){
            if(mat[i][candidate]==1){
                oneCount++;
            }
        }
       
        
        if(zeroCount == n && oneCount == n-1){
            return candidate;
        }
        else{
            return -1;
        }
    }
};