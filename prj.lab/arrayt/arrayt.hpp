// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef ARRAYT_ARRAYT_HPP_20241202
#define ARRAYT_ARRAYT_HPP_20241202

#include <cstddef>
#include <memory>
#include <stdexcept>

template<class T>
class ArrayT {
public:
  ArrayT() = default;
  ArrayT(const ArrayT&);
  
  //! \param size - начальный размер, 0 < size
  ArrayT(const std::ptrdiff_t size);
  
  ~ArrayT() = default;
  
  ArrayT& operator=(const ArrayT&);

  [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
  
  //! \param size - новый размер, 0 <= size
  void Resize(const std::ptrdiff_t size) { size_ = size; }
  
  //! \param idx - индекс  элемента, 0 <= idx < Size()
  [[nodiscard]] T& operator[](const std::ptrdiff_t idx);
  [[nodiscard]] const T& operator[](const std::ptrdiff_t idx) const;

  //! \param idx - индекс вставляемого элемента, 0 <= idx <= size 
  void Insert(const std::ptrdiff_t idx, const double val) { (idx); (val); }

  //! \param idx - индекс удаляемого элемента, 0 <= idx < size 
  void Remove(const std::ptrdiff_t idx) { (idx); }

private:
  std::ptrdiff_t capacity_ = 0;  //!< размер буффера
  std::ptrdiff_t size_ = 0;      //!< число элементов в массиве
  std::unique_ptr<T[]> data_;      //!< буффер
};


template<class T>
ArrayT<T>::ArrayT(const ArrayT<T>& src)
  : capacity_(src.size_)
  , size_(capacity_) {
  data_.reset(new T[capacity_]{T()});
  std::copy(src.data_.get(), src.data_.get() + size_, data_.get());
}

template<class T>
ArrayT<T>::ArrayT(const std::ptrdiff_t size) 
    : capacity_(size)
    , size_(size) {
  if (size_ <= 0) {
    throw std::invalid_argument("ArrayD::ArrayD - non positive size");
  }
  data_.reset(new T[size]{T()});
}

template<class T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& rhs) {
  if (this != &rhs) {
    Resize(rhs.size_);
    std::copy(rhs.data_.get(), rhs.data_.get() + size_, data_.get());
  }
  return *this;
}


template<class T>
T& ArrayT<T>::operator[](const std::ptrdiff_t idx) {
  if (idx < 0 || size_ <= idx) {
    throw std::invalid_argument("ArrayD::operator[] - invalid argument");
  }
  return *(data_.get() + idx);
}

template<class T>
const T& ArrayT<T>::operator[](const std::ptrdiff_t idx) const {
  if (idx < 0 || size_ <= idx) {
    throw std::invalid_argument("ArrayD::operator[] - invalid argument");
  }
  return *(data_.get() + idx);
}

#endif // !ArrayT_ArrayT_HPP_20241202
