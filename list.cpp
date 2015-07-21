// list
// - linked list
// - stack derived from linked list

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

// -----------------  CLASS ListNode  ---------------------------------------------

template <class NODETYPE>
class List;

template <class NODETYPE>
class ListNode {
    friend class List<NODETYPE>;
public:
    ListNode(const NODETYPE &);
    NODETYPE get() const;
private:
    NODETYPE data;
    ListNode<NODETYPE> *next;
    ListNode<NODETYPE> *prev;
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &n)
{
    data = n;
    next = NULL;
    prev = NULL;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::get() const
{
    return data;
}

// -----------------  CLASS List  -------------------------------------------------

template <class NODETYPE>
class List {
public:
    List();
    ~List();
    void insert_at_head(const NODETYPE &);
    void insert_at_tail(const NODETYPE &);
    bool remove_from_head(NODETYPE &);
    bool remove_from_tail(NODETYPE &);
    bool is_empty();
    void fwd_print();
    void rev_print();
// XXX begin end
private:
    ListNode<NODETYPE> * head;
    ListNode<NODETYPE> * tail;
};

template <class NODETYPE>
List<NODETYPE>::List()
{
    head = tail = NULL;
}

template <class NODETYPE>
List<NODETYPE>::~List()
{
    NODETYPE val;
    // cout << "DESTRUCTOR ...\n";
    while (remove_from_head(val)) {
        // cout << "destroyed " << val << endl;
    }
}

template <class NODETYPE>
void List<NODETYPE>::insert_at_head(const NODETYPE &n)
{
    ListNode<NODETYPE> *ptr;

    ptr = new ListNode<NODETYPE>(n);  
    assert(ptr);

    if (is_empty()) {
        head = tail = ptr;
    } else {
        head->prev = ptr;
        ptr->next = head;
        head = ptr;
    }
}

template <class NODETYPE>
void List<NODETYPE>::insert_at_tail(const NODETYPE &n)
{
    ListNode<NODETYPE> *ptr;

    ptr = new ListNode<NODETYPE>(n);  
    assert(ptr);

    if (is_empty()) {
        head = tail = ptr;
    } else {
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}

template <class NODETYPE>
bool List<NODETYPE>::remove_from_head(NODETYPE &val)
{
    if (is_empty()) {
        return false;
    }

    ListNode<NODETYPE> *ptr = head;
    val = ptr->get();
    head = ptr->next;
    if (head == NULL) {
        tail = NULL;
    } else {
        head->prev = NULL;
    }
    delete ptr;
    return true;
}

template <class NODETYPE>
bool List<NODETYPE>::remove_from_tail(NODETYPE &val)
{
    if (is_empty()) {
        return false;
    }

    ListNode<NODETYPE> *ptr = tail;
    val = ptr->get();
    tail = ptr->prev;
    if (tail == NULL) {
        head = NULL;
    } else {
        tail->next = NULL;
    }
    delete ptr;
    return true;
}

template <class NODETYPE>
bool List<NODETYPE>::is_empty()
{
    return head == NULL;
}

template <class NODETYPE>
void List<NODETYPE>::fwd_print()
{
    if (is_empty()) {
        cout << "empty";
        return;
    }

    ListNode<NODETYPE> *ptr = head;
    while (ptr) {
        cout << ptr->get() << " ";
        ptr = ptr->next;
    }
}

template <class NODETYPE>
void List<NODETYPE>::rev_print()
{
    if (is_empty()) {
        cout << "empty";
        return;
    }

    ListNode<NODETYPE> *ptr = tail;
    while (ptr) {
        cout << ptr->get() << " ";
        ptr = ptr->prev;
    }
}

// -----------------  STACK  ------------------------------------------------------

// XXX

// -----------------  MAIN  -------------------------------------------------------

int main()
{
    // test list_of_doubles
    {
    cout << "list_of_doubles: init" << endl;
    List<double> list_of_doubles;
    for (double d = 1; d <= 10; d++) {
        list_of_doubles.insert_at_tail(d);
    }

    cout << "list_of_doubles: fwd_print = ";
    list_of_doubles.fwd_print();
    cout << endl;

    cout << "list_of_doubles: rev_print = ";
    list_of_doubles.rev_print();
    cout << endl;

    cout << "list_of_doubles: remove_from_tail = ";
    double val;
    while (list_of_doubles.remove_from_tail(val)) {
        cout << val << " ";
    }
    cout << endl;

    cout << "list_of_doubles: fwd_print = ";
    list_of_doubles.fwd_print();
    cout << endl;

    cout << "list_of_doubles: rev_print = ";
    list_of_doubles.rev_print();
    cout << endl;
    }
    cout << endl;

    // test list_of_chars
    {
    cout << "list_of_chars: init" << endl;
    List<char> list_of_chars;
    for (char c = 'a'; c <= 'z'; c++) {
        list_of_chars.insert_at_tail(c);
    }

    cout << "list_of_chars: fwd_print = ";
    list_of_chars.fwd_print();
    cout << endl;
    }
    cout << endl;

    cout << "done" << endl;
    return 0;
}
