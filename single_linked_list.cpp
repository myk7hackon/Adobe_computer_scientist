#include <iostream>

using namespace std;

class Node {
    public:
        int val;
    Node * next;

    Node() {
        return;
    }
    Node(int val) {
        this -> val = val;
        this -> next = NULL;
    }

    void AddElement(Node ** head, int val) {
        Node * new_element_ptr = new Node();
        new_element_ptr -> val = val;
        new_element_ptr -> next = NULL;
        Node * temp_ptr = * head;
        while (temp_ptr -> next != NULL) {
            temp_ptr = (temp_ptr) -> next;
            cout << temp_ptr -> val << endl;
        }
        cout << temp_ptr -> val << endl;
        temp_ptr -> next = new_element_ptr;
    }

    void DeleteElem(Node ** head, int val) {
        Node * temp_ptr = * head;
        while (temp_ptr -> next -> val != val) {
            temp_ptr = (temp_ptr) -> next;
            cout << temp_ptr -> val << endl;
        }
        temp_ptr -> next = temp_ptr -> next -> next;
    }

    void length(Node * head) {
        Node * temp_ptr = head;
        int length = 0;
        while (temp_ptr) {
            temp_ptr = temp_ptr -> next;
            length += 1;
        }
        cout << "Length is " << length << endl;
    }
    void length_recursive(Node * head, int count = 0) {
        if (head == NULL) {
            cout << "Length recursive is " << count << endl;
            return;
        }
        this -> length_recursive(head -> next, count + 1);
    }
    void find_elem_recurv(Node * head, int search_val, int index = 0) {
        if (head == NULL) {
            cout << "Element doesn't exist" << endl;
            return;
        }
        if (head -> val == search_val) {
            cout << "This element is at index " << index + 1 << endl;
            return;
        }
        find_elem_recurv(head -> next, search_val, index + 1);
    }
    void nth_element_from_the_end(Node * head, int n) {
        Node * forward_ptr = head;
        Node * backward_ptr = head;
        if (head == NULL) {
            cout << "Empty List\n";
            return;
        }
        while (n) {
            forward_ptr = forward_ptr -> next;
            n = n - 1;
            if (forward_ptr == NULL) {
                cout << "Empty List\n";
                return;
            }
        }
        while (forward_ptr != NULL) {
            forward_ptr = forward_ptr -> next;
            backward_ptr = backward_ptr -> next;
        }
        cout << "Nth from end is " << backward_ptr -> val << endl;
    }

    void findMiddleElem(Node * head) {
        Node * forward_ptr = head;
        Node * backward_ptr = head;
        while (forward_ptr && forward_ptr -> next) {
            backward_ptr = backward_ptr -> next;
            forward_ptr = forward_ptr -> next -> next;
        }
        cout << "Middle Pointer is " << backward_ptr -> val << endl;
    }

    void findIfACycle(Node * head) {
        Node * fast_ptr = head;
        Node * slow_ptr = head;
        while (fast_ptr -> next && fast_ptr && slow_ptr) {
            fast_ptr = fast_ptr -> next -> next;
            slow_ptr = slow_ptr -> next;
            if (fast_ptr == slow_ptr) {
                cout << "Its a cycle\n";
                break;
            }
        }
        fast_ptr = head;
        while (fast_ptr && slow_ptr) {
            if (fast_ptr == slow_ptr) {
                cout << "Its a cycle at " << slow_ptr -> val << endl;
                return;
            }
            fast_ptr = fast_ptr -> next;
            slow_ptr = slow_ptr -> next;
        }
    }

    void swapPairWise(Node ** head, Node ** next) {
        if ( * head != NULL && * next != NULL) {
            int x = ( * head) -> val;
            int y = ( * next) -> val;
            ( * head) -> val = y;
            ( * next) -> val = x;
            if (( * head) -> next && ( * next) -> next)
                swapPairWise( & (( * head) -> next -> next), & (( * next) -> next -> next));
        }
    }

    Node * reverseLinkedList(Node ** head, Node ** next, Node * heading) {
        Node * temp = * head;
        while (temp -> next != NULL)
            temp = temp -> next;
        if ( * next != NULL && * head != NULL) {
            reverseLinkedList(next, & (( * next) -> next), heading);
            cout << ( * head) -> val << "  " << ( * next) -> val << endl;
            Node * temp = ( * next) -> next;
            ( * next) -> next = * head;
            ( * head) -> next = temp;
        }
        return temp;
    }
};
void freeList(Node ** head) {
    Node * current = * head;
    while (current != NULL) {
        Node * next = current -> next;
        free(current);
        current = next;
    }
}

int main() {
    Node * head = new Node();
    head -> val = 4;
    head -> next = NULL;
    ( * head).AddElement( & head, 2);
    for (int i = 0; i < 100; i++)
        ( * head).AddElement( & head, i + 7);
    cout << "Head value is " << head -> val << endl;
    Node * temp_ptr = head;
    cout << "Print after insertion\n";
    while (temp_ptr -> next != NULL) {
        cout << temp_ptr -> val << "-->";
        temp_ptr = temp_ptr -> next;
    }
    cout << temp_ptr -> val << endl;
    ( * head).nth_element_from_the_end(head, 11);
    ( * head).length(head);
    ( * head).length_recursive(head);
    ( * head).find_elem_recurv(head, 4);
    ( * head).find_elem_recurv(head, 55);
    ( * head).findMiddleElem(head);
    ( * head).DeleteElem( & head, 2);
    ( * head).length(head);
    ( * head).length_recursive(head);
    temp_ptr = head;
    cout << "\\\nAfter Deletion  ";
    while (temp_ptr -> next != NULL) {
        cout << temp_ptr -> val << "-->";
        temp_ptr = temp_ptr -> next;
    }
    cout << temp_ptr -> val << endl;
    freeList( & head);
    cout << head << endl;

    cout << "Cycle Detection" << endl;
    Node * head2 = new Node();
    head2 -> val = 4;
    head2 -> next = NULL;
    Node * temp = new Node();
    head2 -> next = temp;
    temp -> val = 3;
    temp -> next = NULL;
    cout << head2 -> next -> val << endl;
    Node * temp2 = new Node();
    temp -> next = temp2;
    temp2 -> val = 14;
    temp2 -> next = NULL;
    Node * temp3 = new Node();
    temp2 -> next = temp3;
    temp3 -> val = 7;
    temp3 -> next = NULL;
    Node * temp4 = new Node();
    temp3 -> next = temp4;
    temp4 -> val = 11;
    temp4 -> next = NULL;
    Node * temp5 = new Node();
    temp5 -> val = 41;
    temp5 -> next = NULL;
    temp4 -> next = temp5;
    temp_ptr = head2;
    while (temp_ptr != NULL) {
        cout << temp_ptr -> val << "-->";
        temp_ptr = temp_ptr -> next;
    }
    cout << endl;
    temp_ptr = head2;
    ( * head2).swapPairWise( & head2, & (head2 -> next));
    temp_ptr = head2;
    while (temp_ptr != NULL) {
        cout << temp_ptr -> val << "-->";
        temp_ptr = temp_ptr -> next;
    }
    cout << endl;
    head2 = ( * head2).reverseLinkedList( & head2, & (head2 -> next), head2);
    temp_ptr = head2;
    while (temp_ptr != NULL) {
        cout << temp_ptr -> val << "-->";
        temp_ptr = temp_ptr -> next;
    }

}
