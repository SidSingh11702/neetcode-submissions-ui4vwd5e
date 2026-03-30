class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses); vector<int> indegree(numCourses, 0); queue<int> source;
        for (const auto &prerequisite : prerequisites) adjList[prerequisite[1]].push_back(prerequisite[0]), indegree[prerequisite[0]]++;
        for (int i=0; i<numCourses; i++) if (!indegree[i]) source.push(i);
        int finished = 0;
        while (!source.empty()) {
            int currentCourse = source.front(); source.pop(); finished++;
            for (const auto &neighbour : adjList[currentCourse]) if (!(--indegree[neighbour])) source.push(neighbour);
        }
        return finished == numCourses;
    }
};
