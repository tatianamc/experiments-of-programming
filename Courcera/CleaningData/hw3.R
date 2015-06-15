task4 <- function() {
  con = url("http://biostat.jhsph.edu/~jleek/contact.html")
  htmlCode = readLines(con)
  close
  htmlCode
  result<-c(0,0,0,0)
  result[1] <- nchar(htmlCode[10])
  result[2] <- nchar(htmlCode[20])
  result[3] <- nchar(htmlCode[30])
  result[4] <- nchar(htmlCode[100])
  result
}

task5 <- function() {
  ws<-c(15,4,4,5,4,4,5,4,4,5,4,4)
  dat <<- read.fwf("getdata-wksst8110.for",ws, skip = 4,header = FALSE)
  sum(dat[5])
}