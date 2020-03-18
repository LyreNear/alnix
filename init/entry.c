#include "console.h"

int kern_entry(multiboot_t *mboot_ptr) {

	console_clear();
	console_write_color("Hello, OS kernel!\n", rc_black, rc_green);

	return 0;
}
