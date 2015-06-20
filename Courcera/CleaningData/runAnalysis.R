runAnalysis <- function() {
  if(!file.exists('./data')){dir.create("./data")}
  fileUrl <- "urlPath"
  download.file(fileUrl, destfile="./data/restaurants.csv", method="curl")
  restData <- read.csv("./data/restaurants.csv")  
}