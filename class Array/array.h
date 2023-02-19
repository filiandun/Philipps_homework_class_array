#pragma once
#include <iostream>
#include <stdarg.h>
#include "node.h"

template<typename T>
class Array
{
public:
	Array();

	Array(const Array& array); // copy constructor
	Array(Array&& array) noexcept; // move constructor

	~Array() = default;

private:
	size_t size;

	Node<T>* begin_node;
	Node<T>* end_node;

public:
	size_t get_size() const;
	void set_size(size_t size, size_t grow);

	size_t get_upper_bound() const;
	bool is_empty() const;

	void free_extra();
	void remove_all();

	T get_at(size_t index) const;
	void set_at(size_t index, T data);

	Node<T>* operator[](size_t index);

	void add(T data);
	void append(Array& array);

	void operator=(size_t index);

	Array* get_data();

	void insert_at(size_t index, T data);
	void remove_at(size_t index, T data);

	void print() const;

};





template<typename T>
inline Array<T>::Array()
{
	this->size = 0;

	this->begin_node = nullptr;
	this->end_node = nullptr;
}


template<typename T>
inline Array<T>::Array(const Array& array)
{
	//std::cerr << "COPY" << std::endl;

	try
	{
		if (array.begin_node == nullptr && array.end_node == nullptr)
		{
			this->begin_node = nullptr;
			this->end_node = nullptr;

			throw "ERROR: COPIED QUEUE IS EMPTY!";
		}

		this->size = array.size;

		Node<T>* temp_node = array.begin_node;
		while (temp_node != nullptr)
		{
			this->add(temp_node->data);
			temp_node = temp_node->next_node;
		}
	}

	catch (const char* error_str)
	{
		std::cerr << error_str << std::endl;
	}
}


template<typename T>
inline Array<T>::Array(Array&& array) noexcept
{
	//std::cerr << "MOVE" << std::endl;
	this->size = array.size;

	this->begin_node = array.begin_node;
	this->end_node = array.end_node;

	array.begin_node = nullptr;
	array.end_node = nullptr;
}




template<typename T>
inline size_t Array<T>::get_size() const
{
	return this->size;
}

template<typename T>
inline void Array<T>::set_size(size_t size, size_t grow)
{
	return this->size;
}

template<typename T>
inline size_t Array<T>::get_upper_bound() const
{
	size_t size = this->size;
	Node<T>* temp_node = this->begin_node;

	while (temp_node != nullptr)
	{
		--size;
		if (temp_node != nullptr)
		{
			return size;
		}
		temp_node = temp_node->next_node;
	}

	return size;
}

template<typename T>
inline bool Array<T>::is_empty() const
{
	try
	{
		if (this->begin_node == nullptr && this->end_node == nullptr)
		{
			return true;
		}

		else if (this->begin_node != nullptr && this->end_node != nullptr)
		{
			return false;
		}

		else 
		{
			delete this;
			throw "ERROR: ARRAY IS BROKEN";
		}
	}

	catch (const char* error_str)
	{
		std::cerr << error_str << std::endl;
	}
}

template<typename T>
inline void Array<T>::free_extra()
{
}

template<typename T>
inline void Array<T>::remove_all()
{
	this->begin_node = nullptr;
	this->end_node = nullptr;
}

template<typename T>
inline T Array<T>::get_at(size_t index) const
{
	Node<T>* temp_node = this->begin_node;
	size_t i = 0;

	while (temp_node != nullptr && i != index)
	{
		temp_node = temp_node->next_node;
		++i;
	}

	return temp_node->data;
}

template<typename T>
inline void Array<T>::set_at(size_t index, T data)
{
	Node<T>* temp_node = this->begin_node;
	size_t i = 0;

	while (temp_node != nullptr && i != index)
	{
		temp_node = temp_node->next_node;
		++i;
	}

	temp_node->data = data;
}

template<typename T>
inline Node<T>* Array<T>::operator[](size_t index)
{
	Node<T>* temp_node = this->begin_node;
	size_t i = 0;

	while (temp_node != nullptr && i != index)
	{
		temp_node = temp_node->next_node;
		++i;
	}

	return temp_node;
}

template<typename T>
inline void Array<T>::add(T data)
{
	try
	{
		if (this->end_node == nullptr && this->begin_node == nullptr)
		{
			Node<T>* new_node = new Node<T>(data);

			this->begin_node = new_node;
			this->end_node = new_node;
		}

		else if (this->end_node != nullptr && this->begin_node != nullptr)
		{
			Node<T>* new_node = new Node<T>(data);

			this->end_node->next_node = new_node;
			new_node->previous_node = this->end_node;
			this->end_node = new_node;
		}

		else
		{
			delete this;
			throw "ERROR: ARRAY IS BROKEN";
		}
	}

	catch (const char* error_str)
	{
		std::cerr << error_str << std::endl;
	}
}

template<typename T>
inline void Array<T>::append(Array& array)
{
	Node<T>* temp_node = array.begin_node;
	while (temp_node != nullptr)
	{
		this->add(temp_node->data);
		temp_node = temp_node->next_node;
	}
}

template<typename T>
inline void Array<T>::operator=(size_t index)
{
}

template<typename T>
inline Array<T>* Array<T>::get_data()
{
	return this;
}

template<typename T>
inline void Array<T>::insert_at(size_t index, T data)
{
	Node<T>* temp_node = this->begin_node;
	size_t i = 0;

	while (temp_node != nullptr && i != index)
	{
		temp_node = temp_node->next_node;
		++i;
	}

	temp_node->data = data;
}

template<typename T>
inline void Array<T>::remove_at(size_t index, T data)
{
	Node<T>* temp_node = this->begin_node;
	size_t i = 0;

	while (temp_node != nullptr && i != index)
	{
		temp_node = temp_node->next_node;
		++i;
	}

	temp_node->data = data;
}

template<typename T>
inline void Array<T>::print() const
{
	Node<T>* temp_node = this->begin_node;
	while (temp_node != nullptr)
	{
		std::cout << temp_node->data << " ";
		temp_node = temp_node->next_node;
	}
	std::cout << std::endl;
}
