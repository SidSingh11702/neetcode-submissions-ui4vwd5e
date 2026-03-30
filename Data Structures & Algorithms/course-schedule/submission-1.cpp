class Solution {
    bool hasCycle(int currentVertex, int numVertices, vector<vector<int>>& adjList, vector<int>& visited) {
        if (visited[currentVertex] == 1) return true; else if (visited[currentVertex] == 2) return false;
        visited[currentVertex] = 1;
        for (const int &neighbour : adjList[currentVertex]) if (hasCycle(neighbour, numVertices, adjList, visited)) return true;
        visited[currentVertex] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses); vector<int> visited(numCourses, 0);
        for (const auto &prerequisite : prerequisites) adjList[prerequisite[1]].push_back(prerequisite[0]);
        for (int i=0; i<numCourses; i++) if (hasCycle(i, numCourses, adjList, visited)) return false;
        return true;
    }
};
