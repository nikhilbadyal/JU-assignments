#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

bool
BFS(vector<vector<int>> &graph, queue<int> &q, vector<bool> &visited, vector<int> &parent, int maxBreadth, char n) {

    int u = q.front();
    cout << n << " " << u << endl;
    q.pop();
    for (int i = 0; i < graph[u].size() && maxBreadth; i++) {
        int v = graph[u][i];
        cout << v << endl;

        if (!visited[v]) {
            parent[v] = u;
            visited[v] = true;
            q.push(v);
        }
    }
    return false;
}


int isIntersecting(vector<bool> &s_visited, vector<bool> &t_visited, int V) {
    int intersectNode = -1;
    for (int i = 0; i < V; i++) {
        if (s_visited[i] && t_visited[i])
            return i;
    }
    return -1;
}

void printPath(vector<int> &s_parent, vector<int> &t_parent, int s, int t, int intersectNode) {
    vector<int> path;
    path.push_back(intersectNode);
    int i = intersectNode;
    while (i != s) {
        path.insert(path.begin(), s_parent[i]);
        i = s_parent[i];
    }
    i = intersectNode;
    while (i != t) {
        path.push_back(t_parent[i]);
        i = t_parent[i];
    }

    vector<int>::iterator it;
    cout << "*****Path*****\n";
    for (it = path.begin(); it != path.end(); it++)
        cout << *it << " ";
    cout << "\n";
};

bool BS(vector<vector<int>> &graph, int src, int target, int maxBreadth) {

    vector<bool> s_visited(graph.size(), false), t_visited(graph.size(), false);
    vector<int> sParent(graph.size(), 0), tParent(graph.size(), 0);

    queue<int> s_queue, t_queue;

    int intersectNode = -1;

    s_queue.push(src);
    s_visited[src] = true;
    sParent[src] = -1;

    t_queue.push(target);
    t_visited[target] = true;
    tParent[target] = -1;

    while (!s_queue.empty() && !t_queue.empty()) {
        cout << "hello" << endl;
        BFS(graph, s_queue, s_visited, sParent, maxBreadth, 's');
        BFS(graph, t_queue, t_visited, tParent, maxBreadth, 't');

        intersectNode = isIntersecting(s_visited, t_visited, graph.size());

        if (intersectNode != -1) {
            cout << "Path exist between " << src << " and " << target << "\n";
            cout << "Intersection at: " << intersectNode << "\n";

            printPath(sParent, tParent, src, target, intersectNode);
            return true;
        }
    }
    return false;
}

void BIBS(vector<vector<int>> &graph, char src, char target, int maxDepth) {


    for (int i = 0; i <= maxDepth; i++) {
        cout << "\nBreadth : " << i << endl;
        if (BS(graph, src, target, i)) {
            cout << "Solved" << endl;
            break;
        } else {
            cout << "path doesn't exist" << endl;
        }
    }
}

int main() {
    vector<vector<int>> graph(15);

    graph[0].push_back(4);
    graph[1].push_back(4);
    graph[2].push_back(5);
    graph[3].push_back(5);
    graph[4].push_back(6);
    graph[5].push_back(6);
    graph[6].push_back(7);
    graph[7].push_back(8);
    graph[8].push_back(9);
    graph[8].push_back(10);
    graph[9].push_back(11);
    graph[9].push_back(12);
    graph[10].push_back(13);
    graph[10].push_back(14);


    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[5].push_back(2);
    graph[5].push_back(3);
    graph[6].push_back(4);
    graph[6].push_back(5);
    graph[7].push_back(6);
    graph[8].push_back(7);
    graph[9].push_back(8);
    graph[10].push_back(8);
    graph[11].push_back(9);
    graph[12].push_back(9);
    graph[13].push_back(10);
    graph[14].push_back(10);


    BIBS(graph, 0, 14, 6);

}
