// User function Template for Java

/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/

class Solution {
    Node divide(Node head) {
        // code here
        Node evendummy=new Node(0);
        Node odddummy=new Node(0);
        Node even=evendummy;
        Node odd=odddummy;
        Node curr=head;
        while(curr!=null ){
            if(curr.data%2==0){
                even.next=curr;
                even=even.next;
                
            }else{
                odd.next=curr;
                odd=odd.next;
            }
            curr=curr.next;
            
        }
        odd.next = null;                  
        even.next=odddummy.next;
        return evendummy.next;
    }
}