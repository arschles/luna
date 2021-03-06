
//
// array.h
//
// Copyright (c) 2011 TJ Holowaychuk <tj@vision-media.ca>
//

#ifndef __LUNA_ARRAY__
#define __LUNA_ARRAY__

#include "object.h"
#include "kvec.h"

/*
 * Luna array.
 */

typedef kvec_t(luna_value_t *) luna_array_t;

/*
 * Initialize an array.
 */

#define luna_array_init(self) kv_init(*self)

/*
 * Return the array length.
 */

#define luna_array_length(self) kv_size(*self)

/*
 * Push `obj` into the array.
 */

#define luna_array_push(self, obj) \
  kv_push(luna_value_t *, *self, obj)

/*
 * Pop an object out of the array.
 */

#define luna_array_pop(self) \
  (luna_array_length(self) \
    ? kv_pop(*self) \
    : NULL)

/*
 * Return the object at `i`.
 */

#define luna_array_at(self, i) \
  (((i) >= 0 && (i) < luna_array_length(self)) \
    ? kv_A(*self, (i)) \
    : NULL)

/*
 * Iterate the array, populating `i` and `val`.
 */

#define luna_array_each(self, block) { \
    luna_value_t *val; \
    int len = luna_array_length(self); \
    for (int i = 0; i < len; ++i) { \
      val = luna_array_at(self, i); \
      block; \
    } \
  }

// protos

luna_array_t *
luna_array_new();

#endif /* __LUNA_ARRAY__ */