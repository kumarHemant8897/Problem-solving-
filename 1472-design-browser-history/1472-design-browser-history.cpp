class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string x) {
        url = x;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    Node* currpage;

    BrowserHistory(string homepage) {
        currpage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);

        
        currpage->next = NULL;

        newNode->prev = currpage;
        currpage->next = newNode;
        currpage = newNode;
    }
    
    string back(int steps) {
        while (steps-- && currpage->prev != NULL) {
            currpage = currpage->prev;
        }
        return currpage->url;
    }
    
    string forward(int steps) {
        while (steps-- && currpage->next != NULL) {
            currpage = currpage->next;
        }
        return currpage->url;
    }
};