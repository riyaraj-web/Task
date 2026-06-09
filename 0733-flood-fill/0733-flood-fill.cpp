class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        const int h = image.size(), w = image[0].size();
        
        std::function<void(int, int, int)> dfs;
        
        dfs = [&](int r, int c, int srcColor) -> void{
          
            if( (r < 0 ) || ( r >=  h ) || ( c < 0) || ( c >= w) 
                         || ( image[r][c] == newColor )          
                         || ( image[r][c] != srcColor )            ){

                // Reject for invalid coordination, repeated traversal, or different color      
                return;
            }


            // update color
            image[r][c] = newColor;


            // DFS to 4-connected neighbors
            dfs( r-1, c, srcColor );
            dfs( r+1, c, srcColor );
            dfs( r, c-1, srcColor );
            dfs( r, c+1, srcColor );

            return;
        };
        // ==================================
        
        dfs( sr, sc, image[sr][sc] );
        
        return image;
        
    }
};