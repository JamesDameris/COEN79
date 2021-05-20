//File: node.cpp
//Authors: James Dameris and Zach Azer
//Class implemented: node (see node.h)
#ifndef ITEM_CPP
#define ITEM_CPP

#include "node.h"

namespace coen79_lab7
{
/* Function: copy constructor
 * Description: copy constructor for the node class
*/ 
    node::node(const std::string &itemName, const float &newPrice, node *nextNode) {
        name = itemName;
        price = newPrice;
        link = nextNode;
    }
/* Function: set name
 * Description: sets the name field of the node
*/     
    void node::setName(const std::string &newName) {
        name = newName;
    }
/* Function: set price
 * Description: sets the price field of the node
*/ 
    void node::setPrice(const float &newPrice) {
        price = newPrice;
    }
/* Function: set link
 * Description: sets the link field of the node
*/ 
    void node::setLink(node *new_next) {
        link = new_next;
    }
/* Function: get link
 * Description: returns the link from this node
*/ 
    node* node::getLink() {
        return link;
    }
/* Function: get link (constant)
 * Description: returns the constant version of the link from this node
*/ 
    const node* node::getLink() const {
        return link;
    }
/* Function: get name
 * Description: returns the name field of the node
*/ 
    std::string node::getName() const{
        return name;
    }
/* Function: get price
 * Description: returns the price field of the node
*/  
    float node::getPrice() const {
        return price;
    }
/* Function: list init 
 * Description: initializes an empty list and modifies the head and tail pointers
*/ 
    void list_init(node*& head, node*& tail, const std::string& newName, const float& newPrice) {
        head = new node(newName, newPrice, NULL);
        tail = head;
    }
/* Function: list tail insert
 * Description: inserts a node at the back of the list
 * Runtime: O(1)
*/ 
    void list_tail_insert(node*& tail, const std::string &newName, const float &newPrice) {
        // assert(tail != NULL && newName != "");
        node* insert_ptr = new node(newName, newPrice, NULL);
    	tail->setLink(insert_ptr);
        tail = tail->getLink();
    }
/* Function: list clear
 * Description: returns all nodes of the list to the heap and sets head to null
 * Runtime: O(1)
*/ 
    void list_clear(node*& head) {
        
        while (head != NULL) {
    	    list_head_remove(head);
        }
    }
/* Function: list copy
 * Description: copies the head and tail pointers to be the head and tail pointers of a new list of the same nodes
 * Runtime: O(n)
*/ 
    void list_copy(const node *old_head, node* &new_head, node* &new_tail) {
        new_head = NULL;
        new_tail = new_head;
        
        const node *cur = old_head;
        while (cur != NULL) {
            if (new_head == NULL) {
                new_head = new node(cur->getName(), cur->getPrice());
                new_tail = new_head;
            }
            else {
                new_tail->setLink(new node(cur->getName(), cur->getPrice()));
                new_tail = new_tail->getLink();
            }
            cur=cur->getLink();
        }
    }
/* Function: list head remove
 * Description: removes the first node of the list
 * Runtime: O(1)
*/ 
    void list_head_remove(node*& head) {
        node *remove_ptr;
    	remove_ptr = head;
    	head = head->getLink();
    	delete remove_ptr;
    }
/* Function: list print
 * Description: prints the list
 * Runtime: O(n)
*/ 
    void list_print(node *head) {
        node *cur = head;
        while (cur != NULL) {
            std::cout << "- " << cur->getName() << ", where the price is $" << cur->getPrice() << std::endl;
            cur = cur->getLink();
        }
    }
/* Function: list contains item
 * Description: returns true if the name is in the list, false if not
 * Runtime: O(n)
*/ 
    bool list_contains_item(node *head_ptr, const std::string& newName) {
        return (list_search(head_ptr, newName) != NULL);
    }
/* Function: list search
 * Description: searches through the list looking for a specific target
 * Runtime: O(n)
*/ 
    node* list_search(node* head_ptr, const std::string& target)
    {
        node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink( ))
            if (target == cursor->getName( ))
                return cursor;
        return NULL;
    }
/* Function: list search (constant)
 * Description: searches through the list looking for a specific target
 * Runtime: O(n)
*/ 
    const node* list_search(const node* head_ptr, const std::string & target)
    {
        const node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink( ))
            if (target == cursor->getName( ))
                return cursor;
        return NULL;
    }
    
}

#endif
