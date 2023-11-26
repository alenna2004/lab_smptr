#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include "unptr.h"
#ifndef SHPTR_H
#define SHPTR_H


template <class T> 
class SharedPtr
{
private:
	UniquePtr<T>* uniq_ptr;
	int* reference_count; 
	void increase_count();
	void decrease_count();
public:
	SharedPtr(T* object);
	SharedPtr();
	SharedPtr(const SharedPtr<T> &other);
	~SharedPtr();
	T& operator*() const;
	SharedPtr<T>& operator=(const SharedPtr<T> &other);
	T* operator->() const;
	T* get() const;
	void reset(T* q = 0);
	void swap(SharedPtr<T> &other);
	bool unique() const;
	int use_count() const;
};


template <class T>
SharedPtr<T>::SharedPtr(T* object)
{
	uniq_ptr = new UniquePtr<T>(object);
	reference_count = new int(1);
	*reference_count = 1;
}


template <class T>
SharedPtr<T>::SharedPtr()
{
	uniq_ptr = new UniquePtr<T>();
	reference_count = new int(1);
}


template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &other)
{
	this->uniq_ptr = other.uniq_ptr;
	this->reference_count = other.reference_count;
	this->increase_count();
}


template <class T>
SharedPtr<T>::~SharedPtr()
{
	this->decrease_count();
	if(*reference_count <= 0){
		delete uniq_ptr;
	}
}


template <class T>
T& SharedPtr<T>::operator*() const
{
	return *(uniq_ptr->get());
}


template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T> &other)
{
	if(this->get() != other.get()){
		this->decrease_count();
		if(*reference_count == 0){
			delete uniq_ptr;
		}
	}
	this->uniq_ptr = other.uniq_ptr;
	this->reference_count = other.reference_count;
	this->increase_count();
	return *this;
}


template <class T>
T* SharedPtr<T>::operator->() const
{
	return uniq_ptr->get();
}


template <class T>
T* SharedPtr<T>::get() const
{
	return uniq_ptr->get();
}


template <class T>
void SharedPtr<T>::reset(T* q)
{
	uniq_ptr->reset(q);
	decrease_count();
	this->reference_count = new int(1);
	*reference_count = 0;
}


template <class T>
void SharedPtr<T>::swap(SharedPtr<T> &other)
{
	uniq_ptr->swap(*(other.uniq_ptr));
	int* tmp_count = this->reference_count;
	this->reference_count = other.reference_count;
	other.reference_count = tmp_count;
}


template <class T>
bool SharedPtr<T>::unique() const
{
	if(*reference_count == 1){
		return true;
	}
	return false;
}


template <class T>
int SharedPtr<T>::use_count() const
{
	return *reference_count;
}


template <class T>
void SharedPtr<T>::increase_count()
{
	*reference_count += 1;
}


template <class T>
void SharedPtr<T>::decrease_count()
{
	*reference_count -= 1;
}

#endif
