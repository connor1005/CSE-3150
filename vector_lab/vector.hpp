#pragma once
#include <cstddef>
#include <stdexcept>
#include <concepts>

template <typename T>
concept EqualityComparable = requires(const T& a, const T& b) {
	{ a == b } -> std::convertible_to<bool>;
};

template <typename T>
requires EqualityComparable<T>
class Vector {
private:
	T* data_;
	size_t size_;
	size_t capacity_;
	void resize_capacity(size_t new_capacity);

public:
	Vector();
	~Vector();

	Vector(const Vector&) = delete;
	Vector& operator=(const Vector&) = delete;
	
	size_t size() const;
	size_t capacity() const;
	bool empty() const;

	void push_back(const T& value);
	T& at(size_t index);
};

template <typename T>
Vector<T>::Vector() : data_(nullptr), size(0), capacity_(0) {}

template <typename T>
Vector<T>::~Vector() {
	delete[] data_;
}

template <typename T>
size_t Vector<T>::size() const {
	return size_;
}

template <typename T>
size_t Vector<T>::capacity() const {
	return capacity_;
}

template <typename T>
bool Vector<T>::empty() const {
	return size_ == 0;
}

template <typename T>
void Vector<T>::resize_capacity(size_t new_capacity) {
	T* new_data = new T[new_capacity];
	for (size_t i = 0; i < size_; ++i) {
		new_data[i] = data_[i];
	}
	delete[] data_;
	data_ = new_data;
	capacity_ = new_capacity;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
	if (size_ == capacity_) {
		size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
		resize_capacity(new_cap);
	}
	data_[size_] = value;
	size_++;
}

template <typename T>
T& Vector<T>::at(size_t index) {
	if (index >= size_) {
		throw std::out_of_range("Vector index out of bounds!");
	}
	return data_[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
	return data_[index];
}

template <typename T>
const T& Vector<T>::opertor[](size_t index) const {
	return data_[index];
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& other) const {
	if (size_ != other.size_) {
		return false;
	}
	for (size_t i = 0; i < size_; ++i) {
		if (!(data_[i] == other.data_[i])) {
			return false;
		}
	}
	return true;
}
