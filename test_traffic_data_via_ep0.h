/********************************************************************************
 *                            Module: music_engine
 *                 Copyright(c) 2003-2011 Actions Semiconductor,
 *                            All Rights Reserved.
 *
 * History:
 *      <author>    <time>           <version >             <desc>
 *     hujunhua   2017-12-16 11:30     1.0             build this file
 ********************************************************************************/
#ifndef __TEST_TRAFFIC_DATA_VIA_EP0_H__
#define __TEST_TRAFFIC_DATA_VIA_EP0_H__
#include "attr.h"


/*我这里默认配成64字节，这里可指定的一次读取数据长度原则上可以任意值， 但是考虑到AUDIO驱动中buf资源限制，暂定为0-512bytes。
一次读取长度设置超过512，会被截取前512bytes数据，余下的会丢失*/
#define GET_TRAFFIC_DATA_ONCE_FROM_EP0_LEN 0x40

/*这里上层不能随意修改，这个地址是由AUDIO驱动中的g_ctrl_trans_in_buf地址确定。
用于驱动层存储即将发送到EP0端口的数据buf首地址。目前暂定该buf大小为512bytes*/
//#define CTRL_TRANS_DATA_BUFF_ADDR 0x9fc11200

/*上层不能随意修改，需要与AUDIo驱动层同步*/
//#define CTRL_TRANS_DATA_BUFF_LEN 0x200

//所测试接口的回调函数
//typedef int (*ud_interface_callback)(uint8 *param1, int param2);
//typedef int (*ud_interface_callback)(uint8 *, int);

//typedef void (*isr_cbk)(void);



/*测试从ep0读取数据以及发送到ep0 buf 数据正确性验证*/
extern void test_traffic_data_of_ep0(void)__FAR__;

#endif //__TEST_TRAFFIC_DATA_VIA_EP0_H__
