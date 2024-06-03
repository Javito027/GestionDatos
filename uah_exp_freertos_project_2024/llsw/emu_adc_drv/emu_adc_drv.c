#include "public/adc_drv.h"
#include <stdlib.h>

#define N_SID0_HK_PARAM_NUM 5

//0 is -10  4095 is + 10
static uint16_t emu_hk_sid0_parameters[N_SID0_HK_PARAM_NUM] = {
		2375,
		2621,
		2723,
		3072, 2048 };

/**
 * \brief Adds noise to a given parameter value, ensuring the noisy value
 *        remains within the same multiple of 10 as the original value.
 *
 * The function calculates the lower and upper limits of the range for the
 * noisy value, based on the original value. It generates a random noise value
 * between -5 and 5 (inclusive) and adds it to the original value. The noisy
 * value is then clamped to the calculated range to ensure it remains within
 * the same multiple of 10 as the original value.
 *
 * @param value The original uint8_t value to which noise will be added.
 * @return The noisy value after adding the noise and clamping it within the
 *         defined range.
 */
uint16_t get_noise() {

	// Generate a random noise value between -5 and 5 (inclusive)
	int16_t noise_value = (rand() % 11) - 5;

	// Return the noisy value as a uint8_t integer
	return noise_value;
}

uint16_t sample_adc_channel(uint8_t channel_id) {

	uint16_t emu_sample_value = 0;

	if (channel_id < N_SID0_HK_PARAM_NUM) {

		emu_sample_value = emu_hk_sid0_parameters[channel_id];

		emu_sample_value += get_noise();

	}

	return emu_sample_value;

}

//Sample ADC channel and return value
void sample_SID0_Params(uint16_t params[5]) {

	for(int i =0; i < 5; i++){

		params[i]=sample_adc_channel(i);
	}

}
