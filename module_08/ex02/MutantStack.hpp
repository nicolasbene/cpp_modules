#ifndef MutantStack_HPP
#define MutantStack_HPP

# include <iostream>
# include <stack>
# include <deque>

//faire des recherche sur la STL, class stack, class deque
//comparer cette class avec celui de 42ccppsey 


template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		MutantStack &operator=(MutantStack const &other) { std::stack<T>::operator=(other); return *this; }
		virtual ~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
};

#endif