/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) {
            return null;
        }

        Node headPtr = new Node(-1);
        Node temp = headPtr;
        Map<Node, Node> hm = new HashMap<>();

        while(head != null) {
            if(hm.containsKey(head)) {
                temp.next = hm.get(head);
                temp = temp.next;
            } else {
                temp.next = new Node(head.val);
                temp = temp.next;
                hm.put(head, temp);
            }

            if(head.random != null) {
                if(hm.containsKey(head.random)) {
                    temp.random = hm.get(head.random);
                } else {
                    temp.random = new Node(head.random.val);
                    hm.put(head.random, temp.random);
                }
            } else {
                temp.random = null;
            }
            head = head.next;
        }

        return headPtr.next;
    }
}
