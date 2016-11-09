#include "ax8052.h"
#include "wtimer.h"

__reentrantb uint8_t wtimer1_remove(struct wtimer_desc __xdata *desc) __reentrant
{
	struct wtimer_desc __xdata *d;
	uint8_t ret;
	uint8_t __autodata iesave = IE_1;
	IE_1 = 0;
	ret = wtimer_removecb_core((struct wtimer_callback __xdata *)desc);
	ret += wtimer1_removecb_core(desc);
	IE_1 = iesave;
	return ret;
}
