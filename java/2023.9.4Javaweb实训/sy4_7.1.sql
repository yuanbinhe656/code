-- insert into user(列名,列名) values(值1,值2)
insert into user(username,password,balance) values('ls','123456',1000.0)

-- 查询username='ls'的用户
-- * 全部的列名
select * from user where username='ls'


-- 登录的sql, 能得到用户信息，不为null 就能登录 ，为Null 不能登录 
select * from user where username='ls' and password = '123457'

-- 使用Sql为ls添加三个常用旅客
-- 查询username='ls'的常用旅客
select * from passenger where username='ls'

insert into passenger(pid,pname,cardnum,phone,username) values(DEFAULT,'ls1','412000198912054568','18200000000','ls')

-- 删除常用旅客
delete from passenger where pid = 4


-- 模糊查询 姓名  % 0个或多个字符 
--  _ 1个字符
select * from passenger where pname like '%1%' 

-- 查询 张xx
select * from passenger where pname like '张%' 

-- 查询 --
select * from passenger where pname like '__' 

-- 根据手机号查询旅客

select * from passenger where phone = '18236000001'


-- 查询所有的航班
select * from flight

select fight_date '日期',fight_num 航班号,arrival_time 到达时间 from flight


-- 查询2023-07-03 北京出发的所有航班
select * from flight where fight_date = '2023-07-03' and departure_city = '北京'


-- 预定
select * from flight where fid = (1)
select * from passenger where username='zhangsan'

select pname,cardnum from passenger where username='zhangsan'
-- substr(要截取的字符串,从哪个位置开始截取)
select pname,substr(cardnum,length(cardnum)-5) from passenger where username='zhangsan'
-- 姓名-081234   concat 拼接
select concat(pname,'-',substr(cardnum,length(cardnum)-5)) from passenger where username='zhangsan'

-- 扣钱
-- 查询余额
select * from user where username='zhangsan'

-- update 充值
update user set balance = balance+500 where username='zhangsan'

-- update 消费
update user set balance = balance-1269 where username='zhangsan'

-- 生成订单
select * from flightorder where username='zhangsan'

-- insert 语句生成订单
insert into flightorder(oid,order_time,order_amount,order_status,username,fid,pid)
values(default,NOW(),1269,1,'zhangsan',1,2)


-- 查询当前登录用户的所有订单
select * from flightorder where username='zhangsan'
-- 多表连查  消除笛卡尔积
select 
	fo.oid '订单号',
	f.fight_num '航班号',
	f.fight_date '起飞时间',
	concat(f.departure_city,'-',f.arrival_city) '行程',
	p.pname '乘机人',
	f.ticket_price '票价',
	(0.066*f.ticket_price) '政策',
	fo.order_amount '应付',
	fo.username '操作人',
	fo.order_time '创建时间'
from flightorder fo	left join flight f on fo.fid = f.fid
	left join passenger p on fo.pid = p.pid
where fo.username='zhangsan'

-- 在上条sql的基础上分别根据定单号，乘机人，航班日期进行搜索

-- 退票 
-- 1.退钱
update user set balance = balance+(select order_amount from flightorder where oid=1) where username = 'zhangsan';
-- 2.删除订单
delete from flightorder where oid = 1
-- 3.查看退款有没有到账
select * from user where username='zhangsan'

