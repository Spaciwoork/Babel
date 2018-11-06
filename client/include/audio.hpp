/*
** EPITECH PROJECT, 2021
** CPP_babel_2021
** File description:
** 
*/

#ifndef AUDIO_HPP_
# define AUDIO_HPP_

#include <stdio.h>
#include <stdlib.h>
#include "portaudio.h"

 /* #define SAMPLE_RATE  (17932) // Test failure to open with this value. */
 #define SAMPLE_RATE  (44100)
 #define FRAMES_PER_BUFFER (512)
 #define NUM_SECONDS     (3)
 #define NUM_CHANNELS    (2)
 /* #define DITHER_FLAG     (paDitherOff) */
 #define DITHER_FLAG     (0) 
 
 #define WRITE_TO_FILE   (0)
 
 /* Select sample format. */
 #if 1
 #define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;
 #define SAMPLE_SILENCE  (0.0f)
 #define PRINTF_S_FORMAT "%.8f"
 #elif 1
    #define PA_SAMPLE_TYPE  paInt16
    typedef short SAMPLE;
    #define SAMPLE_SILENCE  (0)
    #define PRINTF_S_FORMAT "%d"
    #elif 0
    #define PA_SAMPLE_TYPE  paInt8
    typedef char SAMPLE;
   #define SAMPLE_SILENCE  (0)
    #define PRINTF_S_FORMAT "%d"
    #else
    #define PA_SAMPLE_TYPE  paUInt8
    typedef unsigned char SAMPLE;
   #define SAMPLE_SILENCE  (128)
    #define PRINTF_S_FORMAT "%d"
    #endif
    
    typedef struct
    {
        int          frameIndex;  /* Index into sample array. */
        int          maxFrameIndex;
        SAMPLE      *recordedSamples;
    }
    paTestData;

PaStream *record(paTestData          *data);
void play_sound(paTestData          data, int size);

int recordCallback( const void *inputBuffer, void *outputBuffer,
                               unsigned long framesPerBuffer,
                               const PaStreamCallbackTimeInfo* timeInfo,
                               PaStreamCallbackFlags statusFlags,
		    void *userData );

int playCallback( const void *inputBuffer, void *outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo,
                            PaStreamCallbackFlags statusFlags,
		  void *userData );

#endif
