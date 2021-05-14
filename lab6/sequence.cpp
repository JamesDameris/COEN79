//FILE: sequence.cpp
//CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
//
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//
//INVARIANT for the sequence class
//  1. The number of items in the sequence is stored in the member variable "many_nodes"
//
//  2. For an empty sequence, we do not care what is stored in any of data and head_ptr
//      and tail_ptr point to NULL; for a non-empty sequence, the items stored in the
//      sequence can be accessed using head_ptr and tail_ptr and we don't care what is
//      stored in the rest of the data.
//
//  3. If there is a current item, then it lies in *cursor; if there is no
//     current item, then cursor* equals NULL.
//
//  4. If there is a previous item, then it lies in precursor*.  If there is no previous
//       item, then precursor equals NULL.


#include <iostream>
#include <algorithm> //provides copy function
#include <cassert> //for assert function
#include "sequence.h" //header file for class
#include "node.h" // provides node class

using namespace std; //For copy function

namespace coen79_lab6
{
    // Default private member variable initialization function.
    void sequence::init()
    {
        //Initializing pointers to NULL
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        //Initializiing many_nodes (or our counter) to 0
        many_nodes = 0;
    }

    //CONSTRUCTOR IMPLEMENTATION for default constructor
    sequence::sequence ()
    {
        init();
    }

    //Copy Constructor
    sequence::sequence(const sequence& source)
    {
        init();
        *this = source;
    }
    void sequence::start(){
        cursor = head_ptr;
        precursor = NULL;
    }
    void sequence::end(){
        cursor = tail_ptr;
        node* temp;
        for (temp = head_ptr; temp != NULL; temp = temp->link()) {
            if(temp->link() == tail_ptr){
                precursor = temp;
            }
        }
    }
    void sequence::advance(){
        assert(is_item() == true);
        if (cursor == tail_ptr) {
            precursor = cursor;
            cursor = NULL;

        }
        else {
            precursor = cursor;
            cursor = cursor->link();
        }
    }
    void sequence::insert(const value_type& entry) {
        if (head_ptr == NULL) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            tail_ptr = head_ptr;
        }
        else if (cursor == NULL) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = NULL;
        }
        else if (cursor == head_ptr) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
        }
        else{
            list_insert(precursor, entry);
            cursor = precursor->link();
        }
        many_nodes++;
    }
    void sequence::attach(const value_type& entry) {
        if (head_ptr == NULL) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            tail_ptr = cursor;
        }
        else if (cursor == NULL) {
            list_insert(tail_ptr, entry);
            cursor = tail_ptr->link();
            tail_ptr = cursor;
        }
        else if (cursor == tail_ptr) {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
            tail_ptr = cursor;
        }
        else {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
        }
        many_nodes++;

    }
    void sequence::operator=(const sequence& source) {
        if (this == &source) {
            return;
        }
        list_clear(head_ptr);
        many_nodes = 0;
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        if (source.precursor != NULL) {
            precursor = list_search(head_ptr, source.precursor->data());
        }
        else {
            precursor = NULL;
        }
        if (source.cursor != NULL) {
            cursor = list_search(head_ptr, source.cursor->data());
        }
        else {
            cursor = NULL;
        }
        
        
    }
    void sequence::remove_current(){
        assert(is_item() == true);
        if (precursor == NULL) {
            cursor = cursor->link();
            list_head_remove(head_ptr);
        }
        else if (cursor == tail_ptr) {
            tail_ptr = precursor;
            list_remove(precursor);
            cursor = NULL;
        }
        else {
            cursor = cursor->link();
            list_remove(precursor);
        }
        many_nodes--;

    }
    sequence::size_type sequence::size() const{
        return many_nodes;
    }
    bool sequence::is_item() const{
        if (cursor == NULL) {
            return false;
        }
        return true;
    }
    sequence::value_type sequence::current( ) const{
        assert(is_item() == true);
        return cursor->data();
    }

    sequence::~sequence() {
        list_clear(head_ptr);
    }
    
}
