#ifndef CHRONOS_INTINCLUDES_EVENTS_EVERY_X_DAYS_H_
#define CHRONOS_INTINCLUDES_EVENTS_EVERY_X_DAYS_H_

#include "../DateTime.h"
#include "../Event.h"
namespace Chronos {
namespace Mark {

class EveryXDays : public Event {
public:
	EveryXDays(Days days, Hours hour, Minutes min, Seconds sec=0);

	virtual DateTime next(const DateTime & dt) const;
	virtual DateTime previous(const DateTime & dt)  const;
	virtual Event * clone()  const;
private:

	DateTime applyTo(const DateTime & dt) const;

	Days days;
	Hours hour;
	Minutes minute;
	Seconds sec;
};

} /* namespace Event */
} /* namespace Chronos */

#endif /* CHRONOS_INTINCLUDES_EVENTS_EVERY_X_DAYS_H_ */
