/* ------------------------------------------
 * Copyright (c) 2017, Synopsys, Inc. All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * 1) Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.

 * 2) Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.

 * 3) Neither the name of the Synopsys, Inc., nor the names of its contributors may
 * be used
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
--------------------------------------------- */

/**
 * \file
 * \ingroup EMBARC_APP_FREERTOS_IOT_ILIGHT_SMARTDEVICE
 * \brief mic used in ilight
 */

/**
 * \addtogroup  EMBARC_APP_FREERTOS_IOT_ILIGHT_SMARTDEVICE
 * @{
 */

/* coustom HAL */
#include "mic.h"

/* mic operation */
static DEV_IIC *adc_iic_port;

/**
 * \brief	Adc value get of mic
 * \details	Get the adc value of mic using iic0.
 * \param[out]	the value of adc convert
 */
uint8_t adc_get(void)
{
	uint8_t REG_data;

	adc_iic_port -> iic_read((void*)(&REG_data), 1);
	EMBARC_PRINTF("ADC_DATA:%d\r\n", REG_data);

	return REG_data;
}

/**
 * \brief	Initial the mic
 * \details	Initial the mic using iic0.
 */
void mic_init(void)
{
	uint32_t point;

	point = (0x90 >> 1);
	adc_iic_port = iic_get_dev(DW_IIC_0_ID);
}

/**
 * \brief	IIC address point to mic
 * \details	IIC address point to mic.
 */
void iic_point_mic(void)
{
	uint32_t point = (0x90 >> 1);

	if (adc_iic_port->iic_control( IIC_CMD_MST_SET_TAR_ADDR, (void *)point) == E_OK) {
		EMBARC_PRINTF("Target reset mic OK!\n");
	}
}

/** @} */