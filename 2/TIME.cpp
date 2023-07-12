#include "TIME.h"
Time::Time() {
	/*
	����������� ������ Time �� ���������
	@param NULL
	*/
	hour = new int(0);
	minute = new int(0);
	second = new int(0);
}
Time::Time(int h, int m, int s) {
	/*
	����������� ������ Time � �����������
	@param int h - ����
	@param int m - ������
	@param int s - �������
	*/
	hour = new int(h);
	minute = new int(m);
	second = new int(s);
}
Time::~Time() {
	/*���������� ������ Time*/
	delete hour, minute, second;
}
Time::Time(const Time& copy) {
	/*
	����������� ����������� ������ Time, ��� �������� � �-��
	@param const Time & copy - ����� ������������� ���������� ������ Time(����� ����������)
	*/
	hour = new int(*copy.hour);
	minute = new int(*copy.minute);
	second = new int(*copy.second);
}
void Time::setH(int h) {
	/*
	��������� �������� �����
	@param int h - ���� 
	@return NULL
	*/
	*hour = h;
}
void Time::setM(int m) {
	/*
	��������� �������� �����
	@param int m - ������
	@return NULL
	*/
	*minute = m;
}
void Time::setS(int s) {
	/*
	��������� �������� ������
	@param int s - �������
	@return NULL
	*/
	*second = s;
}
int Time::getH() {
	/*
	��������� �������� ���� ����� ������ Time
	@param NULL
	@return - �������� ���� ����� ������ Time
	*/
	return *hour;
}
int Time::getM() {
	/*
	��������� �������� ���� ����� ������ Time
	@param NULL
	@return - �������� ���� ����� ������ Time
	*/
	return *minute;
}
int Time::getS() {
	/*
	��������� �������� ���� ������ ������ Time
	@param NULL
	@return - �������� ���� ������ ������ Time
	*/
	return *second;
}

string Time::toString() {
	/*
	����������� ������ ������
	@param NULL
	@return - ������ ��� ������
	*/
	string h = "", m = "", s = "";
	h = *hour < 10 ? "0" + to_string(*hour) : to_string(*hour);
	m = *minute < 10 ? "0" + to_string(*minute) : to_string(*minute);
	s = *second < 10 ? "0" + to_string(*second) : to_string(*second);
	return h + ":" + m + ":" + s + "\n";
}

Time  Time::operator +(Time obj) {
	/*
	�������� ��������
	@param obj - ������ ������ Time
	@return - ������ ������ Time
	*/
	int sec = *second, objS = obj.getS(),
		min = *minute, objM = obj.getM(),
		h = *hour, objH = obj.getH();
	sec += objS;
	if (sec >= 60) {
		min += 1;
		sec -= 60;
	}
	if (min >= 60) {
		h += 1;
		min-= 60;
	}
	min += objM;
	if (min >= 60) {
		h += 1;
		min-= 60;
	}
	if (h >= 24)
		h-=24;
	h += objH;
	if (h >= 24)
		h -= 24;
	Time c(h, min, sec);
	return c;
}
Time  Time::operator  + (int sec)
{
	/*
	�������� ��������
	@param sec - ����� ����� , ���-�� ������
	@return - ������ ������ Time
	*/
	int h = *hour, m = *minute, s = *second;
	s += sec;
	while (s >= 60) {
		m += 1;
		s -= 60;
	}
	while (m >= 60) {
		h += 1;
		m -= 60;
	}
	while (h >= 24)
		h -= 24;
	Time c(h, m, s);
	return c;
}
Time  Time::operator -(Time obj) {
	/*
	�������� ���������
	@param obj - ������ ������ Time
	@return - ������ ������ Time
	*/
	int sec = *second, objS = obj.getS(),
		min = *minute, objM = obj.getM(),
		h = *hour, objH = obj.getH();
	sec -= objS;
	if (sec < 0) {
		min -= 1;
		sec += 60;
	}
	if (min < 0) {
		h -= 1;
		min += 60;
	}
	min -= objM;
	if (min < 0) {
		h -= 1;
		min += 60;
	}
	if (h < 0)
		h += 24;
	h -= objH;
	if (h < 0)
		h += 24;
	Time c(h, min, sec);
	return c;
}
Time  Time::operator  - (int sec)
{
	/*
	�������� ���������
	@param sec - ����� ����� , ���-�� ������
	@return - ������ ������ Time
	*/
	int h = *hour, m = *minute, s = *second;
	s -= sec;
	while (s < 0) {
		m -= 1;
		s += 60;
	}
	while (m < 0) {
		h -= 1;
		m += 60;
	}
	while (h < 0)
		h += 24;
	Time c(h, m, s);
	return c;
}

bool Time::operator ==(Time obj) {
	/*
	�������� ��������� ==
	@param obj - ������ ������ Time
	@return - ������� �������� ,��������� �������� ��������� 
	*/
	return (*hour == obj.getH()&&*minute==obj.getM()&&*second==obj.getS());
}
bool Time::operator !=(Time obj) {
	/*
	�������� ��������� !=
	@param obj - ������ ������ Time
	@return - ������� �������� ,��������� �������� ���������
	*/
	return !(*hour == obj.getH() && *minute == obj.getM() && *second == obj.getS());
}
bool Time::operator <(Time obj) {
	/*
	�������� ��������� <
	@param obj - ������ ������ Time
	@return - ������� �������� ,��������� �������� ���������
	*/
	int h = obj.getH(), m = obj.getM(), s = obj.getS();
	if (*hour < h)
		return 1;
	else if (*hour > h)
		return 0;
	else{
		if (*minute < m)
			return 1;
		else if (*minute > m)
			return 0;
		else {
			if (*second < s)
				return 1;
			else
				return 0;
		}
	}
}
bool Time::operator >(Time obj) {
	/*
	�������� ��������� >
	@param obj - ������ ������ Time
	@return - ������� �������� ,��������� �������� ���������
	*/
	int h = obj.getH(), m = obj.getM(), s = obj.getS();
	if (*hour > h)
		return 1;
	else if (*hour < h)
		return 0;
	else {
		if (*minute > m)
			return 1;
		else if (*minute < m)
			return 0;
		else {
			if (*second > s)
				return 1;
			else
				return 0;
		}
	}
}
bool Time::operator <=(Time obj) {
	/*
	�������� ��������� <=
	@param obj - ������ ������ Time
	@return - ������� �������� ,��������� �������� ���������
	*/
	int h = obj.getH(), m = obj.getM(), s = obj.getS();
	if (*hour < h)
		return 1;
	else if (*hour > h)
		return 0;
	else {
		if (*minute < m)
			return 1;
		else if (*minute > m)
			return 0;
		else {
			if (*second < s)
				return 1;
			else if (*second > s)
				return 0;
			else
				return 1;
		}
	}
}
bool Time::operator >=(Time obj) {
	/*
	�������� ��������� >=
	@param obj - ������ ������ Time
	@return - ������� �������� ,��������� �������� ���������
	*/
	int h = obj.getH(), m = obj.getM(), s = obj.getS();
	if (*hour > h)
		return 1;
	else if (*hour < h)
		return 0;
	else {
		if (*minute > m)
			return 1;
		else if (*minute < m)
			return 0;
		else {
			if (*second > s)
				return 1;
			else if (*second < s)
				return 0;
			else
				return 1;
		}
	}
}

Time& Time::operator +=(Time obj) {
	/*
	�������� ������������ +=
	@param obj - ������ ������ Time
	@return - ������ ������ Time,����� ������������� ��������� ������������
	*/
	int objS = obj.getS(),
		objM = obj.getM(),
		objH = obj.getH();
	*second += objS;
	if (*second >= 60) {
		*minute += 1;
		*second -= 60;
	}
	if (*minute >= 60) {
		*hour += 1;
		*minute -= 60;
	}
	*minute += objM;
	if (*minute >= 60) {
		*hour += 1;
		*minute -= 60;
	}
	if (*hour >= 24)
		*hour-= 24;
	*hour += objH;
	if (*hour >= 24)
		*hour -= 24;
	return *this;
}
Time& Time::operator +=(int sec) {
	/*
	�������� ������������ +=
	@param sec - ����� ����� (���-�� ������)
	@return - ������ ������ Time,����� ������������� ��������� ������������
	*/
	*second += sec;
	while (*second >= 60) {
		*minute += 1;
		*second -= 60;
	}
	while (*minute >= 60) {
		*hour += 1;
		*minute -= 60;
	}
	while (*hour >= 24)
		*hour -= 24;
	return *this;
}
Time& Time::operator -=(Time obj) {
	/*
	�������� ������������ -=
	@param obj - ������ ������ Time
	@return - ������ ������ Time,����� ������������� ��������� ������������
	*/
	int objS = obj.getS(),
		objM = obj.getM(),
		objH = obj.getH();
	*second -= objS;
	if (*second < 0) {
		*minute -= 1;
		*second += 60;
	}
	if (*minute < 0) {
		*hour -= 1;
		*minute += 60;
	}
	*minute -= objM;
	if (*minute < 0) {
		*hour -= 1;
		*minute += 60;
	}
	if (*hour < 0)
		*hour += 24;
	*hour -= objH;
	if (*hour < 0)
		*hour += 24;
	return *this;
}
Time& Time::operator -=(int sec) {
	/*
	�������� ������������ +=
	@param sec - ����� ����� (���-�� ������)
	@return - ������ ������ Time,����� ������������� ��������� ������������
	*/
	*second -= sec;
	while (*second < 0) {
		*minute -= 1;
		*second += 60;
	}
	while (*minute < 0) {
		*hour -= 1;
		*minute += 60;
	}
	while (*hour < 0)
		*hour += 24;
	return *this;
}

