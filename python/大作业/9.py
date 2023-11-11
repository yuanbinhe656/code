import turtle


def koch(t, n):

    if n < 5:
        t.fd(n)
        return
    m = n / 3
    koch(t, m)
    t.lt(60)
    koch(t, m)
    t.rt(120)
    koch(t, m)
    t.lt(60)
    koch(t, m)


def snowflake(t, n):
    # 画一朵雪花，每一边都是一个科赫曲线
    for i in range(3):
        koch(t, n)
        t.rt(120)


bob = turtle.Turtle()
bob.color('black')
bob.penup()  # 画笔提起（不能画）
bob.goto(-150, 90)  # 去到这个点
bob.pendown()  # 画笔落下（开始画）
snowflake(bob, 300)  # 调用函数开始画雪花
turtle.mainloop()
