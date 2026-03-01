#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  static ListNode *create(const std::vector<int> &nums);
  void destroy();
};

ListNode *ListNode::create(const std::vector<int> &nums) {
  auto dummy = ListNode();
  auto cur = &dummy;
  for (auto &i : nums) {
    cur->next = new ListNode(i);
    cur = cur->next;
  }
  return dummy.next;
}

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode small_head, large_head;
    auto small = &small_head, large = &large_head;
    auto temp = head;

    while (head) {
      temp = head;
      if (head->val < x) {
        head = head->next;
        small->next = temp;
        temp->next = nullptr;
        small = temp;
      } else {
        head = head->next;
        large->next = temp;
        temp->next = nullptr;
        large = temp;
      }
    }
    small->next = large_head.next;
    return small_head.next;
  }
};

int main(void) {
  auto l = ListNode::create({1, 4, 3, 2, 5, 2});
  Solution s{};
  s.partition(l, 3);
  return 0;
}
