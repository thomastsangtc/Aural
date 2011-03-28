//
//  AUCAudioBuffer.m
//  Aural
//
//  Created by Karl Stenerud on 2/19/11.
//
// Copyright 2011 Karl Stenerud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Note: You are NOT required to make the license available from within your
// iOS application. Including it in your project is sufficient.
//
// Attribution is not required, but appreciated :)
//

#import "AudioBuffer.h"


namespace aural
{
    AudioBuffer::AudioBuffer(void*const leftChannelData,
                             void*const rightChannelData,
                             const unsigned int numBytes,
                             AudioStreamBasicDescription& format)
    : leftChannelData_(leftChannelData)
    , rightChannelData_(rightChannelData)
    , numBytes_(numBytes)
    , format_(format)
    , numFrames_(numBytes / format.mBytesPerFrame)
    {
    }
    
    AudioBuffer::~AudioBuffer()
    {
        if(NULL != leftChannelData_)
        {
            free(leftChannelData_);
        }
        if(NULL != rightChannelData_)
        {
            free(rightChannelData_);
        }
    }
}
