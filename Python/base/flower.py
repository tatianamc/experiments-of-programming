import turtle

def draw_tr(pen):
    pen.forward(100)
    pen.right(120)

def draw_flower():
    window = turtle.Screen()
    window.bgcolor("white")
    pen = turtle.Turtle()
    pen.shape("classic")
    pen.color("blue")
    pen.speed(10)
    
    for _ in range(36):
        draw_tr(pen)
        pen.right(5)
   
    pen.forward(50)
    pen.left(90)
    pen.forward(150)
    
    window.exitonclick()
    
    
draw_flower()
