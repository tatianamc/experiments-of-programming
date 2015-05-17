complete <- function(directory, id = 1:332) {
  
  files <- list.files(directory, full.names=TRUE)
  
  result <- data.frame(id= numeric(0), nobs= integer(0))
  
  for(i in id ){
    mydata = read.csv(files[i]) 
    nobs <-nrow(mydata[complete.cases(mydata),])
    newrow <- data.frame(id= i, nobs= nobs)
    result <- rbind(result, newrow)
    
  }
  
  result
  
}