/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode root = new ListNode();
        ListNode current = root;
        boolean brk = false;
        while(!brk){
            brk = true;
            int mn = (int)2e9;
            for(int i = 0;i < lists.length;i++){
                if(lists[i] == null){continue;}
                if(lists[i].val < mn){mn = lists[i].val;}
            }
            for(int i = 0;i < lists.length;i++){
                while(lists[i] != null && lists[i].val == mn){
                    current.next = new ListNode();
                    current = current.next;
                    brk = false;
                    lists[i] = lists[i].next;
                    current.val = mn;
                }
            }
        }
        return root.next;
    }
}
