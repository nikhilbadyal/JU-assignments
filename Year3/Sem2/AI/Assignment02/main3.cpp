#include <iostream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int depth=0;
stack<vector<vector<int>>>st;
int cont = 0;
bool dfs(vector<vector<int>>& src, vector<vector<int>>& target, vector<vector<bool>>& visited, int x, int y, int maxDepth){
    visited[x][y] = true;
    cout<<"At Depth : "<<depth-maxDepth<<endl;
    for(int i=0;i<src.size();i++){
        for(int j=0;j<src[0].size();j++){
            cout<<src[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl<<endl;

    if(maxDepth == 0){
        cout<<"At max Depth, Now going back : "<<endl;
        return false;
    }

    int flag = 0;
    for(int i=0;i<src.size();i++){
        for(int j=0;j<src[0].size();j++){
            if(src[i][j] != target[i][j]){
                flag = 1;
            }
        }
    }
    
    if(flag == 0){
        return true;
    }

    for(int k=0;k<4;k++){
        int di = x + dx[k];
        int dj = y + dy[k];

        if(di>=0 && di<src.size() && dj>=0 && dj < src[0].size() && !visited[di][dj]){
            swap(src[x][y], src[di][dj]);
            int flag2 = 0;
            if(dfs(src, target, visited, di, dj, maxDepth-1)){
                st.push(src);
                cont++;
                swap(src[x][y], src[di][dj]);
                flag2=1;
                return true;
            }
            if(flag2 == 0)
                swap(src[x][y], src[di][dj]);

        }
    }
    visited[x][y] = false;
    return false;
}
void DLS(vector<vector<int>>& src, vector<vector<int>>& target, int maxDepth){
     int flag = 0;
    for(int i=0;i<src.size();i++){
        for(int j=0;j<src[0].size();j++){
            if(src[i][j] != target[i][j]){
                flag = 1;
            }
        }
    }
    if(flag == 0){
        cout<<"Source and target both are same"<<endl;
    }
    vector<vector<bool>>visited(src.size(), vector<bool>(src[0].size(), false));
    if(dfs(src, target, visited, 1, 2, maxDepth)){
        cout<<"Solution found : "<<endl;
        st.push(src);
        while(!st.empty()){
            
            vector<vector<int>>v;
            v = st.top();st.pop();
            for(int i=0;i<src.size();i++){
                for(int j=0;j<src[0].size();j++){
                    cout<<v[i][j]<<" ";
                }cout<<endl;
            }
            cout<<endl;
        }
    }else{
        cout<<"Solution does not found : ";
    }

}
int main() {
    vector<vector<int>> src = {{1,2,5},
                               {3,4,0},
                               {6,7,8}};

    
    vector<vector<int>> target = {{1,4,2},
                                  {0,3,5},
                                  {6,7,8}};
    
   int maxDepth = 8;
   depth=maxDepth;
   DLS(src, target, maxDepth);

}
