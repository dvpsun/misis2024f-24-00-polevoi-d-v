// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef ARRAYD_ARRAYD_HPP_20241120
#define ARRAYD_ARRAYD_HPP_20241120

#include <cstddef>

class ArrayD {
public:
  ArrayD() = default;

  ArrayD(const ArrayD&) = default;
  
  //! \param size - начальный размер, 0 < size
  ArrayD(const std::ptrdiff_t size) : size_(size) { }
  
  ~ArrayD() = default;
  
  [[nodiscard]] ArrayD& operator=(const ArrayD&) = default;

  [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
  
  //! \param size - новый размер, 0 <= size
  void Resize(const std::ptrdiff_t size) { size_ = size; }
  
  //! \param idx - индекс  элемента, 0 <= idx < Size()
  [[nodiscard]] double& operator[](const std::ptrdiff_t idx) { return *data_; }
  [[nodiscard]] double operator[](const std::ptrdiff_t idx) const { return *data_; }

  //! \param idx - индекс вставляемого элемента, 0 <= idx <= size 
  void Insert(const std::ptrdiff_t idx, const double val) { }

  //! \param idx - индекс удаляемого элемента, 0 <= idx < size 
  void Remove(const std::ptrdiff_t idx) { }

private:
  std::ptrdiff_t capacity_ = 0;  //!< размер буффера
  std::ptrdiff_t size_ = 0;      //!< число элементов в массиве
  double* data_ = 0;             //!< буффер
};

#endif // !ARRAYD_ARRAYD_HPP_20241120
