import unittest
def function_name(a,b):#定义一个待测试的函数
    return a+'.'+b

class name_Test(unittest.TestCase):#定义一个测试类
    def test_fist(self):#在该类中定义一个方法
        testname=function_name('liu','jun')#通过一个变量将待测试函数的返回值获取
        self.assertEqual(testname,'liu.jun')#将该函数的返回值类型与自己预期的结果进行匹配
        self.assertEqual(a,b)#核实a==b
        self.assertNotEqual(a,b)#核实a！=b
        self.assertTrue(x)#核实x为真
        self.assertFalse(x)#核实x为假
        self.assertIn(item,list)#核实item在list中
        self.assertNotIn(item,list)#核实item不在list中
unittest.main()#调用该测试类函数

