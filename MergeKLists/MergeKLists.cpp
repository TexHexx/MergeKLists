#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class findNeeded
{
public:
    bool operator()(ListNode* lhs, ListNode* rhs)
    {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> iterators = lists;
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        std::priority_queue<ListNode*, vector<ListNode*>, findNeeded> queue;
        for (auto iterator = lists.begin(); iterator < lists.end(); ++iterator) {
            if (*iterator != nullptr) {
                queue.push(*iterator);
                (*iterator) = (*iterator)->next;
            };
        }
        while (queue.size() > 0) {
            head->next = new ListNode(queue.top()->val);
            queue.pop();
            head = head->next;
            for (auto iterator = lists.begin(); iterator < lists.end(); ++iterator) {
                if ((*iterator) == nullptr)
                    continue;
                queue.push(*iterator);
                (*iterator) = (*iterator)->next;
            }
        };
        return result->next;
    }
};

int main()
{
    
}
