import turtle

def draw_figures():
    window = turtle.Screen()
    window.bgcolor("red")
    brad = turtle.Turtle()
    brad.shape("turtle")
    brad.color("yellow")
    brad.speed(1)
    
    for _ in range(4):
        brad.forward(100)
        brad.right(90)
    
    p2 = turtle.Turtle()
    p2.shape("classic")
    p2.color("blue")
    p2.circle(100)
    
    for _ in range(3):
        p2.forward(100)
        p2.right(120)
        
    window.exitonclick()
    
    
draw_figures()
