class Solution {
public:
        int count(ListNode *head){
            int res=0;
            while(head){
                res++;
                head=head->next;
            }
            return res;
        }
        vector<int> nextLargerNodes(ListNode* head) {
            int n=count(head);
            vector<int> ans(n,0);
            stack<pair<int,int>> s;
            int i=0;
            while(head){
                while(!s.empty() && s.top().first<head->val){
                    int idx=s.top().second;
                    s.pop();
                    ans [idx] = head->val;
                }
                s.push({head->val,i++});
                head=head->next;
        }
        return ans;
    }
};