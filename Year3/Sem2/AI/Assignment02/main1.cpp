#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

void BestFirstSearch(unordered_map<char, vector<pair<char, int>>> &graph, char src, char target) {
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    unordered_map<char, bool> visited;
    pq.push({0, src});

    while (!pq.empty()) {
        char node = pq.top().second;
        pq.pop();
        cout << node << " ";
        if (node == target) {
            break;
        }

        vector<pair<char, int>> neighbor;
        neighbor = graph[node];

        for (int i = 0; i < neighbor.size(); i++) {
            if (!visited[neighbor[i].first]) {
                visited[neighbor[i].first] = true;
                pq.push({neighbor[i].second, neighbor[i].first});
            }
        }
    }
}

int main() {
    unordered_map<char, vector<pair<char, int>>> graph;

    graph['A'].push_back({'B', 5});
    graph['A'].push_back({'D', 3});

    graph['B'].push_back({'C', 1});

    graph['C'].push_back({'E', 6});
    graph['C'].push_back({'G', 8});

    graph['D'].push_back({'E', 2});
    graph['D'].push_back({'F', 2});

    graph['E'].push_back({'B', 4});

    graph['F'].push_back({'G', 3});

    graph['G'].push_back({'E', 4});


    BestFirstSearch(graph, 'A', 'G');
}
