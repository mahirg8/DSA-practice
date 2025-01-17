// You are given an undirected graph consisting of v vertices and a list of edges, along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

// Note: The graph is indexed with 0-based indexing.

// Examples:

// Input: v = 4, edges[] = [(0,1),(1,2),(2,3),(3,0),(0,2)], m = 3
// Output: true
// Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:
// Vertex 0: Color 3
// Vertex 1: Color 2
// Vertex 2: Color 1
// Vertex 3: Color 2

class Solution {
  public:
    bool isSafe(int node, int color, vector<int>& colors, vector<vector<int>>& adj) {
    for (int neighbor : adj[node]) {
        if (colors[neighbor] == color) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

bool solve(int node, int v, vector<int>& colors, vector<vector<int>>& adj, int m) {
    if (node == v) {
        return true; // All nodes are colored successfully
    }

    // Try all colors for the current node
    for (int color = 1; color <= m; color++) {
        if (isSafe(node, color, colors, adj)) {
            colors[node] = color; // Assign the color

            // Recur for the next node
            if (solve(node + 1, v, colors, adj, m)) {
                return true;
            }

            // Backtrack
            colors[node] = 0;
        }
    }

    return false; // No valid coloring found
}

bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    // Create an adjacency list from the edges
    vector<vector<int>> adj(v);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    // Initialize the colors array with 0 (no color assigned)
    vector<int> colors(v, 0);

    // Start the backtracking solution from the first vertex
    return solve(0, v, colors, adj, m);
}

};