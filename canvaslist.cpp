#include "canvaslist.h"

#include <iostream>

using namespace std;

CanvasList::CanvasList() {
    list_size = 0;
    list_front = nullptr;
}

CanvasList::CanvasList(const CanvasList& other) {
    //if we're trying to copy an empty list
    if (other.front() == nullptr) {
        list_front = nullptr;
        list_size = 0;
        return;
    }

    //create new node to iterate through other list
    ShapeNode* oCurr = other.front();

    //instantiate new front node for this list
    list_front = new ShapeNode;
    list_front->value = oCurr->value->copy();
    list_front->next = nullptr;
    list_size = 1;

    //instantiate new node to iterate through this list
    ShapeNode* tCurr = list_front;

    //move oCurr to next to prepare for loop
    oCurr = oCurr->next;

    while (oCurr != nullptr) { 
        //allocate memory for the next node
        tCurr->next = new ShapeNode;
        tCurr = tCurr->next;
        //populate the new node's values
        tCurr->value = oCurr->value->copy();
        tCurr->next = nullptr;
        //move to next iteration of other list
        oCurr = oCurr->next;

        //update list_size
        list_size++;
    }
}

CanvasList& CanvasList::operator=(const CanvasList& other) {
    //just return the list if they're the same
    if (other.front() == list_front) {
        return *this;
    }

    //get rid of old data because it is useless
    this->clear();
    this->list_size = 0;
    this->list_front = nullptr;

    //if we're trying to copy an empty list
    if (other.front() == nullptr) {
        list_front = nullptr;
        list_size = 0;
        return *this;
    }

    //create new node to iterate through other list
    ShapeNode* oCurr = other.front();

    //instantiate new front node for this list
    list_front = new ShapeNode;
    list_front->value = oCurr->value->copy();
    list_front->next = nullptr;
    list_size = 1;

    //instantiate new node to iterate through this list
    ShapeNode* tCurr = list_front;

    //move oCurr to next to prepare for loop
    oCurr = oCurr->next;

    while (oCurr != nullptr) { 
        //allocate memory for the next node
        tCurr->next = new ShapeNode;
        tCurr = tCurr->next;
        //populate the new node's values
        tCurr->value = oCurr->value->copy();
        tCurr->next = nullptr;
        //move to next iteration of other list
        oCurr = oCurr->next;

        //update list_size
        list_size++;
    }

    return *this;
}

CanvasList::~CanvasList() {
    ShapeNode* curr = list_front;

    while (curr != nullptr) {
        curr = curr->next;
        delete list_front->value;
        delete list_front;
        list_front = curr;
    }

    delete curr;
}

void CanvasList::clear() {
    //create nodes to hold front since we're setting it to nullptr
    ShapeNode* curr = list_front;
    ShapeNode* nxt;

    list_front = nullptr;

    //clearing, so we go until the list is done
    while (curr != nullptr) {
        //hold our next value
        nxt = curr->next;

        //remove curr from memory
        delete curr->value;
        delete curr;

        //move curr to the next value
        curr = nxt;

        //decrement list_size
        list_size--;
    }
}

void CanvasList::insert_after(int index, Shape* s) {
    //return if index is invalid
    if (index >= list_size || index < 0 || list_size == 0) {
        return;
    }

    //go to the node at index
    //KEEP IN MIND: Indexing starts at 0
    ShapeNode* curr = list_front;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    //populate new node and add it to the list
    //updating the relevant variables
    ShapeNode* sn = new ShapeNode;
    sn->value = s;
    sn->next = curr->next;
    curr->next = sn;
    list_size++;
}

void CanvasList::push_front(Shape* s) {
    //instantiate the new ShapeNode
    ShapeNode* sn = new ShapeNode;
    sn->value = s;
    sn->next = list_front;

    //update canvaslist variables to account for new head
    list_front = sn;
    list_size++;
}

void CanvasList::push_back(Shape* s) {
    //instantiate new node 
    ShapeNode* nn = new ShapeNode;
    nn->value = s;
    nn->next = nullptr;

    //if list is empty, no need to iterate through
    //just make nn the head and return
    if (list_front == nullptr) {
        list_front = nn;
        list_size++;
        return;
    }

    //iterate through list until we reach the last node
    ShapeNode* curr = list_front;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    //add nn to the end of the list and update size
    curr->next = nn;
    list_size++;
}

void CanvasList::remove_at(int index) {
    //if the index is the front node
    if (index == 0) {
        Shape* del = pop_front();
        delete del;
        return;
    }

    //if the index is the last node in the list
    if (index == list_size - 1) {
        Shape* del = pop_back();
        delete del;
        return;
    }  

    //if the index is invalid
    if (index < 0 || index >= list_size) {
        return;
    }

    //if we're removing in the middle
    ShapeNode* curr = list_front;

    //iterate through the linked list until we reach the node before deletion
    for (int i = 0; i < index - 1; i++) {
        if (curr == nullptr) {
            return;
        }
        curr = curr->next;
    }

    //save the node after our node for deletion
    ShapeNode* oneAfter = curr->next->next;

    //delete the node
    delete curr->next->value;
    delete curr->next;

    //fill the gap set by our deletion
    curr->next = oneAfter;

    //update list size
    list_size--;
}

void CanvasList::remove_every_other() {
    for (int i = 1; i < list_size; i += 2) {
        remove_at(i);
        i--; //decrement i since we're decreasing list_size with each remove statement
    }
}

Shape* CanvasList::pop_front() {
    //can't pop anything if there's nothing to pop
    if (list_front == nullptr) {return nullptr;}

    //store shape in variable to return
    Shape* popped = list_front->value;
    
    //save head's next node that will become list head
    ShapeNode* nextNode = list_front->next;
    
    //deleting current head and updating that value to next value
    delete list_front;
    list_front = nextNode;

    //update list_size
    list_size--;

    return popped;
}

Shape* CanvasList::pop_back() {
    //return nullptr if the list is empty
    if (list_front == nullptr) {
        return nullptr;
    }

    //case list is size 1
    if (list_size == 1) {
        Shape* s = list_front->value;

        delete list_front;
        list_front = nullptr;

        list_size--;

        return s;
    }

    ShapeNode* curr = list_front;

    //stops at the node before the last node
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    //take last node out of the list, update penultimate node
    ShapeNode* del = curr->next;
    curr->next = nullptr;

    //get shape and free useless node's memory
    Shape* ret = del->value;
    delete del;

    //update size
    list_size--;

    if (list_size == 0) {
        list_front = nullptr;
    }

    return ret;
}

ShapeNode* CanvasList::front() const {
    return list_front;
}

bool CanvasList::empty() const {
    if (list_front == nullptr) {
        return true;
    }
    return false;
}

int CanvasList::size() const {
    return list_size;
}

int CanvasList::find(int x, int y) const {
    ShapeNode* curr = list_front;
    int index = -1;

    //go through list
    for (int i = 0; i < list_size && curr != nullptr; i++) {
        //end the loop if we find the same x and y, set index as i and return it
        if (curr->value->getX() == x && curr->value->getY() == y) {
            index = i;
            break;
        }
        curr = curr->next;
    }

    return index;
}

Shape* CanvasList::shape_at(int index) const {
    //if the index is invalid return nullptr
    if (index >= list_size || index < 0) {
        return nullptr;
    }

    //iterate through list until we reach the index
    ShapeNode* curr = list_front;
    for (int i = 0; i < index; i++) {
        //catch nullptr just in case
        if (curr == nullptr) {
            return nullptr;
        }

        curr = curr->next;
    }
    return curr->value;
}

void CanvasList::draw() const {
    ShapeNode* curr = list_front;
    while (curr != nullptr) {
        cout << curr->value->as_string() << endl;
        curr = curr->next;
    }
}

void CanvasList::print_addresses() const {
    ShapeNode* curr = list_front;

    while (curr != nullptr) {
        cout << "Node Address: " << curr << "\tShape Address " << curr->value << endl;
        curr = curr->next;
    }
}