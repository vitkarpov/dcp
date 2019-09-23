class MyStack {
 private:
  deque<int> q;

 public:
  /** Push element x onto stack. */
  void push(int x) { q.push_back(x); }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    deque<int> tmp;

    while (q.size() > 1) {
      tmp.push_back(q.front());
      q.pop_front();
    }
    int top = q.front();
    q.pop_front();

    while (!tmp.empty()) {
      q.push_back(tmp.front());
      tmp.pop_front();
    }
    return top;
  }

  /** Get the top element. */
  int top() { return q.back(); }

  /** Returns whether the stack is empty. */
  bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
