class Node {
public:
    Node* links[2];

    Node() {
        links[0] = links[1] = nullptr;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->links[bit] == nullptr)
                node->links[bit] = new Node();

            node = node->links[bit];
        }
    }

    int getMax(int num) {
        Node* node = root;
        int ans = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->links[1 - bit]) {
                ans |= (1 << i);
                node = node->links[1 - bit];
            } else {
                node = node->links[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for (int x : nums)
            trie.insert(x);

        int ans = 0;

        for (int x : nums)
            ans = max(ans, trie.getMax(x));

        return ans;
    }
};