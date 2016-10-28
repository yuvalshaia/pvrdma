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

#ifndef __PVRDMA_VERBS_H__
#define __PVRDMA_VERBS_H__

int pvrdma_query_device(struct ib_device *ibdev,
			struct ib_device_attr *props,
			struct ib_udata *udata);
int pvrdma_query_port(struct ib_device *ibdev, u8 port,
		      struct ib_port_attr *props);
int pvrdma_query_gid(struct ib_device *ibdev, u8 port,
		     int index, union ib_gid *gid);
int pvrdma_query_pkey(struct ib_device *ibdev, u8 port,
		      u16 index, u16 *pkey);
enum rdma_link_layer pvrdma_port_link_layer(struct ib_device *ibdev,
					    u8 port);
int pvrdma_modify_device(struct ib_device *ibdev, int mask,
			 struct ib_device_modify *props);
int pvrdma_modify_port(struct ib_device *ibdev, u8 port,
		       int mask, struct ib_port_modify *props);
int pvrdma_mmap(struct ib_ucontext *context, struct vm_area_struct *vma);
struct ib_ucontext *pvrdma_alloc_ucontext(struct ib_device *ibdev,
					  struct ib_udata *udata);
int pvrdma_dealloc_ucontext(struct ib_ucontext *context);
struct ib_pd *pvrdma_alloc_pd(struct ib_device *ibdev,
			      struct ib_ucontext *context,
			      struct ib_udata *udata);
int pvrdma_dealloc_pd(struct ib_pd *ibpd);
struct ib_mr *pvrdma_get_dma_mr(struct ib_pd *pd, int acc);
struct ib_mr *pvrdma_reg_user_mr(struct ib_pd *pd, u64 start, u64 length,
				 u64 virt_addr, int access_flags,
				 struct ib_udata *udata);
int pvrdma_dereg_mr(struct ib_mr *mr);
struct ib_mr *pvrdma_alloc_mr(struct ib_pd *pd, enum ib_mr_type mr_type,
			      u32 max_num_sg);
int pvrdma_map_mr_sg(struct ib_mr *ibmr, struct scatterlist *sg,
		     int sg_nents, unsigned int *sg_offset);
int pvrdma_modify_cq(struct ib_cq *cq, u16 cq_count, u16 cq_period);
int pvrdma_resize_cq(struct ib_cq *ibcq, int entries,
		     struct ib_udata *udata);
struct ib_cq *pvrdma_create_cq(struct ib_device *ibdev,
			       const struct ib_cq_init_attr *attr,
			       struct ib_ucontext *context,
			       struct ib_udata *udata);
int pvrdma_resize_cq(struct ib_cq *ibcq, int entries,
		     struct ib_udata *udata);
int pvrdma_destroy_cq(struct ib_cq *cq);
int pvrdma_poll_cq(struct ib_cq *ibcq, int num_entries, struct ib_wc *wc);
int pvrdma_req_notify_cq(struct ib_cq *cq, enum ib_cq_notify_flags flags);
struct ib_ah *pvrdma_create_ah(struct ib_pd *pd, struct ib_ah_attr *ah_attr);
int pvrdma_destroy_ah(struct ib_ah *ah);
struct ib_qp *pvrdma_create_qp(struct ib_pd *pd,
			       struct ib_qp_init_attr *init_attr,
			       struct ib_udata *udata);
int pvrdma_modify_qp(struct ib_qp *ibqp, struct ib_qp_attr *attr,
		     int attr_mask, struct ib_udata *udata);
int pvrdma_query_qp(struct ib_qp *ibqp, struct ib_qp_attr *qp_attr,
		    int qp_attr_mask, struct ib_qp_init_attr *qp_init_attr);
int pvrdma_destroy_qp(struct ib_qp *qp);
int pvrdma_post_send(struct ib_qp *ibqp, struct ib_send_wr *wr,
		     struct ib_send_wr **bad_wr);
int pvrdma_post_recv(struct ib_qp *ibqp, struct ib_recv_wr *wr,
		     struct ib_recv_wr **bad_wr);

#endif /* __PVRDMA_VERBS_H__ */
