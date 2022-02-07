
#include <iostream>

using namespace ft
{
    template <class T, class Container = std::stack<T> >
    class stack
    {
        private:
            Container container;
            Container container_type
            T value_type
            size_t size_type
            typedef T& reference;
            typedef T const & const_reference;
        public:
            stack();
            ~stack();
            operator=();
            T& top()
            {
                return container.back();
            }
            size();
            
            void push(const T& value)
            {
                container.push_back();
            }
            
            void pop()
            {
                container.pop_back();
            }
            empty();
        }
}
