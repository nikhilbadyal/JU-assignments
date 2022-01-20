#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

bool dfs(unordered_map<char, vector<char>>& graph, unordered_map<char, bool>& visited, char u, char target, int depth){
    cout<<u<<" ";
    visited[u] = true;

    if(u == target){
        return true;
    }
    if(depth == 0){
        return false;
    }


    vector<char>neighbor;
    neighbor = graph[u];
    for(int i=0;i<graph[u].size();i++){
        char v = graph[u][i];
        if(!visited[v]){
            if(dfs(graph, visited, v, target, depth-1)){
                return true;
            }
        }
    }
    return false;
}
void IDDFS(unordered_map<char, vector<char>>& graph, char src, char target, int maxDepth){
    
    for(int i=0;i<=maxDepth;i++){
        unordered_map<char, bool>visited;
        cout<<"\nDepth : "<<i<<endl;
        if(dfs(graph, visited, src, target, i)){
            break;
        }
    }
}
int main() {
    unordered_map<char, vector<char>> graph;

    graph['A'].push_back('B');
    graph['A'].push_back('C');

    graph['B'].push_back('D');
    graph['B'].push_back('E');

    graph['C'].push_back('F');
    graph['C'].push_back('G');
    graph['C'].push_back('H');

    graph['D'].push_back('I');
    graph['D'].push_back('J');

    graph['E'].push_back('K');
    graph['E'].push_back('L');
    graph['E'].push_back('M');

    graph['F'].push_back('N');

    graph['H'].push_back('O');
    graph['H'].push_back('P');

    int maxDepth = 3;

    IDDFS(graph, 'A', 'N', maxDepth);
   
}
