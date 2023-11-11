import turtle
turtle.speed(10)
def tree(n):
    turtle.penup()
    turtle.setpos(0,-250)
    turtle.pendown()
    turtle.left(90)


    tree_branch(n)
    turtle.exitonclick()

def tree_branch(t):
    if t<=0:
        return 0
    turtle.forward(20*t)
    turtle.right(20)
    tree_branch(t-1)
    turtle.left(40)
    tree_branch(t-1)
    turtle.right(20)
    turtle.backward(20*t)



tree(7)
