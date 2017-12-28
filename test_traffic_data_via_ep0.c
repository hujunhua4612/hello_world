/*******************************************************************************
 *                              US211A
 *                            Module: music engine
 *                 Copyright(c) 2003-2011 Actions Semiconductor,
 *                            All Rights Reserved.
 *
 * History:
 *      <author>        <time>           <version >            <desc>
 *     hujunhua     2017-12-16 11:00     1.0             build this file
 *******************************************************************************/
#include "test_traffic_data_via_ep0.h"
#include "libc_interface.h"
#include "ud_interface.h"
#include "kernel_interface.h"

uint8 temp_ctrl_trans_buf[GET_TRAFFIC_DATA_ONCE_FROM_EP0_LEN] = {0};
int g_test_dat_len = 0;


void test_ud_set_traffic_data_interface(void)
{
    int ret_dat_len = 0;

    //check param0: NULL
    ret_dat_len = (int)ud_set_traffic_data_to_ep0(NULL,sizeof(temp_ctrl_trans_buf));
    if (-1 == ret_dat_len)
    {
        libc_print("CHECK SUCCES1!\n",0,0);
    }
    else
    {
        libc_print("CHECK ERROR1: param0 is null!\n",0,0);
    }

    //check param1: -1
    ret_dat_len = (int)ud_set_traffic_data_to_ep0(temp_ctrl_trans_buf,-1);
    if (-1 == ret_dat_len)
    {
        libc_print("CHECK SUCCES1!\n",0,0);
    }
    else
    {
        libc_print("CHECK ERROR1: param1 is -1!\n",0,0);
    }

    //check param1: 0
    ret_dat_len = (int)ud_set_traffic_data_to_ep0(temp_ctrl_trans_buf,0);
    if (-1 == ret_dat_len)
    {
        libc_print("CHECK SUCCES1!\n",0,0);
    }
    else
    {
        libc_print("CHECK ERROR1: param1 is 0!\n",0,0);
    }

    //check param1: > 64
    ret_dat_len = (int)ud_set_traffic_data_to_ep0(temp_ctrl_trans_buf,100);
    if (100 == ret_dat_len)
    {
        libc_print("CHECK SUCCES1!\n",0,0);
    }
    else
    {
        libc_print("CHECK ERROR1: param1 is 100!\n",0,0);
    }

    //check param1: > 512
    ret_dat_len = (int)ud_set_traffic_data_to_ep0(temp_ctrl_trans_buf,1000);
    if (512 == ret_dat_len)
    {
        libc_print("CHECK SUCCES1!\n",0,0);
    }
    else
    {
        libc_print("CHECK ERROR1: param1 is 1000!\n",0,0);
    }

    //���ｫ��PC���߻����ⲿ�豸�����������ݣ���д��PC���߻����ⲿ�豸���ж϶�д�����Ƿ�һ��
    //�������ݳ��ȣ��������ó����ȡ���ݳ���һ�¡�����׺в��ԡ�������ʲô���ݣ��Ͷ���ȥʲô���ݽ��а׺в���
    ret_dat_len = (int)ud_set_traffic_data_to_ep0(temp_ctrl_trans_buf,g_test_dat_len);

}


int test_ud_get_traffic_data_interface(void)
{
    int ret_dat_len = 0;

    //��������ͨ����ǰ��λ��
    ud_set_cmd(BACKUP_TRAFFIC_DATA_CURRENT_READ_POS, 0); 
    
    //check param1: > 512
    ret_dat_len = (int)ud_get_traffic_data_from_ep0(temp_ctrl_trans_buf,1000);
    if (ret_dat_len > 0) //ֻ������ЧԴ�����ˣ��ŻῪʼ�׺в���
    {
        //�ָ�����ͨ����ǰ��λ��
        ud_set_cmd(RESTORE_TRAFFIC_DATA_CURRENT_READ_POS, 0);

        //check param0 : NULL
        ret_dat_len = (int)ud_get_traffic_data_from_ep0(NULL,sizeof(temp_ctrl_trans_buf));
        if (-1 == ret_dat_len)
        {
            libc_print("CHECK SUCCES!\n",0,0);
        }
        else
        {
            libc_print("CHECK ERROR: param0 is null!\n",0,0);
        }

        //check param1: -1
        ret_dat_len = (int)ud_get_traffic_data_from_ep0(temp_ctrl_trans_buf,-1);
        if (-1 == ret_dat_len)
        {
            libc_print("CHECK SUCCES!\n",0,0);
        }
        else
        {
            libc_print("CHECK ERROR: param1 is -1!\n",0,0);
        }
    
        //check param1: 0
        ret_dat_len = (int)ud_get_traffic_data_from_ep0(temp_ctrl_trans_buf,0);
        if (-1 == ret_dat_len)
        {
            libc_print("CHECK SUCCES!\n",0,0);
        }
        else
        {
            libc_print("CHECK ERROR: param1 is 0!\n",0,0);
        }
        
        //check param1: GET_TRAFFIC_DATA_ONCE_FROM_EP0_LEN
        ret_dat_len = (int)ud_get_traffic_data_from_ep0(temp_ctrl_trans_buf,sizeof(temp_ctrl_trans_buf));
        g_test_dat_len = ret_dat_len; //�����������ڲ��Ե����ݳ���

        return 0;
    }
    else
    {
        return -1;
    }
}

//���Դ�ep0��ȡ�����Լ����͵�ep0 buf ������ȷ����֤
void test_traffic_data_of_ep0(void)
{
    //�Ȳ��Խ������ݹ���
    if (test_ud_get_traffic_data_interface() == 0) //����Ч�����ˣ��ż����׺в���
    {
        //�ٲ���С���������ݹ���
        test_ud_set_traffic_data_interface();
    }
}
