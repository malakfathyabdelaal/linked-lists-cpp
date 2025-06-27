

#include <iostream>
#include<string>
using namespace std;

class StringNode {
public:
    char info;
    StringNode* next;
    StringNode* prev;

    StringNode() {
        info=' ';
        next =nullptr;
        prev = nullptr;
    }
    StringNode(char n, StringNode* per = nullptr, StringNode* nex = nullptr) {
        info = n;
        next = nex;
        prev= per;
    }
};

class LinkedList {
public:
    StringNode* head, *tail;

    LinkedList() {
        head = tail = nullptr;
    }

    void addtohead(char item) {
        StringNode* newNode= new StringNode(item);
        if (head==nullptr) {head =tail= newNode;return;}
        newNode->next = head;
        head->prev=newNode;
        head = newNode;
    }
    void addtotail(char item) {
        StringNode*newNode= new StringNode(item);
        if (head==nullptr) {
            head = tail = newNode;
            return;
        }
        StringNode* temp=head;
        while (temp->next!=nullptr){temp=temp->next;}
        temp->next=newNode;
        newNode->prev=temp;
        tail=newNode;
    }
    void deletefromhead() {
        if (head==nullptr) {
            cout<<"empty list"<<endl;
            return;
        }
        StringNode* temp=head;
        head=head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }
    void deletefromtail() {
        if (head==nullptr) {
            cout<<"empty list"<<endl;
            return;
        }
        StringNode* temp=tail;
        tail=tail->prev;
        if (tail!=nullptr){tail->next=nullptr;}
        else{head=nullptr;}
        delete temp;
    }
    int stringLength() {
        StringNode* temp=head;
        int length=0;
        while (temp!=nullptr) {temp=temp->next; length++;}
        return length;
    }
    void InsertChar(char item, int pos) {
        if (pos<0 || pos>stringLength()) {cout<<"Invalid Input"<<endl;}
        StringNode* newNode = new StringNode(item);
        if (head==nullptr){ head=tail=newNode; return;}
        if (pos==0) {
            addtohead(item);
            return;
        }
        StringNode* ptr=head;
        int ctr=0;
        while (ptr!=nullptr && ctr<pos-1) {ptr=ptr->next; ctr++;}
        if(ptr->next==nullptr) {addtotail(item); return;}

        newNode->next=ptr->next;
        newNode->prev=ptr;
        ptr->next=newNode;
    }
    void DeleteChar(int pos) {
        if (head == nullptr || pos < 0 || pos >= stringLength()) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos==0) {
            deletefromhead(); return;
        }
        if (head==nullptr){return;}
        StringNode* ptr=head;
        int ctr=0;
        while (ptr!=nullptr && ctr< pos) {ptr=ptr->next; ctr++;}
        if (ptr == nullptr) {cout<<"invalid position"<<endl;return;}
        if (ptr->next== nullptr){deletefromtail(); return;}
        StringNode* del=ptr;
        if (ptr->prev != nullptr) {
            ptr->prev->next=ptr->next;
        }
        if (ptr->next != nullptr) {
            ptr->next->prev=ptr->prev;
        }
        delete del;
    }


    void ConCatenate(LinkedList& list2) {
        if (head==nullptr && list2.head==nullptr) {return;}
        if (list2.head==nullptr) {return;}
        if (head==nullptr) {head=list2.head; tail= list2.tail; return;}
        tail->next=list2.head;
        list2.head->prev=tail;
        tail=list2.tail;
    }
    string SubstringExtraction(int location, int length) {
        if (head == nullptr|| location < 0 || location >= stringLength()|| length <= 0) {cout<<"invalid input"<<endl; return  "";}
        StringNode* ptr=head;
        int ctr=0;
        while (ptr!=nullptr && ctr<location) {
            ptr=ptr->next;
            ctr++;
        }
        if (ptr == nullptr) {cout<<"Invalid position"<<endl; return "";}
        string result= "";
        int strCounter=0;
        while (ptr!= nullptr && strCounter< length) {
            result+=ptr->info;
            ptr=ptr->next;
            strCounter++;
        }
        return result;
    }
    int Search(string word) {
        if (head == nullptr) {
            cout << "Invalid Input" << endl;
            return -1;
        }
            int ctr=0;
            StringNode* ptr=head;
            while (ptr!=nullptr) {
                if (ptr->info == word[0]) {
                    string extracted= SubstringExtraction(ctr, word.length());
                    if (extracted == word) {
                        cout << word << " found at index " << ctr << endl;
                        return ctr;
                    }
                }
                    ptr=ptr->next;
                    ctr++;
                }
        cout<<"Invalid Input"<<endl;
        return -1;

            }



    void Replacment(string Given, string New) {
        if (head == nullptr) {
            cout<<"empty list"<<endl;
            return;
        }
        int indG =Search(Given);
        if (indG==-1) {
            cout<<"Invalid Input"<<endl;
            return;
        }
        for (int i=0;i<Given.length();i++) {
            DeleteChar(indG);
        }
        for (int i= 0;i<New.length();i++ ) {
            InsertChar(New[i],indG+i);
        }

        }
    void Display() {
        if (head==nullptr) {
            cout<<"empty list"<<endl;
        }
        StringNode* ptr=head;
        while (ptr!=nullptr) {
            cout<<ptr->info;
            ptr=ptr->next;
        }
    }

};
int main() {
    string S1, S2, Given, New;
    LinkedList list1, list2;
    int index,length;
    cout<<"please enter the string to add to list1"<<endl;
    cin>>S1;
    for (int i=0;i<S1.length();i++) {
        list1.InsertChar(S1[i],i);
    }
    cout<<"please enter the string to add to list2"<<endl;
    cin>>S2;
    for (int i=0;i<S2.length();i++) {
        list2.InsertChar(S2[i],i);
    }

  list1.ConCatenate(list2);
    cout<<"Concatenated list is:" <<endl;
    list1.Display();

    cout<<"   choose a character by index to remove:"<<endl;
    cin>>index;
    list1.DeleteChar(index);
    cout<<"list after removal:"<<endl;
    list1.Display();

    cout<<"    enter the index and the length to get the substring "<<endl;
    cin>>index>>length;
    cout<<"substring extraction:"<<list1.SubstringExtraction(index,length)<<endl;

    cout<<"Search for a string in the list:"<<endl;
    cin>>S2;
    list1.Search(S2);

    cout<<"Enter 2 substrings to replace one with another"<<endl;
    cin>>Given>>New;
    list1.Replacment(Given,New);
    cout<<"List after Replacment:"<<endl;
    list1.Display();


    return 0;
}
