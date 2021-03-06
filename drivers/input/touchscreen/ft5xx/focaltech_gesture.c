/*
 *
 * FocalTech fts TouchScreen driver.
 * 
 * Copyright (c) 2010-2015, Focaltech Ltd. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

 /*******************************************************************************
*
* File Name: Focaltech_Gestrue.c
*
* Author: Xu YongFeng
*
* Created: 2015-01-29
*   
* Modify by mshl on 2015-07-06
*
* Abstract:
*
* Reference:
*
*******************************************************************************/

/*******************************************************************************
* 1.Included header files
*******************************************************************************/
#include "focaltech_core.h"

/*******************************************************************************
* Private constant and macro definitions using #define
*******************************************************************************/
#define  KEY_GESTURE_U		KEY_U
#define  KEY_GESTURE_UP		KEY_UP
#define  KEY_GESTURE_DOWN		KEY_DOWN
#define  KEY_GESTURE_LEFT		KEY_LEFT 
#define  KEY_GESTURE_RIGHT		KEY_RIGHT
#define  KEY_GESTURE_O		KEY_O
#define  KEY_GESTURE_E		KEY_E
#define  KEY_GESTURE_M		KEY_M 
#define  KEY_GESTURE_L		KEY_L
#define  KEY_GESTURE_W		KEY_W
#define  KEY_GESTURE_S		KEY_S 
#define  KEY_GESTURE_V		KEY_V
#define  KEY_GESTURE_Z		KEY_Z

#define GESTURE_LEFT		0x20
#define GESTURE_RIGHT		0x21
#define GESTURE_UP		    0x22
#define GESTURE_DOWN		0x23
#define GESTURE_DOUBLECLICK	0x24
#define GESTURE_O		    0x30
#define GESTURE_W		    0x31
#define GESTURE_M		    0x32
#define GESTURE_E		    0x33
#define GESTURE_C		    0x34
#define GESTURE_L		    0x44
#define GESTURE_S		    0x46
#define GESTURE_V		    0x54
#define GESTURE_Z		    0x41
#define FTS_GESTRUE_POINTS 255
#define FTS_GESTRUE_POINTS_ONETIME  62
#define FTS_GESTRUE_POINTS_HEADER 8
#define FTS_GESTURE_OUTPUT_ADRESS 0xD3
#define FTS_GESTURE_OUTPUT_UNIT_LENGTH 4

/*******************************************************************************
* Private enumerations, structures and unions using typedef
*******************************************************************************/


/*******************************************************************************
* Static variables
*******************************************************************************/
short pointnum = 0;
unsigned short coordinate_x[150] = {0};
unsigned short coordinate_y[150] = {0};

/*******************************************************************************
* Global variable or extern global variabls/functions
*******************************************************************************/

/*******************************************************************************
* Static function prototypes
*******************************************************************************/


/*******************************************************************************
* Name: fts_Gesture_init
* Brief:
* Input:
* Output: None
* Return: None
*******************************************************************************/
/*int fts_Gesture_init(struct input_dev *input_dev)
{
	input_set_capability(input_dev, EV_KEY, KEY_POWER);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_U); 
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_UP); 
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_DOWN);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_LEFT); 
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_RIGHT); 
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_O);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_E); 
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_M); 
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_L);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_W);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_S); 
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_V);
	input_set_capability(input_dev, EV_KEY, KEY_GESTURE_Z);
		
	__set_bit(KEY_GESTURE_RIGHT, input_dev->keybit);
	__set_bit(KEY_GESTURE_LEFT, input_dev->keybit);
	__set_bit(KEY_GESTURE_UP, input_dev->keybit);
	__set_bit(KEY_GESTURE_DOWN, input_dev->keybit);
	__set_bit(KEY_GESTURE_U, input_dev->keybit);
	__set_bit(KEY_GESTURE_O, input_dev->keybit);
	__set_bit(KEY_GESTURE_E, input_dev->keybit);
	__set_bit(KEY_GESTURE_M, input_dev->keybit);
	__set_bit(KEY_GESTURE_W, input_dev->keybit);
	__set_bit(KEY_GESTURE_L, input_dev->keybit);
	__set_bit(KEY_GESTURE_S, input_dev->keybit);
	__set_bit(KEY_GESTURE_V, input_dev->keybit);
	__set_bit(KEY_GESTURE_Z, input_dev->keybit);

	return 0;
}*/

/*******************************************************************************
* Name: fts_check_gesture
* Brief:
* Input:
* Output: None
* Return: None
*******************************************************************************/
/*static void fts_check_gesture(struct input_dev *input_dev,int gesture_id)
{
	switch(gesture_id)
	{
	        case GESTURE_LEFT:
	                input_report_key(input_dev, KEY_GESTURE_LEFT, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_LEFT, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_RIGHT:
	                input_report_key(input_dev, KEY_GESTURE_RIGHT, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_RIGHT, 0);
	                input_sync(input_dev);
			    break;
	        case GESTURE_UP:
	                input_report_key(input_dev, KEY_GESTURE_UP, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_UP, 0);
	                input_sync(input_dev);                                  
	                break;
	        case GESTURE_DOWN:
	                input_report_key(input_dev, KEY_GESTURE_DOWN, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_DOWN, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_DOUBLECLICK:
	                input_report_key(input_dev, KEY_GESTURE_U, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_U, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_O:
	                input_report_key(input_dev, KEY_GESTURE_O, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_O, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_W:
	                input_report_key(input_dev, KEY_GESTURE_W, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_W, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_M:
	                input_report_key(input_dev, KEY_GESTURE_M, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_M, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_E:
	                input_report_key(input_dev, KEY_GESTURE_E, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_E, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_L:
	                input_report_key(input_dev, KEY_GESTURE_L, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_L, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_S:
	                input_report_key(input_dev, KEY_GESTURE_S, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_S, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_V:
	                input_report_key(input_dev, KEY_GESTURE_V, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_V, 0);
	                input_sync(input_dev);
	                break;
	        case GESTURE_Z:
	                input_report_key(input_dev, KEY_GESTURE_Z, 1);
	                input_sync(input_dev);
	                input_report_key(input_dev, KEY_GESTURE_Z, 0);
	                input_sync(input_dev);
	                break;
	        default:
	                break;
	}

}*/
//Begin<REQ><><20150910>Add WAKEUP_GESTURE for ft5xx;xiongdajun
#ifdef CONFIG_FT5XX_TGESTURE_FUNCTION
static int fts_check_gesture(int gesture_id)
{
      int result;

	printk("fts gestrue_id: %d\n", gesture_id);
	switch(gesture_id)
	{
	        case GESTURE_LEFT:
                       result = KEY_GESTURE_LEFT;
	                break;
	        case GESTURE_RIGHT:
                       result = KEY_GESTURE_RIGHT;
			    break;
	        case GESTURE_UP:
                    result = KEY_GESTURE_UP;
	                break;
	        case GESTURE_DOWN:
                    result = KEY_GESTURE_DOWN;
	                break;
	        case GESTURE_DOUBLECLICK:
                    result = KEY_GESTURE_U;
	                break;
	        case GESTURE_O:
                    //result = KEY_GESTURE_O;
		    result = 'o';
	                break;
	        case GESTURE_W:
                    result = KEY_GESTURE_W;
	                break;
	        case GESTURE_M:
                    result = 'm';
	                break;
	        case GESTURE_E:
                    result = KEY_GESTURE_E;
	                break;
              case GESTURE_C:
                    result = 'c';
                    break;
	        case GESTURE_L:
                    result = KEY_GESTURE_L;
	                break;
	        case GESTURE_S:
                    result = 's';
	                break;
	        case GESTURE_V:
                    result = KEY_GESTURE_V;
	                break;
	        case GESTURE_Z:
                    result = KEY_GESTURE_Z;
	                break;
	        default:
	                break;
	}
    return result;

}
#endif
//END<REQ><><20150910>Add WAKEUP_GESTURE for ft5xx;xiongdajun
 /************************************************************************
* Name: fts_read_Gestruedata
* Brief: read data from TP register
* Input: no
* Output: no
* Return: fail <0
***********************************************************************/
int fts_read_Gestruedata(void)
{
	unsigned char buf[FTS_GESTRUE_POINTS * 3] = { 0 };
	int ret = -1;
	int i = 0;
	int gestrue_id = 0;

	buf[0] = 0xd3;
	pointnum = 0;

	ret = fts_i2c_read(fts_i2c_client, buf, 1, buf, FTS_GESTRUE_POINTS_HEADER);

	if (ret < 0)
	{
		printk( "%s read touchdata failed.\n", __func__);
		return ret;
	}

	 if (fts_updateinfo_curr.CHIP_ID==0x54 || fts_updateinfo_curr.CHIP_ID==0x58 || fts_updateinfo_curr.CHIP_ID==0x86)
	 {
		 gestrue_id = buf[0];
		 pointnum = (short)(buf[1]) & 0xff;
		 buf[0] = 0xd3;

		 if((pointnum * 4 + 2)<255)
		 {
		    	 ret = fts_i2c_read(fts_i2c_client, buf, 1, buf, (pointnum * 4 + 2));
		 }
		 else
		 {
		        ret = fts_i2c_read(fts_i2c_client, buf, 1, buf, 255);
		        ret = fts_i2c_read(fts_i2c_client, buf, 0, buf+255, (pointnum * 4 + 2) -255);
		 }
		 if (ret < 0)
		 {
		       printk( "%s read touchdata failed.\n", __func__);
		       return ret;
		 }
         //Begin<REQ><><20150910>Add WAKEUP_GESTURE for ft5xx;xiongdajun
#ifdef CONFIG_FT5XX_TGESTURE_FUNCTION
              if(gestrue_id == GESTURE_DOUBLECLICK)
                {
                    gTGesture = 'u';
                    input_report_key(ft5xx_key_dev,KEYCODE_KEYTP, 1);
                    input_report_key(ft5xx_key_dev,KEYCODE_KEYTP, 0);
                    input_sync(ft5xx_key_dev);
              }
              else
                {
                    gTGesture = fts_check_gesture(gestrue_id);
                    input_report_key(ft5xx_key_dev,KEYCODE_KEYTP, 1);
                    input_report_key(ft5xx_key_dev,KEYCODE_KEYTP, 0);
                    input_sync(ft5xx_key_dev);
                }
		 //fts_check_gesture(fts_input_dev,gestrue_id);
#endif
	 //END<REQ><><20150910>Add WAKEUP_GESTURE for ft5xx;xiongdajun
		 for(i = 0;i < pointnum;i++)
		 {
		    	coordinate_x[i] =  (((s16) buf[2 + (4 * i)]) & 0x0F) <<
		        	8 | (((s16) buf[3 + (4 * i)])& 0xFF);
		    	coordinate_y[i] = (((s16) buf[4 + (4 * i)]) & 0x0F) <<
		        	8 | (((s16) buf[5 + (4 * i)]) & 0xFF);
		 }
		 return -1;
	}
	 return -1;
	/*
	else
	{
		if (0x24 == buf[0])
		{
			gestrue_id = 0x24;
			fts_check_gesture(fts_input_dev,gestrue_id);
			printk( "%d check_gesture gestrue_id.\n", gestrue_id);
			return -1;
		}

		pointnum = (short)(buf[1]) & 0xff;
		buf[0] = 0xd3;
		if((pointnum * 4 + 8)<255)
		{
			ret = fts_i2c_read(fts_i2c_client, buf, 1, buf, (pointnum * 4 + 8));
		}
		else
		{
			ret = fts_i2c_read(fts_i2c_client, buf, 1, buf, 255);
			ret = fts_i2c_read(fts_i2c_client, buf, 0, buf+255, (pointnum * 4 + 8) -255);
		}
		if (ret < 0)
		{
			printk( "%s read touchdata failed.\n", __func__);
			return ret;
		}

		gestrue_id = fetch_object_sample(buf, pointnum);
		fts_check_gesture(fts_input_dev,gestrue_id);
		printk( "%d read gestrue_id.\n", gestrue_id);

		for(i = 0;i < pointnum;i++)
		{
		    coordinate_x[i] =  (((s16) buf[0 + (4 * i)]) & 0x0F) <<
		        8 | (((s16) buf[1 + (4 * i)])& 0xFF);
		    coordinate_y[i] = (((s16) buf[2 + (4 * i)]) & 0x0F) <<
		        8 | (((s16) buf[3 + (4 * i)]) & 0xFF);
		}
		return -1;
	}
	*/
}
