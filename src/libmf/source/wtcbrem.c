#include "ax8052.h"
#include "wtimer.h"

__reentrantb uint8_t wtimer_remove_callback(struct wtimer_callback __xdata *desc) __reentrant
{
	struct wtimer_desc __xdata *d;
	uint8_t ret;
	uint8_t __autodata iesave = IE_1;
	IE_1 = 0;
	ret = wtimer_removecb_core(desc);
	IE_1 = iesave;
	return ret;
}
