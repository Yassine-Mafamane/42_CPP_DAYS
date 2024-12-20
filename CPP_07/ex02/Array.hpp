/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 01:21:59 by ymafaman          #+#    #+#             */
/*   Updated: 2024/12/20 16:44:00 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		Array( unsigned int size );
		Array( const Array& ref );

		~Array();

		T&				operator[]( unsigned int index );
		Array&			operator=( const Array& rhs );
		unsigned int	size( void ) const;

	private:
		T*				array;
		unsigned int	arr_size;
};

/* ====== Methods Implementation ====== */

template <typename T>
Array<T>::Array() : array(NULL), arr_size(0){}

template <typename T>
Array<T>::Array( unsigned int arr_size )
{
	if (!arr_size)
	{
		this->arr_size = 0;
		this->array = NULL;
	}

	this->arr_size = arr_size;

	try
	{
		this->array = new T[arr_size];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Memory allocation for new array has failed!";
		this->array = NULL;
		this->arr_size = 0;
	}
}

template <typename T>
Array<T>::Array( const Array& ref )
{
	this->arr_size = ref.arr_size;

	try
	{
		this->array = new T[this->arr_size];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Memory allocation for the array has failed!";
		this->array = NULL;
		this->arr_size = 0;
	}

	for (unsigned int i = 0; i < this->arr_size; i++)
		this->array[i] = ref.array[i];
}

template <typename T>
Array<T>::~Array()
{
	if (this->array)
		delete [] this->array;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array& rhs )
{
	if (this == &rhs)
	{
		return (*this);
	}

	if (this->array)
		delete [] this->array;

	this->arr_size = rhs.arr_size;

	try
	{
		this->array = new T[rhs.arr_size];
	}
	catch(const std::exception& e)
	{
		std::cerr << "Memory allocation for the array has failed!";
		this->array = NULL;
		this->arr_size = 0;
	}

	for (unsigned int i = 0; i < this->arr_size; i++)
		this->array[i] = rhs.array[i];

	return (*this);
}

template <typename T>
T&   Array<T>::operator[]( unsigned int index )
{
	if (this->arr_size != 0 && index < this->arr_size)
		return (this->array[index]);
	else
		throw std::out_of_range("Index out of range");
}

template <typename T>
unsigned int  Array<T>::size() const
{
	return (this->arr_size);
}
#endif