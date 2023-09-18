#ifndef MutantStack_HPP
#define MutantStack_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const &instance) : std::stack<T>(instance) {}
		MutantStack &operator=(MutantStack const &rhs) { std::stack<T>::operator=(rhs); return *this; }
		virtual ~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
};

#endif