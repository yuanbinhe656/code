MOV R0,#00H ;初始化R0
MOV R1,#03H ;给R1赋值
MOV A,R1 ;吧R1的值传送到A
PUSH A ;吧A入栈
AND A,#00H ;吧A与0作于运算
OUT ;
OR A ,#00H ;吧A与0作或运算
OUT ;
CPL A ;吧A按位取反
OUT
CPL A ;再把A按位取反
OUT
MOV A,@R1 ;间接寻址
OUT
POP A ;出栈
OUT
MOV R2,#03H ;给R2赋值
TEST R2,#0FH ;检查R2末位是否为0
JZ OVER ;跳转到结束
LOOP: SUB R2,#01H ;将R2减去1
CALL INCA ;调用小程序
MOV A,R0 ;吧R0的值传给A
ADD R1,A ;吧A的值加到R1上
ADD R2,#01H ;R2加1
MOV A,R2 ; 吧R2的值传送到A
SUB R1,A ; R1值减去A的值
SUB R2,#01H ; R2减去1
JMP LOOP ;跳转到循环
INCA: TEST R2,#0FH ;检查R2末位是否为0
JZ OVER ; 跳转结束
TEST R2,#01H ; 测试末位为1，是就跳转
JZ NEXT ;跳转
MOV A,R1 ;吧R1的值传送到A中
ADD R0,A ; 吧累加器A的数与寄存器R0的数进行加和
RET ;返回
NEXT: SHL R1 ;将被乘数左移一位
SHR R2 ; 将乘数右移一位
JMP INCA ; 继续下一次判定并作乘法
OVER: JMP OVER ;死循环锁住PC的值
————————————————
版权声明：本文为CSDN博主「敲代码去」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/whj707216853/article/details/79726277
