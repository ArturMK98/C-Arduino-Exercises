/**
 * Header file for switch reading functionality
 * used with Arduino Uno.
 *
 * Version 3 of this file - developed for 2018-2019 
 */

#ifndef __EE108_SWITCHES_H
#define __EE108_SWITCHES_H
 
#include <ee108_constants.h>

#ifdef __cplusplus
extern "C" {
#endif

const int SW_OFF_START = 0x01; // switch off now, but was ON the last time we checked
                                // NOTE: you won't see SW_OFF_START on its own
                                // Instead it will be part of NORMAL_CLICK or LONG_CLICK
const int SW_OFF_CONTINUED = 0x02; // switch OFF now and was also OFF the last time we checked
const int SW_ON_START = 0x04; // switch ON now, but was OFF the last time we checked
const int SW_ON_CONTINUED = 0x08; // switch ON now and was also ON the last time we checked

const int SW_CLICK = 0x11; // just transitioned from switch ON to OFF after normal press duration
const int SW_CLICK_LONG = 0x21; // just transitioned from switch ON to OFF (after a "long" press duration)

// bit masks to check for multiple events (only for use with bitwise tests)
// NOTE: we have to repeat the literal values here from above because of some 
// limitations of const values in C in this specific situation
const int SW_ON_ANY = 0x04 | 0x08; // = SW_ON_START | SW_ON_CONTINUED;
const int SW_CLICK_ANY = 0x11 | 0x21; // = SW_CLICK | SW_CLICK_LONG;


const unsigned int TIME_NOT_SET = 0;

// struct SwitchInfo is defined in ee108_switches.c and not here because it
// is part of the private implementation of the ee108 library and should not be
// exposed to programs that are simply using the library.
//   We can still define a pointer to it here however and that is what we do.

typedef struct SwitchInfo * SwitchPtr;

extern SwitchPtr sw1Object;
extern SwitchPtr sw2Object;


void setSwitchDebounce(unsigned int debounceMs);
void setSwitchClickDurations(unsigned int longClickMs);

/**
 * read the (debounced) switch value and optionally output the
 * time spent in the previous state.
 *
 * If the switch has just been released, the previous state was
 * all the time that the switch was pressed. If the switch was
 * just pressed, then the previous state was all the time that
 * the switch had not been pressed.
 *
 * Typically this function should be called once per superloop.
 * In any case, the function must be called relatively frequently (at least
 * every 100ms or so) in order to correctly detect the button being
 * held down and the difference between long and normal clicks. 
 * 
 * @param sw	the switch to read
 * @param pPrevStateDurationMs
 *         		[optional] if this value is not needed, pass in a NULL pointer.
 *              if you want this value, pass in a valid pointer. The pointee will
 *              be set to the length of time the switch was in the state it had the
 *              previous time this function was called.
 *
 *              EXAMPLE:
 *
 *              0 ms, SW1 is initially not pressed
 *              ...readSwitchEventTimes called multiple times - details not important
 *              990 ms, user presses SW1
 *              1000 ms, readSwitchEventTimes called,  currentSwState=ON, prevSwState=OFF,
 *                       prevStateDuration=1000ms (in the previous OFF state)
 *              1050 ms, readSwitchEventTimes called, currentSwState=ON, prevSwState=ON,
 *                       prevStateDuration=50ms (in ON state)
 *              1100 ms, readSwitchEventTimes called, currentSwState=ON, prevSwState=ON,
 *                       prevStateDuration=100ms (in ON state)
 *              1120 ms, user releases SW1
 *              1150 ms, readSwitchEventTimes called, currentSwState=OFF, prevSwState=ON,
 *                       prevStateDuration=150ms (in the previous ON state)
 *              1200 ms, readSwitchEventTimes called, currentSwState=OFF, prevSwState=OFF,
 *                       prevStateDuration=50ms (in OFF state)
 *              etc.
 */
int readSwitchEventTimes(SwitchPtr sw, 
                          unsigned int *pPrevStateDurationMs);

/**
 * read the current switch event as simply as possible
 *
 * Usually this function or readSwitchEventTimes should be called
 * once per superloop.
 *
 * @param sw    a SwitchPtr referring to valid switch state information
 *              (usually sw1 or sw2)
 * @returns the current switch event which is one of:
 *            SW_OFF_CONTINUED the button is not pressed
 *            SW_ON_START      the button has just transitioned from not
 *                             pressed to pressed
 *            SW_ON_CONTINUED  the button was already pressed and has
 *                             been held down continuously since
 *            SW_CLICK_NORMAL the button has just been released. A press
 *                            followed by a release is called a click.
 *            SW_CLICK_LONG   the button has just been released after a long
 *                            hold
 */
int readSwitchEvent(SwitchPtr sw);


#ifdef __cplusplus
}
#endif

#endif //  __EE108_SWITCHES_H