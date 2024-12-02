// 2024 by Polevoi Dmitry under Unlicense

#include <arrayd/arrayd.hpp>

#include <cstring>
#include <stdexcept>

ArrayD::ArrayD(const ArrayD& src) 
  : capacity_(src.size_)
  , size_(capacity_)
  , data_(new double[size_]) {
  std::memcpy(data_, src.data_, size_ * sizeof(*data_));
}
  

ArrayD::ArrayD(const std::ptrdiff_t size)
  : capacity_(size)
  , size_(size) { 
  if (size_ <= 0) {
    throw std::invalid_argument("ArrayD::ArrayD - non positive size");
  }
  data_ = new double[capacity_]{0.0};
}
  
ArrayD::~ArrayD() {
  delete[] data_;
}
  
ArrayD& ArrayD::operator=(const ArrayD& rhs) {
  if (this != & rhs) {
    Resize(rhs.size_);
    size_ = rhs.size_;
    std::memcmp(data_, rhs.data_, size_ * sizeof(*data_));
  }
  return *this;
}

void ArrayD::Resize(const std::ptrdiff_t size) { 
  if (size_ < 0) {
    throw std::invalid_argument("ArrayD::Resize - non positive size");
  }
  if (capacity_ <= size) {
  } else {

  }
}
  

double& ArrayD::operator[](const std::ptrdiff_t idx) { 
  if (idx < 0 || size_ <= idx) {
    throw std::invalid_argument("ArrayD::operator[] - invalid argument");
  }
  return *(data_ + idx);
}

double ArrayD::operator[](const std::ptrdiff_t idx) const { 
  if (idx < 0 || size_ <= idx) {
    throw std::invalid_argument("ArrayD::operator[] - invalid argument");
  }
  return data_[idx];
}

void ArrayD::Insert(const std::ptrdiff_t idx, const double val) {
  if (idx < 0 || size_ < idx) {
    throw std::invalid_argument("ArrayD::Insert - invalid argument");
  }
  Resize(size_ + 1);
  if (idx != Size() - 1) {
    std::memmove(data_ + idx + 1, data_ + idx, (size_ - idx) * sizeof(double));
  }
  data_[idx] = val;
}


void ArrayD::Remove(const std::ptrdiff_t idx) { 
  if (idx < 0 || size_ <= idx) {
    throw std::invalid_argument("ArrayD::operator[] - invalid argument");
  }
  if (idx != size_ - 1) {
    // удаляем НЕ в конце
    std::memmove(data_ + idx, data_ + idx + 1, (size_ - idx) * sizeof(double));
  }
  Resize(size_ - 1);
}
