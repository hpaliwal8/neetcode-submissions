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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;

        ListNode temp1 = l1;
        ListNode temp2 = l2;
        ListNode headPtr = new ListNode(-1);
        ListNode ptr = headPtr;

        while(temp1 != null && temp2 != null) {
            int sum = temp1.val + temp2.val + carry;
            ptr.next = new ListNode(sum % 10);
            carry = sum/10;

            ptr = ptr.next;

            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        while(temp1 != null) {
            int sum = temp1.val + carry;
            ptr.next = new ListNode(sum % 10);
            carry = sum/10;

            ptr = ptr.next;

            temp1 = temp1.next;
        }


        while(temp2 != null) {
            int sum = temp2.val + carry;
            ptr.next = new ListNode(sum % 10);
            carry = sum/10;

            ptr = ptr.next;

            temp2 = temp2.next;
        }

        if(carry != 0) {
            ptr.next = new ListNode(carry);
            carry = 0;

            ptr = ptr.next;
        }

        return headPtr.next;
    }
}
