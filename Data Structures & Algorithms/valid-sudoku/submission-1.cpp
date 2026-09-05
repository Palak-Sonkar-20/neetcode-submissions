class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check for rows        
        for(int i =0; i<9 ;i++){
            unordered_map<char , int> mp;
            for(int j=0 ; j<9 ; j++){
                if (board[i][j] == '.') {
                    continue;
                }
                mp[board[i][j]]++;
                if(mp[board[i][j]]> 1){
                    return false;
                }
            }
            
        }
        //check for columns
        for(int j =0; j<9 ;j++){
            unordered_map<char , int> mp;
            for(int i=0 ; i<9 ; i++){
                if (board[i][j] == '.') {
                    continue;
                }
                mp[board[i][j]]++;
                if(mp[board[i][j]]> 1){
                    return false;
                }
            }
            
        }
        //check for squares
        for(int k =0 ; k<9 ; k+=3){
            for(int m =0 ; m<9 ; m+=3){
                unordered_map<char , int> mp;
                for(int i =k+0 ; i<k+3; i++){
                    for(int j =m+0 ; j<m+3 ; j++){
                        if (board[i][j] == '.') {
                            continue;
                        }
                        mp[board[i][j]]++;
                        if(mp[board[i][j]]>1){
                            return false;
                        }
                    }
                }
            }   
        }
        return true;
    }
};
