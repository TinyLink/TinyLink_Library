#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <pocketsphinx/ad.h>
#include <pocketsphinx/err.h>
#include <pocketsphinx/pocketsphinx.h>
#include <sys/select.h>
#include <unistd.h>

#include "Voice_USB_Voice_BBB.h"
#include "TL_Config.h"
#include "grovepi.h"

namespace tinylink {

	Voice_USB_RPI::Voice_USB_RPI(void){

	}

	char* Voice_USB_RPI::recognize(int time_s) {

		const arg_t cont_args_def[] =
		{
			POCKETSPHINX_OPTIONS,
			/* Argument file. */
			{
				"-argfile",
				ARG_STRING,
				NULL,
				"Argument file giving extra arguments."
			},
			{
				"-adcdev",
				ARG_STRING,
				"plughw:0,0",
				"Name of audio device to use for input."
			},
			{
				"-infile",
				ARG_STRING,
				NULL,
				"Audio file to transcribe."
			},
			{
				"-inmic",
				ARG_BOOLEAN,
				"yes",
				"Transcribe audio from microphone."
			},
			{
				"-time",
				ARG_BOOLEAN,
				"no",
				"Print word times in file transcription."
			},
			CMDLN_EMPTY_OPTION
		};

		cmd_ln_t *config;                  // create configuration structure
		ps_decoder_t *ps;

		ad_rec_t *ad;                      // create audio recording structure - for use with ALSA functions
		int16 adbuf[2048];                 // buffer array to hold audio data
		uint8 utt_started, in_speech;      // flags for tracking active speech - has speech started? - is speech currently happening?
		int32 k;                           // holds the number of frames in the audio buffer
		char const *hyp;                   // pointer to "hypothesis" (best guess at the decoded result)
		const char* recordSound;

		char const *cfg;
		int myArgc = 4;
		const char * tmp[] = {"-lm", "/usr/local/voice/9612.lm", "-dict", "/usr/local/voice/9612.dic"};
		char* myArgv[4];

		int count = 0;
		string str_result = "";    //the recognize result to return
		char * ch_result;

		err_set_logfp(NULL);
		err_set_debug_level(0);

		for(int i = 0; i < myArgc; i++)
		{
			myArgv[i] = const_cast<char*>(tmp[i]);
		}

		config = cmd_ln_parse_r(NULL, cont_args_def, myArgc, myArgv, TRUE);
		if (config && (cfg = cmd_ln_str_r(config, "-argfile")) != NULL)
		{
			config = cmd_ln_parse_file_r(config, cont_args_def, cfg, FALSE);
		}

		if (config == NULL || (cmd_ln_str_r(config, "-infile") == NULL && cmd_ln_boolean_r(config, "-inmic") == FALSE))
		{
			if(config != NULL)
			{
				cmd_ln_free_r(config);
			}
			perror("Specify '-infile <file.wav>' to recognize from file or '-inmic yes' to recognize from microphone.\n");
			exit(-1);
		}

		ps_default_search_args(config);
		ps = ps_init(config);
		if (ps == NULL)
		{
			cmd_ln_free_r(config);
			return NULL;
		}

		if ((ad = ad_open_dev(cmd_ln_str_r(config, "-adcdev"),(int) cmd_ln_float32_r(config, "-samprate"))) == NULL)
		{
			perror("Failed to open audio device\n");
			exit(-1);
		}
		if(ad_start_rec(ad) < 0)
		{
			perror("Failed to start recording\n");
			exit(-1);
		}
		if(ps_start_utt(ps) < 0)
		{
			perror("Failed to start utterance\n");
			exit(-1);
		}

		// clear the utt_started flag
		utt_started = FALSE;

		while(1)
		{
			// capture the number of frames in the audio buffer
			if((k = ad_read(ad, adbuf, 2048)) < 0)
			{
				perror("Failed to read audio\n");
				exit(-1);
			}

			count = count + k;

			if(count > 16000 * time_s)
			{
				break;
			}

			// send the audio buffer to the pocketsphinx decoder
			ps_process_raw(ps, adbuf, k, FALSE, FALSE);

			// test to see if speech is being detected
			//1 if last buffer contained speech, 0 - otherwise
			in_speech = ps_get_in_speech(ps);

			// if speech has started and utt_started flag is false
			if (in_speech && !utt_started)
			{
				// then set the flag
				utt_started = TRUE;
			}

			// if speech has ended and the utt_started flag is true
			/* speech -> silence transition, time to start new utterance  */
			if (!in_speech && utt_started)
			{

				// then mark the end of the utterance
				ps_end_utt(ps);

				// stop recording
				//ad_stop_rec(ad);

				// query pocketsphinx for "hypothesis" of decoded statement
				hyp = ps_get_hyp(ps, NULL );

				if (hyp != NULL)
				{
					if(str_result.empty() || strlen(hyp) == 0)
					{
						str_result = str_result + hyp;
					}
					else
					{
						str_result = str_result + "," + hyp;
					}
				}

				//cout << hyp << endl;

				// start recording
				//if(ad_start_rec(ad) < 0)
				//{
				//	perror("Failed to start recording\n");
				//	exit(-1);
				//}

				// mark the start of the utterance
				if(ps_start_utt(ps) < 0)
				{
					perror("Failed to start utterance\n");
					exit(-1);
				}

				//clear the utt_started flag
				utt_started = FALSE;
			}
		}

		if (FALSE && utt_started)
		{
			// then mark the end of the utterance
			ps_end_utt(ps);

			// stop recording
			//ad_stop_rec(ad);

			hyp = ps_get_hyp(ps, NULL);
			if (hyp != NULL)
			{
				if(str_result.empty() || strlen(hyp) == 0)
				{
					str_result = str_result + hyp;
				}
				else
				{
					str_result = str_result + "," + hyp;
				}
			}
		}

		ad_stop_rec(ad);
		ad_close(ad);	// close the microphone
		ps_free(ps);
		cmd_ln_free_r(config);

		int len = str_result.length();
		ch_result = new char[len+1];
		strcpy(ch_result, str_result.c_str());

		return ch_result;
	}
}

tinylink::Voice_USB_RPI TL_Voice;

