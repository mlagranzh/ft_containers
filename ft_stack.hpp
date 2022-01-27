
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

        protected:
            C c;
        //     // typedef T& reference;
        //     // typedef T const & const_reference;
        // protected: 
        public:
            stack() : c() {};

            explicit stack(const C& cont)
            {
                c(cont);
            }

            value_type& top()
            {
                return c.back();
            };

            const value_type& top() const 
            { 
                return (c.back()); 
            }

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
            
            bool Eq(const stack<T, C>& X) const
            {
                return (c == X.c);
            }

            bool Lt(const stack<T, C>& X) const
            {
                return (c < X.c);
            }

    };
    
    template <class T, class C>
	    bool operator== (const ft::stack<T, C>& X, const ft::stack<T, C>& Y)
		{ 
            return (X.Eq(Y)); 
        }

	template <class T, class C>
	    bool operator!= (const ft::stack<T, C>& X, const ft::stack<T, C>& Y)
		{ 
            return (!(X == Y)); 
        }

    template <class T, class C>
	    bool operator< (const ft::stack<T, C>& X, const ft::stack<T, C>& Y)
		{ 
            return (X.Lt(Y));
        }

    template <class T, class C>
	    bool operator<= (const ft::stack<T, C>& X, const ft::stack<T, C>& Y)
		{ 
            return (!(Y > X)); 
        }
	
    template <class T, class C>
	    bool operator> (const ft::stack<T, C>& X, const ft::stack<T, C>& Y)
		{ 
            return (Y < X); 
        }

    template <class T, class C>
	    bool operator>= (const ft::stack<T, C>& X, const ft::stack<T, C>& Y)
		{ 
            return (!(X < Y));
        }
}
#endif