/**
* This file is part of BareSDK and licensed under the:
* BSD 3-Clause License
* Copyright (c) 2021, Matheus Xavier
* All rights reserved.
*/

#ifndef LLRT_RINGBUFF_H
#define LLRT_RINGBUFF_H

#include "common.h"

/**
 * Ringbuffer struct, this implementation deals in bytes,
 * care is expected from the caller to only read/write
 * constant end or to keep track of element sizing
 * elsewhere.
 */
struct llrt_ringbuffer {
	size_t size;
	size_t r_off;
	size_t w_off;
	uint8_t *data;
};

/**
 * Initialize a llrt_ringbuffer using buff as a backing buffer
 * @attention Care must be taken to not use after freeing of the `buff` buffer (not applicable to llrt_stack memory)
 * @param self the llrt_ringbuffer to initialize
 * @param buff the buffer to initialize
 * @param buff_len how long is the buffer
 */
extern void ringbuffer_init(struct llrt_ringbuffer *self, uint8_t *buff,
			    size_t buff_len);

/**
 * Write n bytes from source to to the llrt_ringbuffer self
 * @param self the llrt_ringbuffer to operate on
 * @param src where to copy the bytes from
 * @param n how many bytes to copy
 * @return -1 on failure 0 on success
 */
extern int llrt_ringbuffer_write(struct llrt_ringbuffer *self, uint8_t *src, size_t n);

/**
 *
 * @param self the llrt_ringbuffer to operate on
 * @param dst where to copy bytes to
 * @param n how many bytes to retrieve
 * @return -1 on failure 0 on success
 */
extern size_t llrt_ringbuffer_read(struct llrt_ringbuffer *self, uint8_t *dst, size_t n);

#endif
