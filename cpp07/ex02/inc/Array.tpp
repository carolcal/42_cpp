/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:28:20 by cayamash          #+#    #+#             */
/*   Updated: 2025/07/28 17:20:32 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* *********************** Constructors and Destructor ********************** */
template <typename T>
Array<T>::Array(void) : _len(0), _array(NULL) {};

template <typename T>
Array<T>::Array(unsigned int n) : _len(n)
{
	if (n > 0)
		_array = new T[n]();
	else
		_array = NULL;
};

template <typename T>
Array<T>::Array(const Array &other) : _len(other._len)
{
	if (other._len > 0)
	{
		_array = new T[_len];
		for (unsigned int i = 0; i < _len; i++)
			_array[i] = other._array[i];
	}
	else
		_array = NULL;
}

template <typename T>
Array<T>::~Array(void) { delete[] _array; };

/* ******************************** Operators ******************************* */
template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _array;
		_len = other._len;
		if (_len > 0)
		{
			_array = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
				_array[i] = other._array[i];
		}
		else
			_array = NULL;
	}
	return *this;
};

template <typename T>
T& Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _len)
		throw std::out_of_range("Index is out of range.");
	return _array[index];
}

/* ***************************** Member Functions *************************** */
template <typename T>
unsigned int	Array<T>::size(void) const
{
	if (_len > 0)
		return _len;
	return 0;
}
