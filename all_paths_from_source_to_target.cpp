/*

Given a directed acyclic graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 

Constraints:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.

*/

class Solution {
    vector<vector<int>> adj;
    vector<vector<int>> result;
    int n;
    void dfs(int i,vector<int> &temp) {
        if (i == n-1) {
            temp.push_back(i);
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(i);
        for(auto &x:adj[i]) {
            dfs(x,temp);
        }
        temp.pop_back();
    } 
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        adj.resize(n);
        for(int i = 0;i<n;++i) {
            for(auto &x:graph[i]) {
                adj[i].push_back(x);
            }
        }
        vector<int> temp;
        dfs(0,temp);
        return result;
    }
};