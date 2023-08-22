# include <vector>
# include <iostream>
#include <map>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    bool isCycle(int i, vector<bool>& visited, vector<vector<int>>& graph, vector<bool>& marked) {
        if (visited[i]){
            return true;
        }
        visited[i] = marked[i] = true ;

        for (auto course: graph[i]) {
            if (!visited[course]){
                if(isCycle(course, visited, graph, marked)){
                    return true ;
                }
            }
            else if (marked[course]){
                return true ;
            }
        }

        marked[i] = false ;
        return false ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> marked(numCourses, false) ;
        vector<bool> visited(numCourses, false);
        vector<vector<int>> graph(numCourses);

        for (auto & prerequisite : prerequisites) {
            graph[prerequisite.at(1)].push_back(prerequisite.at(0)) ;
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]){
                if(isCycle(i, visited, graph, marked)){
                    return false ;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution s ;
//    vector<vector<int>> vec = {{1, 0}, {0, 1}} ;
//    vector<vector<int>> vec = {{1, 0}} ;
    vector<vector<int>> vec = {{0, 1}} ;
    int num = 2;

    cout << s.canFinish(num, vec) ;
    return 0 ;
}