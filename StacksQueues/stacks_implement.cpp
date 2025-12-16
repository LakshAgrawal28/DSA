#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

/*
  Striver-style compact stack implementations:
  1) ArrayStack        - fixed capacity, O(1) push/pop
  2) LinkedListStack   - dynamic size, O(1) push/pop
  3) QueueStack        - emulate stack using single queue (rotation)
*/

/* ---------- 1) Array-based stack (vector-backed) ---------- */
class ArrayStack {
    vector<int> a;
    int topIdx;          // -1 when empty
public:
    explicit ArrayStack(int capacity = 1000) : a(capacity), topIdx(-1) {}

    void push(int x) {
        if (topIdx + 1 >= (int)a.size()) { cout << "Stack overflow\temp"; return; }
        a[++topIdx] = x;
    }

    int pop() {
        if (isEmpty()) return -1;
        return a[topIdx--];
    }

    int top() const { return isEmpty() ? -1 : a[topIdx]; }
    bool isEmpty() const { return topIdx == -1; }
    int size() const { return topIdx + 1; }
};


/* ---------- 2) Linked-list stack ---------- */
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedListStack {
    Node* head;   // top of stack
    int cnt;
public:
    LinkedListStack() : head(nullptr), cnt(0) {}
    ~LinkedListStack() {
        while (head) { Node* t = head; head = head->next; delete t; }
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        ++cnt;
    }

    int pop() {
        if (!head) return -1;
        int v = head->val; // for return

        Node* temp = head;
        head = head->next;
        delete temp;
        
        --cnt;
        return v;
    }

    int top() const { return head ? head->val : -1; }
    bool isEmpty() const { return cnt == 0; }
    int size() const { return cnt; }
};


/* ---------- 3) Stack using one queue (rotation trick) ---------- */
class QueueStack {
    queue<int> q;
public:
    void push(int x) {
        int temp = q.size();
        q.push(x);
        // rotate previous elements behind the new one
        for (int i = 0; i < temp; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int v = q.front(); q.pop(); return v;
    }

    int top() const { return q.empty() ? -1 : q.front(); }
    bool isEmpty() const { return q.empty(); }
    int size() const { return (int)q.size(); }
};


int main() {
    return 0;
}
