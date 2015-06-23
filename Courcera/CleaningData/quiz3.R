task1<- function() {
  rdata <- read.csv("./data/getdata-data.csv")
  agricultureLogical <- (rdata$ACR==3)&(rdata$AGS==6)
  which(agricultureLogical)
}

task2 <- function() {
  library("jpeg")
  img <- readJPEG("./data/getdata-jeff.jpg", native = TRUE)
  quantiles <- quantile(img, probs = seq(0,1,0.10))
  answer <- c(quantiles[4],quantiles[9])
  answer
}

task3 <- function() {
  GDP <-  read.csv("./data/getdata-data-GDP.csv")
  FEDSTAT <- read.csv("./data/getdata-data-EDSTATS_Country.csv")
  
  mergedData <- merge(GDP,FEDSTAT,by.x="X",by.y="CountryCode", all=FALSE)
  mergedData[,2] <- as.numeric(as.character(mergedData[,2])) 
  
  mergedData <- mergedData[!is.na(mergedData$Gross.domestic.product.2012),]
  
  sortedMergedData <- mergedData[order(-mergedData$Gross.domestic.product.2012),]  
  sortedMergedData
}

task4 <- function() {
  GDP <<-  read.csv("./data/getdata-data-GDP.csv")
  FEDSTAT <<- read.csv("./data/getdata-data-EDSTATS_Country.csv")
  
  mergedData <- merge(GDP,FEDSTAT,by.x="X",by.y="CountryCode", all=FALSE)
  mergedData[,2] <- as.numeric(as.character(mergedData[,2])) 
  
  mergedData <- mergedData[!is.na(mergedData$Gross.domestic.product.2012),]
  
  sortedMergedData <<- mergedData[order(-mergedData$Gross.domestic.product.2012),] 
  
  aggregate(`Gross.domestic.product.2012` ~Income.Group , data=sortedMergedData, mean)
  
}


task5 <- function() {
  GDP <<-  read.csv("./data/getdata-data-GDP.csv")
  FEDSTAT <<- read.csv("./data/getdata-data-EDSTATS_Country.csv")
  
  mergedData <- merge(GDP,FEDSTAT,by.x="X",by.y="CountryCode", all=FALSE)
  mergedData[,2] <- as.numeric(as.character(mergedData[,2])) 
  
  mergedData <- mergedData[!is.na(mergedData$Gross.domestic.product.2012),]
  
  sortedMergedData <<- mergedData[order(-mergedData$Gross.domestic.product.2012),] 
  
  sortedMergedData[sortedMergedData[,2]<39 & sortedMergedData[,12]=="Lower middle income",]
}