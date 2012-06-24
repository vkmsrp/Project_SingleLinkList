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

	/*
	 * Accessor functions.
	 */
	inline T GetData();
	inline void SetData(const T& data);
	inline Node<T>* GetNext();
	inline void SetNext(Node<T>* next);

private:
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
** Accessor functions for Node class.
**/
template<typename T>
inline T Node<T>::GetData() {
	return mData;
}

template<typename T>
inline void Node<T>::SetData(const T& data) {
	mData = data;
}

template<typename T>
inline Node<T>* Node<T>::GetNext() {
	return mNext;
}

template<typename T>
inline void Node<T>::SetNext(Node<T>* next) {
	mNext = next;
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
	unsigned int GetCount();
	void Pushback(const T& inData);
	void Pushfront(const T& inData);
	T Popback();
	T Popfront();
	Node<T>& InsertAfter(const Node<T>& node, const T& data);
	Node<T>& InsertBefore(const Node<T>& node, const T& data);
	void Remove(const Node<T>& node);
	//void Remove(const T& inData);
	//T& GetAt(const unsigned int inIndex);
	//Node<T>* Find(const Node<T>& node);
	//Node<T>* Find(const T& data);

private:
	void IncrementLength();
	void DecrementLength();
	bool IsNodeValid(const Node<T>& node);

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
void SingleLinkList<T>::IncrementLength() {
	mLength++;
}

template<typename T>
void SingleLinkList<T>::DecrementLength() {
	if(mLength >=) {
		mLength--;
	}
}

template<typename T>
bool SingleLinkList<T>::IsNodeValid(const Node<T>& node) {
	if(*node == NULL || this->IsEmpty()) {
		return false;
	}
	Node<T>* tempNode = this->mHeadList;
	while(tempNode->GetNext() != NULL) {
		if(tempNode == *node) {
			return true;
		}
	}
	return false;
}

template<typename T>
unsigned int SingleLinkList<T>::GetCount() {
	return mLength;
}

template<typename T>
bool SingleLinkList<T>::IsEmpty() {
	if(mLength <= 0)
		return true;
	else
		return false;
}

template<typename T>
void SingleLinkList<T>::Pushfront(const T& inData) {
	Node<T>* newNode = new Node<T>(inData);
	if(!newNode) {
		return;
	}
	newNode->SetData(inData);

	/* If the link-list is empty */
	if(this->IsEmpty()) {
		newNode->SetNext(NULL);
		this->mListHead = newNode;
	}
	else {
		/* If the link-list is containing element. */
		newNode->SetNext(this->mListHead);
		this->mListHead = newNode;
	}

	this->IncrementLength();
}

template<typename T>
void SingleLinkList<T>::Pushback(const T& inData) {
	Node<T>* newNode = new Node<T>(inData);
	if(!newNode){
		return;
	}

	newNode->SetData(inData);

	/* If link-list is empty. */
	if(this->IsEmpty()) {
		newNode->SetNext(NULL);
		this->mListHead = newNode;
	}
	else {
		/* If the link-list is containing element. */
		Node<T>* tempNode = this->mListHead;
		while(tempNode->GetNext() != NULL) {
			tempNode = tempNode->GetNext();
		}
		tempNode->SetNext(newNode);
		newNode->SetNext(NULL);
	}

	this->IncrementLength();
}

template<typename T>
T SingleLinkList<T>::Popback() {
	T retVal;
	if(this->IsEmpty()) {
	}
	else {
		Node<T>* tempNode = this->mListHead;
		while(tempNode->GetNext() != NULL) {
			tempNode = tempNode->GetNext();
		}
		if(this->mListHead == tempNode){
			mListHead = NULL;
		}
		retVal = tempNode->GetData();
		delete tempNode;
		this->DecrementLength();
	}

	return retVal;
}

template<typename T>
T SingleLinkList<T>::Popfront() {
	T retVal;
	if(this->IsEmpty()) {
	}
	else {
		Node<T>* tempNode = this->mListHead;
		if(mListHead->GetNext() == NULL) {
			this->mListHead->SetNext(NULL);
		}
		else {
			this->mListHead = mListHead->GetNext();
		}
		retVal = tempNode->GetData();
		delete tempNode;
	}
	return retVal;
}

template<typename T>
Node<T>& SingleLinkList<T>::InsertAfter(const Node<T>& node, const T& data) {
	if(this->IsNodeValid()) {
		Node<T>* newNode = new Node<T>(data);
		newNode->SetNext(node.GetNext());
		node.SetNext(newNode);
		return *newNode;
	}
	else {
	}
}

template<typename T>
Node<T>& SingleLinkList<T>::InsertBefore(const Node<T>& node, const T& data) {
	if(this->IsNodeValid()) {
		Node<T>* newNode = new Node<T>(node->GetData());
		newNode->SetNext(node.GetNext());
		node.SetNext(newNode);
		node.SetData(data);
		return node;
	}
	else {
	}
}

template<typename T>
void SingleLinkList<T>::Remove(const Node<T>& node) {
	if(this->IsNodeValid()) {
		node->SetData(node->GetNext()->GetData());
		Node<T>* tempNode = node->GetNext();
		node->SetNext(node->GetNext()->GetNext());
		delete tempNode;
	}
}