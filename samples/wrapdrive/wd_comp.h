/*
 * Copyright (c) 2017. Hisilicon Tech Co. Ltd. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef __WD_COMP_H
#define __WD_COMP_H

#include <stdlib.h>
#include <errno.h>

#include "../../drivers/crypto/hisilicon/wd/wd_usr_if.h"
#include "../../drivers/crypto/hisilicon/wd/wd_comp_usr_if.h"

enum wd_comp_op {
	WD_COMP_INVALID,
	WD_COMP_PRESS,
	WD_COMP_INFLATE,
	WD_COMP_PSSTHRH,
};

enum wd_comp_flush {
	WD_INVALID_CFLUSH,
	WD_NO_CFLUSH,
	WD_PARTIAL_CFLUSH,
	WD_FULL_CFLUSH,
	WD_FINISH,
};

struct wd_comp_msg {

	/* First 8 bytes of the message must indicate algorithm */
	union {
		char  *alg;
		__u64 pading;
	};

	/* address type */
	__u32 aflags;

	/* Comsumed bytes of input data */
	__u32 in_coms;
	__u32 in_bytes;
	__u32 out_bytes;
	__u64 src;
	__u64 dst;
	__u8 comp_lv;
	__u8 file_type;
	__u8 humm_type;
	__u8 op_type;
	__u32 win_size;

	/* This flag indicates the output mode, from enum wd_comp_flush */
	__u32 cflags;
	__u32 resv1;
	__u64 resv2;
};

#endif
