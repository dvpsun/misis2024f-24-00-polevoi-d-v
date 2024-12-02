// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef ARRAYT_ARRAYT_HPP_20241202
#define ARRAYT_ARRAYT_HPP_20241202

#include <cstddef>

template<class T>
class ArrayT {
public:
  ArrayT() = default;
  ArrayT(const ArrayT&) = default;
  
  //! \param size - начальный размер, 0 < size
  ArrayT(const std::ptrdiff_t size) : size_(size) { }
  
  ~ArrayT() = default;
  
  [[nodiscard]] ArrayT& operator=(const ArrayT&) = default;

  [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
  
  //! \param size - новый размер, 0 <= size
  void Resize(const std::ptrdiff_t size) { size_ = size; }
  
  //! \param idx - индекс  элемента, 0 <= idx < Size()
  [[nodiscard]] double& operator[](const std::ptrdiff_t idx) { (idx);  return *data_; }
  [[nodiscard]] double operator[](const std::ptrdiff_t idx) const { (idx);  return *data_; }

  //! \param idx - индекс вставляемого элемента, 0 <= idx <= size 
  void Insert(const std::ptrdiff_t idx, const double val) { (idx); (val); }

  //! \param idx - индекс удаляемого элемента, 0 <= idx < size 
  void Remove(const std::ptrdiff_t idx) { (idx); }

private:
  std::ptrdiff_t capacity_ = 0;  //!< размер буффера
  std::ptrdiff_t size_ = 0;      //!< число элементов в массиве
  T* data_ = 0;                  //!< буффер
};

#endif // !ArrayT_ArrayT_HPP_20241202
