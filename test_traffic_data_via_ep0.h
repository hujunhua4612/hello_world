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


/*������Ĭ�����64�ֽڣ������ָ����һ�ζ�ȡ���ݳ���ԭ���Ͽ�������ֵ�� ���ǿ��ǵ�AUDIO������buf��Դ���ƣ��ݶ�Ϊ0-512bytes��
һ�ζ�ȡ�������ó���512���ᱻ��ȡǰ512bytes���ݣ����µĻᶪʧ*/
#define GET_TRAFFIC_DATA_ONCE_FROM_EP0_LEN 0x40

/*�����ϲ㲻�������޸ģ������ַ����AUDIO�����е�g_ctrl_trans_in_buf��ַȷ����
����������洢�������͵�EP0�˿ڵ�����buf�׵�ַ��Ŀǰ�ݶ���buf��СΪ512bytes*/
//#define CTRL_TRANS_DATA_BUFF_ADDR 0x9fc11200

/*�ϲ㲻�������޸ģ���Ҫ��AUDIo������ͬ��*/
//#define CTRL_TRANS_DATA_BUFF_LEN 0x200

//�����ԽӿڵĻص�����
//typedef int (*ud_interface_callback)(uint8 *param1, int param2);
//typedef int (*ud_interface_callback)(uint8 *, int);

//typedef void (*isr_cbk)(void);



/*���Դ�ep0��ȡ�����Լ����͵�ep0 buf ������ȷ����֤*/
extern void test_traffic_data_of_ep0(void)__FAR__;

#endif //__TEST_TRAFFIC_DATA_VIA_EP0_H__
