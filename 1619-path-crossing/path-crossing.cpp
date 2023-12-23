class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> s;
        int x=0,y=0;
        s.insert(to_string(x)+","+to_string(y));
        for(int i=0;i<path.size();i++){
            if(path[i]=='N') y++;
            else if(path[i]=='S') y--;
            else if(path[i]=='E') x++;
            else x--;
            if(s.count(to_string(x)+","+to_string(y))) return true;
            s.insert(to_string(x)+","+to_string(y));
        }
        return false;
    }
};