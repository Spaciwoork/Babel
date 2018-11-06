/*
** EPITECH PROJECT, 2021
** CPP_babel_2021
** File description:
** 
*/

#include <iostream>
#include "../include/audio.hpp"
 
int recordCallback( const void *inputBuffer, void *outputBuffer,
		    unsigned long framesPerBuffer,
		    const PaStreamCallbackTimeInfo* timeInfo,
		    PaStreamCallbackFlags statusFlags,
		    void *userData )
{
        paTestData *r_data = (paTestData*)userData;
	const SAMPLE *r_rptr = (const SAMPLE*)inputBuffer;
	SAMPLE *r_wptr = &r_data->recordedSamples[r_data->frameIndex * NUM_CHANNELS];
	long r_framesToCalc;
	long r_i;
	int r_finished;
	unsigned long r_framesLeft = r_data->maxFrameIndex - r_data->frameIndex;
	
	(void) outputBuffer;
	(void) timeInfo;
	(void) statusFlags;
	(void) userData;
	if( r_framesLeft < framesPerBuffer )
	{
		r_framesToCalc = r_framesLeft;
		r_finished = paComplete;
	}
	else
	{
		r_framesToCalc = framesPerBuffer;
		r_finished = paContinue;
	}
	
	if( inputBuffer == NULL )
	{
		for( r_i=0; r_i<r_framesToCalc; r_i++ )
		{
               *r_wptr++ = SAMPLE_SILENCE;
               if( NUM_CHANNELS == 2 ) *r_wptr++ = SAMPLE_SILENCE;
           }
	}
	else
	{
		for( r_i=0; r_i<r_framesToCalc; r_i++ )
		{
			*r_wptr++ = *r_rptr++;
			if( NUM_CHANNELS == 2 ) *r_wptr++ = *r_rptr++;
		}
	}
	r_data->frameIndex += r_framesToCalc;
	return r_finished;
}

int playCallback( const void *inputBuffer, void *outputBuffer,
		  unsigned long framesPerBuffer,
		  const PaStreamCallbackTimeInfo* timeInfo,
		  PaStreamCallbackFlags statusFlags,
		  void *userData )
{
	paTestData *data = (paTestData*)userData;
	SAMPLE *rptr = &data->recordedSamples[data->frameIndex * NUM_CHANNELS];
	SAMPLE *wptr = (SAMPLE*)outputBuffer;
	unsigned int i;
	int finished;
	unsigned int framesLeft = data->maxFrameIndex - data->frameIndex;
	
	(void) inputBuffer;
	(void) timeInfo;
       (void) statusFlags;
       (void) userData;

       if( framesLeft < framesPerBuffer )
       {
	       for( i=0; i<framesLeft; i++ )
	       {
               *wptr++ = *rptr++;
               if( NUM_CHANNELS == 2 ) *wptr++ = *rptr++;
	       }
	       for( ; i<framesPerBuffer; i++ )
	       {
		       *wptr++ = 0;
               if( NUM_CHANNELS == 2 ) *wptr++ = 0;
	       }
	       data->frameIndex += framesLeft;
	       finished = paComplete;
       }
       else
       {
	       for( i=0; i<framesPerBuffer; i++ )
	       {
		       *wptr++ = *rptr++;
		       if( NUM_CHANNELS == 2 ) *wptr++ = *rptr++;
	       }
	       data->frameIndex += framesPerBuffer;
	       finished = paContinue;
       }
       return finished;
}

PaStream *record(paTestData          *data)
{
	PaError             err = paNoError;
	int                 i;
	
	PaStream*           stream;
	PaStreamParameters  inputParameters;
	PaStreamParameters  outputParameters;
	int                 totalFrames;
	int                 numBytes;
	int                 numSamples;

	data->maxFrameIndex = totalFrames = NUM_SECONDS * SAMPLE_RATE;
	data->frameIndex = 0;
	numSamples = totalFrames * NUM_CHANNELS;
	numBytes = numSamples * sizeof(SAMPLE);
	std::cout << numBytes << std::endl;
	data->recordedSamples = (SAMPLE *) malloc( numBytes );
	for( i=0; i<numSamples; i++ ) data->recordedSamples[i] = 0;
	err = Pa_Initialize();
	if( err != paNoError ) return NULL;
	
	inputParameters.device = Pa_GetDefaultInputDevice();
	if (inputParameters.device == paNoDevice) {
		fprintf(stderr,"Error: No default input device.\n");
		return NULL;
	}
	inputParameters.channelCount = 2;
	inputParameters.sampleFormat = PA_SAMPLE_TYPE;
	inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
	inputParameters.hostApiSpecificStreamInfo = NULL;
	
	err = Pa_OpenStream(
		&stream,
		&inputParameters,
		NULL,
		SAMPLE_RATE,
		FRAMES_PER_BUFFER,
		paClipOff,
		recordCallback,
		data);
	if( err != paNoError ) return NULL;
	
	err = Pa_StartStream( stream );
	if( err != paNoError ) return NULL;
	printf("\n=== Now recording!! Please speak into the microphone. ===\n"); fflush(stdout \
		);
	
	while( ( err = Pa_IsStreamActive( stream ) ) == 1 )
	{
		Pa_Sleep(1000);
		printf("index = %d\n", data->frameIndex ); fflush(stdout);
	}
	if( err < 0 ) return NULL;
	err = Pa_CloseStream( stream );
	if( err != paNoError ) return NULL;
}

void play_sound(paTestData          data, int size)
{
        PaError             err = paNoError;
        int                 i;
        PaStream*           stream;
        PaStreamParameters  inputParameters;
        PaStreamParameters  outputParameters;
        int                 numBytes;
        int                 numSamples;
        int                 totalFrames;
        data.maxFrameIndex = totalFrames = size;
	data.frameIndex = 0;
        err = Pa_Initialize();
      if( err != paNoError ) return ;
        inputParameters.device = Pa_GetDefaultInputDevice();
       if (inputParameters.device == paNoDevice) {
           fprintf(stderr,"Error: No default input device.\n");
           return ;
       }
        inputParameters.channelCount = 2;
       inputParameters.sampleFormat = PA_SAMPLE_TYPE;
       inputParameters.suggestedLatency = Pa_GetDeviceInfo( inputParameters.device )->defaultLowInputLatency;
       inputParameters.hostApiSpecificStreamInfo = NULL;  
        data.frameIndex = 0;
       outputParameters.device = Pa_GetDefaultOutputDevice();
       if (outputParameters.device == paNoDevice) {
           fprintf(stderr,"Error: No default output device.\n");
           return ;
       }
       outputParameters.channelCount = 2;
       outputParameters.sampleFormat =  PA_SAMPLE_TYPE;
       outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defau\
ltLowOutputLatency;
       outputParameters.hostApiSpecificStreamInfo = NULL;

       printf("\n=== Now playing back. ===\n"); fflush(stdout);
       err = Pa_OpenStream(
                 &stream,
                 NULL,
                 &outputParameters,
                 SAMPLE_RATE,
                 FRAMES_PER_BUFFER,
                 paClipOff,
		 playCallback,
                 &data );
       if( err != paNoError ) return ;

       if( stream )
       {
           err = Pa_StartStream( stream );
           if( err != paNoError ) return ;

           printf("Waiting for playback to finish.\n"); fflush(stdout);

           while( ( err = Pa_IsStreamActive( stream ) ) == 1 ) {
                   Pa_Sleep(100);
           }
           if( err < 0 ) return ;

           err = Pa_CloseStream( stream );
           if( err != paNoError ) return ;

           printf("Done.\n"); fflush(stdout);
       }
}
