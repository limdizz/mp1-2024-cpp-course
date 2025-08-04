#pragma once
class Time {
private:
	int hours, minutes, seconds;
public:
	void getTime();
	void checkTimeValues();
	void printTime();
	void getTimesSum(Time b);
	void formatTimesSum();
	void getTimesDifference(Time b);
	void formatTimesDifference(Time b);

	friend std::istream& operator>>(std::istream& is, Time& time);
	friend std::ostream& operator<<(std::ostream& os, const Time& time);
};
