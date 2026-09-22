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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode ptr1 = head;
        ListNode ptr2 = ptr1;

        ListNode prev = new ListNode(-1);
        while(n-- > 0) {
            ptr2 = ptr2.next;
        }

        while(ptr2 != null) {
            prev = ptr1;
            ptr1 = ptr1.next;
            ptr2 = ptr2.next;
        }

        if(ptr1 == head) {
            head = ptr1.next;
            ptr1.next = null;
        } else {
            prev.next = ptr1.next;
        }

        return head;
    }
}
