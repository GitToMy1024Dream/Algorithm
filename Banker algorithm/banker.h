#include <stdio.h>
#include <Windows.h>
#define rows 20
#define false 0
#define true !false
int Resource[rows] = {0};//������Դ������
int MaxNeed[rows][rows] ={0}; //����������������Դ��
int Allocation[rows][rows] = {0};  //�ѷ������Դ��
int Available[rows] = {0};  //ʣ����õ���Դ��
int Need[rows][rows] = {0}; //�����̻���Ҫ���ٸ�����Դ
 
void MaxProcess();//��Դ����
void AllocationProcess();//�ѷ�����Դ����
void AvailableProcess(); //ʣ�������Դ����
void MaxNeedProcess();      //����������������Դ��
void NeedProcess();  		//�����̻���Ҫ������Դ
void Request();//ĳʱ������������Դ
int SafeCheck(); //��ȫ���
int Compare();   //���ؽ��̵ķ���ֵ
void Insert();  //��ӽ���
void Exit();   //�˳�