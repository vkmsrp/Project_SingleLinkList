#pragma once

/*
 * Node for singly link list.
 */
template<typename T>
class Node {
public:
	Node();
	Node(const T& inData);
	Node(const T& inData, const Node*& inNext);
	Node(const Node& rhs);
	virtual ~Node();
	inline bool operator==(const Node &rhs) const;
	Node& operator=(Node const &rhs);

	T mData;
	Node* mNext;
};

template<typename T>
Node<T>::Node() {
	this->mNext = NULL;
}

template<typename T>
Node<T>::Node(const T& inData) {
	this->mData = inData;
	this->mData = NULL;
}

template<typename T>
Node<T>::Node(const T& inData, const Node*& inNext) {
	this->mData = inData;
	this->mData = NULL;
}

template<typename T>
Node<T>::~Node() {
	mNext = NULL;
}

template<typename T>
Node<T>::Node(const Node& rhs) {
	this->mData = rhs.mData;
	this->mNext = rhs.mNext;
}

template<typename T>
bool Node<T>::operator==(const Node &rhs) const {
	if(this->mData == rhs.mData && this->mNext == rhs.mNext) {
		return true;
	}
	else {
		return false;
	}
}


template<typename T>
Node<T>& Node<T>::operator=(const Node& rhs) {
	/* Check for self-assignment by comparing the address of the implicit object and the parameter */
	if(this == &rhs) {
		return *this;
	}
	else {
		this->mData = rhs.mData;
		this->mNext = rhs.mNext;
		return *this;
	}
}

/*
 * Single List class
 */
template<typename T>
class SingleLinkList {
public:
	/* Constructors and Destructors */
	SingleLinkList();
	SingleLinkList(const SingleLinkList& other);
	virtual ~SingleLinkList();
	SingleLinkList& operator=(const SingleLinkList& rhs);
	
	/* Single link list operations */
	inline unsigned int Length();
	inline bool IsEmpty();
	void Pushback(const T& inData);
	void Pushfront(const T& inData);
	//T Popback();
	//T Popfront();
	//Node& InsertAfter(const Node& inNode);
	//Node& InsertBefore(const Node& inNode);
	//Node& RemoveAfter(const Node& inNode);
	//Node& RemoveBefore(const& inNode);
	//void Remove(const T& inData);
	//T& GetAt(const unsigned int inIndex);



private:
	Node<T>* mListHead;
	unsigned int mLength;
};

template<typename T>
SingleLinkList<T>::SingleLinkList() {
	this->mLength = 0;
	mListHead = NULL;
}

template<typename T>
SingleLinkList<T>::~SingleLinkList() {
	// TODO VIVEK: to add the purge of entire link list.

	this->mLength = 0;
}

template<typename T>
unsigned int SingleLinkList<T>::Length() {
	return mLength;
}

template<typename T>
bool SingleLinkList<T>::IsEmpty() {
	if(length <= 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
void SingleLinkList<T>::Pushfront(const T& inData) {
	Node<T>* newNode = new Node(inData);
	if(!newNode) {
		return;
	}
	newNode->mData = inData;

	/* If the link-list is empty */
	if(this->IsEmpty()) {
		newNode->mNext = NULL;
		this->mListHead = newNode;
	}
	else {
		/* If the link-list is containing element. */
		newNode->mNext = this->mListHead;
		this->mListHead = newNode;
	}
}

template<typename T>
void SingleLinkList<T>::Pushback(const T& inData) {
	Node<T>* newNode = new Node(inData);
	if(!newNode){
		return;
	}

	newNode->mData = inData;

	/* If link-list is empty. */
	if(this->IsEmpty()) {
		newNode->mNext = NULL;
		this->mListHead = newNode;
	}
	else {
		/* If the link-list is containing element. */
		Node<T>* tempNode = this->mListHead;
		while(tempNode->mNext != NULL) {
			tempNode = temp->next;
		}
		tempNode->mNext = newNode;
		newNode->mNext = NULL;
	}
}