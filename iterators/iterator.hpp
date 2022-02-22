# ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
namespace ft
{
    // iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical com-
    // pare, std::pair, std::make_pair

        /*
        ** @brief The basic struct of is_integral has
        ** has a boolean ("value") that contain true if the type is from.
        ** the list, otherwise false.
        */
        template <bool is_integral, typename T>
        struct is_integral_res 
        {
            typedef T type;
            static const bool value = is_integral;
        };

        /*
        ** @brief default template of the structure is_integral_type.
        ** If the type given in argument is from the list, the structure
        ** will be overide by nexts, in according to it type.
        ** If the type given is argument isn't in the list, 
        ** stocked value will be false. So it's not a integral type.
        */


        /*
            is_integral_type
        */
        template <typename>
            struct is_integral_type : public is_integral_res<false, bool> {};
        template <>
            struct is_integral_type<bool> : public is_integral_res<true, bool> {};
        template <>
            struct is_integral_type<char> : public is_integral_res<true, char> {};
        template <>
            struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};
        template <>
            struct is_integral_type<short int> : public is_integral_res<true, short int> {};
                template <>
            struct is_integral_type<int> : public is_integral_res<true, int> {};
        template <>
            struct is_integral_type<long int> : public is_integral_res<true, long int> {};
        template <>
            struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};
        template <>
            struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
        template <>
            struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
        template <>
            struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
        template <>
            struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
                template <>
            struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

        /*
            ТЭГИ
        */
        class random_access_iterator_tag { };
        class bidirectional_iterator_tag { };
        class forward_iterator_tag { };
        class input_iterator_tag { };
        class output_iterator_tag { };


    /*
        valid_iterator_tag_res
    */

    /*
    ** @brief Validity of an iterator from is tag.
    ** This is the base struct for all is_..._iterator_tag.
    ** A boolean is defined by the template and saved in
    ** structure. Type too.
    */
    template <bool is_valid, typename T>
        struct valid_iterator_tag_res { typedef T type; const static bool value = is_valid; };
    
    /*
    ** @brief Basic to check if the typename given
    ** is an input_iterator. Based on valid_iterator_tag_res.
    ** In this if the typename is not from the possible
    ** input iterator form, validity is set to false.
    */
    template <typename T>
        struct is_input_iterator_tagged : public valid_iterator_tag_res<false, T> { };
    template <>
        struct is_input_iterator_tagged<ft::random_access_iterator_tag>
            : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };
    template <>
        struct is_input_iterator_tagged<ft::bidirectional_iterator_tag>
            : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };
    template <>
        struct is_input_iterator_tagged<ft::forward_iterator_tag>
            : public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };
    template <>
        struct is_input_iterator_tagged<ft::input_iterator_tag>
            : public valid_iterator_tag_res<true, ft::input_iterator_tag> { };


    /*
        is_ft_iterator_tagged
    */

    /*
    ** @brief This will return a structure
    ** that contain a boolean "value" true if the
    ** iterator given is tagged with a ft iterator
    ** tag, otherwise "value" is false.
    */
    template <typename T>
        struct is_ft_iterator_tagged : public valid_iterator_tag_res<false, T> { };
        template <>
        struct is_ft_iterator_tagged<ft::random_access_iterator_tag>
            : public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };
    template <>
        struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag>
            : public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };
    template <>
        struct is_ft_iterator_tagged<ft::forward_iterator_tag>
            : public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };
    template <>
        struct is_ft_iterator_tagged<ft::input_iterator_tag>
            : public valid_iterator_tag_res<true, ft::input_iterator_tag> { };
    template <>
        struct is_ft_iterator_tagged<ft::output_iterator_tag>
            : public valid_iterator_tag_res<true, ft::output_iterator_tag> { };

    // /*
    // ** @Brief Invalid iterator Exception.
    // ** Based on std::exception. Called when
    // ** the iterator tested does not meet demand.
    // */
    // template <typename T>
    // class InvalidIteratorException : public std::exception
    // {
    //     private:
    //         std::string _msg;
        
    //     public :
    //         InvalidIteratorException () throw() { _msg = "Is invalid iterator tag : " + std::string(typeid(T).name()); }
    //         InvalidIteratorException (const InvalidIteratorException&) throw() {}
    //         InvalidIteratorException& operator= (const InvalidIteratorException&) throw() {}
    //         virtual ~InvalidIteratorException() throw() {}
    //         virtual const char* what() const throw() { return (_msg.c_str()); }
    // };


        template <class Iterator>
        struct iterator_traits 
        {
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;
            typedef typename Iterator::iterator_category iterator_category;
        };

        /*
        ** @brief Iterator traits class defining properties of
        ** iterators. This create a default operation with an
        ** object (first argument in tempate argument).
        */
        template <class T> struct iterator_traits<T*>
        {
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef ft::random_access_iterator_tag  iterator_category;
        };

        /*
        ** @brief Iterator traits class defining properties of
        ** iterators. This create a default operation with a
        ** const object (first argument in tempate argument).
        */
        template <class T> class iterator_traits<const T*>
        {
            /* Result of subtracting one iterator from another. */
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef const T*                        pointer;
            typedef const T&                        reference;
            typedef ft::random_access_iterator_tag  iterator_category;
        };


    /*
    ** @brief Give a difference_type defined in ft::iterator_traits
    ** that's the difference of address in memory
    ** between last and first iterator.
    **
    ** @param first The first iterator.
    ** @param last The last iterator.
    ** @return The difference.
    */
    template<class InputIterator>
        typename ft::iterator_traits<InputIterator>::difference_type
            distance (InputIterator first, InputIterator last)
        {
            typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
            while (first != last)
            {
                first++;
                rtn++;
            }
            return (rtn);
        }

    /*
    ** @brief Base class for iterator, not really usefull, but type
    ** defined can be use for iterator_traits. An iterator permeted to
    ** take any element range in an object and using a set of operators.
    */
    template <class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&>
        class iterator
        {
            public:
                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;
                typedef Category    iterator_category;
        };

    template <class T>
        class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
        {  
            /* Category of the iterator. */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
            
            /* Type of elements pointed. */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
            
            /* Type to represent the difference between two iterators. */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
            
            /* Type to represent a pointer to an element pointed */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
            
            /* Type to represent a reference to an element pointed */
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;
            
            private:
                /* Element pointed by the iterator. */
                pointer _elem;
        };

    template <class Iterator>
    class reverse_iterator
    {
        public:

            /* Iterator's type. */
            typedef Iterator    iterator_type;

            /* Preserves Iterator's category. */
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            
            /* Preserves Iterator's value type. */
            typedef typename ft::iterator_traits<Iterator>::value_type      value_type;
            
            /* Preserves Iterator's difference type. */
            typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
            
            /* Preserves Iterator's pointer. */
            typedef typename ft::iterator_traits<Iterator>::pointer     pointer;
            
            /* Preserves Iterator's reference. */
            typedef typename ft::iterator_traits<Iterator>::reference   reference;
            
            /*
            ** @brief Default.
            ** Construct a reverse iterator object.
            ** This will points to no object.
            */
            reverse_iterator()
            :
                _elem()
            {}

            /*
            ** @brief Initialization.
            ** Construct a reverse iterator object from
            ** an original iteretor "it".
            ** The behavior of the constructed object
            ** replicate the orignal, but he iterates
            ** in the reverse order.
            **
            ** @param it The iterator to replicate.
            */
            explicit reverse_iterator (iterator_type it)
            :
                _elem(it)
            {}

            /*
            ** @brief Copy.
            ** Contruct a reverse iterator from other reverse iterator.
            ** Save the sense of iterateration as "rev_it".
            **
            ** @param rev_it original reverse iterator.
            */
            template <class Iter>
                reverse_iterator (const reverse_iterator<Iter>& rev_it)
                :
                    _elem(rev_it.base())
                {}

            /* Added to follow subject obligation */
            virtual ~reverse_iterator() {}

            /*
            ** @brief Return a copy of the base iterator.
            ** Same type as the usert to construct the reverse_iterator.
            ** But pointing to the element next of this.
            ** (A reverse iterator always pointing to an element at
            ** an offset of -1).
            **
            ** @return A copy of the base iterator.
            */
            iterator_type base() const
            { return (_elem); }

            /*
            ** @brief Return a reference to the element pointed
            ** by the iterator.
            **
            ** @return The reference.
            */
            reference operator*() const
            {
                iterator_type tmp = _elem;
                return (*(--tmp));
            }

            /*
            ** @brief Return a reverse iterator pointing to
            ** the element at n position away from the pointed
            ** element of the iterator.
            ** This function need the base iterator to be a
            ** "random-access iterator".
            **
            ** @param "n" Number of elements to offset.
            ** @return An iterator pointing to the element at "n"
            ** position away.
            */
            reverse_iterator operator+ (difference_type n) const { return (reverse_iterator(_elem - n)); }

            /*
            ** @brief Advances the reverse_iterator by one position.
            ** Pre-increment.
            **
            ** @return return "(*this)" incremented.
            */
            reverse_iterator& operator++()
            {
                --_elem;
                return (*this);
            }

            /*
            ** @brief Advances the reverse_iterator by one position.
            ** Post-increment.
            **
            ** @return the value "(*this)" value had before the
            ** call.
            */
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }

            /*
            ** @brief Advances the "reverse_iterator" by n element positions.
            ** This function need the base iterator to be a
            ** "random-access iterator".
            **
            ** @param n the number of element.
            ** @return the reverse iterator itself (*this).
            */
            reverse_iterator& operator+= (difference_type n)
            {
                _elem -= n;
                return (*this);
            }

            /*
            ** @brief Return a reverse iterator pointing to the element
            ** located n positions before the element the iterator
            ** currently points to.
            ** This function need the base iterator to be a
            ** "random-access iterator".
            **
            ** @param n the number of element.
            ** @return An iterator pointing to the element
            ** n position before the currently pointed one.
            */
            reverse_iterator operator- (difference_type n) const { return (reverse_iterator(_elem + n)); }

            /*
            ** @brief Decreases the reverse iterator by one position.
            **
            ** @return "(*this)".
            */
            reverse_iterator& operator--()
            {
                ++_elem;
                return (*this);
            }

            /*
            ** @brief Decreases the reverse iterator by one position.
            **
            ** @retun "(*this)" value before the call.
            */
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }

            /*
            ** @brief Decreases the reverse iterator by "n" element
            ** postion.
            ** This function need the base iterator to be a
            ** "random-access iterator".
            **
            ** @param n Number of elements to offset.
            ** @return "(*this)".
            */
            reverse_iterator& operator-= (difference_type n)
            {
                _elem += n;
                return (*this);
            }

            /*
            ** @brief Give a pointer to the element
            ** pointed.
            **
            ** @return A pointer to the element pointed.
            */
            pointer operator->() const { return &(operator*()); }

            /*
            ** @brief Accesse the element at "n" positions
            ** away from the element currently pointed.
            ** Cause undefined behavior if the element
            ** does not exist.
            **
            ** @param n The number of positions.
            ** @return A reference at "n".
            */
            reference operator[] (difference_type n) const { return (this->base()[-n - 1]); }

        private:
            iterator_type     _elem;
    };

    /*
    ** @brief Equal comparison between two reverse iterator.
    **
    ** @param lhs Base of comparison.
    ** @param rhs To compare with "lsh".
    ** @return True if the condition is hold, otherwise false.
    */
    template <class Iterator>
        bool operator== (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() == rhs.base()); }

    /* For reverser_iterator == const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator== (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() == rhs.base()); }

    /*
    ** @brief Different comparison between two reverse iterator.
    **
    ** @param lhs Base of comparison.
    ** @param rhs To compare with "lsh".
    ** @return True if the condition is hold, otherwise false.
    */
    template <class Iterator>
        bool operator!= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() != rhs.base()); }

    /* For reverser_iterator != const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator!= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() != rhs.base()); }

    /*
    ** @brief Inferior comparison between two reverse iterator.
    **
    ** @param lhs Base of comparison.
    ** @param rhs To compare with "lsh".
    ** @return True if the condition is hold, otherwise false.
    */
    template <class Iterator>
        bool operator<  (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() > rhs.base()); }

    /* For reverser_iterator < const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator< (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() > rhs.base()); }

    /*
    ** @brief Inferior or equal comparison between two reverse iterator.
    **
    ** @param lhs Base of comparison.
    ** @param rhs To compare with "lsh".
    ** @return True if the condition is hold, otherwise false.
    */
    template <class Iterator>
        bool operator<= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() >= rhs.base()); }

    /* For reverser_iterator <= const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator<= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() >= rhs.base()); }

    /*
    ** @brief Superior comparison between two reverse iterator.
    **
    ** @param lhs Base of comparison.
    ** @param rhs To compare with "lsh".
    ** @return True if the condition is hold, otherwise false.
    */
    template <class Iterator>
        bool operator> (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() < rhs.bash()); }

    /* For reverser_iterator > const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator> (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() < rhs.base()); }
    /*
    ** @brief Superior or equal comparison between two reverse iterator.
    **
    ** @param lhs Base of comparison.
    ** @param rhs To compare with "lsh".
    ** @return True if the condition is hold, otherwise false.
    */
    template <class Iterator>
        bool operator>= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs) { return (lhs.base() <= rhs.base()); }

    /* For reverser_iterator >= const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator>= (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() <= rhs.base()); }

    /*
    ** @brief Give a reverse iterator pointing to
    ** "rev_it" plus "n".
    **
    ** @param n The number of location away the element pointed 
    ** by rev_it.
    ** @param rev_it The reverse iterator.
    ** @return A reverse iterator pointing to n element
    ** after rev_it pointed element.
    */
    template <class Iterator>
        reverse_iterator<Iterator> operator+ (
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }

    /*
    ** @brief The distance between lhs and rhs.
    **
    ** @param lhs Base of comparison.
    ** @param rhs To compare with "lsh".
    ** @return The number of elements between lsh and rhs.
    */
    template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator- (
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs) { return (lhs.base() - rhs.base()); }

    /* For reverser_iterator - const_reverse_iterator */
    template <class Iterator_L, class Iterator_R>
        bool operator- (const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs) { return (lhs.base() - rhs.base()); }

    /* Lexicographical comparison */

    /*
    ** @brief Return true if the range [first1, last2) compare
    ** lexicographically lest than the range [first2, last2).
    **
    ** @param first1, last1 the start and the end of the first range.
    ** @param first2, last2 the start and the end of the second range.
    ** @return true if the first range compares lexicographically less
    ** than the second, false otherwise.
    */
    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1) return false;
                else if (*first1 < *first2) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }

    /*
    ** @brief Return true if the range [first1, last2) compare
    ** lexicographically lest than the range [first2, last2).
    ** The comparision is effectued by "comp".
    **
    ** @param first1, last1 the start and the end of the first range.
    ** @param first2, last2 the start and the end of the second range.
    ** @param comp the function that will compare.
    ** @return true if the first range compares lexicographically less
    ** than the second, false otherwise.
    */
    template <class InputIterator1, class InputIterator2, class Compare>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2,
                                        Compare comp)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || comp(*first2, *first1)) return false;
                else if (comp(*first1, *first2)) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }
}

# endif