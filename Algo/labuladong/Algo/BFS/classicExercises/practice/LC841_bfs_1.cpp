#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> used;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        used = vector<bool>(rooms.size(), false);
        queue<int> q;
        q.push(0);
        used[0] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int room = q.front();
                q.pop();
                for(int i = 0; i < rooms[room].size(); i++){
                    int key = rooms[room][i];
                    if(used[key] == false){
                        q.push(key);
                        used[key] = true;
                    }
                }
            }
        }
        for(int i = 0; i < used.size(); i++){
            if(used[i] = false){
                return false;
            }
        }
        return true;
    }
};