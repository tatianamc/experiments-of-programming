import scala.annotation.tailrec
def or(x:Boolean,y: =>Boolean) = if(x) true else y
def and(x:Boolean,y: => Boolean) = if(x) y else false
//def loop:Boolean = loop
//and(false, loop)
/** Calculates the square root of parameter x */
def improve(guess: Double, x: Double) =
  (guess + x/guess)/2

def abs(x: Double) =
  if( x< 0) -x else x

def isGoodEnough(guess: Double, x: Double) =
  abs(guess*guess - x) < 0.001

def sqrtIter(guess: Double, x: Double): Double =
  if (isGoodEnough(guess, x)) guess
  else sqrtIter(improve(guess, x), x)

def sqrt(x: Double): Double = sqrtIter(1.0, x)
println(sqrt(2))
def gcd(a: Int, b: Int): Int =
if(b==0) a else gcd(b, a%b)
@tailrec
def gcd2(a: Int, b: Int): Int =
  if(b==0) a else gcd2(b, a%b)

def fact(a: Int): Int =
  if(a==1) 1 else a*fact(a-1)

fact(5)
@tailrec
  def loop(acc: Int, n:Int): Int =
    if(n==0) acc
    else
    loop(acc*n,n-1)
    loop(1,60)

