/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    string converListToString(ListNode* root){
        string s = "";
        while(root != nullptr){
            s += root->val + '0';
            root = root->next;
        }
        return s;
    }
    string addTwoStrings(string a, string b){
        string res = "";
        if(a.size() < b.size()){swap(a,b);}
        int c = 0;
        for(int i = 0;i < (int)a.size();i++){
            int da = a[i] - '0';
            int db = 0;
            if(i < (int)b.size()){db = b[i] - '0';}
            int sum = da + db + c;
            if(sum > 9){sum -= 10; c = 1;}else{c = 0;}
            res += sum + '0';
        }
        if(c > 0){res += '1';}
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string sL1 = converListToString(l1);
        string sL2 = converListToString(l2);
        string res = addTwoStrings(sL1, sL2);
        ListNode* root = new ListNode();
        root->val = res[0] - '0';
        ListNode* current = root;
        for(int i = 1;i < res.size();i++){
            current->next = new ListNode();
            current = current->next;
            current->val = res[i] - '0';
        }
        return root;
    }
};
