#include <cstdlib>
#include <cstring>
#include <stdexcept>
#ifndef UNPTR_H
#define UNPTR_H


template <class T> 
class UniquePtr
{
private:
	T* ptr{0};
public:
	UniquePtr(T* object_ptr);
	UniquePtr(){};
	UniquePtr(const UniquePtr<T> &other) = delete;
	UniquePtr(UniquePtr<T> &&other);
	~UniquePtr();
	T& operator*() const;
	UniquePtr<T>& operator=(const UniquePtr<T> &other) = delete;
	T* operator->() const;
	T* get() const;
	void reset(T* new_ptr = 0);
	T* release();
	void swap(UniquePtr &other);
};


template <class T>
UniquePtr<T>::UniquePtr(T* object_ptr)
{
	ptr = object_ptr;
}


template <class T>
UniquePtr<T>::UniquePtr(UniquePtr<T> &&other)
{
	this->ptr = other.ptr;
	other.ptr = 0;
}


template <class T>
UniquePtr<T>::~UniquePtr()
{
	if (ptr != 0){
		delete ptr;
	}
}


template <class T>
T& UniquePtr<T>::operator*() const
{
	return *(ptr);
}


template <class T>
T* UniquePtr<T>::operator->() const
{
	return ptr;
}


template <class T>
T* UniquePtr<T>::get() const
{
	return ptr;
}


template <class T>
void UniquePtr<T>::reset(T* new_ptr)
{
	if(ptr != 0){
		delete ptr;
	}
	ptr = new_ptr;
}


template <class T>
T* UniquePtr<T>::release()
{
	T* standart_pointer = ptr;
	ptr = 0;
	return standart_pointer;
}


template <class T>
void UniquePtr<T>::swap(UniquePtr &other)
{
	T* tmp_ptr = this->ptr;
	this->ptr = other.ptr;
	other.ptr = tmp_ptr;
}


#endif