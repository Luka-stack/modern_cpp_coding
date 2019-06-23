//
// Created by takacchi on 27/05/19.
//

#ifndef MODERN_CPP_EXC_MYVECTOR_H
#define MODERN_CPP_EXC_MYVECTOR_H

#include <iostream>

template <class T>
class MyVector
{
private:
    typedef T value_type;
    typedef value_type* iterator;
    typedef const value_type const_iterator;

public:
    MyVector() : cur_size(0), buf_cap(0), buffer(new T[0]) {}
    explicit MyVector(size_t initial) : cur_size(initial), buf_cap(initial), buffer(new T[initial]) {}
    MyVector(size_t, T const&);
    MyVector(MyVector const&);
    ~MyVector() { delete [] buffer; }

    constexpr T* at(int const index) { return buffer[index]; }
    constexpr T const& at(int const index) const { return buffer[index]; }

    constexpr T* front() { return buffer[0]; }
    constexpr T const& front() const { return buffer[0]; }

    constexpr T* back() { return buffer[cur_size-1]; }
    constexpr T const& back() const { return buffer[cur_size-1]; }

    constexpr T* data() { return buffer; }
    constexpr T const& data() const { return buffer; }

    constexpr size_t size() const { return cur_size; }
    constexpr size_t capacity() const { return buf_cap; }
    constexpr bool is_empty() const { return cur_size == 0; }

    void erase(unsigned, unsigned=1);
    void push_back(const T&);
    void fill(const T&);
    void clear();
    T pop();

    constexpr T& operator[](unsigned index) { return buffer[index]; }
    constexpr T const& operator[](unsigned index) const { return buffer[index]; }
    MyVector& operator=(MyVector const&);

    const_iterator begin() const { return buffer; }
    const_iterator end() const { return buffer + cur_size; }
    iterator begin() { return buffer; }
    iterator end() { return buffer + cur_size; }

private:
    void resize(size_t);

private:
    size_t cur_size;
    size_t buf_cap;
    T* buffer;
};

template<class T>
MyVector<T>::MyVector(size_t size, const T& initial)
{
    this->cur_size = size;
    buf_cap = size*2;
    buffer = new T[buf_cap];

    for (int i = 0; i < size; i++)
        buffer[i] = initial;
}

template<class T>
MyVector<T>::MyVector(const MyVector<T>& vector)
{
    cur_size = vector.cur_size;
    buf_cap = vector.buf_cap;

    for (int i = 0; i < cur_size; i++)
        buffer[i] = vector.buffer[i];
}

template<class T>
void MyVector<T>::resize(size_t max)
{
    T* tmp = new T[max];
    for (int i = 0; i < cur_size; i++)
        tmp[i] = buffer[i];
    buffer = tmp;
}

template<class T>
void MyVector<T>::push_back(const T& item)
{
    if (cur_size == buf_cap)
        resize(2*cur_size);
    buffer[cur_size++] = item;
}

template<class T>
T MyVector<T>::pop()
{
    T item = buffer[--cur_size];
    //buffer[cur_size] = nullptr;
    buffer[cur_size].~T();
    if (cur_size > 0 && cur_size == buf_cap/4)
        resize(buf_cap/2);

    return item;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> const& vector)
{
    cur_size = vector.cur_size;
    buf_cap = vector.buff_cap;
    buffer = new T[buf_cap];

    for (int i = 0; i < cur_size; i++)
        buffer[i] = vector.buffer[i];

    return *this;
}

template<class T>
void MyVector<T>::fill(const T& item)
{
    for (int i = 0; i < cur_size; i++)
        buffer[i] = item;
}

template<class T>
void MyVector<T>::erase(unsigned first, unsigned count)
{
    T* tmp = new T[buf_cap-count];

    for (int i = 0; i < cur_size; i++)
    {
        if (i >= first && i < first+count)
            buffer[i].~T();
        else
            tmp[i] = buffer[i];
    }

    cur_size -= count;
    buffer = tmp;
}

template<class T>
void MyVector<T>::clear()
{
    ~MyVector();
    buffer = new T[buffer];
    cur_size = 0;
}


#endif //MODERN_CPP_EXC_MYVECTOR_H
