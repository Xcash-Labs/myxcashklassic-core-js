#pragma once

#include <stddef.h>
#include <string.h>
#include <utility>

namespace epee
{
  class mlocker
  {
  public:
    mlocker(const void *addr, size_t len) { (void)addr; (void)len; }
    ~mlocker() {}

    mlocker(const mlocker&) = delete;
    mlocker& operator=(const mlocker&) = delete;
  };

  template<typename T>
  struct mlocked : public T
  {
    mlocked() : T() {}

    mlocked(const T& other) : T(other) {}

    mlocked(const mlocked& other) : T(static_cast<const T&>(other)) {}

    mlocked& operator=(const mlocked& other)
    {
      if (this != &other) {
        static_cast<T&>(*this) = static_cast<const T&>(other);
      }
      return *this;
    }

    mlocked& operator=(const T& other)
    {
      static_cast<T&>(*this) = other;
      return *this;
    }

    ~mlocked() {}
  };
}

template<typename T>
T& unwrap(epee::mlocked<T>& src)
{
  return static_cast<T&>(src);
}

template<typename T>
const T& unwrap(const epee::mlocked<T>& src)
{
  return static_cast<const T&>(src);
}

template<typename T>
T& unwrap(T& src)
{
  return src;
}

template<typename T>
const T& unwrap(const T& src)
{
  return src;
}