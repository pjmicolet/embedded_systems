#ifndef __main_h_
#define __main_h_
#include <mqx.h>
#include <bsp.h>
#include "tfs.h"
#include "httpd.h"
#include "fio.h"




#include <rtcs.h>
#ifdef APPLICATION_HAS_SHELL
#include <sh_rtcs.h>
#endif
#include <ipcfg.h>


/* Task ID */

#define MAIN_TASK   			1
#define ALARM_POLL   			2
#define ALARM_1   				3
#define ALARM_2   				4
#define ALARM_3   				5
#define ALARM_4   				6
#define ALARM_1_TIMER   		7
#define ALARM_2_TIMER   		8
#define ALARM_3_TIMER   		9
#define ALARM_4_TIMER   		10


#define ENET_DEVICE 0
#define RTCS_DHCP 0

#define ENET_IPADDR IPADDR(129,215,252,107)
#define ENET_IPMASK IPADDR(255,255,255,0)
#define ENET_GATEWAY IPADDR(129,215,252,252)
#define RTCS_PPP 0

    


extern void Main_task (uint_32);
extern void Alarm_poll (uint_32);
extern void Alarm_1 (uint_32);
extern void Alarm_2 (uint_32);
extern void Alarm_3 (uint_32);
extern void Alarm_4 (uint_32);
extern void Alarm_1_Timer (uint_32);
extern void Alarm_2_Timer (uint_32);
extern void Alarm_3_Timer (uint_32);
extern void Alarm_4_Timer (uint_32);



void rtcs_init(void);

_mqx_int get_rtc_callback(HTTPD_SESSION_STRUCT*);
_mqx_int set_rtc_callback(HTTPD_SESSION_STRUCT*);
_mqx_int set_alarm_callback(HTTPD_SESSION_STRUCT*);
_mqx_int led_callback(HTTPD_SESSION_STRUCT*);
_mqx_int set_hush(HTTPD_SESSION_STRUCT*);
_mqx_int toggle_alarm_callback(HTTPD_SESSION_STRUCT *);
void button_alarm_trigger(void*);
void button_release(void*);
void button_alarm_toggle_enable(void *);
void button_alarm_hush(void *);


/* PPP device must be set manually and 
** must be different from the default IO channel (BSP_DEFAULT_IO_CHANNEL) 
*/
#define PPP_DEVICE      "ittyb:" 

/*
** Define PPP_DEVICE_DUN only when using PPP to communicate
** to Win9x Dial-Up Networking over a null-modem
** This is ignored if PPP_DEVICE is not #define'd
*/
#define PPP_DEVICE_DUN  1

/*
** Define the local and remote IP addresses for the PPP link
** These are ignored if PPP_DEVICE is not #define'd
*/
#define PPP_LOCADDR     IPADDR(192,168,0,216)
#define PPP_PEERADDR    IPADDR(192,168,0,217)

/*
** Define a default gateway
*/
#define GATE_ADDR       IPADDR(192,168,0,1)

#endif /* __main_h_ */

