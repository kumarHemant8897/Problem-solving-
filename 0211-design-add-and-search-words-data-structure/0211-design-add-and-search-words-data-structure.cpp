class TrieNode{
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;

        for(char ch : word){
            int idx = ch - 'a';

            if(node->child[idx] == NULL)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->isEnd = true;
    }

    bool solve(TrieNode* node, string &word, int idx){
        if(node == NULL)
            return false;

        if(idx == word.size())
            return node->isEnd;

        if(word[idx] == '.'){
            for(int i = 0; i < 26; i++){
                if(solve(node->child[i], word, idx + 1))
                    return true;
            }
            return false;
        }

        return solve(node->child[word[idx] - 'a'], word, idx + 1);
    }

    bool search(string word) {
        return solve(root, word, 0);
    }
};