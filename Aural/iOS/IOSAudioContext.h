//
//  IOSAudioContext.h
//  Aural
//
//  Created by Karl Stenerud on 3/26/11.
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

#ifndef AURAL_IOSAUDIOCONTEXT_H
#define AURAL_IOSAUDIOCONTEXT_H


#import <AudioToolbox/AudioToolbox.h>
#include "AudioContext.h"
#include "AudioUnitHelpers.h"


namespace aural
{
    class IOSAudioManager;
    class IOSAudioSource;
    
    class IOS3DMixerAudioContext: public AudioContext
    {
    public:
        IOS3DMixerAudioContext(IOSAudioManager*const manager,
                               const unsigned int maxSources);
        ~IOS3DMixerAudioContext();
        
        AudioUnit mixerUnit();
        
        UInt32 maxFramesPerSlice();
        void setMaxFramesPerSlice(const UInt32 maxFramesPerSlice);
        
        Float64 sampleRate();
        void setSampleRate(const Float64 sampleRate);
        
        bool active();
        void setActive(const bool value);
        
        AudioSource* newSource();
        void deleteSource(AudioSource*const audioSource);
        
        Mutex& mutex();

    private:
        IOS3DMixerAudioContext(const IOS3DMixerAudioContext&);
        IOS3DMixerAudioContext& operator=(const IOS3DMixerAudioContext&);

    private:
        void setNumElements(const UInt32 numElements);

        Mutex mutex_;
        
        AudioUnitGraph graph_;
        
        IOSAudioManager* manager_;
        IOSAudioSource** sources_;
        const unsigned int maxSources_;
        
        AudioUnitAccessor inputAccessor_;
        AudioUnitAccessor outputAccessor_;
        AudioUnitAccessor globalAccessor_;

        bool active_;
    };
    
    inline AudioUnit IOS3DMixerAudioContext::mixerUnit()
    {
        return graph_.mixerUnit();
    }

    inline Mutex& IOS3DMixerAudioContext::mutex()
    {
        return mutex_;
    }
}

#endif // AURAL_IOSAUDIOCONTEXT_H
