/*Medium

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0) return true;
        
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites) {
            inDegree[p[0]]++;
            graph[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++ ) {
            if (inDegree[i] == 0) {
                q.push(i);
                inDegree[i]--;
            }
                
        }
        int c = 0;
        while (!q.empty()) {

            int curr = q.front();
            q.pop();
            c++;
            for (auto g : graph[curr]) {
                inDegree[g]--;
                if (inDegree[g] == 0) {
                    q.push(g);
                }

            }
        }
        if (c == numCourses) 
            return true;
        return false;
    }
};