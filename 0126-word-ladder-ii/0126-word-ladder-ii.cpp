class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path){
        if(word == beginWord){
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for(auto p : parent[word]){
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while(!q.empty() && !found){
            int size = q.size();
            unordered_set<string> levelVisited;

            for(int s = 0; s < size; s++){
                string word = q.front();
                q.pop();

                for(int i = 0; i < word.size(); i++){
                    string temp = word;

                    for(char ch = 'a'; ch <= 'z'; ch++){
                        temp[i] = ch;

                        if(st.count(temp) && !visited.count(temp)){
                            if(temp == endWord) found = true;

                            if(!levelVisited.count(temp)){
                                q.push(temp);
                                levelVisited.insert(temp);
                            }

                            parent[temp].push_back(word);
                        }
                    }
                }
            }

            for(auto w : levelVisited){
                visited.insert(w);
            }
        }

        if(!found) return {};

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);

        return ans;
    }
};