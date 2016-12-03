#include "Customer.h"
#include "tinystr.h"
#include "tinyxml.h"
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iomanip>

using namespace std;
static const int NUM_OF_CUSTOMER = 51;        //顾客数量
static const char* FILENAME = "RC101_050.xml";  //文件名

int main(){
	vector<Customer *> customerSet(0);  // 顾客集，每个元素是Customer对象的指针
	int i,j,k,count;
	int temp1;    // 存放整型数据
	float temp2;  // 存放浮点型数据
	Customer* customer;   // 临时顾客节点指针
	for (i=0; i<NUM_OF_CUSTOMER; i++) {  // 先初始化顾客集
		customer = new Customer();
		customerSet.push_back(customer);
	}
	TiXmlDocument doc(FILENAME);    // 读入XML文件
	if(!doc.LoadFile()) return -1;  // 如果无法读取文件，则返回
	TiXmlHandle hDoc(&doc);         // hDoc是doc指向的对象
	TiXmlElement* pElem;            // 指向元素的指针
	pElem = hDoc.FirstChildElement().Element(); //指向根节点
	TiXmlHandle hRoot(pElem);       // hRoot是根节点

	// 读取x,y，它们放在network->nodes->node节点中
	TiXmlElement* nodeElem = hRoot.FirstChild("network").FirstChild("nodes").FirstChild("node").Element(); //当前指向了node节点
	count = 0;  // 记录移动到了哪个node节点，并且把该node节点的信息录入到顺序对应的customer中
	for(nodeElem; nodeElem; nodeElem = nodeElem->NextSiblingElement()) { // 挨个读取node节点的信息
		customer = customerSet[count];  // 当前顾客节点，注意不能赋值给一个新的对象，否则会调用复制构造函数
		TiXmlHandle node(nodeElem);  // nodeElem所指向的节点
		TiXmlElement* xElem = node.FirstChild("cx").Element();  // cx节点
		TiXmlElement* yElem = node.FirstChild("cy").Element();  // cy节点
		nodeElem->QueryIntAttribute("id", &temp1);  //把id放到temp1中，属性值读法
		customer->setId(temp1);           
		temp2 = atof(xElem->GetText());    // char转float
		customer->setX(temp2);
		temp2 = atof(yElem->GetText());
		customer->setY(temp2);
		count++;
	}

	// 读取其余信息
	TiXmlElement* requestElem = hRoot.FirstChild("requests").FirstChild("request").Element(); // 指向了request节点
	count = 0;
	for(requestElem; requestElem; requestElem = requestElem->NextSiblingElement()) {
		customer = customerSet[count];     // 当前顾客节点，注意不能赋值给一个新的对象，否则会调用复制构造函数
		TiXmlHandle request(requestElem);  // 指针指向的对象
		TiXmlElement* startTimeElem = request.FirstChild("tw").FirstChild("start").Element(); // start time
		TiXmlElement* endTimeElem = request.FirstChild("tw").FirstChild("end").Element();     // end time
		TiXmlElement* quantityElem = request.FirstChild("quantity").Element();                // quantity
		TiXmlElement* serviceTimeElem = request.FirstChild("service_time").Element();         // service time
		// 分别读取各项数据
		temp2 = atof(startTimeElem->GetText());
		customer->setStartTime(temp2);   
		temp2 = atof(endTimeElem->GetText());
		customer->setEndTime(temp2);
		temp2 = atof(quantityElem->GetText());
		customer->setQuantity(temp2);
		temp2 = atof(serviceTimeElem->GetText());
		customer->setServiceTime(temp2);
		count++;
	}

	// 将读取到的信息输出到控制台
	cout<<setiosflags(ios_base::left)<<setw(6)<<"id"<<setw(6)<<"x"<<setw(6)<<
		"y"<<setw(12)<<"startTime"<<setw(12)<<"endTime"<<setw(12)<<"quantity"<<setw(14)<<"serviceTime"<<endl;
	for(i=0; i<NUM_OF_CUSTOMER; i++) {
		customer = customerSet[i];
		customer->show();
	}
	system("pause");
	return 0;
}