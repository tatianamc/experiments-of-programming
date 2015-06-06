getAnswer <- function() {
  data <- read.csv("data/getdata-data-ss06hid.csv", colClasses = "character");
  # data[,outname]<-as.numeric(data[,outname] );
  nrow(data[data$VAL==24,])
}

getAnswer3 <- function() {
  library(xlsx)
  dat <- read.xlsx("data/getdata-data-DATA.gov_NGAP.xlsx", sheetIndex=1, header=TRUE, rowIndex=18:23, colIndex=7:15)
  sum(dat$Zip*dat$Ext,na.rm=T) 
}

getAnswer4 <- function() {
  library(XML)
  doc <- xmlTreeParse("data/restaurants.xml", useInternal=TRUE)
  rootNode <- xmlRoot(doc)
  # xmlName(rootNode)
  zipcodes <- xpathSApply(rootNode, "//row/zipcode", xmlValue)
  length(zipcodes[zipcodes==21231])
}

getAnswer5 <- function() {
  library(data.table)
  DT <- fread("data/getdata-data-ss06pid.csv")
  
  #print(system.time(rowMeans(DT)[DT$SEX==1]))
  #print(system.time(rowMeans(DT)[DT$SEX==2]))
  
  #system.time(sapply(split(DT$pwgtp15,DT$SEX),mean))
  
  #system.time(DT[,mean(pwgtp15),by=SEX])
  #system.time(tapply(DT$pwgtp15,DT$SEX,mean))
  system.time(mean(DT$pwgtp15,by=DT$SEX))
  
}