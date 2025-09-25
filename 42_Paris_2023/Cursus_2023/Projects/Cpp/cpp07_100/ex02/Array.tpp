/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 06:12:15 by mechard           #+#    #+#             */
/*   Updated: 2025/03/27 06:12:15 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array <T>::Array(const Array<T>& other) : _array(new T[other._size]), _size(other._size)
{
    if (_size)
	{
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
	{
        delete [] _array;
        _size = other._size;
        if (_size > 0)
		{
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
		else
		{
            _array = 0;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete [] _array;
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if (index < 0 || static_cast<unsigned int>(index) >= _size)
        throw OutOfRangeException();
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
    if (index < 0 || static_cast<unsigned int>(index) >= _size)
        throw OutOfRangeException();
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return (BOLD RED "Index out of bounds" RESET);
}
