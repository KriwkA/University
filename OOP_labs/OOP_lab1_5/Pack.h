#include <iostream>
#include <string>

class Pack
{
public:
	size_t id;
	std::string title;
	Pack() {};
	Pack(const size_t& _id, const std::string& _title);
	friend std::ostream& operator<<(std::ostream& os, const Pack& pack);
	char operator==(const Pack& _pack) const;
	~Pack() {};
};