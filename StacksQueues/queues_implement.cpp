#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

/*
  1) Circular array queue (uses std::vector, no manual new/delete)
     - O(1) push/pop, fixed capacity
*/
class CircularArrayQueue {
    vector<int> a;
    int cap;
    int sz = 0;
    int frontIdx = 0;   // index of current front
    int backIdx = 0;    // index where next push will place element
public:
    explicit CircularArrayQueue(int capacity = 1000) : a(capacity), cap(capacity) {}

    void push(int x) {
        if (sz == cap) { cout << "Queue overflow\n"; return; }
        a[backIdx] = x;
        backIdx = (backIdx + 1) % cap;
        ++sz;
    }

    int pop() {
        if (empty()) return -1;
        int v = a[frontIdx];
        frontIdx = (frontIdx + 1) % cap;
        --sz;
        return v;
    }

    int front() const { return empty() ? -1 : a[frontIdx]; }
    bool empty() const { return sz == 0; }
    int size() const { return sz; }
};


/*
  2) Linked-list queue (dynamic size)
     - O(1) push and pop, no capacity limit
*/
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedListQueue {
    Node* head = nullptr; // front
    Node* tail = nullptr; // back
    int sz = 0;
public:
    ~LinkedListQueue() {
        while (head) { Node* t = head; head = head->next; delete t; }
    }

    void push(int x) {
        Node* n = new Node(x);
        if (!tail) head = tail = n;
        else { tail->next = n; tail = n; }
        sz++;
    }

    int pop() {
        if (!head) return -1;
        int v = head->val;
        Node* t = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete t;
        sz--;
        return v;
    }

    int front() const { return head ? head->val : -1; }
    bool empty() const { return sz == 0; }
    int size() const { return sz; }
};


/*
  3a) Queue using two stacks — Push-efficient (amortized O(1) push)
       - push: push to 'in'
       - pop/front: if 'out' empty, move all from 'in' to 'out' (reverse)
       - This is the classic LeetCode/Striver version
*/
class QueueTwoStacksPushEfficient {
    stack<int> in, out;
    void moveIfNeeded() {
        if (out.empty()) {
            while (!in.empty()) { out.push(in.top()); in.pop(); }
        }
    }
public:
    void push(int x) { in.push(x); }
    int pop() {
        moveIfNeeded();
        if (out.empty()) return -1;
        int v = out.top(); out.pop(); return v;
    }
    int front() {
        moveIfNeeded();
        return out.empty() ? -1 : out.top(); // empty hai toh -1, otherwise top
    }
    bool empty() const { return in.empty() && out.empty(); }
    int size() const { return (int)in.size() + (int)out.size(); }
};


/*
  3b) Queue using two stacks — Pop-efficient (O(1) pop/front, push is costly)
       - To keep pop/front O(1), on push we transfer all elements to a temp stack,
         push new element, then move back so 'out' top is the front.
       - Useful when pops are far more frequent than pushes.
*/
class QueueTwoStacksPopEfficient {
    stack<int> mainSt; // top = front
public:
    void push(int x) {
        // move all to temp, push x, move back so top stays front
        stack<int> temp;
        while (!mainSt.empty()) { temp.push(mainSt.top()); mainSt.pop(); }
        mainSt.push(x);
        while (!temp.empty()) { mainSt.push(temp.top()); temp.pop(); }
    }

    int pop() {
        if (mainSt.empty()) return -1;
        int v = mainSt.top(); mainSt.pop(); return v;
    }

    int front() const { return mainSt.empty() ? -1 : mainSt.top(); }
    bool empty() const { return mainSt.empty(); }
    int size() const { return (int)mainSt.size(); }
};


int main() {
    return 0;
}
