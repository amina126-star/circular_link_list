#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr)
	{}
};
class CircularLinkedList
{
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr)
    {}

    ~CircularLinkedList()
    {
        if (head)
        {
            Node* temp = head;
            while (temp->next != head)
            {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            delete temp;
        }
    }

    void insertAtHead(int data)
    {

        if (!head)
        {
            head = new Node(data);
            // head->next =head;

        }
        else
        {
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp = head;
        }
    }

    void insertAtTail(int data)
    {
        //  Node* newNode = new Node(data);

        if (!head)
        {
            head = new Node(data);
            head->next = head;
        }
        else
        {
            Node* temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = new Node(data);
            temp->next->next = head;

        }
    }

        void deleteAtHead()
        {
            if (!head)
                return;
            if (head->next == head)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node* temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
        }
        void deleteAtTail()
        {
            if (!head)
            {
                exit(0);
            }
            else if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node* temp = head;
                Node* prev = nullptr;
                while (temp->next!=head)
                {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = head;
                delete temp;
            }
        }
        void addAfter(int targetValue, int newValue)
        {
            Node* temp = search(targetValue);
     
            if (temp == nullptr)
            {
                insertAtTail(newValue);

            }
            else
            {
                Node* newptr = new Node(newValue);
                if (temp->next == nullptr || temp->next == head)
                {
                    newptr->next = head;
                }
                else
                {
                    newptr->next = temp->next;
                }
                temp->next= newptr;
              
            }
        }
        void deleteAfter(int targetValue)
        {
            Node* temp = search(targetValue);
            if (temp->next == nullptr)
            {
                return;
            }
            else
            {
                Node* ptr = temp->next;
                temp->next = temp->next->next;
                if (ptr == head)
                {
                    head = temp->next;
                }
                delete ptr;

            }
        }
        void addBefore(int targetValue, int newValue) {
            Node* temp = search(targetValue);

            if (temp == nullptr) {
                // Target value not found
                return;
            }

            Node* newptr = new Node(newValue);

            if (temp == head) {
                // Target node is head, update head
                Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                newptr->next = head;
                last->next = newptr;
                head = newptr;
            }
            else {
                Node* prev = head;
                while (prev->next != temp) {
                    prev = prev->next;
                }
                newptr->next = temp;
                prev->next = newptr;
            }
        }
        void deleteBefore(int targetValue) 
        {
            Node* temp = search(targetValue);

            if (temp == nullptr || temp == head) {
                // Target value not found or target node is head
                return;
            }

            Node* prev = head;
            while (prev->next != temp) {
                prev = prev->next;
            }

            if (prev == head) {
                // Node to delete is the last node
                Node* last = head;
                while (last->next != prev) {
                    last = last->next;
                }
                last->next = temp;
            }
            else {
                prev->next = temp->next;
            }

            delete prev;
        }




        void printList()
        {
            if (!head) return;
            Node* temp = head;
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }

        Node* search(int targetValue)
        {
            Node* temp = head;
            while (temp)
            {
                if (temp->data == targetValue)
                    return temp;
                temp = temp->next;
            }
            return temp;
           
        }
        void reverse()
        {
            if (head == nullptr || head->next == head)
            {
                return;
            }

            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;

            while (curr != head)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
            prev->next = curr;
        }
     void deleteNode(int data)
{
    if (!head)
        return;
    if (head->data == data)
    {
        deleteAtHead();
        return;
    }
    Node* temp = head;
    while (temp->next != head)
    {
        if (temp->next->data == data)
        {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }
}       
};

    
        int main()
        {
            CircularLinkedList list;
            list.insertAtTail(1);
            list.insertAtTail(2);
            list.insertAtTail(3);
            list.printList(); // Output: 1 2 3
            //  list.deleteNode(2);
            //  list.printList(); // Output: 1 3
          return 0;
        }
