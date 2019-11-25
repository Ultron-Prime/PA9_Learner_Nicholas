/* -------------------------------------------------
FILE:		NodeQueue.h
DESCRIPTION:	NodeQueue header file for Project 9 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:		Uses class Node from Project 8, with a slight change to make NodeQueue the friend class

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-11-20	1.0 Created this file, added class NodeQueue declar/implement-ation
*/

#ifndef NODEQUEUE_H
#define NODEQUEUE_H

#include "DataType.h"

class Node{

  friend class NodeQueue;  //allows direct accessing of link and data from class NodeQueue

  public:
    Node() :
	  m_next( NULL )
	{
	}
	Node(const DataType & data, Node * next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	Node(const Node & other) :
	  m_next( other.m_next ),
	  m_data( other.m_data )
	{
	}
	
    DataType & data(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<DataType &>(static_cast<const Node &>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }
    const DataType & data() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }
    Node * next(){
	  return m_next;
    }
    const Node * next() const{
	  return m_next;
    }

  private:
    Node * m_next; 						
    DataType m_data;
};


class NodeQueue
{
	friend std::ostream & operator<<(std::ostream & os,const NodeQueue& nodeQueue);//(i)
	
	public:
		NodeQueue();					//(1)
		NodeQueue(size_t size, const DataType & value);	//(2)
		NodeQueue(const NodeQueue & other);		//(3)
		~NodeQueue();					//(4)
		
		NodeQueue & operator= (const NodeQueue & rhs);	//(5)
		DataType & front();				//(6a)
		const DataType & front() const;			//(6b)
		DataType & back();				//(7a)
		const DataType & back() const;			//(7b)
		void push(const DataType & value);		//(8)
		void pop();					//(9)
		size_t size() const;				//(10)
		bool empty() const;				//(11)
		bool full() const;				//(12)
		void clear();					//(13)
		void serialize(std::ostream & os) const;	//(14)
	private:
		Node * m_front;
		Node * m_back;
		size_t m_size;
};


//(1)
NodeQueue::NodeQueue(): m_front(NULL), m_back(NULL), m_size(0) { }

//(2)
NodeQueue::NodeQueue(size_t size, const DataType & value): m_front(NULL), m_back(NULL), m_size(0)
{
	for (size_t i = 0; i < size; ++i)
		push(value);

}

//(3)
NodeQueue::NodeQueue(const NodeQueue & other): m_front(NULL), m_back(NULL), m_size(other.m_size)
{
	for (Node * curr = other.m_front; curr != NULL; curr = curr->m_next)
		push(curr->m_data);
}

//(4)
NodeQueue::~NodeQueue()
{
	while(m_size)
		pop();
	
	std::cout << "NodeQueue destructor called" << std::endl;
}

//(5)
NodeQueue & NodeQueue::operator= (const NodeQueue & rhs)
{
	if (this != &rhs)
	{
		while(m_front != NULL && m_size != 0)
			pop();
		
		for (Node * curr = rhs.m_front; curr != NULL; curr = curr->m_next)
			push(curr->m_data);
	}else;
	
	return *this;
}

//(6a)
DataType & NodeQueue::front()
{
	return m_front->m_data;
}

//(6b)
const DataType & NodeQueue::front() const
{
	return m_front->m_data;
}

//(7a)
DataType & NodeQueue::back()
{
	return m_back->m_data;
}

//(7b)
const DataType & NodeQueue::back() const
{
	return m_back->m_data;
}

//(8)
void NodeQueue::push(const DataType & value)
{
	if (m_back != NULL && m_size != 0)
	{
		m_back->m_next = new Node(value);
		m_back = m_back->m_next;
	}else
	{
		m_front = m_back = new Node(value);
	}
	
	++m_size;
}

//(9)
void NodeQueue::pop()
{
	if (m_size != 0)
	{
		Node * delnode = m_front;
		m_front = m_front->m_next;
		delete delnode;
		--m_size;
	}else;
}

//(10)
size_t NodeQueue::size() const
{
	return m_size;
}

//(11)
bool NodeQueue::empty() const
{
	return (m_front == NULL);
}

//(12)
bool NodeQueue::full() const
{
	return false;
}

//(13)
void NodeQueue::clear()
{
	while(m_size)
		pop();
}

//(14)
void NodeQueue::serialize(std::ostream & os) const
{
	for (Node * curr = m_front; curr != NULL; curr = curr->m_next)
		os << curr->m_data << std::endl;
}

//(i)
std::ostream & operator<<(std::ostream & os,const NodeQueue& nodeQueue)
{
	nodeQueue.serialize(os);
	return os;
}

#endif

