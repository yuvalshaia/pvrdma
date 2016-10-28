/*
 * Copyright (c) 2012-2016 VMware, Inc.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of EITHER the GNU General Public License
 * version 2 as published by the Free Software Foundation or the BSD
 * 2-Clause License. This program is distributed in the hope that it
 * will be useful, but WITHOUT ANY WARRANTY; WITHOUT EVEN THE IMPLIED
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License version 2 for more details at
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program available in the file COPYING in the main
 * directory of this source tree.
 *
 * The BSD 2-Clause License
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __PVRDMA_USER_H__
#define __PVRDMA_USER_H__

#include <linux/types.h>

#define PVRDMA_UVERBS_ABI_VERSION	3
#define PVRDMA_BOARD_ID			1
#define PVRDMA_REV_ID			1

struct pvrdma_alloc_ucontext_resp {
	__u32 qp_tab_size;
	__u32 reserved;
};

struct pvrdma_alloc_pd_resp {
	__u32 pdn;
	__u32 reserved;
};

struct pvrdma_create_cq {
	__u64 buf_addr;
	__u32 buf_size;
	__u32 reserved;
};

struct pvrdma_create_cq_resp {
	__u32 cqn;
	__u32 reserved;
};

struct pvrdma_resize_cq {
	__u64 buf_addr;
	__u32 buf_size;
	__u32 reserved;
};

struct pvrdma_create_srq {
	__u64 buf_addr;
};

struct pvrdma_create_srq_resp {
	__u32 srqn;
	__u32 reserved;
};

struct pvrdma_create_qp {
	__u64 rbuf_addr;
	__u64 sbuf_addr;
	__u32 rbuf_size;
	__u32 sbuf_size;
	__u64 qp_addr;
};

#endif /* __PVRDMA_USER_H__ */
