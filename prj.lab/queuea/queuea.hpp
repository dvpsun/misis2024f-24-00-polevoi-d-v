// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef QUEUEA_QUEUEA_HPP_20241207
#define QUEUEA_QUEUEA_HPP_20241207

#include <cstddef>
#include <cstdint>

class QueueA final {
public:
  using T = std::uint8_t;

  QueueA() = default;

  QueueA(const QueueA& src);

  QueueA(QueueA&& src) noexcept;
  
  ~QueueA();
  
  QueueA& operator=(const QueueA& src);

  QueueA& operator=(QueueA&& src);

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const T val);
  
  [[nodiscard]] T& Top();

  [[nodiscard]] const T& Top() const;

  void Clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;  //!< 
  T* data_ = nullptr;        //!< 
  std::ptrdiff_t head_ = -1; //!< 
  std::ptrdiff_t tail_ = -1; //!< 
private:
  std::ptrdiff_t Count() const;
  void Swap(QueueA&& src) noexcept;
};

#endif
