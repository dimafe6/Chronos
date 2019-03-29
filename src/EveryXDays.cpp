#include "chronosinc/Delta.h"
#include "chronosinc/marks/EveryXDays.h"
namespace Chronos
{
namespace Mark
{
EveryXDays::EveryXDays(Days d, Hours h, Minutes m, Seconds s) : Event(), days(d), hour(h), minute(m), sec(s)
{
}

Event *EveryXDays::clone() const
{
	return new EveryXDays(days, hour, minute, sec);
}

DateTime EveryXDays::applyTo(const DateTime &dt) const
{
	Chronos::TimeElements els(dt.asElements());

	els.Hour = hour;
	els.Minute = minute;
	els.Second = sec;

	return DateTime(els);
}

DateTime EveryXDays::next(const DateTime &dt) const
{

	DateTime theNext(applyTo(dt));

	if (theNext > dt)
		return theNext;

	theNext += Span::Days(days);

	return theNext;
}

DateTime EveryXDays::previous(const DateTime &dt) const
{
	DateTime thePrev(applyTo(dt));

	if (thePrev < dt)
		return thePrev;

	thePrev -= Span::Days(days);
	return thePrev;
}
} // namespace Mark
} /* namespace Chronos */
