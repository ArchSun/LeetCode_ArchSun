class Solution {
public:
    bool dfs( vector<vector<char> > &board, int cur, int count) {
        if( cur==count )
            return true;
        int i = pos[cur]/9;
        int j = pos[cur]%9;
        int k = 0;
        for( k=0; k<9; k++ ) {
            if( row[i][k] || column[j][k] || block[i-i%3+j/3][k] )
                continue;
            board[i][j] = k+'1';
            row[i][k] = true;
            column[j][k] = true;
            block[i-i%3+j/3][k] = true;
            if( dfs( board, cur+1, count))
                return true;
            row[i][k] = false;
            column[j][k] = false;
            block[i-i%3+j/3][k] = false;
            board[i][j] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        int i = 0;
        int j = 0;
        int val = 0;
        count = 0;
        memset( row, false, sizeof(row));
        memset( column, false, sizeof(column));
        memset( block, false, sizeof(block));
        for( i=0; i<9; i++ ) {
            for( j=0; j<9; j++ ) {
                if( board[i][j]=='.')
                    pos[count++] = i * 9 + j;
                else {
                   val = board[i][j]-'1';
                   row[i][val] = true;
                   column[j][val] = true;
                   block[i-i%3+j/3][val] = true;
                }
            }
        }
        dfs( board, 0, count);
    }
private:    
    bool row[9][9];
    bool column[9][9];
    bool block[9][9];
    int pos[81];
    int count;
};
