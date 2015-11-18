#ifndef SLIST_H
#define SLIST_H

#include <algorithm>
#include <iostream>
using namespace std;

template <typename Object>
class List
{
  private:    
    // The basic doubly linked list node.
    // Nested inside of List, can be public
    // because the Node is itself private
    struct Node
    {
        Object  data;
        Node   *next;
        //got rid of prev to make a singly linked list.

		  // had to remove mention of prev from these to make a singly linked list
        Node( const Object & d = Object{ }, Node * n = nullptr )
          : data{ d }, next{ n } { }
        
        Node( Object && d, Node * n = nullptr )
          : data{ std::move( d ) }, next{ n } { }
    };

  public:
    class const_iterator
    {
      public:
  
        // Public constructor for const_iterator.
        const_iterator( ) : current{ nullptr }
          { }

        // Return the object stored at the current position.
        // For const_iterator, this is an accessor with a
        // const reference return type.
        const Object & operator* ( ) const
          { return retrieve( ); }
        
        const_iterator & operator++ ( )
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++ ( int )
        {
            const_iterator old = *this;
            ++( *this );
            return old;
        }

/*************************************
*         No longer any operator--   *
*************************************/
            
        bool operator== ( const const_iterator & rhs ) const
          { return current == rhs.current; }

        bool operator!= ( const const_iterator & rhs ) const
          { return !( *this == rhs ); }
          
       

      protected:
        Node *current;

        // Protected helper in const_iterator that returns the object
        // stored at the current position. Can be called by all
        // three versions of operator* without any type conversions.
        Object & retrieve( ) const
          { return current->data; }

        // Protected constructor for const_iterator.
        // Expects a pointer that represents the current position.
        const_iterator( Node *p ) :  current{ p }
          { }
        
        friend class List<Object>;
    };

    class iterator : public const_iterator
    {
      public:

        // Public constructor for iterator.
        // Calls the base-class constructor.
        // Must be provided because the private constructor
        // is written; otherwise zero-parameter constructor
        // would be disabled.
        iterator( )
          { }

        Object & operator* ( )
          { return const_iterator::retrieve( ); }

        // Return the object stored at the current position.
        // For iterator, there is an accessor with a
        // const reference return type and a mutator with
        // a reference return type. The accessor is shown first.
        const Object & operator* ( ) const
          { return const_iterator::operator*( ); }
        
        iterator & operator++ ( )
        {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }


      protected:
        // Protected constructor for iterator.
        // Expects the current position.
        iterator( Node *p ) : const_iterator{ p }
          { }
			//.. so trying to use iterator and the compiler is complaining that const_iterator is protected.. 
			// i thought being a friend to the list class would stop this from happening.
        friend class List<Object>;
    };

  public:
    List( )
      { init( ); }

    ~List( )
    {
        delete head;
    }

    List( const List & rhs )
    {
        init( );
        for( auto & x : rhs )
            push_back( x );
    }

    List & operator= ( const List & rhs )
    {
        List copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    

/**********************************************
* 3.11 a: get the size of the list		 	    *
**********************************************/
    int size( ) const
      { return theSize; }

/*********************************************
* 3.11 b: my version of 'print a list' 		*
**********************************************/
    
    void printList(){
    	Node *printThis = head->next;
    	cout<<"our list: ";
    	while(printThis != NULL){
    		cout << printThis->data << " ";
    		printThis = printThis->next;
    	}
    	cout << endl;
    }

/**********************************************
* 3.11 c: my version of 'test if value' 		 *
**********************************************/
   
    bool checkVal(Object x){
		 iterator start = begin();
		 int yesNo = 0;
		 for(start; start != NULL; start++){
		 	if(*start == x) yesNo = 1;
		 }
		 if(yesNo == 1) return 1;
		 else return 0;
	 }

/**********************************************************************
*3.11 d: my version of 'test if value is there and add if it is not'	 *
**********************************************************************/

	 void addValueIfNotPresent(Object x){
	 	if(checkVal(x) == 0){
	 		push_front(x);
	 	}
	 }
	 
/*********************************************************************
*		3.11 e: find and remove.if present										*
**********************************************************************/

	 void removeValueIfPresent(Object x){
	 	Node *start = head->next;
	 	Node * prev = head;
		while(start != NULL){
			if(start->data == x){
				prev->next = start->next;
				erase(start);
				break;
			} else {
				prev = prev->next;
				start = start->next;
			}
		 }
	 }

    
     Object & front( )
      { return *begin( ); }
    
    const Object & front( ) const
      { return *begin( ); }
      
	
	//arrrrgghhh. took me a while to get this working. but, i broke it down into manageable steps (that make sense to me)
	//p is the first node.
	//q is the new node we're putting at the front
	//then, we get x that we're passing in to the function and assign it to q's data
	//then we make q point to whatever the old beginning was
	//and change head->next to the new node, q
	//and increment the size.
	void push_front( const Object & x )
      { 
      	Node *p = head->next;
        	Node *q = new Node;
        	q->data = x;
        	q->next = p;
        	head->next = q;
        	++theSize;
      }
    
    		
    // Return true if the list is empty, false otherwise.
    bool empty( ) const
      { return size( ) == 0; }
      		
    List( List && rhs )
      : theSize{ rhs.theSize }, head{ rhs.head }
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
    }
   
    List & operator= ( List && rhs )
    {    
        std::swap( theSize, rhs.theSize );
        std::swap( head, rhs.head );
        
        return *this;
    }
    
    void erase( iterator itr )
    {
    	  //here's an iterator to the current node
        Node *p = itr.current;
        //the next node
        Node *q( p->next );
        if(q != NULL) {
		     delete p;
		     //reduce the size
		     --theSize;
		    } else {
		    delete p;
		    --theSize;
		    }
			
    }
    
    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin( )
      { return iterator( head->next ); }

    const_iterator begin( ) const
      { return const_iterator( head->next ); }

    

  private:
  	 // we keep track of the size of the list with this private data member. incrementing when inserting and decrementing when erasing
  	 // there is no longer a tail.
    int   theSize;
    Node *head;

    void init( )
    {
        theSize = 0;
        head = new Node;
        head->next = NULL;
    }
};

#endif
