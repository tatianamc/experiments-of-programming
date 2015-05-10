# Vectors
x <- c(1,2,3) # create vector of objects
y <- vector("numeric",length=10) 
p = 1:6
z = as.character(p)

# List
x <- list(1, "a", TRUE, 1+4i)


# Matrix
#1
xx1 <- matrix(nrow=2, ncol=3)

#2
xx2 <- matrix(1:6,nrow=2, ncol=3)

#3
m <- 1:10
dim(m) <-c(2,5)

#4
xx <- 1:3
yy <- 10:12
amx = cbind(xx,yy)
bmx = rbind(xx,yy)


## Factors
facX <- factor(c("yes", "yes","no"))
faxY <- factor(c("yes", "yes","no"), levels = c("yes","no"))

main <- function() {
	print(class(p))
	print(x)
	
	#Factors
	print(table(facX))
	print(unclass(facX))
}

# x<- c(1,2,3,4,3,3,2,2,11,1)
# x[1]
# x[x>2]
#
# Flags if true or false
# u <- x>2
#
#
#
