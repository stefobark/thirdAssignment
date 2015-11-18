#ifndef LIST_H
#define LIST_H

#include <algorithm>
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
        Node   *prev;
        Node   *next;

        Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr )
          : data{ d }, prev{ p }, next{ n } { }
        
        Node( Object && d, Node * p = nullptr, Node * n = nullptr )
          : data{ std::move( d ) }, prev{ p }, next{ n } { }
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

        const_iterator & operator-- ( )
        {
            current = current->prev;
            return *this;
        }

        const_iterator operator-- ( int )
        {
            const_iterator old = *this;
            --( *this );
            return old;
        }
            
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

        iterator & operator-- ( )
        {
            this->current = this->current->prev;
            return *this;
        }

        iterator operator-- ( int )
        {
            iterator old = *this;
            --( *this );
            return old;
        }

      protected:
        // Protected constructor for iterator.
        // Expects the current position.
        iterator( Node *p ) : const_iterator{ p }
          { }

        friend class List<Object>;
    };

  public:
    List( )
      { init( ); }

    ~List( )
    {
        clear( );
        delete head;
        delete tail;
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

    
    List( List && rhs )
      : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
   
    List & operator= ( List && rhs )
    {    
        std::swap( theSize, rhs.theSize );
        std::swap( head, rhs.head );
        std::swap( tail, rhs.tail );
        
        return *this;
    }
    
    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin( )
      { return iterator( head->next ); }

    const_iterator begin( ) const
      { return const_iterator( head->next ); }

    // Return iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    iterator end( )
      { return iterator( tail ); }

    const_iterator end( ) const
      { return const_iterator( tail ); }

    // Return number of elements currently in the list.
    int size( ) const
      { return theSize; }

    // Return true if the list is empty, false otherwise.
    bool empty( ) const
      { return size( ) == 0; }

    void clear( )
    {
        while( !empty( ) )
            pop_front( );
    }
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                        methods i wrote                                                      //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 	// here's my idea for swap. give it two iterators that point into the list. create a temporary object
 	// assign the value of a to tmp, assign the value b to a, and then assign tmp to the value of b
 	// and it works! yay :)
	void swap(iterator a, iterator b)
	{
		Object tmp = *a;
		*a = *b;
		*b = tmp;
	}
   
   //after much mind boggling, I found a nice solution that makes sense to me
   //at http://stackoverflow.com/questions/3198569/reverse-doubly-link-list-in-c
   //i just adapted it a little to fit in this List class
   void reverse()
   {
   	//start current pointing to head (the beginning of the list)
		Node *current = head;
		//we're using tmp so that we can move through the list 
		//at the beginning of the following while loop we have "tmp=current->next;"
		//and at the end we have "current=tmp;" which allows us to move along on the next iteration
		Node * tmp;
		
		//eventually, "current=tmp;" will set current to NULL, that means we're done with the list
		while(current != NULL){
			tmp = current->next; //every iteration, tmp will point to the next element after current
		  	current->next = current->prev; //we switch the pointers, current->next now points to what current->prev points at
		  	current->prev = tmp; //this is why we created tmp. so we can switch current->prev to current->next
		  	//but, eventually tmp (which is current->next) will be null
		  	//and at that point we know we're at the end of the list
		  	if( tmp == NULL ) {
		  		tail = head; //so, we switch tail to head
		  		head = current; //and because we're at the end, head is current
		  	}
		  	current = tmp; //but, if we haven't reached the end of the list, we keep moving through it by setting current to tmp
		  	//and tmp is holding the current->next before we set it to current->prev
		}
    }
    
    //and, then I took another look at my previous try. i was getting close. but the main difference is 
    //that this person's solution checks to see if next (or "tmp" from the other solution) is null inside the while loop!
    //and if it is, they set tail to head and head to current. I kept trying to do that after the while loop,
    //AHA!! I see.
    //I just need to keep the last "current" before current == NULL! so, now, before "current = next" I have previous = current!
    //and no more segmentation fault!
    //it works!
    void myReverse()
   {
		Node *current = head;
		Node *next;
		Node *previous;
		
		tail = head; //might as well set tail to head here, since we're not really using tail to check anything with it.
		while(current != NULL){
			next = current->next;
         current->next = current->prev;
         current->prev = next;
         previous = current;
         current = next;
		}
      head = previous;
    }
    	
    	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                          end of methods i wrote                                                                           //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    	
    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    
   
    	
    Object & front( )
      { return *begin( ); }

    const Object & front( ) const
      { return *begin( ); }

    Object & back( )
      { return *--end( ); }

    const Object & back( ) const
      { return *--end( ); }

    void push_front( const Object & x )
      { insert( begin( ), x ); }

    void push_back( const Object & x )
      { insert( end( ), x ); }

    void push_front( Object && x )
      { insert( begin( ), std::move( x ) ); }    
      
    void push_back( Object && x )
      { insert( end( ), std::move( x ) ); }

    void pop_front( )
      { erase( begin( ) ); }

    void pop_back( )
      { erase( --end( ) ); }

    // Insert x before itr.
    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ x, p->prev, p } );
    }

    // Insert x before itr.
    iterator insert( iterator itr, Object && x )
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ std::move( x ), p->prev, p } );
    }
    
    // Erase item at itr.
    iterator erase( iterator itr )
    {
        Node *p = itr.current;
        iterator retVal( p->next );
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;

        return retVal;
    }

    iterator erase( iterator from, iterator to )
    {
        for( iterator itr = from; itr != to; )
            itr = erase( itr );

        return to;
    }

  private:
    int   theSize;
    Node *head;
    Node *tail;

    void init( )
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

#endif
