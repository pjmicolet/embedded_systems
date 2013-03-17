/**HEADER*******************************************************************
 * 
 * Copyright (c) 2008 Freescale Semiconductor;
 * All Rights Reserved
 *
 * Copyright (c) 1989-2008 ARC International;
 * All Rights Reserved
 *
 **************************************************************************** 
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
 * IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************
 *
 * Comments:
 *
 *   This file contains main initialization for your application
 *   and infinite loop
 *
 *END************************************************************************/

#include "main.h"

/*
 * Variables
 */
// Part 2 
static char html[] = "<html>\
	Trigger LEDs</br>\
	<script>\
		function testingOut(id){\
			var item = document.getElementById(id);\
			if(item.id == 'led' || item.id == 'led2' || item.id == 'led3' || item.id=='led4'){\
				quickie = window.open('led.cgi?'+item.value,'_blank', false);\
				quickie.close();\
			}\
			else if(item.id == 'time'){\
				quickie = window.open('set_rtc.cgi?'+item.value, '_blank', false);\
			}\
			else if(item.id == 'gtime'){\
				quickie = window.open('get_rtc.cgi?', '_blank', false);\
			}\
			else if(item.id == 'hush'){\
				quickie = window.open('set_hush.cgi?', '_blank', false);\
				quickie.close();\
			}\
			else if(item.id == 'turn_on'){\
				quickie = window.open('toggle.cgi?', '_blank', false);\
				quickie.close();\
			}\
			else if (item.id =='utime1'){\
				quickie = window.open('set_alarm.cgi?led=1&time='+item.value+'&on=1','_blank', false);\
				time = document.getElementById('utext1');\
				time.innerHTML = item.value;\
			}\
			else if (item.id =='otime1'){\
				quickie = window.open('set_alarm.cgi?led=1&time='+item.value+'&on=0','_blank', false);\
				time = document.getElementById('otext1');\
				time.innerHTML = item.value;\
			}\
			else if (item.id =='utime2'){\
				quickie = window.open('set_alarm.cgi?led=2&time='+item.value+'&on=1','_blank', false);\
				time = document.getElementById('utext2');\
				time.innerHTML = item.value;\
			}\
			else if (item.id =='otime2'){\
				quickie = window.open('set_alarm.cgi?led=2&time='+item.value+'&on=0','_blank', false);\
				time = document.getElementById('otext2');\
				time.innerHTML = item.value;\
			}\
			else if (item.id =='utime3'){\
				quickie = window.open('set_alarm.cgi?led=3&time='+item.value+'&on=1','_blank', false);\
				time = document.getElementById('utext3');\
				time.innerHTML = item.value;\
			}\
			else if (item.id =='otime3'){\
				quickie = window.open('set_alarm.cgi?led=3&time='+item.value+'&on=0','_blank', false);\
				time = document.getElementById('otext3');\
				time.innerHTML = item.value;\
			}\
			else if (item.id =='utime4'){\
				quickie = window.open('set_alarm.cgi?led=4&time='+item.value+'&on=1','_blank', false);\
				time = document.getElementById('utext4');\
				time.innerHTML = item.value;\
			}\
			else if (item.id =='otime4'){\
				quickie = window.open('set_alarm.cgi?led=4&time='+item.value+'&on=0','_blank', false);\
				time = document.getElementById('otext4');\
				time.innerHTML = item.value;\
			}\
		}\
	</script>\
	Toggle Alarms:\
	<input type='submit' onclick='testingOut(this.id)' id='led' value='1'>\
	<input type='submit' onclick='testingOut(this.id)' id='led2' value='2'>\
	<input type='submit' onclick='testingOut(this.id)' id='led3' value='3'>\
	<input type='submit' onclick='testingOut(this.id)' id='led4' value='4'> </br>\
	<input type='submit' onclick='testingOut(this.id)' id='hush' value='Hush'></br>\
	<input type='submit' onclick='testingOut(this.id)' id='turn_on' value='Toggle Alarm'> </br>\
	Alarm 1 On <b id='utext1'>00:00:00</b> Off <b id='otext1'>00:00:00</b> </br>\
	Alarm 2 On <b id='utext2'>00:00:00</b> Off <b id='otext2'>00:00:00</b> </br>\
	Alarm 3 On <b id='utext3'>00:00:00</b> Off <b id='otext3'>00:00:00</b> </br>\
	Alarm 4 On <b id='utext4'>00:00:00</b> Off <b id='otext4'>00:00:00</b> </br>\
	Change Alarm 1 Times:</br>\
	On <input type='text' id='utime1'> <input type='submit' value='Set Time' onclick='testingOut(utime1.id)'><br>\
	Off <input type='text' id='otime1'> <input type='submit' value='Set Time' onclick='testingOut(otime1.id)'><br>\
	Change Alarm 2 Times:</br>\
	On <input type='text' id='utime2'> <input type='submit' value='Set Time' onclick='testingOut(utime2.id)'><br>\
	Off <input type='text' id='otime2'> <input type='submit' value='Set Time' onclick='testingOut(otime2.id)'><br>\
	Change Alarm 3 Times:</br>\
	On <input type='text' id='utime3'> <input type='submit' value='Set Time' onclick='testingOut(utime3.id)'><br>\
	Off <input type='text' id='otime3'> <input type='submit' value='Set Time' onclick='testingOut(otime3.id)'><br>\
	Change Alarm 4 Times:</br>\
	On <input type='text' id='utime4'> <input type='submit' value='Set Time' onclick='testingOut(utime4.id)'><br>\
	Off <input type='text' id='otime4'> <input type='submit' value='Set Time' onclick='testingOut(otime4.id)'><br>\
	Set time: <input type='text' id='time'> <input type='submit' value='Set Time' onclick='testingOut(time.id)'></br>\
	<input type='submit' value='Get time' id='gtime' onclick='testingOut(this.id)'></br>\
\
</br>\
</html>";
const TFS_DIR_ENTRY static_data[] = { {"/index.html", 0, (unsigned char*) html, sizeof(html) }, {0, 0, 0, 0} };
static HTTPD_ROOT_DIR_STRUCT http_root_dir[] = { {"","tfs:"}, {0, 0} };
HTTPD_STRUCT* http_server;

// Part 3
HMI_CLIENT_STRUCT_PTR hmi_client;
static HTTPD_CGI_LINK_STRUCT http_cgi_params[] = 
{ 
		{ "led", led_callback},
		{ "set_hush", set_hush},
		{ "toggle", toggle_alarm_callback},
		{ "get_rtc", get_rtc_callback},
		{ "set_rtc", set_rtc_callback},
		{ "set_alarm", set_alarm_callback},
		{0,0} 
};

RTC_TIME_STRUCT time;
char buffer[32];
int seconds, minutes, hours;

// Alarm variables
uint_8 		masterAlarmEnable;
uint_8 		alarmEnable[4];
uint_8		alarmTrigger[4];
uint_8 		requestOn[4];
uint_8 		requestOff[4];

RTC_TIME_STRUCT alarmTimeOn[4];
RTC_TIME_STRUCT alarmTimeOff[4];

_task_id	alarm_poll_id;
_task_id	alarm_1_id;
_task_id	alarm_2_id;
_task_id	alarm_3_id;
_task_id	alarm_4_id;
_task_id	alarm_1_timer_id;
_task_id	alarm_2_timer_id;
_task_id	alarm_3_timer_id;
_task_id	alarm_4_timer_id;

/*
 * Functions
 */

_mqx_int set_alarm_callback(HTTPD_SESSION_STRUCT *session)
{
	int led = 0;
	int on = 0;
	httpd_sendstr(session->sock, "<html><body>set_alarm_callback</br></body></html>");
	sscanf(session->request.urldata, "led=%u&time=%u:%u:%u&on=%u",&led, &hours, &minutes, &seconds, &on);
	sprintf(buffer, "%u %u:%u:%u %u\n", led, (hours), (minutes), (seconds), on);
	httpd_sendstr(session->sock, buffer);
	if(on)
	{
		alarmTimeOn[led - 1].seconds = hours*3600 + minutes*60 + seconds;
		requestOn[led - 1] = 1;
	}
	else
	{
		alarmTimeOff[led - 1].seconds = hours*3600 + minutes*60 + seconds;
		requestOff[led - 1] = 1;
	}
	return session->request.content_len;
}

_mqx_int get_rtc_callback(HTTPD_SESSION_STRUCT *session)
{
	httpd_sendstr(session->sock, "<html><body>get_rtc_callback</br></body></html>");
	_rtc_get_time(&time);
	minutes = time.seconds / 60;
	hours = minutes / 60;
	sprintf(buffer, "%u:%u:%u\n", (hours), (minutes % 60), (time.seconds % 60));
	httpd_sendstr(session->sock, buffer);
	return session->request.content_len;
}

_mqx_int set_rtc_callback(HTTPD_SESSION_STRUCT *session)
{
	httpd_sendstr(session->sock, "<html><body>set_rtc_callback</br></body></html>");
	sscanf(session->request.urldata, "%u:%u:%u", &hours, &minutes, &seconds);
	time.seconds = hours*3600 + minutes*60 + seconds;
	_rtc_set_time(&time);
	return session->request.content_len;
}

_mqx_int led_callback(HTTPD_SESSION_STRUCT *session)
{
	int led = atoi(session->request.urldata);
	httpd_sendstr(session->sock, "<html><body>Alarm toggle</body></html>");
	alarmEnable[led - 1] = ~ alarmEnable[led - 1];
	alarmTrigger[led - 1] = 0;
	btnled_toogle(hmi_client, HMI_GET_LED_ID(led));
	return session->request.content_len;
}

_mqx_int set_hush(HTTPD_SESSION_STRUCT *session)
{
	httpd_sendstr(session->sock, "<html><body>Hush </body></html>");
	if(alarmEnable[0])
	{
		alarmTrigger[0] = 0;
		btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_ON);
	}
	if(alarmEnable[1])
	{
		alarmTrigger[1] = 0;
		btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_ON);
	}	
	if(alarmEnable[2])
	{
		alarmTrigger[2] = 0;
		btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_ON);
	}	
	if(alarmEnable[3])
	{
		alarmTrigger[3] = 0;
		btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_ON);
	}
	return session->request.content_len;
}

_mqx_int toggle_alarm_callback(HTTPD_SESSION_STRUCT *session)
{
	httpd_sendstr(session->sock, "<html><body>Toggle Alarm #yolo </body></html>");

	if(masterAlarmEnable) // Disable alarm
	{	
		alarmEnable[0] = 0;
		alarmEnable[1] = 0;
		alarmEnable[2] = 0;
		alarmEnable[3] = 0;
		alarmTrigger[0] = 0;
		alarmTrigger[1] = 0;
		alarmTrigger[2] = 0;
		alarmTrigger[3] = 0;
		btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_OFF);
		btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_OFF);
		btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_OFF);
		btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_OFF);
	}
	else // Enable alarm
	{
		alarmEnable[0] = 1;
		alarmEnable[1] = 1;
		alarmEnable[2] = 1;
		alarmEnable[3] = 1;
		alarmTrigger[0] = 0;
		alarmTrigger[1] = 0;
		alarmTrigger[2] = 0;
		alarmTrigger[3] = 0;
		btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_ON);
		btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_ON);
		btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_ON);
		btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_ON);
	}
	masterAlarmEnable = ~masterAlarmEnable;
	return session->request.content_len;

}

void button_alarm_trigger(void *ptr)
{
	if(alarmEnable[(int) ptr])
	{
		if(alarmTrigger[(int) ptr] == 0)
		{
			alarmTrigger[(int) ptr] = 1;
		}
	}
}

void button_alarm_toggle_enable(void *ptr)
{
	if(masterAlarmEnable) // Disable alarm
	{	
		alarmEnable[0] = 0;
		alarmEnable[1] = 0;
		alarmEnable[2] = 0;
		alarmEnable[3] = 0;
		alarmTrigger[0] = 0;
		alarmTrigger[1] = 0;
		alarmTrigger[2] = 0;
		alarmTrigger[3] = 0;
		btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_OFF);
		btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_OFF);
		btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_OFF);
		btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_OFF);
	}
	else // Enable alarm
	{
		alarmEnable[0] = 1;
		alarmEnable[1] = 1;
		alarmEnable[2] = 1;
		alarmEnable[3] = 1;
		alarmTrigger[0] = 0;
		alarmTrigger[1] = 0;
		alarmTrigger[2] = 0;
		alarmTrigger[3] = 0;
		btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_ON);
		btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_ON);
		btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_ON);
		btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_ON);
	}
	masterAlarmEnable = ~masterAlarmEnable;
}

void button_alarm_hush(void *ptr)
{	
	if(alarmEnable[0])
	{
		alarmTrigger[0] = 0;
		btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_ON);
	}
	if(alarmEnable[1])
	{
		alarmTrigger[1] = 0;
		btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_ON);
	}	
	if(alarmEnable[2])
	{
		alarmTrigger[2] = 0;
		btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_ON);
	}	
	if(alarmEnable[3])
	{
		alarmTrigger[3] = 0;
		btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_ON);
	}
}

TASK_TEMPLATE_STRUCT MQX_template_list[] =
{
		/*  Task number, Entry point, Stack, Pri, String, Auto? */
		{MAIN_TASK,   Main_task,   2000,  9,   "main", MQX_AUTO_START_TASK},
		{ALARM_POLL,   Alarm_poll,   2000,  8,   "alarm_poll", 0},
		{ALARM_1,   Alarm_1,   2000,  7,   "alarm_1", 0},
		{ALARM_2,   Alarm_2,   2000,  7,   "alarm_2", 0},
		{ALARM_3,   Alarm_3,   2000,  7,   "alarm_3", 0},
		{ALARM_4,   Alarm_4,   2000,  7,   "alarm_4", 0},
		{ALARM_1_TIMER,   Alarm_1_Timer,   2000,  7,   "alarm_1_timer", 0},
		{ALARM_2_TIMER,   Alarm_2_Timer,   2000,  7,   "alarm_2_timer", 0},
		{ALARM_3_TIMER,   Alarm_3_Timer,   2000,  7,   "alarm_3_timer", 0},
		{ALARM_4_TIMER,   Alarm_4_Timer,   2000,  7,   "alarm_4_timer", 0},
		{0,           0,           0,     0,   0,      0,                 }
};

/*TASK*-----------------------------------------------------------------
 *
 * Function Name  : Main_task
 * Comments       :
 *    This task initializes MFS and starts SHELL.
 *
 *END------------------------------------------------------------------*/

void Main_task(uint_32 initial_data)
{
	/* HMI init*/
	hmi_client = _bsp_btnled_init();
	/* Real Time Clock init */
	_rtc_init(RTC_INIT_FLAG_ENABLE);
	/* RTCS init */
	rtcs_init();

	_io_tfs_install("tfs:", static_data);
	http_server = httpd_server_init_af(http_root_dir, "\\index.html", AF_INET);
	httpd_server_run(http_server);     

	HTTPD_SET_PARAM_CGI_TBL(http_server, http_cgi_params);

	/* Variable init */
	masterAlarmEnable = 0;
	alarmEnable[0] = 0;
	alarmEnable[1] = 0;
	alarmEnable[2] = 0;
	alarmEnable[3] = 0;
	alarmTrigger[0] = 0;
	alarmTrigger[1] = 0;
	alarmTrigger[2] = 0;
	alarmTrigger[3] = 0;
	requestOn[0] = 0;
	requestOn[1] = 0;
	requestOn[2] = 0;
	requestOn[3] = 0;
	requestOff[0] = 0;
	requestOff[1] = 0;
	requestOff[2] = 0;
	requestOff[3] = 0;
	
	btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_OFF);
	btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_OFF);
	btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_OFF);
	btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_OFF);

	alarm_poll_id 		= _task_create(0, ALARM_POLL, 0);
	alarm_1_id			= _task_create(0, ALARM_1, 0);
	alarm_2_id			= _task_create(0, ALARM_2, 0);
	alarm_3_id			= _task_create(0, ALARM_3, 0);
	alarm_4_id			= _task_create(0, ALARM_4, 0);
	alarm_1_timer_id	= _task_create(0, ALARM_1_TIMER, 0);
	alarm_2_timer_id	= _task_create(0, ALARM_2_TIMER, 0);
	alarm_3_timer_id	= _task_create(0, ALARM_3_TIMER, 0);
	alarm_4_timer_id	= _task_create(0, ALARM_4_TIMER, 0);
	
	/*******************************
	 * 
	 * START YOUR CODING HERE
	 *
	 ********************************/   

	for (;;)
	{
		btnled_poll(hmi_client);
		// Poll the ethernet
		ipcfg_task_poll();
		_time_delay(10);
	}
}

void Alarm_poll(uint_32 initial_data)
{
	btnled_add_clb(hmi_client, HMI_BUTTON_5, HMI_VALUE_PUSH, button_alarm_toggle_enable, NULL);
	btnled_add_clb(hmi_client, HMI_BUTTON_6, HMI_VALUE_PUSH, button_alarm_hush, NULL);
}

void Alarm_1(uint_32 initial_data)
{
	btnled_add_clb(hmi_client, HMI_BUTTON_1, HMI_VALUE_PUSH, button_alarm_trigger,(void*) 0);
	while(1)
	{
		_time_delay(50);
		if(alarmTrigger[0])
		{
			btnled_toogle(hmi_client, HMI_LED_1);
		}
	}
}

void Alarm_2(uint_32 initial_data)
{
	btnled_add_clb(hmi_client, HMI_BUTTON_2, HMI_VALUE_PUSH, button_alarm_trigger,(void*) 1);
	while(1)
	{
		_time_delay(50);
		if(alarmTrigger[1])
		{
			btnled_toogle(hmi_client, HMI_LED_2);
		}
	}
}

void Alarm_3(uint_32 initial_data)
{
	btnled_add_clb(hmi_client, HMI_BUTTON_3, HMI_VALUE_PUSH, button_alarm_trigger,(void*) 2);
	while(1)
	{
		_time_delay(50);
		if(alarmTrigger[2])
		{
			btnled_toogle(hmi_client, HMI_LED_3);
		}
	}
}

void Alarm_4(uint_32 initial_data)
{
	btnled_add_clb(hmi_client, HMI_BUTTON_4, HMI_VALUE_PUSH, button_alarm_trigger,(void*) 3);
	while(1)
	{
		_time_delay(50);
		if(alarmTrigger[3])
		{
			btnled_toogle(hmi_client, HMI_LED_4);
		}
	}
}

void Alarm_1_Timer(uint_32 initial_data)
{
	while(1)
	{
		_time_delay(50);
		if(requestOn[0])
		{
			_rtc_get_time(&time);
			if(time.seconds >= alarmTimeOn[0].seconds)
			{
				alarmEnable[0] = 1;
				alarmTrigger[0] = 0;
				btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_ON);
				requestOn[0] = 0;
			}
		}		
		if(requestOff[0])
		{
			_rtc_get_time(&time);
			if(time.seconds >= alarmTimeOff[0].seconds)
			{
				alarmEnable[0] = 0;
				alarmTrigger[0] = 0;
				btnled_set_value(hmi_client, HMI_LED_1, HMI_VALUE_OFF);
				requestOff[0] = 0;
			}
		}
	}
}


void Alarm_2_Timer(uint_32 initial_data)
{
	while(1)
	{
		_time_delay(50);
		if(requestOn[1])
		{
			_rtc_get_time(&time);
			if(time.seconds >= alarmTimeOn[1].seconds)
			{
				alarmEnable[1] = 1;
				alarmTrigger[1] = 0;
				btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_ON);
				requestOn[1] = 0;
			}
		}
		if(requestOff[1])
		{
			_rtc_get_time(&time);
			if(time.seconds >= alarmTimeOff[1].seconds)
			{
				alarmEnable[1] = 0;
				alarmTrigger[1] = 0;
				btnled_set_value(hmi_client, HMI_LED_2, HMI_VALUE_OFF);
				requestOff[1] = 0;
			}
		}
	}
}

void Alarm_3_Timer(uint_32 initial_data)
{
	while(1)
	{
		_time_delay(50);
		if(requestOn[2])
		{
			_rtc_get_time(&time);
			if(time.seconds >= alarmTimeOn[2].seconds)
			{
				alarmEnable[2] = 1;
				alarmTrigger[2] = 0;
				btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_ON);
				requestOn[2] = 0;
			}
		}		
		if(requestOff[2])
		{
			_rtc_get_time(&time);
			if(time.seconds >= alarmTimeOff[2].seconds)
			{
				alarmEnable[2] = 0;
				alarmTrigger[2] = 0;
				btnled_set_value(hmi_client, HMI_LED_3, HMI_VALUE_OFF);
				requestOff[2] = 0;
			}
		}
	}
}

void Alarm_4_Timer(uint_32 initial_data)
{
	while(1)
	{
		_time_delay(50);
		if(requestOn[3])
		{
			_rtc_get_time(&time);
			if(time.seconds >= alarmTimeOn[3].seconds)
			{
				alarmEnable[3] = 1;
				alarmTrigger[3] = 0;
				btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_ON);
				requestOn[3] = 0;
			}
		}
		if(requestOff[3])
		{
			_rtc_get_time(&time);
			if(time.seconds >= alarmTimeOff[3].seconds)
			{
				alarmEnable[3] = 0;
				alarmTrigger[3] = 0;
				btnled_set_value(hmi_client, HMI_LED_4, HMI_VALUE_OFF);
				requestOff[3] = 0;
			}
		}
	}
}


/* EOF */
