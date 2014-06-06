class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > row( 9, vector<bool>(9, false));
        vector<vector<bool> > column( 9, vector<bool>(9, false));
        vector<vector<bool> > block( 9, vector<bool>(9, false));

        int i = 0;
        int j = 0;
        int val = 0;
        for( i=0; i<9; i++ ) {
            for( j=0; j<9; j++ ) {
                if( board[i][j]=='.')
                    continue;
                else {
                   val = board[i][j]-'1';
                   if( row[i][val] || column[j][val] || block[i-i%3+j/3][val] )
                        return false;
                   row[i][val] = 1;
                   column[j][val] = 1;
                   block[i-i%3+j/3][val] = 1;
                }
            }
        }
        return true;
    }
};
