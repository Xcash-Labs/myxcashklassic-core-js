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
}