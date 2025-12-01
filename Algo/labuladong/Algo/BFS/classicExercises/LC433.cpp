// LC433 - 最小基因变化
// #bfs

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string> pathused;
    unordered_set<string> isvalid;
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        for(int i = 0; i < bank.size(); i++){
            isvalid.insert(bank[i]);
        }
        queue<string> q;
        q.push(startGene);
        pathused.insert(startGene);
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string cur = q.front();
                q.pop();

                if(cur == endGene)
                    return steps;
                
                vector<string> newgenes = generate(cur);
                for(int i = 0; i < newgenes.size(); i++){
                    if(pathused.count(newgenes[i]) == false){
                        q.push(newgenes[i]);
                        pathused.insert(newgenes[i]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    vector<string> generate(string& cur){
        vector<string> res;
        vector<char> list = {'A', 'G', 'C', 'T'};
        for(int i = 0; i < cur.size(); i++){
            for(int j = 0; j < list.size(); j++){
                string newgene = cur;
                if(newgene[i] == list[j]){
                    continue;
                }
                newgene[i] = list[j];
                if(isvalid.count(newgene) == false){
                    continue;
                }
                res.push_back(newgene);
            }
        }
        return res;
    }

    
};