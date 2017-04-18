#pragma once

template <typename T>
class MyList
{
private:
	struct Element
	{
		T item;
		Element* next;
		Element* prev;
	};
	Element* first;
	Element* last;
	size_t size_;
public:

	class bad_List
	{
	private:
		char* error_;
	public:
		bad_List() :error_("unknown") {};

		bad_List(char* error)
		{
			error_ = error;
		}

		bad_List(const bad_List& e)
		{
			error_ = e.what();
		}

		char* what() const
		{
			return error_;
		}
	};

	MyList() 
	{
		size_ = 0;
		first = nullptr;
		last = nullptr;
	}

	MyList(const MyList& copy)
	{
		size_ = 0;
		Element* temp = copy.first;
		if (temp != nullptr)
		{
			size_++;
			first = new Element;
			first->prev = nullptr;
			first->next = nullptr;
			last = first;
			first->item = temp->item;
			temp = temp->next;
		}
		while (temp != nullptr)
		{
			size_++;
			last->next = new Element;
			last->next->prev = last;
			last->next->next = nullptr;
			last = last->next;
			last->item = temp->item;
			temp = temp->next;
		}
	}

	inline size_t size() const
	{
		return size_;
	}

	void pushBack(const T& newItem)
	{
		size_++;
		if (first == nullptr)
		{
			first = new Element;
			last = first;
			last->next = nullptr;
			last->prev = nullptr;
			last->item = newItem;
			return;
		}
		last->next = new Element;
		last->next->next = nullptr;
		last->next->prev = last;
		last = last->next;
		last->item = newItem;
	}

	void popBack()
	{
		if (size_ == 0)
			throw bad_List("List is empty.");
		size_--;
		Element* temp = last;
		last = last->prev;
		delete temp;
		if (last == nullptr)
		{
			first = nullptr;
			return;
		}
		last->next = nullptr;
		return;
	}

	void pushFront(const T& newItem)
	{
		size_++;
		if (first == nullptr)
		{
			first = new Element;
			last = first;
			last->next = nullptr;
			last->prev = nullptr;
			last->item = newItem;
			return;
		}
		first->prev = new Element;
		first->prev->prev = nullptr;
		first->prev->next = first;
		first = first->prev;
		first->item = newItem;
	}

	void popFront()
	{
		if (size_ == 0)
			throw bad_List("List is empty.");
		size_--;
		Element* temp = first;
		first = first->next;
		delete temp;
		if (first != nullptr)
			first->prev = nullptr;
		return;
	}

	void deleteItem(const size_t& n)
	{
		if (n >= size_)
			throw bad_List("Out of range.");
		size_--;
		Element* temp = first;
		for (size_t i = 0; i < n;++i)
			temp = temp->next;
		if (temp == first)
		{
			if (first == last)
			{
				last = nullptr;
				first = nullptr;
				delete temp;
				return;
			}
			first = first->next;
			first->prev = nullptr;
			delete temp;
			return;
		}
		if (temp == last)
		{
			last = last->prev;
			last->next = nullptr;
			delete temp;
			return;
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
	}
	
	char enable(const T& searchItem) const
	{
		Element* temp = first;
		while (temp != nullptr)
		{
			if (searchItem == temp->item)
				return 1;
			temp = temp->next;
		}
		return 0;
	}

	T operator[](const size_t& n)
	{
		if (n >= size_)
			throw bad_List("Out of range.");
		Element* temp = first;
		for (size_t i = 0; i < n; ++i)
			temp = temp->next;
		return temp->item;
	}

	T operator[](const size_t& n) const
	{
		if (n >= size_)
			throw bad_List("Out of range.");
		Element* temp = first;
		for (size_t i = 0; i < n; ++i)
			temp = temp->next;
		return temp->item;
	}

	friend std::ostream& operator<< (std::ostream& os, const MyList& _a)
	{
		if (!_a.size_)
			os << "List is empty." << std::endl;
		for (int i = 0; i < _a.size(); ++i)
			os << _a[i];
		return os;
	}

	~MyList() 
	{
		Element* temp;
		while (first != nullptr)
		{
			temp = first;
			first = first->next;
			delete temp;
		}
	}
};

