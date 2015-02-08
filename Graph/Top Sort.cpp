/*
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A-->B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.
Note
You can assume that there is at least one topological order in the graph.
Example
For graph as follow: 

The topological order can be:

[0, 1, 2, 3, 4, 5]

or

[0, 2, 3, 1, 5, 4]

Challenge
Can you do it in both BFS and DFS?
*/




typedef DirectedGraphNode Node;
class Solution {
public:
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        if (graph.empty()) {
            return graph;
        }
        queue<Node*> zeroInQue;
        vector<int> indgree(graph.size(), 0);
        vector<Node*> res;
        
        //compute indgree
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i]->neighbors.size(); j++) {
                int index = graph[i]->neighbors[j]->label;
                indgree[index]++;
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            if (indgree[i] == 0) {
                zeroInQue.push(graph[i]);
            }
        }
        
        //sort
        while (!zeroInQue.empty()) {
            auto cur = zeroInQue.front();
            zeroInQue.pop();
            
            res.push_back(cur);
            auto neighbors = cur->neighbors;
            for (int i = 0; i < neighbors.size(); i++) {
                int index = neighbors[i]->label;
                indgree[index]--;
                if (indgree[index] == 0) {
                    zeroInQue.push(neighbors[i]);
                }
            }
        }
        
        return res;
    }
};
