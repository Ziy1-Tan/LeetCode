struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    vector<int> arr;
    while (head) {
      arr.push_back(head->val);
      head = head->next;
    }
    int l = 0, r = arr.size() - 1;
    while (l < r) {
      if (arr[l] != arr[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
};

class Solution2 {
 public:
  bool isPalindrome(ListNode* head) {
    if (!head) {
      return true;
    }
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode* revHead = reverseList(slow->next);
    while (revHead) {
      if (head->val != revHead->val) {
        return false;
      }
      head = head->next;
      revHead = revHead->next;
    }
    return true;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head;
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};

class Solution3 {
 public:
  bool isPalindrome(ListNode* head) {
    tmp = head;
    return check(head);
  }

 private:
  ListNode* tmp = nullptr;
  bool check(ListNode* head) {
    if (head == nullptr) {
      return true;
    }

    bool res = check(head->next) && (head->val == tmp->val);
    tmp = tmp->next;
    return res;
  }
};

int main(int argc, char const* argv[]) {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(22);
  head->next->next->next->next = new ListNode(11);
  Solution3 s;
  cout << s.isPalindrome(head) << endl;

  return 0;
}
