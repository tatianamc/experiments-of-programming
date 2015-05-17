corr <- function(directory, threshold = 0) {
  files <- list.files(directory, full.names=TRUE)
  
  comp <- complete("specdata")
  comp <- comp[comp$nobs>threshold,]

  result = numeric(nrow(comp))
  if(nrow(comp)>1) {
    for(i in 1:nrow(comp)) {
      current <- comp[i,]$id
      mydata = read.csv(files[current]) 
      result[i] <- cor(mydata$sulfate, mydata$nitrate, use = "complete")
    }
  }
  
  result  
}