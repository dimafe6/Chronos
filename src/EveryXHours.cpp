#include "chronosinc/Delta.h"
#include "chronosinc/marks/EveryXHours.h"
namespace Chronos
{
namespace Mark
{
EveryXHours::EveryXHours(Hours h, Minutes m, Seconds s) : Event(), hours(h), minute(m), sec(s)
{
}

Event *EveryXHours::clone() const
{
	return new EveryXHours(hours, minute, sec);
}

DateTime EveryXHours::applyTo(const DateTime &dt) const
{
	Chronos::TimeElements els(dt.asElements());

	els.Minute = minute;
	els.Second = sec;

	return DateTime(els);
}

DateTime EveryXHours::next(const DateTime &dt) const
{

	DateTime theNext(applyTo(dt));

	if (theNext > dt)
		return theNext;

	theNext += Span::Hours(hours);

	return theNext;
}

DateTime EveryXHours::previous(const DateTime &dt) const
{
	DateTime thePrev(applyTo(dt));

	if (thePrev < dt)
		return thePrev;

	thePrev -= Span::Hours(hours);
	return thePrev;
}
} // namespace Mark
} /* namespace Chronos */
