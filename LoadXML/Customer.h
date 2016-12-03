#ifndef _Customer_H
#define _Customer_H

class Customer{
public:
	Customer(int id=0, float x=0, float y=0, float startTime=0, float endTime=0, float quantity=0, float serviceTime=0);
	void setId(int id);   // ���ó�Աid��ֵ
	void setX(float x);   // ���ó�Աx��ֵ
	void setY(float y);   // ���ó�Աy��ֵ
	void setStartTime(float startTime);  // ���ó�ԱstartTime��ֵ
	void setEndTime(float endTime);      // ���ó�ԱendTime��ֵ
	void setQuantity(float quantity);    // ���ó�Աquantity��ֵ
	void setServiceTime(float serviceTime);  // ���ó�ԱserviceTime��ֵ
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
