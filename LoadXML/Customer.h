#ifndef _Customer_H
#define _Customer_H

class Customer{
public:
	Customer(int id=0, float x=0, float y=0, float startTime=0, float endTime=0, float quantity=0, float serviceTime=0);
	void setId(int id);   // 设置成员id的值
	void setX(float x);   // 设置成员x的值
	void setY(float y);   // 设置成员y的值
	void setStartTime(float startTime);  // 设置成员startTime的值
	void setEndTime(float endTime);      // 设置成员endTime的值
	void setQuantity(float quantity);    // 设置成员quantity的值
	void setServiceTime(float serviceTime);  // 设置成员serviceTime的值
	void show();
private:
	int id;
	float x;
	float y;
	float startTime;
	float endTime;
	float quantity;
	float serviceTime;
};

#endif
