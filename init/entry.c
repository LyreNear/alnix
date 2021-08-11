#include "console.h"
#include "debug.h"


int kern_entry() {
    init_debug();

	console_clear();
	console_write_color("Hello, OS kernel!\n", rc_black, rc_green);

    panic("test");
	return 0;
}
