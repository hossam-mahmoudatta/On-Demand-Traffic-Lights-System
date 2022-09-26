/*
 * CFile1.c
 *
 * Created: 8/28/2022 11:02:12 AM
 *  Author: TESTER
 */ 
#define _OVERFLOW_TIMER						(((1000 / ((F_CPU / 64) / 256))))

#define _TICK_TIME							(uint8_t)((_OVERFLOW_TIMER)* (_KBD_CHECK_SKIP + 1))
#define _DEBOUNCE							30
#define _DEBOUNCE_TICKS   					(((_DEBOUNCE / _TICK_TIME)))
#define _LONG_HOLD_TICKS					(2000 / _TICK_TIME)
#define _VERY_LONG_HOLD_TICKS				(5000 / _TICK_TIME)
#define _DC_GAP_TICKS						(250  / _TICK_TIME)
#define _KBD_CHECK_SKIP						(0)

#define _EVENT_NOEVENT						(0)
#define _EVENT_CLICK						(1)
#define _EVENT_DOUBLE_CLICK					(2)
#define _EVENT_LONG_PRESS					(3)
#define _EVENT_VERY_LONG_PRESS				(4)

volatile uint8_t _key = (1 << PC7);
volatile uint8_t _key_last = (1 << PC7);
volatile uint8_t _key_pressed = 0;
volatile uint8_t _key_wait_for_up = 0;
volatile uint8_t _key_wait_for_DC = 0;
volatile uint8_t key_event;
volatile uint8_t _ignore_rel = 0;
volatile uint8_t _skip_kbd_check = _KBD_CHECK_SKIP;

volatile uint16_t _debounce_timer = 0;
volatile uint16_t _kbd_timer = 0;

void init_timer2(void) {
	TCCR0A |= ( 1 << CS01) | ( 1 << CS00);
	TCNT0 = 0;
	TIMSK0 |= (1 << TOIE0);  // Set interrupt overflow
}

void init_Button(void) {
	DDRC &= ~(1 << PC7);    //pc7 as input (PCINT15)
	_key = _key_last = PINC & (1 << PC7);
}

uint8_t getKBDevent(void) {
	uint8_t ev = key_event;

	key_event = 0;
	return ev;
}

ISR(TIMER0_OVF_vect) {
	if(_skip_kbd_check++ < _KBD_CHECK_SKIP) goto TIMER0_exit;
	_skip_kbd_check = 0;
	_key = PINC & (1 << PC7);
	if(_key != _key_last) {
		if (_debounce_timer < _DEBOUNCE_TICKS ) {// first click or debouncing
			_debounce_timer++;
			goto TIMER0_exit;
		}
		if(_debounce_timer == _DEBOUNCE_TICKS) _kbd_timer = 0;
		_key_pressed = 1;
		_key_last = _key;
		_debounce_timer = 0;
		} else {
		if(_key_pressed) {
			_kbd_timer++;
			if(!_key) {							//key down
				if(_kbd_timer > _LONG_HOLD_TICKS) {
					key_event = _EVENT_LONG_PRESS;
					_key_wait_for_up = 0;
					_ignore_rel = 1;
					_key_pressed = 0;
					_key_wait_for_DC = 0;
				}
				if(_key_wait_for_DC) {
					key_event = _EVENT_DOUBLE_CLICK;
					_key_wait_for_DC = 0;
					_key_wait_for_up = 0;
					_ignore_rel = 1;
					//_key_pressed =0;
					} else {
					if(!_ignore_rel) _key_wait_for_up = 1;
				}
				} else {				//key up
				_ignore_rel = 0;
				if(_key_wait_for_up) {
					if(_kbd_timer > _DC_GAP_TICKS) {  //double click has expired - "normal" click
						key_event = _EVENT_CLICK;
						_kbd_timer = 0;
						_key_wait_for_up = 0;
						_key_wait_for_DC = 0;
						//_key_pressed =0;
						} else {
						_key_wait_for_up = 1;
						_key_wait_for_DC = 1;

					}
				}
			}
		}
	}

	TIMER0_exit:;

}