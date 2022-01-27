
#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include <iostream>
#include <deque>

namespace ft
{
    template <class T, class C = std::deque<T> >
    class stack
    {
        private:
            typedef C container_type;
            typedef typename C::value_type value_type;
            typedef typename C::size_type size_type;
            C c;
        //     // typedef T& reference;
        //     // typedef T const & const_reference;
        // protected: 
        //     C c;
        public:
        //     stack() : c() {};
        //     // explicit stack(const container_type& cont);
            value_type& top()
            {
                return c.back();
            };
            
            void push(const value_type& value)
            {
                c.push_back(value);
            };
            
            bool empty() const
            {
                return (c.empty());
            }

            void pop()
            {
                c.pop_back();
            };

            size_type size() const
            {
                return (c.size());
            }
    };
}
#endif