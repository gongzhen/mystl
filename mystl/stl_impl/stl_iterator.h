//============================================================================// Name        : iterator.h// Author      : // Version     : // Copyright   : Your copyright notice// Description : standard interface to  STL Standards//============================================================================/* *  This is an internal header file. *  This file implements some iterator adapters, *  such as _normal_iterator,reverse_iterator, back_insert_iterator, *  front_insert_iterator, insert_iterator, , and their *  supporting functions and overloaded operators. */ #ifndef _mstl_iterator_h #define _mstl_iterator_h namespace numb {	//This iterator adapter is a normal iterator	using numb::iterator;	using numb::iterator_traits;	template<typename Iterator, typename Container>	class _normal_iterator	{		protected:			Iterator M_current;			typedef iterator_traits<Iterator>  traits_type;		public:			typedef Iterator								iterator_type;			typedef typename traits_type::iterator_category	iterator_category;			typedef typename traits_type::value_type  	 	value_type;			typedef typename traits_type::difference_type 	difference_type;			typedef typename traits_type::reference 		reference;			typedef typename traits_type::pointer   		pointer;			//default ctor			_normal_iterator():M_current(Iterator()){}			//copy ctor			explicit _normal_iterator(const Iterator& i):M_current(i){}						//To-do: Allow iterator to const_iterator conversion						//for forward iterator 			reference operator*()const			{	return *M_current;}			pointer operator->()const			{	return M_current;}			//++i			_normal_iterator& 			operator ++()			{				++M_current;				return *this;			}			//i++			_normal_iterator 			operator ++(int)			{				return _normal_iterator(M_current++);			}			//for bidirectional iterator			//--i			_normal_iterator& 			operator --()			{				--M_current;				return *this;			}			//i--			_normal_iterator 			operator --(int)			{return _normal_iterator(M_current--);}						//for random access iterator,[],+=,-=,+,-			reference 			operator[](const difference_type& n)const			{	return M_current[n];}						_normal_iterator& 			operator +=(const difference_type& n)			{				M_current+=n;				return *this;			}			_normal_iterator&			operator -=(const difference_type& n)			{				M_current-=n;				return *this;			}			_normal_iterator			operator +(const difference_type& n)const			{				return _normal_iterator(M_current+n);			}			_normal_iterator			operator -(const difference_type& n)const			{				return _normal_iterator(M_current-n);			}			const Iterator&			base() const			{ return M_current; }				};	// Forward iterator requirements  template<typename _IteratorL, typename _IteratorR, typename _Container>    inline bool    operator==(const _normal_iterator<_IteratorL, _Container>& __lhs,	       const _normal_iterator<_IteratorR, _Container>& __rhs)    { return __lhs.base() == __rhs.base(); }  template<typename _Iterator, typename _Container>    inline bool    operator==(const _normal_iterator<_Iterator, _Container>& __lhs,	       const _normal_iterator<_Iterator, _Container>& __rhs)    { return __lhs.base() == __rhs.base(); }  template<typename _IteratorL, typename _IteratorR, typename _Container>    inline bool    operator!=(const _normal_iterator<_IteratorL, _Container>& __lhs,	       const _normal_iterator<_IteratorR, _Container>& __rhs)    { return __lhs.base() != __rhs.base(); }  template<typename _Iterator, typename _Container>    inline bool    operator!=(const _normal_iterator<_Iterator, _Container>& __lhs,	       const _normal_iterator<_Iterator, _Container>& __rhs)    { return __lhs.base() != __rhs.base(); }  // Random access iterator requirements  template<typename _IteratorL, typename _IteratorR, typename _Container>    inline bool    operator<(const _normal_iterator<_IteratorL, _Container>& __lhs,	      const _normal_iterator<_IteratorR, _Container>& __rhs)    { return __lhs.base() < __rhs.base(); }  template<typename _Iterator, typename _Container>    inline bool    operator<(const _normal_iterator<_Iterator, _Container>& __lhs,	      const _normal_iterator<_Iterator, _Container>& __rhs)    { return __lhs.base() < __rhs.base(); }  template<typename _IteratorL, typename _IteratorR, typename _Container>    inline bool    operator>(const _normal_iterator<_IteratorL, _Container>& __lhs,	      const _normal_iterator<_IteratorR, _Container>& __rhs)    { return __lhs.base() > __rhs.base(); }  template<typename _Iterator, typename _Container>    inline bool    operator>(const _normal_iterator<_Iterator, _Container>& __lhs,	      const _normal_iterator<_Iterator, _Container>& __rhs)    { return __lhs.base() > __rhs.base(); }  template<typename _IteratorL, typename _IteratorR, typename _Container>    inline bool    operator<=(const _normal_iterator<_IteratorL, _Container>& __lhs,	       const _normal_iterator<_IteratorR, _Container>& __rhs)    { return __lhs.base() <= __rhs.base(); }  template<typename _Iterator, typename _Container>    inline bool    operator<=(const _normal_iterator<_Iterator, _Container>& __lhs,	       const _normal_iterator<_Iterator, _Container>& __rhs)    { return __lhs.base() <= __rhs.base(); }  template<typename _IteratorL, typename _IteratorR, typename _Container>    inline bool    operator>=(const _normal_iterator<_IteratorL, _Container>& __lhs,	       const _normal_iterator<_IteratorR, _Container>& __rhs)    { return __lhs.base() >= __rhs.base(); }  template<typename _Iterator, typename _Container>    inline bool    operator>=(const _normal_iterator<_Iterator, _Container>& __lhs,	       const _normal_iterator<_Iterator, _Container>& __rhs)    { return __lhs.base() >= __rhs.base(); }  // According to the resolution of DR179 not only the various comparison  // operators but also operator- must accept mixed iterator/const_iterator  // parameters.  template<typename _IteratorL, typename _IteratorR, typename _Container>    inline typename _normal_iterator<_IteratorL, _Container>::difference_type    operator-(const _normal_iterator<_IteratorL, _Container>& __lhs,	      const _normal_iterator<_IteratorR, _Container>& __rhs)    { return __lhs.base() - __rhs.base(); }  template<typename _Iterator, typename _Container>    inline typename _normal_iterator<_Iterator, _Container>::difference_type    operator-(const _normal_iterator<_Iterator, _Container>& __lhs,	      const _normal_iterator<_Iterator, _Container>& __rhs)    { return __lhs.base() - __rhs.base(); }  template<typename _Iterator, typename _Container>    inline _normal_iterator<_Iterator, _Container>    operator+(typename _normal_iterator<_Iterator, _Container>::difference_type	      __n, const _normal_iterator<_Iterator, _Container>& __i)    { return _normal_iterator<_Iterator, _Container>(__i.base() + __n); } }//end of namespace numb #endif