class MyLinkedList {
public:

    struct Node {
        int val;
        Node* next;
        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;
    int size;

    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {   
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;       
        size++;                
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;    
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;   
            }
            temp->next = newNode;
        }
        size++;                
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;   

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        int count = 1;

        while (temp != NULL) {
            if (count == index) {  
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                size++;             
                break;
            }
            temp = temp->next;
            count++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;  

        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            size--;                             
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        int count = 0;

        while (temp != NULL) {
            if (count == index) {
                Node* del = temp;
                prev->next = temp->next; 
                temp = temp->next;
                delete del;
                size--;                  
                break;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
    }
};