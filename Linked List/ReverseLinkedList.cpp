#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next; 
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//LinkedList OBJECT DEFINITION
class LinkedList {
    private:
    Node* head;

    public:
    LinkedList(){
        head = NULL;
    }

    LinkedList(Node* head){
        this->head = head; 
    }

    //RETURN HEAD OF LINKED LIST
    Node* getHead(){
        return head;
    }

    //FUNCTION TO INSERT DATA INTO LIST
    void push(int data){
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            return;
        }
        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    
    //DISPLAY LIST
    void displayList(){
        Node* curr = head;
        cout<< "START -> ";
        while(curr != NULL){
            cout<< curr->data << " -> ";
            curr = curr->next;
        }
        cout<< "NULL" << endl;
    }

    //FUNCTION TO REVERSE LIST
    void reverseList(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }


    //FUNCTION TO RETURN MIDDLE ELEMENT
    int middleElement(){
        Node* ptr1 = head;
        Node* ptr2 = head;
        while(ptr2 != NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }
        return ptr1->data;
    }

    //DELETE Nth NODE FROM END
    void deleteFromEnd(int N){
        Node* ptr1 = head;
        while(N--){
            ptr1 = ptr1->next;
        }
        Node* ptr2 = head;
        while(ptr1->next != NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;
    }
};


//FUNCTION TO MERGE 2 SORTED LINKED LISTS
Node* mergeLinkedLists(LinkedList l1, LinkedList l2){
    Node* ptr1 = l1.getHead();
    Node* ptr2 = l2.getHead();
    Node* temp;
    Node* head = (ptr1->data < ptr2->data)? ptr1 : ptr2;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            temp = ptr1->next;
            if(temp != NULL && temp->data > ptr2->data)
                ptr1->next = ptr2;
            if(temp == NULL)
                break;
            ptr1 = temp;
        }
        else{
            temp = ptr2->next;
            if(temp != NULL && temp->data >= ptr1->data)
                ptr2->next = ptr1;
            if(temp == NULL)
                break;
            ptr2 = temp;
        }
    }

    if(ptr1->next == NULL)
        ptr1->next = ptr2;
        
    if(ptr2->next == NULL)
        ptr2->next = ptr1;

    return head;
    
}





int main(){
    // LinkedList ll;// = new LinkedList();
    // ll.push(10);
    // ll.push(20);
    // ll.push(30);
    // ll.push(40);

    // ll.displayList();

    // cout<< "REVERSED LIST IS:" << endl;
    // ll.reverseList();

    // ll.displayList();
    // cout<<"MIDDLE ELEMENT : " << ll.middleElement() << endl;;

    LinkedList l1;
    l1.push(4);
    l1.push(8);
    l1.push(9);
    l1.push(10);
    l1.push(11);

    LinkedList l2;
    l2.push(1);
    l2.push(2);
    l2.push(3);
    l2.push(5);
    l2.push(6);
    l2.push(7);
    //l2.push(11);

    LinkedList ml(mergeLinkedLists(l1, l2));
    ml.displayList();
    ml.deleteFromEnd(6);
    ml.displayList();
}