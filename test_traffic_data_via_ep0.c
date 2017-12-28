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

    //这里将从PC工具或者外部设备读过来的数据，再写回PC工具或者外部设备，判断读写数据是否一样
    //设置数据长度，这里设置成与读取数据长度一致。方便白盒测试。即发送什么数据，就读回去什么数据进行白盒测试
    ret_dat_len = (int)ud_set_traffic_data_to_ep0(temp_ctrl_trans_buf,g_test_dat_len);

}


int test_ud_get_traffic_data_interface(void)
{
    int ret_dat_len = 0;

    //备份数据通道当前读位置
    ud_set_cmd(BACKUP_TRAFFIC_DATA_CURRENT_READ_POS, 0); 
    
    //check param1: > 512
    ret_dat_len = (int)ud_get_traffic_data_from_ep0(temp_ctrl_trans_buf,1000);
    if (ret_dat_len > 0) //只有有有效源数据了，才会开始白盒测试
    {
        //恢复数据通道当前读位置
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
        g_test_dat_len = ret_dat_len; //保存现在正在测试的数据长度

        return 0;
    }
    else
    {
        return -1;
    }
}

//测试从ep0读取数据以及发送到ep0 buf 数据正确性验证
void test_traffic_data_of_ep0(void)
{
    //先测试接收数据功能
    if (test_ud_get_traffic_data_interface() == 0) //有有效数据了，才继续白盒测试
    {
        //再测试小机发送数据功能
        test_ud_set_traffic_data_interface();
    }
}
