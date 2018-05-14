/*
Copyright (C) 2012 Paulo Marques (pjp.marques@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/* 
 * Library for controlling a chain of RGB LEDs based on the P9813 protocol.
 * E.g., supports the Grove Chainable RGB LED product.
 *
 * Information about the P9813 protocol obtained from:
 * http://www.seeedstudio.com/wiki/index.php?title=Twig_-_Chainable_RGB_LED
 */



#ifndef __ChainableLED_h__
#define __ChainableLED_h__

#if defined (SPARK)
  #include "application.h"
#endif

#define _CL_RED             0
#define _CL_GREEN           1
#define _CL_BLUE            2
#define _CLK_PULSE_DELAY    20

class ChainableLED
{
public:
    ChainableLED(int number_of_leds);
    ~ChainableLED();
    
    void init();
    void setColorRGB(int led, int red, int green, int blue);
    void setColorHSB(int led, float hue, float saturation, float brightness);

private:
    int _clk_pin;
    int _data_pin;
    int _num_leds; 

    int* _led_state;
    
    void clk(void);
    void sendByte(int b);
    void sendColor(int red, int green, int blue);
};

#endif

