#include <iostream>

class MyLinkedList
{
    struct Node
    {
        int val;
        Node* next;

        Node() : val(0), next(nullptr) {}
        Node(int val) : val(val), next(nullptr) {}
        Node(int val, Node* next) : val(val), next(next) {}
    };

    Node* virt_head;

public:
    MyLinkedList()
    {
        this->virt_head = new Node();
    }

    ~MyLinkedList()
    {
        auto p = virt_head;
        Node* temp;
        while (p)
        {
            temp = p;
            p = p->next;
            delete temp;
        }
    }
    
    int get(int index)
    {
        auto p = virt_head->next;
        for (int i=0; i<index; i++, p=p->next)
        {
            if (!p) return -1;
        }
        if (!p) return -1;
        return p->val;
    }
    
    void addAtHead(int val)
    {
        auto new_head = new Node(val, virt_head->next);
        virt_head->next = new_head;
    }
    
    void addAtTail(int val)
    {
        auto p = virt_head;
        while (p->next) p = p->next;
        p->next = new Node(val);
    }
    
    void addAtIndex(int index, int val)
    {
        auto p = virt_head;
        for (int i=0; i<index; i++, p=p->next)
        {
            if (!p) return;
        }
        if (!p) return;
        p->next = new Node(val, p->next);
    }
    
    void deleteAtIndex(int index)
    {
        auto p = virt_head;
        for (int i=0; i<index; i++, p=p->next)
        {
            if (!p->next) return;
        }
        if (!p->next) return;
        auto temp = p->next;
        p->next = temp->next;
        delete temp;
    }

    void show()
    {
        std::cout << "-----" << std::endl;
        auto p = virt_head->next;
        while (p)
        {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl << "-----" << std::endl;
    }
};

int main(void)
{
    MyLinkedList l = MyLinkedList();
    l.deleteAtIndex(0);
}
