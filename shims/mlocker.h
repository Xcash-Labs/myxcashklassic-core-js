#pragma once

#include <stddef.h>

namespace epee
{
  class mlocker
  {
  public:
    mlocker(const void *addr, size_t len)
    {
      (void)addr;
      (void)len;
    }

    ~mlocker() {}

    mlocker(const mlocker&) = delete;
    mlocker& operator=(const mlocker&) = delete;
  };

  // WASM-safe no-op replacement.
  // Keep the wrapped type unchanged so it remains trivially copyable.
  template<typename T>
  using mlocked = T;
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