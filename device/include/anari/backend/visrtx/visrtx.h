/*
 * Copyright (c) 2019-2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

// ANARI-SDK
#ifdef __cplusplus
#include <anari/anari_cpp.hpp>
#else
#include <anari/anari.h>
#endif
// VisRTX
#include "anari_library_visrtx_export.h"

#ifdef __cplusplus
extern "C" {
#endif

// Direct VisRTX device construction //////////////////////////////////////////

VISRTX_DEVICE_INTERFACE ANARIDevice makeVisRTXDevice();

// VisRTX extension feature testing ///////////////////////////////////////////

typedef struct
{
  int VISRTX_ARRAY1D_DYNAMIC_REGION;
  int VISRTX_CUDA_OUTPUT_BUFFERS;
  int VISRTX_SAMPLER_COLOR_MAP;
  int VISRTX_TRIANGLE_ATTRIBUTE_INDEXING;
} VisRTXFeatures;

VISRTX_DEVICE_INTERFACE int visrtxGetObjectFeatures(VisRTXFeatures *features,
    ANARILibrary,
    const char *deviceName,
    const char *objectName,
    ANARIDataType objectType);

VISRTX_DEVICE_INTERFACE int visrtxGetInstanceFeatures(
    VisRTXFeatures *features, ANARIDevice device, ANARIObject object);

#ifdef __cplusplus
} // extern "C"

namespace visrtx {

using Features = VisRTXFeatures;

VISRTX_DEVICE_INTERFACE
Features getObjectFeatures(anari::Library library,
    const char *device,
    const char *objectSubtype,
    anari::DataType objectType);

VISRTX_DEVICE_INTERFACE
Features getInstanceFeatures(anari::Device, anari::Object);

} // namespace visrtx
#endif
