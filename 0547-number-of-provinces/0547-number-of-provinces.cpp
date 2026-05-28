class Solution {
public:
    // Find root of city with PATH COMPRESSION
    int find(vector<int>& parent, int city) {
        if(parent[city] != city)
            parent[city] = find(parent, parent[city]); // compress path
        return parent[city];
    }

    // Union two cities into same province
    void unite(vector<int>& parent, vector<int>& rank,
               int a, int b) {
        int rootA = find(parent, a);
        int rootB = find(parent, b);

        if(rootA == rootB) return;  // already same province

        // attach smaller tree under bigger tree
        if(rank[rootA] < rank[rootB])
            parent[rootA] = rootB;
        else if(rank[rootA] > rank[rootB])
            parent[rootB] = rootA;
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // each city is its own parent initially
        vector<int> parent(n), rank(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;

        // union connected cities
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)  // j=i+1 avoids duplicates
                if(isConnected[i][j] == 1)
                    unite(parent, rank, i, j);

        // count cities that are their own root = number of provinces
        int provinces = 0;
        for(int i = 0; i < n; i++)
            if(find(parent, i) == i)  // i is a root
                provinces++;

        return provinces;
    }
};