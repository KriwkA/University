#include "Pack.h"
#include <iomanip>


Pack::Pack(const size_t& _id, const std::string& _title)
{
	id = _id;
	title = _title;
}

std::ostream& operator<<(std::ostream& os, const Pack& _pack)
{
	os.setf(std::ios::left);
	os << std::setw(5) << _pack.id << ' ' << _pack.title << std::endl;
	return os;
}

char Pack::operator==(const Pack& _pack) const
{
	if (_pack.id == id && _pack.title == title)
		return 1;
	return 0;
}