//============================================================================
// Name        : allocator.h
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : a simple implement of STL::allocator
//============================================================================

#ifndef _MALLOCATOR_H
#define _MALLOCATOR_H
#include <new>		//for placement new

//add new line
#include <iostream>


namespace numb
{
	// allocate memory
	template <class T>
	inline T* _allocate(ptrdiff_t size,T*)
	{	std::cout<<"size " << size<< std::endl;
		std::set_new_handler (0);//set handler as 0
		T* temp=static_cast<T*>(::operator new((size_t)(size*sizeof(T))));// allocate size of 
		if(temp==0)
		{
			throw std::bad_alloc();
		}
		return temp;
	}
	// deallocate memory
	template <class T>
	inline void _deallocate(T* buffer)
	{
		::operator delete(buffer);
	}
	// call constructor
	template <class T1,class T2>
	inline void _construct(T1* p,const T2& value)
	{
		::new(p) T1(value);	// only call constructor, no allocate memory. The size of P memory has allocated already.
	}	
	// destructor
	template <class T>
	inline void _destroy(T* p)
	{
		p->~T(); 
	}
	
	//allocator 
	template<class T>
	class allocator
	{
		public:
			//7 type of variables
			typedef T 			value_type;
			typedef	 T* 			pointer;
			typedef const T* 	const_pointer;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef size_t		size_type;
			typedef ptrdiff_t	difference_type;
			
			// default constructor
			allocator()throw(){std::cout<<"allocator constructor. " << std::endl; }
			//copy constructor
			allocator(const allocator &)throw() {std::cout<<"allocator& constructor. " << std::endl;} 
			// ohter type of objects
			template<class Other>  
			allocator(const allocator<Other> &)throw() {} 
			
			//destructor
			~allocator()throw(){}
			//bind allocator for type U
			template<class U>
			struct rebind
			{
				typedef allocator<U> other;
			};
			//allocate memory
			pointer	allocate(size_type s,void* hint=0)
			{
				return _allocate((difference_type)s,(pointer)0);
			}
			//deallocate memory
			void deallocate(pointer p,size_type n)
			{
				_deallocate(p);
			}
			//constructor
			void construct(pointer p,const T& value)
			{
				_construct(p,value);
			}
			//desctructor
			void destroy(pointer p)
			{
				_destroy(p);
			}
			//return address
			pointer address(reference x)
			{
				return (pointer)&x;
			}
			const_pointer address(const_reference x)
			{
				return (const_pointer)&x;
			}
			//return the max size of memory
			size_type max_size()const
			{
				return static_cast<size_type>(-1) / sizeof(T);
			}
	};	//end of class allocator
	
	template<typename Tp>
	inline bool
    operator==(const allocator<Tp>&, const allocator<Tp>&)
    { return true; }
  
    template<typename Tp>
    inline bool
    operator!=(const allocator<Tp>&, const allocator<Tp>&)
    { return false; }
	
  /// allocator<void> specialization. partial specialization
    template<>
    class allocator<void>
    {
    public:
      typedef size_t      size_type;
      typedef ptrdiff_t   difference_type;
      typedef void*       pointer;
      typedef const void* const_pointer;
      typedef void        value_type;

      template<typename T>
        struct rebind
        { typedef allocator<T> other; };
    };
}//end of namespcae numb
#endif