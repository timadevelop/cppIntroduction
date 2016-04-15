#pragma once
class SomeBox
{
private:
	int m_width;
	int m_length;
	int m_height;
public:
	SomeBox(int size)
		: m_width(size), m_length(size), m_height(size) // member init list
	{};
	SomeBox(int width, int length, int height)
		: m_width(width), m_length(length), m_height(height) // member init list
	{};
	int Volume() {
		return m_width * m_length * m_height;
	}
	~SomeBox();
};


class StorageBox : public SomeBox
{
public:
	StorageBox(int size, int d) : SomeBox(size), m_d(d)
	{};
	int getD() {
		return m_d;
	};
	//~StorageBox();
private:
	int m_d;

};