#include <iostream>

using namespace std;

class Node {
public:
    int info;
    Node* next;
    int ctr;

    Node(int i,Node* n=0)
    {
        info = i;
        next = n;
        ctr = 1;
    }

};
class LinkedList {
public:
    Node* head, *tail;

    LinkedList() {
        head = tail = nullptr;
    }
    void addInOrder(int value){

        Node* ptr = head;
        Node* temp = nullptr;
        Node* newV = new Node (value);

        //Empty list case
        if (head==nullptr && tail==nullptr){
            head=tail=newV;
            return;
        }

        //smallest value case
        if (value< (head->info) )
        {
            newV->next=head;
            head = newV;
            return;
        }

            while (ptr != nullptr && ptr->info < value) {
                temp = ptr;
                ptr = ptr -> next;
            }

            //value already exists case
            if (ptr != nullptr && ptr->info == value) {
                ptr->ctr++;
                delete newV;
                return;
            }
            //value larger than tail
            if (ptr == nullptr) {
             tail->next = newV;
                tail=newV;
                return;

            }

        //default case
        newV->next = ptr;
        temp->next = newV;

        }

    void Display(){

        Node* ptr = head;

        while(ptr != nullptr){
            for(int i=0; i < ptr->ctr; i++){
                cout<< ptr->info << " ";
            }
            ptr = ptr -> next;
        }
        cout<<endl;
    }
    void DeleteValue(int value) {
        Node* ptr = head;
        Node* temp = nullptr;

        // Empty list case
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        // Value exists at head and has ctr == 1 (remove head)
        if (head->info == value && head->ctr == 1) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;

            if (head == nullptr) {  // If the list is now empty, update tail
                tail = nullptr;
            }

            return;
        }
        // Traverse the list to find the node
        while (ptr != nullptr && ptr->info != value) {
            temp = ptr;
            ptr = ptr->next;
        }

        // Value not found
        if (ptr == nullptr) {
            cout << "Value not found." << endl;
            return;
        }

        // If the node to delete is the only node in the list
        if (head == tail && ptr->ctr == 1) {
            delete head;
            head = tail = nullptr;
            return;
        }
        // If deleting the tail node (when counter is 1)
        if (ptr == tail && ptr->ctr == 1) {
            temp->next = nullptr;  // Disconnect the last node
            delete tail;
            tail = temp;  // Update tail to the new last node
            return;
        }

        // Value exists once (delete the node)
        if (ptr->ctr == 1) {
            temp->next = ptr->next;
            delete ptr;
            return;
        }

        // Value exists multiple times (decrease counter)
        else if (ptr->ctr > 1) {
            ptr->ctr--;
        }
    }

    void DisplayDes() {
        int count =0;
        Node* temp = head;
        while (temp != nullptr) {
                count+=temp->ctr;
                temp = temp->next;
        }
        int* Arr = new int[count];
        int index =0;
        temp = head;
        while (temp != nullptr) {
            for (int i = 0; i < temp->ctr; i++) {
                Arr[index++]=temp->info;
            }
            temp = temp->next;
        }
        //display des
        for (int i = count - 1; i >= 0; i--) {
            cout << Arr[i] << " ";
        }
        cout << endl;
        delete[] Arr;
    }

    void RemoveMax() {
        Node* temp = head;
        if (head == nullptr) {
            return;
        }
        if (head == tail){ delete head; head=tail=nullptr; return; }
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next= nullptr;

    }
    void Clear() {
        Node* temp = head;
        while (head != nullptr) {
            head = head->next;
            delete temp;
        }
        tail=nullptr;
    }
    void generateFromArray(int arr[],int size) {
        for (int i = 0; i < size; i++) {
            addInOrder(arr[i]);
        }
    }
};

int main() {
    LinkedList list;
    int Arr[]={1,1,7,7,7,2,2,3,10,15};
    int size = 10;
    int del;
    int elem;
    list.generateFromArray(Arr,size);
    list.Display();

    cout<<"enter element you want to add:"<<endl;
    cin>>elem;
    list.addInOrder(elem);
    cout<<"List after element addition:"<<endl;
    list.Display();

    cout<<"list in Descending order:"<<endl;
    list.DisplayDes();

    cout<<"enter the value you want to delete:"<<endl;
    cin>>del;
    list.DeleteValue(del);
    cout<<"list after deleteValue:"<<endl;
    list.Display();

    cout<<"list after RemoveMax:"<<endl;
    list.RemoveMax();
    list.Display();

    cout<<"list removal:"<<endl;
    list.Clear();
    list.Display();

    return 0;
}