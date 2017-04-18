#pragma once
#ifndef _BOOKMARK_H_
#define _BOOKMARK_H_
#include <ostream>
#include <exception>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>

#define record std::string, long long

class Bookmark
{
private:
	std::multimap<record> records_;
	size_t size_;
public:
	Bookmark();
	Bookmark(const Bookmark& _bookmark);
	void add(const std::pair<record>& _newRecord);
	std::multimap<record>::iterator search(const long long& _phone);
	std::pair<std::multimap<record>::iterator,
		std::multimap<record>::iterator> search(const std::string& _account);
	std::multimap<record>::iterator search(const std::pair<record>& _record);
	void del(const std::pair<record>& _record);
	void del(const size_t& _number);
	void del(const std::multimap<record>::iterator& _iter);
	friend std::ostream& operator<<(std::ostream& os, const Bookmark& _bookmark);
};

#endif

