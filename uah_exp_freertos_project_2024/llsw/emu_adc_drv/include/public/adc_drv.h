/*
 * adc_drv.h
 *
 *  Created on: May 5, 2024
 *      Author: opolo70
 */

#ifndef LLSW_EMU_ADC_DRV_INCLUDE_ADC_DRV_H_
#define LLSW_EMU_ADC_DRV_INCLUDE_ADC_DRV_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "public/config.h"
#include "public/basic_types.h"

//Get sample ADC channel and return value
uint16_t sample_adc_channel(uint8_t channel_id) ;

//Sample ADC channel and return value
void sample_SID0_Params(uint16_t params[]) ;

#ifdef __cplusplus
}
#endif

#endif

