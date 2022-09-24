#include <iostream>


using namespace std;

struct Node {
    Node* next, * prev;
    int data;
};

class List {
    Node* head, * tail;
    int  length = 0;

public:
    List() { // конструктор 
        head = NULL;
        tail = NULL;
    }
    //~List();//деструктор 
    void AddHead(int data) {
        Node* temp = new Node;
        temp->next = temp->prev = NULL;
        temp->data = data;
        if (head != NULL) {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else {
            head = temp;
        }
        length++;
    }

    void AddTail(int data) {
        Node* temp = new Node; 
        temp->prev = temp->next = NULL;
        temp->data = data;
        if (head != NULL) {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        else {
            temp->prev = NULL;
            head = tail = temp;
        }
        length++;   
    }

    void DelHead() {
        if (head != NULL) {
            head = head->next;
            head->prev = NULL;
        }
        else {
            cout << "список пуст";
        }
    }

    void DelTail() {
        if (tail != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            cout << "список пуст";
        }
    }

    void AddIndex(int  index, int data) {
        if (index == 0) {
            cout << "input position";
            cin >> index;
        }
        if (index < 1 || index > length + 1){
            cout << "Incorrect position !!!\n";
            return;
        }
        if (index == length + 1) {
            AddTail(data);
            return;
        }
        if (index == 1) {
            AddHead(data);
            return;
        }

        Node* ins = head;
        int  i = 1;
        while (i < index) {
            ins = ins->next;
            i++;
        }
        Node* previns = ins->prev;

        Node* temp = new Node;
        temp->data = data;
        if (previns != 0 and length != 1) {
            previns->next = temp;
        }
        temp->next = ins;
        temp->prev = previns;
        ins->prev = temp;

        length++;
    }
    
    void GetIndex(int  index) {
        if (index == 0) {
            cout << "input position";
            cin >> index;
        }
        if (index < 1 || index > length + 1) {
            cout << "Incorrect position !!!\n";
            return;
        }
        int  i = 1;
        Node* getindex = head;
        while (i < index) {
            getindex = getindex->next;
            i++;
        }
        cout << getindex->data;
    }

    void DelIndex(int  index) {
        if (index == 0) {
            cout << "input position";
            cin >> index;
        }
        if (index < 1 || index > length) {
            cout << "Incorrect position !!!\n";
            return;
        }
        int  i = 1;
        Node* delindex = head;
        while (i < index) {
            delindex = delindex->next;
            i++;
        }
        Node* prevdelindex = delindex->prev;
        Node* nextdelindex = delindex->next;

        if (prevdelindex != NULL and length != 1) {
            prevdelindex->next = nextdelindex;
        }
        if (nextdelindex != NULL and length != 1) {
            nextdelindex->prev = prevdelindex;
        }
        if (index == 1) {
            head = nextdelindex;
        }
        if (index == length) {
            tail = prevdelindex;
        }
        delete delindex;
        length--;
    }

    void GetLength() {
        cout << "Размер списка: " << length << endl;
    }
    int Length() {
        return length;
    }

    void DelAll() {
        while (length != 0) {
            DelIndex(1);
        }
    }

    void ReplaceData(int  index, int data) {
        if (index == 0) {
            cout << "input position";
            cin >> index;
        }
        if (index < 1 || index > length) {
            cout << "Incorrect position !!!\n";
            return;
        }
        int  i = 1;
        Node* replacedata = head;
        while (i < index) {
            replacedata = replacedata->next;
            i++;
        }
        replacedata->data = data;
    }

    void IfEmpty() {
        if (length == 0) {
            cout << "Список пуст";
        }
    }

    void Show() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
    bool Find(List* mainlist, List* sublist) {
        if (mainlist == NULL and sublist == NULL) {
            cout << "Списки пусты!";
            return 0;
        }
        int score = 0;
        int lengthlocal = sublist->Length();

        Node* mainnode = new Node;
        Node* sublistnode = new Node;
        Node* temp = new Node;

        mainnode = mainlist->head;
        sublistnode = sublist->head;


        while (mainnode->next != NULL)
        {
            temp = mainnode;
            while (temp->data == sublistnode->data)
            {
                temp = temp->next;
                sublistnode = sublistnode->next;
                if (sublistnode == NULL)
                {
                    cout << "есть подстрока";
                    return 1;
                }
            }
            sublistnode = sublist->head;
            mainnode = mainnode->next;
        }
        cout << "В строке нет подстрок";
        return 0;
    }   
};



int main()
{
    setlocale(LC_ALL, "RUSSIAN");

    List* mainlist = new List; 
    List* sublist = new List;
    mainlist->AddTail(1);
    mainlist->AddTail(3);
    mainlist->AddTail(3);
    mainlist->AddTail(4);
    mainlist->AddTail(5);
    mainlist->AddTail(6);
    mainlist->AddTail(7);
    mainlist->AddTail(8);
   /* main->DelHead();
    main->DelTail();
    main->Show();*/
    sublist->AddTail(3);
    sublist->AddTail(4);
    sublist->AddTail(5);
    sublist->AddTail(6);

    //main->AddHead(5);
    //main->AddIndex(2, 9);
    
    //main->DelIndex(3);
    //main->ReplaceData(3, 5);
    mainlist->Show();
    mainlist->GetLength();
    sublist->Show();
    sublist->GetLength();
    
    
    
    mainlist->Find(mainlist, sublist);
   /* main->DelAll();
    main->IfEmpty();*/





}


