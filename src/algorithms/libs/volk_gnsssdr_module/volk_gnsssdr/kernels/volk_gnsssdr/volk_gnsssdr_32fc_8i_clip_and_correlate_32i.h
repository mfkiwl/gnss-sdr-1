/*!
 * \file volk_gnsssdr_32fc_8i_clip_and_correlate_32i.h
 * \brief VOLK_GNSSSDR kernel: Preamble / secondary code correlation
 * \authors <ul>
 *          <li> Javier Arribas, 2015. jarribas(at)cttc.es
 *          </ul>
 *
 * VOLK_GNSSSDR kernel that esamples N 16 bits integer short complex vectors using zero hold resample algorithm.
 * It is optimized to resample a single GNSS local code signal replica into N vectors fractional-resampled and fractional-delayed
 * (i.e. it creates the Early, Prompt, and Late code replicas)
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2019  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <https://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#ifndef INCLUDED_volk_gnsssdr_32fc_8i_clip_and_correlate_32i_H
#define INCLUDED_volk_gnsssdr_32fc_8i_clip_and_correlate_32i_H

#ifdef LV_HAVE_GENERIC

static inline void volk_gnsssdr_32fc_8i_clip_and_correlate_32i_generic(int32_t* result, const lv_32fc_t* input, const char* ref, uint32_t num_points)
{
    int32_t corr_value = 0;
    for (uint32_t i = 0; i < num_points; i++)
        {
            if (lv_creal(input[i]) < 0.0)  // symbols clipping
                {
                    if (ref[i] == '0')
                        {
                            corr_value++;
                        }
                    else
                        {
                            corr_value--;
                        }
                }
            else
                {
                    if (ref[i] == '0')
                        {
                            corr_value--;
                        }
                    else
                        {
                            corr_value++;
                        }
                }
        }
    result[0] = corr_value;
}

#endif /*LV_HAVE_GENERIC*/


#endif
