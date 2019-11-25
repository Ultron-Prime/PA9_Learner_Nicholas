/* -------------------------------------------------
FILE:		ArrayQueue.h
DESCRIPTION:	ArrayQueue header file for Project 9 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:		Doesn't implement a copy constructor, destructor, or assignment operator

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-11-20	1.0 Created this file, added class ArrayQueue declar/implement-ation
*/

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "DataType.h"

const size_t ARRAY_MAX = 1000;
class ArrayQueue
{
	friend std::ostream & operator<<(std::ostream & os, const ArrayQueue & arrayQueue);//(i)
	
	public:
		ArrayQueue();						//(1)
		ArrayQueue(size_t count, const DataType & value);	//(2)
		//ArrayQueue(const ArrayQueue & other);			//(3) (Unnecessary)
		//~ArrayQueue();					//(4) (Unnecessary)
		
		//ArrayQueue & operator=(const ArrayQueue & rhs);	//(5) (Unnecessary)
		DataType & front();					//(6a)
		const DataType & front() const;				//(6b)
		DataType & back();					//(7a)
		const DataType & back() const;				//(7b)
		void push(const DataType & value);			//(8)
		void pop();						//(9)
		size_t size() const;					//(10)
		bool empty() const;					//(11)
		bool full() const;					//(12)
		void clear();						//(13)
		void serialize(std::ostream & os) const;		//(14)
	
	private:
	DataType m_array[ARRAY_MAX];
	size_t m_front;
	size_t m_back;
	size_t m_size;
};


//(1)
ArrayQueue::ArrayQueue(): m_front(0), m_back(0), m_size(0) { }

//(2)
ArrayQueue::ArrayQueue(size_t count, const DataType & value): m_front(0), m_back(0), m_size(0)
{
	for (size_t i = 0; i < count; ++i)
		push(value);
}

//(3)
/*ArrayQueue::ArrayQueue(const ArrayQueue & other)		Unnecessary
{
	
}*/

//(4)
/*ArrayQueue::~ArrayQueue()					Unnecessary
{
	
}*/

//(5)
/*ArrayQueue & ArrayQueue::operator=(const ArrayQueue & rhs)	Unnecessary
{
	
}*/

//(6a)
DataType & ArrayQueue::front()
{
	return m_array[0];
}

//(6b)
const DataType & ArrayQueue::front() const
{
	return m_array[0];
}

//(7a)
DataType & ArrayQueue::back()
{
	return m_array[m_size-1];
}

//(7b)
const DataType & ArrayQueue::back() const
{
	return m_array[m_size-1];
}

//(8)
void ArrayQueue::push(const DataType & value)
{
	if (m_size != ARRAY_MAX)
	{
		m_array[m_back] = value;
		m_back = (m_back + 1) % ARRAY_MAX;
		++m_size;
	}else;
}

//(9)
void ArrayQueue::pop()
{
	if (m_size != 0)
	{
		--m_size;
		if (m_size != 0)
		{
			m_front = (m_front + 1) % ARRAY_MAX;
		}else
		{
			clear();
		}
	}else
	{
		clear();
	}
}

//(10)
size_t ArrayQueue::size() const
{
	return m_size;
}

//(11)
bool ArrayQueue::empty() const
{
	return (m_size == 0);
}

//(12)
bool ArrayQueue::full() const
{
	return (m_size == ARRAY_MAX);
}

//(13)
void ArrayQueue::clear()
{
	m_size = 0;
	m_front = 0;
	m_front = 0;
}

//(14)
void ArrayQueue::serialize(std::ostream & os) const
{
	for (size_t i = 0; i < m_size; ++i)
		os << m_array[i] << std::endl;
}

//(i)
std::ostream & operator<<(std::ostream & os, const ArrayQueue & arrayQueue)
{
	arrayQueue.serialize(os);
	return os;
}

#endif

