/*
 * libshcodecs: A library for controlling SH-Mobile hardware codecs
 * Copyright (C) 2009 Renesas Technology Corp.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA  02110-1301 USA
 */

#ifndef	AVCBENCSMP_H
#define	AVCBENCSMP_H

#include <stdio.h>

#include "capture.h"


/*----- structures -----*/

typedef struct {

	/* Table to store an encoding result (MPEG-4 bitstream) */

	/* Size of encoding result (byte unit) */

	/* Input imformation in encoding */

	/* Input YUV file name and it's file pointer */
	char input_file_name_buf[256];	/* for stream-1 */
	FILE *input_yuv_fp;	/* for stream-1 */
	long yuv_CbCr_format;	/* YUV�ǡ�����ʽ��Ϥ��������ǥ����ɥե�������
				   ��Cb,Cr�ǡ������¤ӽ��1:Cb����Cr������2:Cb0,Cr0,Cb1,Cr1,...��
				   3:Cb��1�饤��ʬ,Cr��1�饤��ʬ,...�� */

	char output_file_name_buf[256];	/* ����m4v�ե�����̾ */
	char ctrl_file_name_buf[256];	/* ����YUV�ե�����̾ */

	char buf_input_yuv_file_with_path[256 + 8];	/* ����YUV�ե�����̾�ʥѥ��դ��� *//* 041201 */
	char buf_input_yuv_file[64 + 8];	/* ����YUV�ե�����̾�ʥѥ��ʤ��� */

	char buf_output_directry[256 + 8];	/* ������Υǥ��쥯�ȥ� *//* 041201 */
	char buf_output_stream_file[64 + 8];	/* ���ϥ��ȥ꡼��ե�����̾�ʥѥ��ʤ��� */
	long xpic;
	long ypic;

    long frames_to_encode;

	/* Output imformation in encoding */

	long return_code;	/* return_value of current frame or NAL *//* 041123 */

	FILE *output_file_fp;	/* for output stream-2 */

	capture *ceu;

} APPLI_INFO;


#define ALIGN(a, w) (void *)(((unsigned long)(a) + (w) - 1) & ~((w) - 1))

#endif				/* AVCBENCSMP */
