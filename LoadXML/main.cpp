#include "Customer.h"
#include "tinystr.h"
#include "tinyxml.h"
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iomanip>

using namespace std;
static const int NUM_OF_CUSTOMER = 51;        //�˿�����
static const char* FILENAME = "RC101_050.xml";  //�ļ���

int main(){
	vector<Customer *> customerSet(0);  // �˿ͼ���ÿ��Ԫ����Customer�����ָ��
	int i,j,k,count;
	int temp1;    // �����������
	float temp2;  // ��Ÿ���������
	Customer* customer;   // ��ʱ�˿ͽڵ�ָ��
	for (i=0; i<NUM_OF_CUSTOMER; i++) {  // �ȳ�ʼ���˿ͼ�
		customer = new Customer();
		customerSet.push_back(customer);
	}
	TiXmlDocument doc(FILENAME);    // ����XML�ļ�
	if(!doc.LoadFile()) return -1;  // ����޷���ȡ�ļ����򷵻�
	TiXmlHandle hDoc(&doc);         // hDoc��docָ��Ķ���
	TiXmlElement* pElem;            // ָ��Ԫ�ص�ָ��
	pElem = hDoc.FirstChildElement().Element(); //ָ����ڵ�
	TiXmlHandle hRoot(pElem);       // hRoot�Ǹ��ڵ�

	// ��ȡx,y�����Ƿ���network->nodes->node�ڵ���
	TiXmlElement* nodeElem = hRoot.FirstChild("network").FirstChild("nodes").FirstChild("node").Element(); //��ǰָ����node�ڵ�
	count = 0;  // ��¼�ƶ������ĸ�node�ڵ㣬���ҰѸ�node�ڵ����Ϣ¼�뵽˳���Ӧ��customer��
	for(nodeElem; nodeElem; nodeElem = nodeElem->NextSiblingElement()) { // ������ȡnode�ڵ����Ϣ
		customer = customerSet[count];  // ��ǰ�˿ͽڵ㣬ע�ⲻ�ܸ�ֵ��һ���µĶ��󣬷������ø��ƹ��캯��
		TiXmlHandle node(nodeElem);  // nodeElem��ָ��Ľڵ�
		TiXmlElement* xElem = node.FirstChild("cx").Element();  // cx�ڵ�
		TiXmlElement* yElem = node.FirstChild("cy").Element();  // cy�ڵ�
		nodeElem->QueryIntAttribute("id", &temp1);  //��id�ŵ�temp1�У�����ֵ����
		customer->setId(temp1);           
		temp2 = atof(xElem->GetText());    // charתfloat
		customer->setX(temp2);
		temp2 = atof(yElem->GetText());
		customer->setY(temp2);
		count++;
	}

	// ��ȡ������Ϣ
	TiXmlElement* requestElem = hRoot.FirstChild("requests").FirstChild("request").Element(); // ָ����request�ڵ�
	count = 0;
	for(requestElem; requestElem; requestElem = requestElem->NextSiblingElement()) {
		customer = customerSet[count];     // ��ǰ�˿ͽڵ㣬ע�ⲻ�ܸ�ֵ��һ���µĶ��󣬷������ø��ƹ��캯��
		TiXmlHandle request(requestElem);  // ָ��ָ��Ķ���
		TiXmlElement* startTimeElem = request.FirstChild("tw").FirstChild("start").Element(); // start time
		TiXmlElement* endTimeElem = request.FirstChild("tw").FirstChild("end").Element();     // end time
		TiXmlElement* quantityElem = request.FirstChild("quantity").Element();                // quantity
		TiXmlElement* serviceTimeElem = request.FirstChild("service_time").Element();         // service time
		// �ֱ��ȡ��������
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

	// ����ȡ������Ϣ���������̨
	cout<<setiosflags(ios_base::left)<<setw(6)<<"id"<<setw(6)<<"x"<<setw(6)<<
		"y"<<setw(12)<<"startTime"<<setw(12)<<"endTime"<<setw(12)<<"quantity"<<setw(14)<<"serviceTime"<<endl;
	for(i=0; i<NUM_OF_CUSTOMER; i++) {
		customer = customerSet[i];
		customer->show();
	}
	system("pause");
	return 0;
}