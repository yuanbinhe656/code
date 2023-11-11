#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define PAGE 100   //内存总量100块

int memory[PAGE];
int process[PAGE][PAGE + 1]; //进程数组
int use_num; //已经使用内存
int process_num; //进程数目


void check()
{
	printf("内存总量: %d块，已用空间: %d块，剩余空间: %d块，进程总数: %d个\n", PAGE, use_num, PAGE - use_num, process_num);
	if (use_num < PAGE) {
		printf("已使用的内存块(%d):\n", use_num);
		int tmp = 1;  //用于换行
		for (int i = 0; i < PAGE; i++) {
			if (memory[i] == 1) {
				if (tmp == 15) {
					printf("%d\n", i);
					tmp = 1;
				}
				printf("%d ", i);
				tmp++;
			}
		}
	}
	if (process_num > 0) {
		printf("\n各进程详细使用情况如下: \n");
		for (int i = 0; i < PAGE; i++) {
			if (process[i][0] > 0) {
				printf("进程号：%d \n占用内存块 (%d块)：", i, process[i][0]);
				int tmp = 1;
				for (int j = 1; j <= process[i][0]; j++)
				{
					if (tmp == 15) {
						printf("%d\n", process[i][j]);
						tmp = 1;
					}
					printf("%d ", process[i][j]);
					tmp++;
				}
				printf("\n");
			}
		}
	}
	else {
		printf("\n当前内存无进程块!\n");
	}
}
void init_memory() //随机占用18块内存块
{
	memset(memory, 0, sizeof(memory)); //将所有内存块置为0，表示未使用
	const int count = 18;
	srand((unsigned)time(NULL)); //初始化随机数
	for (int i = 0; i < count; i++) {
		memory[rand() % PAGE] = 1; //产生0~99的随机数
	}
	use_num = count;  //初始化已经使用的内存 
	for (int i = 0; i < PAGE; i++) {   //初始化进程数组
		process[i][0] = 0;
		for (int j = 1; j < PAGE; j++)
			process[i][j] = -1;
	}
	process_num = 0;  //初始化进程数
	printf("初始化结果如下:\n");
	check();
}


void build_process() //创建进程
{
	int num, size;
	printf("请输入进程号（小于%d）和所需页面: ", PAGE);
	scanf("%d%d", &num, &size);
	if (num >= PAGE) {
		printf("输出错误，进程号越界!\n");
		
		return;
	}
	if (PAGE - use_num < size) {
		printf("内存空间不足\n");
		return;
	}
	if (process[num][0] != 0)
	{
		printf("该进程已存在，请使用未使用的进程ID\n");
		return;
	}
	use_num += size;
	process[num][0] = size;
	int k = 0;
	for (int i = 1; i <= size; i++) {   //检查是否存在相同进程号的进程
		while (memory[k] == 1 && k < PAGE) {
			k++;
		}
		process[num][i] = k;
		memory[k++] = 1;
	}
	process_num++;
	printf("创建新进程成功!\n");
}

void end_process()  //结束进程
{
	int num, size;
	if (process_num < 1) {
		printf("当前内存没有进程!\n");
		return;
	}
	printf("请输入进程号（小于%d）: ", PAGE);
	scanf("%d", &num);
	if (process[num][0] == 0) {
		printf("该进程不存在!\n");
		return;
	}
	size = process[num][0];
	for (int j = 1; j < size; j++)
	{
		memory[process[num][j]] = 0;
		process[num][j] = -1;
	}
	process[num][0] = 0;
	process_num--;
	use_num -= size;
	printf("结束进程成功!\n");
}

void menu() //菜单
{
	printf("\n操作菜单:\n");
	printf("1、创建进程\n");
	printf("2、结束进程\n");
	printf("3、查看内存\n");
	printf("0、退出程序\n");
	printf("请输入您要进行的操作: ");
}

int main(int argc, char* argv[])
{
	
	init_memory(); /*初始化内存空间*/
	int choice;
	menu();
	while (scanf("%d", &choice) != 0) {
		switch (choice)
		{
		case 1:
			build_process();
			break;
		case 2:
			end_process();
			break;
		case 3:
			check();
			break;
		case 0:
			printf("程序已经退出!\n");
			exit(0);
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
		menu();
	}
	system("pause");
	return 0;
}