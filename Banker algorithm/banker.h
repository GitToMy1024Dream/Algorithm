#include <stdio.h>
#include <Windows.h>
#define rows 20
#define false 0
#define true !false
int Resource[rows] = {0};//各类资源的总量
int MaxNeed[rows][rows] ={0}; //各进程需求的最大资源量
int Allocation[rows][rows] = {0};  //已分配的资源量
int Available[rows] = {0};  //剩余可用的资源量
int Need[rows][rows] = {0}; //各进程还需要多少各类资源
 
void MaxProcess();//资源总数
void AllocationProcess();//已分配资源矩阵
void AvailableProcess(); //剩余可用资源矩阵
void MaxNeedProcess();      //各进程需求的最大资源数
void NeedProcess();  		//各进程还需要多少资源
void Request();//某时刻重新申请资源
int SafeCheck(); //安全检查
int Compare();   //返回进程的返回值
void Insert();  //添加进程
void Exit();   //退出