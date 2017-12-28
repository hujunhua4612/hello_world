>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
# hello_world
learn git hub at the first time at 2017-12-27
i do not know what you say, i just do it acctording to the text!
thank you for your idea!
my name is hujunhua, i just learn it now!
thank you 
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


typedef enum
{
    CMD_GET_STATUS = 0, //sratus
    CMD_INIT, //init start
    CMD_EXIT, //init exit
    CMD_SET_CFG, //some config data set
    CMD_GET_INFO,//iso data get use
    CMD_SET_INFO,//iso data set use
    CMD_SET_CMD, //can be extension
    CMD_HID_DEAL,
#ifdef SUPPORT_TRAFFIC_DATA_VIA_EP0
    CMD_GET_CTRL_DATA,
    CMD_SET_CTRL_DATA,
#endif
//hid deal
} ud_cmd_e;

typedef struct
{
    ud_op_i get_stauts;
    ud_op_i module_start;
    ud_op_i module_stop;
    ud_op_i set_config;
    ud_op_i get_info;
    ud_op_i set_info;
    ud_op_i set_cmd;
    ud_op_i hid_deal;
#ifdef SUPPORT_TRAFFIC_DATA_VIA_EP0
    ud_op_i get_ctrl_data;
    ud_op_i set_ctrl_data;
#endif
} usound_operations_t;//audio up and down or audio down only


typedef struct
{
    ud_op_i get_stauts;
    ud_op_i module_start;
    ud_op_i module_stop;
    ud_op_i set_config;
    ud_op_i msc_send;
    ud_op_i msc_recive;
    ud_op_i set_cmd;
    ud_op_i msc_deal;
} ureader_operations_t;

typedef struct
{
    ud_op_i get_stauts;
    ud_op_i module_start;
    ud_op_i module_stop;
    ud_op_i set_config;
    ud_op_i hid_get;
    ud_op_i hid_set;
    ud_op_i set_cmd;
    ud_op_i hid_deal;
} uhid_operations_t;

//for comunication
typedef struct
{
    uint8 set_sample;//sample flag
    uint8 set_adc_sample;//adc sample flag
    uint8 set_dac_sample;//dac sample flag
    uint8 no_empty_fla;
    uint8 data_in_flag;
    uint16 line_sta;//if is insert
    uint16 switch_flag;//if need switch_to stub 
    uint32 sample_rate;//rate
    uint32 adc_sample_rate;//adc rate
    uint32 dac_sample_rate;//dac rate
    uint32 start_play;//if is start play
    uint32 start_record;//if is start record
    uint32 volume_chg;//if voluem syn
    uint32 volume_value;//syn volume value
    uint32 hid_idle_time;//hid idle time
    uint32 uspeaker24_energy;
} usound_status_t;

//for comunication
typedef struct
{
    uint32 line_sta;//if is insert
    uint32 card_sta;//if card is exist
    uint32 suspend_flag;//if is suspend now
    uint32 switch_to_adfu;//need to switch toa adfu
    uint32 reset_count;//reset times
    uint32 remove_card;//need remove card
    uint32 pop_out;
} ureader_status_t;



123456789
abcdefghijklmnopqrstuvwxyz


this is test for brancher,so i added this line!
