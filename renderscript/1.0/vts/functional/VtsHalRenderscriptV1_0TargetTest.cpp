/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "VtsHalRenderscriptV1_0TargetTest.h"

// The main test class for RENDERSCRIPT HIDL HAL.
void RenderscriptHidlTest::SetUp() {
    device = IDevice::getService(GetParam());
    ASSERT_NE(nullptr, device.get());

    uint32_t version = 0;
    uint32_t flags = 0;
    context = device->contextCreate(version, ContextType::NORMAL, flags);
    ASSERT_NE(nullptr, context.get());
}

void RenderscriptHidlTest::TearDown() {
    if (context.get() != nullptr) {
        context->contextFinish();
        context->contextDestroy();
    }
}

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(RenderscriptHidlTest);
INSTANTIATE_TEST_SUITE_P(
        PerInstance, RenderscriptHidlTest,
        testing::ValuesIn(android::hardware::getAllHalInstanceNames(IDevice::descriptor)),
        android::hardware::PrintInstanceNameToString);
