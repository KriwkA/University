#include "Bookmark.h"

std::ostream& operator<<(std::ostream& os, const std::pair<record>& _record)
{
	os.setf(std::ios::left);
	os << std::setw(35) << _record.first << std::setw(10) << _record.second;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Bookmark& _bookmark)
{ 
	os.setf(std::ios::left);
	os << std::setw(4) << "N";
	os << std::setw(35) << "FIO";
	os << std::setw(10) << "Phone" << std::endl;
	size_t rowCounter = 0;
	for (auto i : _bookmark.records_)
	{
		os << std::setw(4) << ++rowCounter << i << std::endl;
	}
	return os;
}

Bookmark::Bookmark()
{
	size_ = 0;
}

Bookmark::Bookmark(const Bookmark & _bookmark)
{
	records_ = std::multimap<record>(_bookmark.records_);
	size_ = _bookmark.size_;
}

void Bookmark::add(const std::pair<record>& _newRecord)
{
	records_.insert(_newRecord);
	size_++;
}

std::multimap<record>::iterator Bookmark::search(const long long& _phoneNumber)
{
	for (std::multimap<record>::iterator i = records_.begin(); i != records_.end(); ++i)
		if (i->second == _phoneNumber)
			return i;
	throw std::exception("Phone nubmer not enable in bookmark");
}

std::pair<std::multimap<record>::iterator,
	std::multimap<record>::iterator> Bookmark::search(const std::string& _account)
{
	for (std::multimap<record>::iterator i = records_.begin(); i != records_.end(); ++i)
		if (i->first == _account)
			for (auto j = i; (j->first == _account) && (j != records_.end()); ++j)
				return std::make_pair(i, j);
	throw std::exception("Account not enable in bookmark");
}

std::multimap<record>::iterator Bookmark::search(const std::pair<record>& _record)
{
	for (std::multimap<record>::iterator i = records_.begin(); i != records_.end(); ++i)
		if (i->second == _record.second && i->first == _record.first)
			return i;
	throw std::exception("Phone nubmer not enable in bookmark");
}

void Bookmark::del(const std::pair<record>& _record)
{
	std::multimap<record>::iterator iter = this->search(_record);
	std::multimap<record>::iterator iter2 = iter;
	iter++;
	records_.erase(iter2, iter);
	size_--;
}

void Bookmark::del(const size_t & _number)
{
	if (_number > this->size_ - 1)
		throw std::exception("Size error");
	std::multimap<record>::iterator iter = records_.begin();
	std::multimap<record>::iterator iter2;
	for (size_t i = 0; i < _number; ++i)
		iter++;
	iter2 = iter;
	iter2++;
	records_.erase(iter,iter2);
	size_--;
}