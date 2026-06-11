include <stddef.h>
#include <stdint.h>

extern "C" void cn_slow_hash(
  const void *data,
  size_t length,
  char *hash,
  int variant,
  int prehashed,
  uint64_t height
)
{
  (void)data;
  (void)length;
  (void)hash;
  (void)variant;
  (void)prehashed;
  (void)height;
}