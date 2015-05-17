pollutantmean <- function(directory, pollutant, id = 1:332) {

  allfiles <- list.files(directory, full.names=TRUE)
  files = allfiles[id]
  
  data = data.frame()
  
  #print(files)
  for(i in 1:length(files)) {
    mydata = read.csv(files[i])
    data = rbind(data,mydata)
  }
  
  mean( data[[pollutant]], na.rm = TRUE)
}