
getdata <- function() {
  if (!file.exists("data")) {
    dir.create("data")
  }
  
  fileUrl <-"https://data.baltimorecity.gov/api/views/dz54-2aru/rows.csv?accessType=DOWNLOAD"
  download.file(fileUrl, destfile = "./data/cameras.csv")
  list.files("./data")
  dateDownloaded <- data()
  dateDownloaded
  
  # From file
  # download.table()
  
  # From Excel
  #read.xlsx("path", sheetIndex=1, header=TRUE)
  
  # XML reading
  # library(XML)
  # doc <- xmlTreeParse(fileUrl, useInternal=TRUE)
  # rootName <- xmlRoot(doc)
  
  # load JSON
  # myjson <- toJSON(iris, pretty=TRUE)
  # cat(myjson)
}

