#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "dsexceptions.h"
using namespace std;

template <typename Object>
class Vector
{
  public:
  	 const int SPARE_CAPACITY = 2;
    explicit Vector( int initSize = 0 )
      : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
      { objects = new Object[ theCapacity ]; }
      
    Vector( const Vector & rhs )
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
    { 
        objects = new Object[ theCapacity ];
        for( int k = 0; k < theSize; ++k )
            objects[ k ] = rhs.objects[ k ];
    }
    
    Vector & operator= ( const Vector & rhs )
    {
        Vector copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    
    ~Vector( )
      { delete [ ] objects; }

    Vector( Vector && rhs )
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }
   
    Vector & operator= ( Vector && rhs )
    {    
        std::swap( theSize, rhs.theSize );
        std::swap( theCapacity, rhs.theCapacity );
        std::swap( objects, rhs.objects );
        
        return *this;
    }
    
    bool empty( ) const
      { return size( ) == 0; }
    int size( ) const
      { return theSize; }
    int capacity( ) const
      { return theCapacity; }

    Object & operator[]( int index )
    {
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };
                                                     #endif
        return objects[ index ];
    }

    const Object & operator[]( int index ) const
    {
                                                     #ifndef NO_CHECK
        if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };
                                                     #endif
        return objects[ index ];
    }
	
	Object *begin()
		{return &objects[0];}

    void resize( int newSize )
    {
        if( newSize > theCapacity )
            reserve( newSize * 2 );
        theSize = newSize;
    }

    void reserve( int newCapacity )
    {
        if( newCapacity < theSize )
            return;

        Object *newArray = new Object[ newCapacity ];
        for( int k = 0; k < theSize; ++k )
            newArray[ k ] = std::move( objects[ k ] );

        theCapacity = newCapacity;
        std::swap( objects, newArray );
        delete [ ] newArray;
    }

      // Stacky stuff
    void push_back( const Object & x )
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }
      // Stacky stuff
    void push_back( Object && x )
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = std::move( x );
    }

    void pop_back( )
    {
        if( empty( ) )
            throw UnderflowException{ };
        --theSize;
    }

    const Object & back ( ) const
    {
        if( empty( ) )
            throw UnderflowException{ };
        return objects[ theSize - 1 ];
    }

	 Object * end() {
	 	 	{return &objects[size()];}
    }
/***************************************************************
* 					my attemp at iterator as class type 			   *
*						answering 3.10								*
***************************************************************/    
    
	 class iterator
	 {
	 	 Object * current;
	 	 public:
	 	 //default, no value
	 	 iterator() : current{nullptr}
	 	 	{ }
	 	 // for when we want to initialize the iterator to an element of the vector
	 	 iterator(Object * c ) : current{c}
	 	 { }
	 	 
	 	 //when we want to retrieve that value
	 	 const Object & operator* ( ) const
          { return *current; }
          
       //when we want to move to the next element-- prefix
       //my idea for checking if the iterator is valid is to see if it's value is null
       //if so, i print 'iterated too far'
       iterator operator++ ( )
        {
            ++current;
            if(*current != NULL){
	            return current;
	         } else cout << "iterated tooo far!\n";
           
        }
        
        //postfix
        iterator operator++ ( int )
        {
            iterator old = current;
            ++( current );
            if(*current != NULL){
            	return old;
            } else {
            	cout << "iterated toooo far!\n";
            }
        }
        
        // go back, prefix
        iterator & operator-- ( )
        {
            current--;
            if(*current != NULL){
            	return *current;
            } else {
            	cout << "iterated toooo far!\n";
            }
        }
        
        //go back, postfix
        iterator operator-- ( int )
        {
            iterator old = current;
            --( current );
            if(*current != NULL){
            	return old;
            } else {
            	cout << "iterated toooo far!\n";
            }
        }
        
        bool operator== ( const iterator & rhs ) const
          { return current == rhs.current; }
        bool operator!= ( const iterator & rhs ) const
          { return !( *current == *rhs ); }
	 
	 };
    

  private:
    int theSize;
    int theCapacity;
    Object * objects;
};

#endif
