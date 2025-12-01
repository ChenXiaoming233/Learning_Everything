#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<bool> pathused;
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        pathused = vector<bool>(rooms.size());
        dfs(rooms, 0); 
        pathused[0] = true;
        for(int i = 0; i < rooms.size(); i++){
            if(pathused[i] == false){
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>> &rooms, int room){
        for(int i = 0; i < rooms[room].size(); i++){
            int key = rooms[room][i];
            if(pathused[key] == true){
                continue;
            }
            pathused[key] = true;
            dfs(rooms, key);
        }
    }
};